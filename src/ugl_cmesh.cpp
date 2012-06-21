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
#include "ugl_cmesh.h"

namespace umangagl {

CMesh::CMesh()
{
 //setBoundMax(-10000,-10000,-10000);
 //setBoundMin(10000,10000,10000);
 setScale(1.0,1.0,1.0);
 setPosition(0.0,0.0,0.0);
 setRotation(0.0,0.0,0.0);
 keepCurrent=false;
 vertices=NULL;
 overtices=NULL;
}

void CMesh::setBoundryMinMax(CVector3 min,CVector3 max)
{
 //boundMin.setValues(x,y,z);
 //oboundMin.setValues(x,y,z);
 boundry[0].setValues(min.x,max.y,min.z);
 boundry[1].setValues(max.x,max.y,min.z);
 boundry[2].setValues(max.x,max.y,max.z);
 boundry[3].setValues(min.x,max.y,max.z);
 
 boundry[4].setValues(min.x,min.y,min.z);
 boundry[5].setValues(max.x,min.y,min.y);
 boundry[6].setValues(max.x,min.y,max.z);
 boundry[7].setValues(min.x,min.y,max.z);
 for(int i=0;i<8;i++)
  oboundry[i]=boundry[i]; 
 
}

void CMesh::setPosition(float x,float y,float z)
{
 position.setValues(x,y,z);
}
void CMesh::setScale(float x,float y,float z){
 scale.setValues(x,y,z);
 if(keepCurrent) pPnts=&boundry[0];
  else pPnts=&oboundry[0];
 //CVector3 *ptr=&oboundry[0];
 for(int i=0;i<8;i++)
  {
   boundry[i].x= pPnts[i].x*x; 
   boundry[i].y= pPnts[i].y*y; 
   boundry[i].z= pPnts[i].z*z; 
  }
  keepCurrent=false;
}

CVector3 CMesh::getBoundryMax() {return boundry[2];}
CVector3 CMesh::getBoundryMin() {return boundry[4];}
CVector3 CMesh::getPosition(){return position;}
CVector3 CMesh::getScale(){return scale;}

void CMesh::setRotationX(float angle,bool useLocalCoords)
{
 if(!useLocalCoords) pPnts=&boundry[0];
  else pPnts=&oboundry[0];
 
 float ang=angle*PIdiv180;
 float cosTheta=(float)cos(ang);
 float sinTheta=(float)sin(ang);
 
 for(int i=0;i<8;i++)
 {
  boundry[i].y=pPnts[i].y*cosTheta-pPnts[i].z*sinTheta;
  boundry[i].x=pPnts[i].y*sinTheta+pPnts[i].z*cosTheta;
  boundry[i].x=pPnts[i].x;
 } 
 rotate.y=angle;
 keepCurrent=true;
 setScale(scale.x,scale.y,scale.z);
 keepCurrent=false;
 
}

void CMesh::setRotationY(float angle,bool useLocalCoords)
{
 if(!useLocalCoords) pPnts=&boundry[0];
  else pPnts=&oboundry[0];
 
 float ang=angle*PIdiv180;
 float cosTheta=(float)cos(ang);
 float sinTheta=(float)sin(ang);
 
 for(int i=0;i<8;i++)
 {
  boundry[i].z=pPnts[i].z*cosTheta-pPnts[i].x*sinTheta;
  boundry[i].x=pPnts[i].z*sinTheta+pPnts[i].x*cosTheta;
  boundry[i].y=pPnts[i].y;
 } 
 rotate.y=angle;
 keepCurrent=true;
 setScale(scale.x,scale.y,scale.z);
 keepCurrent=false;
}


void CMesh::setRotationZ(float angle,bool useLocalCoords)
{
 if(!useLocalCoords) pPnts=&boundry[0];
  else pPnts=&oboundry[0];
 
 float ang=angle*PIdiv180;
 float cosTheta=(float)cos(ang);
 float sinTheta=(float)sin(ang);
 
 for(int i=0;i<8;i++)
 {
  boundry[i].z=pPnts[i].z;
  boundry[i].x=pPnts[i].x*cosTheta-pPnts[i].x*sinTheta;
  boundry[i].y=pPnts[i].x*sinTheta+pPnts[i].y*cosTheta;
 } 
 rotate.y=angle;
 keepCurrent=true;
 setScale(scale.x,scale.y,scale.z);
 keepCurrent=false;
 
 
 

}

void CMesh::setRotation(float x,float y,float z)
{
 rotate.setValues(x,y,z);
}
CVector3 CMesh::getRotation()
{
 return rotate;
}

void CMesh::drawBoundingBox()
{
 GLboolean bTex=glIsEnabled(GL_TEXTURE_2D);
 GLboolean bLit=glIsEnabled(GL_LIGHTING);
 glDisable(GL_TEXTURE_2D);
 glDisable(GL_LIGHTING);
 
 glPushMatrix();
 
  glTranslatef(position.x,position.y,position.z);
    
  glColor3f(1.0,1.0,1.0);
  glBegin(GL_LINES);
   for(int i=0;i<4;i++)
   {
    glVertex3f(boundry[i%4].x    ,boundry[i%4].y    ,boundry[i%4].z);
    glVertex3f(boundry[(i+1)%4].x,boundry[(i+1)%4].y,boundry[(i+1)%4].z);
   }
    for(int i=4;i<7;i++)
   {
    glVertex3f(boundry[i].x    ,boundry[i].y    ,boundry[i].z);
    glVertex3f(boundry[(i+1)].x,boundry[(i+1)].y,boundry[(i+1)].z);
   }
    glVertex3f(boundry[4].x    ,boundry[4].y    ,boundry[4].z);
    glVertex3f(boundry[7].x,boundry[7].y,boundry[7].z);
    
    glVertex3f(boundry[4].x    ,boundry[4].y    ,boundry[4].z);
    glVertex3f(boundry[0].x,boundry[0].y,boundry[0].z);
    
    glVertex3f(boundry[5].x    ,boundry[5].y    ,boundry[5].z);
    glVertex3f(boundry[1].x,boundry[1].y,boundry[1].z);
    
    glVertex3f(boundry[6].x    ,boundry[6].y    ,boundry[6].z);
    glVertex3f(boundry[2].x,boundry[2].y,boundry[2].z);
    
    glVertex3f(boundry[7].x    ,boundry[7].y    ,boundry[7].z);
    glVertex3f(boundry[3].x,boundry[3].y,boundry[3].z);
  ///
   //glColor3f(1.0,0.0,0.0);
   
 
  ///
  glEnd();  
 glPopMatrix();
 
 if(bTex) glEnable(GL_TEXTURE_2D);
 if(bLit) glEnable(GL_LIGHTING);
}

bool CMesh::detectBoundingBoxCollision(CVector3 start,CVector3 end)
{

  CVector3 p[4];
  CVector3 n,intp;
  CVector3 pos=getPosition();

 int v[6][4]={{0,1,2,3},{4,5,6,7},{0,3,7,4},{2,1,5,6},{0,4,5,1},{3,2,6,7}};
 for(int k=0;k<6;k++)
 {
 
  p[0]=boundry[v[k][0]];
  p[1]=boundry[v[k][1]];
  p[2]=boundry[v[k][2]];
  p[3]=boundry[v[k][3]];
  
  p[0]=p[0]+pos;
  p[1]=p[1]+pos;
  p[2]=p[2]+pos;
  p[3]=p[3]+pos;
  n=(faceNormal(p));
  if(rayIntersectPlane(start,end,p[0],n,&intp))
   {
   if(pointOnPolygon(intp,p,4)) return true;
   }   
 }
 
 return false;
 }
   
 
 


CMesh::~CMesh()
{
}

};
