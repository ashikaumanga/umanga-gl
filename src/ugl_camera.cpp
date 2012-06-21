#include "ugl_camera.h"
#include <iostream>
#include <cstdlib>
using namespace std;
namespace umangagl{

CCamera::CCamera()
{
 
 positionVec.setValues(0.0,0.0,0.0);
 viewVec.setValues(0.0,0.0,0.5);
 upVec.setValues(0.0,1.0,0.0);
 rightVec.setValues(1.0,0.0,0.0);
 forwardUpVec.setValues(0.0,1.0,0.0);
  rotatedX=rotatedY=rotatedZ=0.0;
  oldMouseX=oldMouseY=0;
}

CCamera::~CCamera()
{
  
 printf("releasing camera :\n",this);
  
}

void CCamera::setPosition(float posx,float posy,float posz)
{
  positionVec.setValues(posx,posy,posz);
}


void CCamera::setLookAt(float X,float Y,float Z)
{
  viewVec.setValues(X,Y,Z);

}

void CCamera::rotateX(GLfloat angle)
{
  rotatedX+=angle;
  CVector3 tmp;
  tmp=viewVec*cos(angle*PIdiv180) + upVec*sin(angle*PIdiv180);
  tmp.normalize();
  viewVec= tmp;
  forwardUpVec=(viewVec.crossProduct(rightVec))*-1;
}

void CCamera::rotateY(GLfloat angle)
{
 rotatedY+=angle;
 viewVec=(viewVec*cos(angle*PIdiv180) - rightVec*sin(angle*PIdiv180));
 viewVec.normalize();
 rightVec=viewVec.crossProduct(upVec);
}

void CCamera::rotateZ(GLfloat angle)
{
 rotatedZ+=angle;
 rightVec=rightVec*cos(angle*PIdiv180) + upVec*sin(angle*PIdiv180);
 rightVec.normalize();
 forwardUpVec=viewVec.crossProduct(rightVec)*-1;
}

void CCamera::moveForward(float distance)
{
 CVector3 vforward=forwardUpVec.crossProduct(rightVec);
 vforward.normalize();
 positionVec=positionVec+ vforward*(distance);
}

void CCamera::move(CVector3 direction)
{
 positionVec=positionVec+direction;
}
    
void CCamera::setCamera()
{
   glLoadIdentity();
   CVector3 viewPoint=positionVec+viewVec;
   gluLookAt(positionVec.x,positionVec.y,positionVec.z,
   viewPoint.x,viewPoint.y,viewPoint.z,
   upVec.x,upVec.y,upVec.z);   
}

void CCamera::setViewByMouse(const int SCREENW,const int SCREENH)
 {
  int mouseX,mouseY;
  int middleX = SCREENW  >> 1;
  int middleY = SCREENH >> 1; 
  float rateY,rateX;
     
    
  SDL_GetMouseState(&mouseX,&mouseY);
  if( (mouseX == middleX) && (mouseY == middleY) ) return;
 rotateX((middleY-mouseY)/2.0);
 rotateY((middleX-mouseX)/2.0);
 SDL_WarpMouse(middleX, middleY);             
 return;
  /*mouseX=mouseX+oldMouseX;
  mouseY=mouseY+oldMouseY;
  rateY=fabsf(mouseY-oldMouseY);
  rateX=fabsf(mouseX-oldMouseX);
  if(mouseY>oldMouseY)
   {
    rotateX(-1.0*rateY);
   } else if (mouseY<oldMouseY)
        {
	  rotateX(1.0*rateY);
	}
 
 if(mouseX>oldMouseX) {rotateY(-1.0*rateX);}
	else if(mouseX<oldMouseX) {rotateY(1.0*rateX);}
	
	oldMouseX=mouseX;
	oldMouseY=mouseY;*/
	               
		
}
 
void CCamera::strafe(float speed)
{
 positionVec=positionVec + (rightVec*speed);
}

CVector3 CCamera::getLookAt()
 {
  return viewVec;
 }

CVector3 CCamera::getPosition()
{
 return positionVec;
}

};//end of namespace
