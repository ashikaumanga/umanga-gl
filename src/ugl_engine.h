/***************************************************************************
 *   Copyright (C) 2006 by Ashika Umanga Umagiliya                         *
 *   umanga@bluebottle.com       umanga@ceit.pdn.ac.lk                     *
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
#ifndef UMANGAGLUGL_ENGINE_H
#define UMANGAGLUGL_ENGINE_H

#include "ugl_oglsdl.h"
#include "ugl_camera.h"

#if defined(_WIN32)
  #define UGLCALLBACK __cdecl
#else
  #define UGLCALLBACK
#endif


namespace umangagl {

/**
@author Ashika Umanga Umagiliya
*/
typedef void (UGLCALLBACK *UGLKeydownCB)(SDL_Event* event);
typedef void (UGLCALLBACK *UGLKeyupCB)(SDL_Event* event);
typedef void (UGLCALLBACK *UGLMousebuttonCB)(SDL_Event* event);
typedef void (UGLCALLBACK *UGLMouseoverCB)(SDL_Event* event);

class CEngine{
private:
    int width;
    int height;
    int windowbpp;
    int flags;
    SDL_Surface *GLWindow;
    GLbitfield clearBits;
    CCamera *defCamera;
    //Callback functions for keyboard and mouse event handling
    UGLKeydownCB keydownFunc;
    UGLKeyupCB keyupFunc;
    UGLMousebuttonCB mousebuttonFunc;
    UGLMouseoverCB mouseoverFunc;
    
public:
    CEngine();
    bool initializeVideo();
    bool initializeVideo(int Width,int Height,int BPP,bool isFullScreen);
    bool initializeSound();
    void addGLSDLFlag(SDL_GLattr flag,int value);
    bool toggleFullScreen();
    bool resizeWindow(int Width,int Height);
    void setPerspective(GLdouble fov_angle,GLdouble aspect_ratio,GLdouble near,GLdouble far);
    void addClearBit(GLbitfield bit);
    void removeClearBit(GLbitfield bit);
    void setWindowCaption(const char *txtCaption);
    void enableFog();
    void disableFog();
    void setFog(GLfloat fogcolor[],GLfloat near,GLfloat far,GLfloat density,GLint fogmode,GLint hintmode);
    void setFog(GLfloat fogcolor[],GLfloat near,GLfloat far,GLfloat density);
    void startScene(bool setupDefaultCamera);
    void endScene();
    void setDefaultCamera(CCamera *cam);
    void pumpEvents();
    void enableTexturing();
    void disableTexturing();
    void enableLighting();
    void disableLighting();
    void setCallbackFuncKeyup(void (UGLCALLBACK *func)(SDL_Event* event));
    void setCallbackFuncKeydown(void (UGLCALLBACK *func)(SDL_Event* event));
    void setCallbackFuncMousebutton(void (UGLCALLBACK *func)(SDL_Event* event));
    void setCallbackFuncMouseover(void (UGLCALLBACK *func)(SDL_Event* event));
    CCamera* getDefaultCamera();
   // static void log(const char* text){fprintf(stdout,"%s\n",text);};
    //void test();
    
    void shutDown();    
    ~CEngine();

};

};

#endif
