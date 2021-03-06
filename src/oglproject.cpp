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


#include <iostream>
#include <cstdlib>
#include <SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <math.h>
#include "umangagl.h"
#define PI M_PI



using namespace std;
using namespace umangagl;
bool done=false;
bool moveForward=false,moveBackward=false;
void start();
CEngine engine;
CLight lit1;
CTexture tex1;
CMD2Mesh mesh;
CVector3 dire;

int main(int argc, char *argv[])
{
   
  engine.initializeVideo(800,600,16,!true);
  engine.setPerspective(60.0,1,0.1,100);
  lit1.enableOpenGLLighting();
  lit1.enableLightSource();
  lit1.setTypeDirectional();
  //lit1.setPosition(0.0,1.0,0.0);
  lit1.setupLight();
  //lit1.setLightingModelAmbient(0.6,0.6,0.6,1.0);
  //lit1.setTypePositional();
  lit1.setSpotCutoffAngle(5);
  tex1.loadPCXTexture("tex2.pcx");
  cout << mesh.loadModel("tris.md2","tex2.pcx");
  mesh.setFrame(40);
  mesh.animation(0,45);
  mesh.setScale(2.0,2.0,2.0);
  mesh.setPosition(5.0,5.0,20.0);
  //mesh.setRotationY(45);
  start();
  engine.shutDown();
  //printf("end");
  return EXIT_SUCCESS;
}
void keyup(SDL_Event* event)
{
 SDL_Event e;
 e=*event;
 
  switch(e.key.keysym.sym) 
    {
        case SDLK_F1 : 
          engine.toggleFullScreen();
	  break;

        case SDLK_ESCAPE:
      	  done=true;
	
	 break;
        case SDLK_UP :
         //engine.getDefaultCamera()->move(0.3,1,1,1);
	  moveForward=false;
	case SDLK_w :
         break;
            
       case SDLK_DOWN : 
          //engine.getDefaultCamera()->move(-0.3,1,1,1);
	 // engine.getDefaultCamera()->moveForward(-0.3);
	  moveBackward=false;
       case SDLK_s :
        
            break;

       case SDLK_RIGHT :
           engine.getDefaultCamera()->strafe(3);
       case SDLK_d :
        
            break;

       case SDLK_LEFT :
         engine.getDefaultCamera()->strafe(-3);
       case SDLK_a :
        break;

        default:  
            break; 
    }
 
}

void mouseover(SDL_Event* event)
{
 engine.getDefaultCamera()->setViewByMouse(800,600);
}

void keydown(SDL_Event* event)
{
 SDL_Event e;
 e=*event;
 
  switch(e.key.keysym.sym) 
    {
        case SDLK_F1 : 
          //engine.toggleFullScreen();
	  break;

        case SDLK_ESCAPE:
      	  done=true;
	
	 break;
        case SDLK_UP :
         //engine.getDefaultCamera()->move(0.3,1,1,1);
	  moveForward=true;
	case SDLK_w :
         break;
            
       case SDLK_DOWN : 
          //engine.getDefaultCamera()->move(-0.3,1,1,1);
	 // engine.getDefaultCamera()->moveForward(-0.3);
	  moveBackward=true;
       case SDLK_s :
        
            break;

       case SDLK_RIGHT :
           engine.getDefaultCamera()->strafe(3);
       case SDLK_d :
        
            break;

       case SDLK_LEFT :
         engine.getDefaultCamera()->strafe(-3);
       case SDLK_a :
        break;

        default:  
            break; 
    }

}

