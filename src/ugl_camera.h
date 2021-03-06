#ifndef umangaGLCamera_H
#define umangaGLCamera_H
#include "ugl_misc.h"
#include "ugl_oglsdl.h"
namespace umangagl
{
class CCamera
{
  private:
   CVector3 positionVec;
   CVector3 viewVec;
   CVector3 upVec;
   CVector3 rightVec;
   CVector3 forwardUpVec;
   GLfloat rotatedX,rotatedY,rotatedZ;
   int oldMouseX,oldMouseY;
 public:
   CCamera();
  ~CCamera();
   //void moveForward(float speed);
   void strafe(float speed);
   void move(CVector3 direction);
   void setCamera();
   void setPosition(float posx,float posy,float posz);
   void setLookAt(float lookx,float looky,float lookz);
   void rotateX(GLfloat angle);
   void rotateY(GLfloat angle);
   void rotateZ(GLfloat angle);
   void setViewByMouse(const int,const int);
   void moveForward(float speed);
   void moveXZPlane(float distance);
   void moveUpward(float distance);
   CVector3 getPosition();
   CVector3 getLookAt();

};
};
#endif

