/***************************************************************************
 *   Copyright (C) 2006 by Ashika Umanga Umagiliya                         *
 *   umanga@bluebottle.com               umanga@ceit.pdn.ac.lk             *
 *                                                                         *
 *   http://umanga.ifreepages.com                                          *  
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/
#include "ugl_engine.h"


namespace umangagl {

CEngine::CEngine()
{
  width=800;
  height=600;
  windowbpp=16;
  flags=SDL_OPENGL;
  clearBits=GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT;
  defCamera=new CCamera();
  keydownFunc=keyupFunc= mousebuttonFunc=mouseoverFunc=NULL;
  
}

bool CEngine::initializeVideo(int Width,int Height,int BPP,bool isFullScreen)
 {
          width=Width;
	  height=Height;
	  windowbpp=BPP;
	  GLWindow=NULL;
	  if(SDL_Init(SDL_INIT_VIDEO)<0)
	  {
	     fprintf(stderr,"Error init SDL: %s\n",SDL_GetError());
	     return false;
	  }
	  
	  const SDL_VideoInfo *info=SDL_GetVideoInfo();
	  
	  if(isFullScreen)
	  {
	   flags|=SDL_FULLSCREEN;
	  }
	  else
	  {
	   //windowbpp=info->vfmt->BitsPerPixel;
	  }
	   
	   
	   flags |= SDL_HWPALETTE; 
	   flags |= SDL_DOUBLEBUF;
	   flags |= SDL_HWACCEL;
	   
	  if(info->hw_available)                         
               { flags |= SDL_HWSURFACE; printf("HW SURFACE \n"); }
           else
               { flags |= SDL_SWSURFACE; printf("SW SURFACE \n"); }
	   
	  
	  
	  
	  
	  GLWindow=SDL_SetVideoMode(width,height,windowbpp,flags);
	  
	  if(GLWindow==NULL)
	  {
	      fprintf(stderr,"Error init VideoMode : %s\n",SDL_GetError());
	      return false;
	  }
	  
	  //SDL_GL_SetAttribute( SDL_GL_DOUBLEBUFFER, 1 );     // double buffered by default//can enavle other buffers
         // SDL_GL_SetAttribute( SDL_GL_DEPTH_SIZE,windowbpp); // size of depth buffer   
	  
	  
	  //glCullFace( GL_BACK );
         //glFrontFace( GL_CCW );
         //glEnable( GL_CULL_FACE );
	  glEnable(GL_DEPTH_TEST);
	  glShadeModel(GL_SMOOTH);
	  glEnable(GL_NORMALIZE);
	
	  
	  
	  
 }

 
void CEngine::addGLSDLFlag(SDL_GLattr flag,int value)
{
    SDL_GL_SetAttribute(flag,value);
}


void CEngine::setPerspective(GLdouble fov_angle,GLdouble aspect_ratio,GLdouble near,GLdouble far)
{
   glMatrixMode(GL_PROJECTION);
   gluPerspective(fov_angle,aspect_ratio,near,far);
   glMatrixMode(GL_MODELVIEW);
}


void CEngine::addClearBit(GLbitfield bit)
{
  clearBits |= bit;
}

void CEngine::startScene(bool setupDefaultCamera)
{
 glClear(clearBits);
 if(setupDefaultCamera)
   defCamera->setCamera();
}


void CEngine::endScene()
{
 //glFlush();
 SDL_GL_SwapBuffers(); 
 //glFlush();
}

CEngine::~CEngine()
{
       delete GLWindow;
       GLWindow=NULL;
       delete defCamera;
       defCamera=NULL;
}

void CEngine::setWindowCaption(const char *txtCaption)
{
    SDL_WM_SetCaption(txtCaption, txtCaption); 
}

void CEngine::shutDown()
 {
              
       printf("\n--UmangaGL shuting down--\n");
  
 }

void CEngine::setFog(GLfloat fogcolor[],GLfloat near,GLfloat far,GLfloat density,GLint fogmode,GLint hintmode)
 {
     
     glFogi (GL_FOG_MODE, fogmode);
     glFogfv(GL_FOG_COLOR, fogcolor);
     glFogf (GL_FOG_DENSITY, density);
     glHint (GL_FOG_HINT, hintmode);
     glFogf (GL_FOG_START, near);
     glFogf (GL_FOG_END, far);
     enableFog();
 }
 
void CEngine::setFog(GLfloat fogcolor[],GLfloat near,GLfloat far,GLfloat density)
{
    setFog(fogcolor,near,far,density,GL_EXP, GL_DONT_CARE); 
}

void CEngine::enableFog()
{
    glEnable(GL_FOG);
}

void CEngine::disableFog()
{
   glDisable(GL_FOG);
}

void CEngine::setDefaultCamera(CCamera* cam)
{
  defCamera=cam;
}

void CEngine::setCallbackFuncKeydown(void (UGLCALLBACK *func)(SDL_Event* event))
{
 keydownFunc=func;
}

void CEngine::setCallbackFuncKeyup(void (UGLCALLBACK *func)(SDL_Event* event))
{
 keyupFunc=func;
}

void CEngine::setCallbackFuncMousebutton(void (UGLCALLBACK *func)(SDL_Event* event))
{
 mousebuttonFunc=func;
}
void CEngine::setCallbackFuncMouseover(void (UGLCALLBACK *func)(SDL_Event* event))
{
 mouseoverFunc=func;
}

void CEngine::pumpEvents()
{
   
   SDL_Event event;
   while( SDL_PollEvent(& event) )  //get all the events from SDL evet poll and call our callback functions
        {
            switch ( event.type )   
            {
                case SDL_QUIT :  
                   SDL_Quit();
		   fprintf(stderr, "******************");
		   break;
                case SDL_KEYDOWN :    
                    if(keydownFunc==NULL) {fprintf(stderr,"No function assigned to keydownFunc()\n");break;}
		    keydownFunc(&event);
                    break;
                    
                case SDL_KEYUP :
                    if(keyupFunc==NULL) {fprintf(stderr,"No function assigned to keyupFunc()\n");break;}
		    keyupFunc(&event);
                    break;

               case SDL_MOUSEMOTION:
                   if(mouseoverFunc==NULL) {fprintf(stderr,"No function assigned to mouseoverFunc()\n");break;}
		   mouseoverFunc(&event);
                   break;
           
              case SDL_MOUSEBUTTONDOWN:
              case SDL_MOUSEBUTTONUP:
                 if(mousebuttonFunc==NULL) {fprintf(stderr,"No function assigned to mousebuttonFunc()\n");break;}
		 mousebuttonFunc(&event);
                
              case SDL_VIDEORESIZE :
                 break;

                default:                                    // any other event
                break;                                  // nothing to do
            } 
        }   

}

void CEngine::enableLighting()
{
 glEnable(GL_LIGHTING);
}
void CEngine::disableLighting()
{
 glDisable(GL_LIGHTING);
}

void CEngine::disableTexturing()
{
 glDisable(GL_TEXTURE_2D);
}

void CEngine::enableTexturing()
{
 glEnable(GL_TEXTURE_2D);
}


bool CEngine::toggleFullScreen()
{
  if (SDL_WM_ToggleFullScreen(GLWindow)>0) return true;
  return false;
}

CCamera* CEngine::getDefaultCamera()
 {
   return defCamera;
 }

};