void drawfloor()
{
 // glPushMatrix();
  //glScalef(4.0,4.0,4.0);
  //mesh.setScale(2.0,2.0,2.0);
  mesh.animate(0,0,0,100);
  //mesh.setPosition(0,0,2);
  //mesh.drawBoundingBox();
 // glPopMatrix();
  lit1.disableOpenGLLighting();
  CVector3 t=engine.getDefaultCamera()->getLookAt();
  
  t=t*5;
  CVector3 p=engine.getDefaultCamera()->getPosition();
  //lit1.setPosition(p.x,p.y,p.z);
  //lit1.setSpotDirection(t.x,t.y,t.z);
  //t.y=t.y+1.0;
  //p.y=p.y+2;
  //glLineWidth (2);
  if(mesh.detectRayTraceCollision(p+t,p)) mesh.drawBoundingBox();
//if(mesh.detectBoundingBoxCollision(p+t,p)) mesh.drawBoundingBox();
  
 // mesh.setPosition(t.x+p.x,t.y+p.y,t.z+p.z);
  glColor3f(1.0,0.0,0.0);
  glBegin(GL_LINES);
   glVertex3f(p.x,p.y,p.z);
   glVertex3f(t.x+p.x,t.y+p.y,t.z+p.z);
  glEnd();
  glColor3f(1.0,1.0,1.0);
  for(float i = -50; i <= 50; i += 2)
    {
       glBegin(GL_LINES);
            glVertex3f(-50, 0, i);
            glVertex3f(50, 0, i);
            glVertex3f(i, 0, -50);
            glVertex3f(i, 0, 50);
        glEnd();
    }
    lit1.enableOpenGLLighting();
}

void drawit()
{
 
 tex1.enableOpenGLTexturing();
 tex1.setActive();
 //engine.disableLighting();
 glPushMatrix();
 glScalef(1.0,1.0,2.0);
 glBegin(GL_POLYGON);

  for(int a=0;a<360;a+=10)
 {
  float ang=(PI/180.0)*a;
  GLfloat x=cos(ang)*3;
  GLfloat y=sin(ang)*3;
  //glColor3f(0.6,0.6,0.2);
  glNormal3f(0.0,0.0,1.0);
  glTexCoord2f((1+cos(ang))/2.0,(1+sin(ang))/2.0);
  glVertex3f(x,y,0);
  
  
 }
 
 glEnd();
 glPopMatrix();
 tex1.disbleOpenGLTextureing();
 //engine.enableLighting();
 
}
float calcAng(CVector3 from,CVector3 to)
{
 CVector3 vN;
 float r,temp;
 vN=from-to;
 CVector3 d;
 r=VectorMagnitude(vN);
 temp=vN.z/r;
 //printf("temp %f",temp);
 if(temp==1)
 {
  d.y=0.0;
 } else if(temp==-1)
 {
  d.y=M_PI;
 } else
 {
  d.y=atan(-temp/sqrt(-temp*temp+1))+(M_PI/2);
 }
 
 temp=vN.x/(r*sin(d.y));
 
 if(temp==1)
  {
   d.z=0;
  } else if(temp==-1)
  {
   d.z=M_PI;
  } else
  {
   float v=(-temp*temp+1);
   if (v<0) v=-v;
   d.z=atan(-temp /sqrt(v)) + (M_PI/2);
  }
  
  if(vN.y<0)
   d.z=-d.z;
 dire.x=d.x*(180/M_PI);
 dire.y=d.y*(180/M_PI);
 dire.z=d.z*(180/M_PI); 
 //mesh.setRotation(dire.x,dire.y,dire.z);
}
void start()
{
	
	//glClearColor(0.1,0.2,0.2,1);
	//GLUquadricObj* q = gluNewQuadric();
	
	
	float f=0.0;
	float fc[4]={0.2,0.2,0.2,1.0};
	
	CVector3 from(0,0,5);
	engine.getDefaultCamera()->setPosition(0,3,5);
	
	engine.setCallbackFuncKeydown(keydown);
	engine.setCallbackFuncKeyup(keyup);
	engine.setCallbackFuncMouseover(mouseover);
	while(!done)
	{
	f+=0.1;
	mesh.setRotationY(f*10,true);
	engine.startScene(!true);
	
	if (moveBackward) engine.getDefaultCamera()->moveForward(-0.1);
	if (moveForward) engine.getDefaultCamera()->moveForward(0.1);
	engine.getDefaultCamera()->setCamera();
	lit1.setupLight();
	//mesh.animate(0,0,0,100); 
	glPushMatrix();
	 
	  drawfloor();
	  calcAng(from,engine.getDefaultCamera()->getPosition());
   glPushMatrix();
	   glTranslatef(0,0,5); 
            //fprintf(stdout,"%f %f\n",dire.z, dire.y);
	   glPushMatrix(); 
	       
	       drawit();
	    glPopMatrix();
   
	
	   
	  
    glPopMatrix();
    glPopMatrix();
       
     
     
	engine.endScene();
	engine.pumpEvents();
	
	
	}	
}
