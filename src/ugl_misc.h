#ifndef MISC_H
#define MISC_H
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "ugl_oglsdl.h"
#ifndef M_PI
#define M_PI 22/7.0
#define M_PI 3.1415926535897932384626433832795
#endif
#define PIdiv180 (M_PI/180.0)
namespace umangagl{
	
class CVector3
{
public:
	CVector3(){
	
	}
	
	CVector3(float X,float Y,float Z)
	{
	  x=X;y=Y;z=Z;
	}
	
	CVector3 operator+(CVector3 vVector)
	{
   	 return CVector3(vVector.x + x, vVector.y + y, vVector.z + z);
	}
	
	CVector3 operator-(CVector3 vVector)
        {
         return CVector3(x - vVector.x, y - vVector.y, z - vVector.z);
        }
    
        CVector3 operator*(float num)
       {
         return CVector3(x * num, y * num, z * num);
       }
    
       CVector3 operator/(float num)
       {
         return CVector3(x / num, y / num, z / num);
       }
    
       
       float dotProduct(CVector3 other)
       {
        return (x*other.x+y*other.y+z*other.z);
       }
       void scalarMultiply(float num)
       {
       x=x*num;
       y=y*num;
       z=z*num;
       }
       void normalize()
       {
        float mag=getMagnitude();
	if(mag==0) return;
	x=x/mag;
	y=y/mag;
	z=z/mag;
       }
       float getMagnitude()
       {
        return (float)sqrt((x * x)+(y*y)+(z*z));	
       }
       void setValues(float X,float Y,float Z)
       {
        x=X;y=Y;z=Z;
       }
       void rotateY(float ang)
       {
        }
	//flatcostheta=0;
	
	CVector3 crossProduct(CVector3 other)
	{
	 
	  CVector3 vNormal;    
            vNormal.x = ((y * other.z) - (z * other.y));
            vNormal.y = ((z * other.x) - (x * other.z));
            vNormal.z = ((x * other.y) - (y * other.x));
        return vNormal;             
	
	
       }
       float x,y,z;
};

CVector3 VectorCross(CVector3 vVector1, CVector3 vVector2);
float VectorMagnitude(CVector3 vNormal);
CVector3 VectorNormalize(CVector3 vVector);
CVector3 VectorSubtract(CVector3 vPoint1, CVector3 vPoint2);
CVector3 VectorTriangleNormal(CVector3 vTriangle[]);
int CreateTexture(unsigned int textureArray[],char *strFileName,int textureID);
void swap(unsigned char & a, unsigned char & b);
bool rayIntersectPlane(CVector3 linestart,CVector3 lineend,CVector3 vertex,CVector3 normal,CVector3 *intersection);
bool pointOnPolygon(CVector3 point,CVector3 vertices[],int numOfVertices);
CVector3 faceNormal(CVector3 pnts[]);
void log(const char* text);
typedef unsigned char byte;
};
#endif
