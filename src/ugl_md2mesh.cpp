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
#include "ugl_md2mesh.h"
#include <cstdlib>
using namespace std;
namespace umangagl {

CMD2Mesh::CMD2Mesh()
{ 
 float tmp[NUMVERTEXNORMALS][3] = {
{-0.525731f, 0.000000f, 0.850651f},
{-0.442863f, 0.238856f, 0.864188f},
{-0.295242f, 0.000000f, 0.955423f},
{-0.309017f, 0.500000f, 0.809017f},
{-0.162460f, 0.262866f, 0.951056f},
{0.000000f, 0.000000f, 1.000000f},
{0.000000f, 0.850651f, 0.525731f},
{-0.147621f, 0.716567f, 0.681718f},
{0.147621f, 0.716567f, 0.681718f},
{0.000000f, 0.525731f, 0.850651f},
{0.309017f, 0.500000f, 0.809017f},
{0.525731f, 0.000000f, 0.850651f},
{0.295242f, 0.000000f, 0.955423f},
{0.442863f, 0.238856f, 0.864188f},
{0.162460f, 0.262866f, 0.951056f},
{-0.681718f, 0.147621f, 0.716567f},
{-0.809017f, 0.309017f, 0.500000f},
{-0.587785f, 0.425325f, 0.688191f},
{-0.850651f, 0.525731f, 0.000000f},
{-0.864188f, 0.442863f, 0.238856f},
{-0.716567f, 0.681718f, 0.147621f},
{-0.688191f, 0.587785f, 0.425325f},
{-0.500000f, 0.809017f, 0.309017f},
{-0.238856f, 0.864188f, 0.442863f},
{-0.425325f, 0.688191f, 0.587785f},
{-0.716567f, 0.681718f, -0.147621f},
{-0.500000f, 0.809017f, -0.309017f},
{-0.525731f, 0.850651f, 0.000000f},
{0.000000f, 0.850651f, -0.525731f},
{-0.238856f, 0.864188f, -0.442863f},
{0.000000f, 0.955423f, -0.295242f},
{-0.262866f, 0.951056f, -0.162460f},
{0.000000f, 1.000000f, 0.000000f},
{0.000000f, 0.955423f, 0.295242f},
{-0.262866f, 0.951056f, 0.162460f},
{0.238856f, 0.864188f, 0.442863f},
{0.262866f, 0.951056f, 0.162460f},
{0.500000f, 0.809017f, 0.309017f},
{0.238856f, 0.864188f, -0.442863f},
{0.262866f, 0.951056f, -0.162460f},
{0.500000f, 0.809017f, -0.309017f},
{0.850651f, 0.525731f, 0.000000f},
{0.716567f, 0.681718f, 0.147621f},
{0.716567f, 0.681718f, -0.147621f},
{0.525731f, 0.850651f, 0.000000f},
{0.425325f, 0.688191f, 0.587785f},
{0.864188f, 0.442863f, 0.238856f},
{0.688191f, 0.587785f, 0.425325f},
{0.809017f, 0.309017f, 0.500000f},
{0.681718f, 0.147621f, 0.716567f},
{0.587785f, 0.425325f, 0.688191f},
{0.955423f, 0.295242f, 0.000000f},
{1.000000f, 0.000000f, 0.000000f},
{0.951056f, 0.162460f, 0.262866f},
{0.850651f, -0.525731f, 0.000000f},
{0.955423f, -0.295242f, 0.000000f},
{0.864188f, -0.442863f, 0.238856f},
{0.951056f, -0.162460f, 0.262866f},
{0.809017f, -0.309017f, 0.500000f},
{0.681718f, -0.147621f, 0.716567f},
{0.850651f, 0.000000f, 0.525731f},
{0.864188f, 0.442863f, -0.238856f},
{0.809017f, 0.309017f, -0.500000f},
{0.951056f, 0.162460f, -0.262866f},
{0.525731f, 0.000000f, -0.850651f},
{0.681718f, 0.147621f, -0.716567f},
{0.681718f, -0.147621f, -0.716567f},
{0.850651f, 0.000000f, -0.525731f},
{0.809017f, -0.309017f, -0.500000f},
{0.864188f, -0.442863f, -0.238856f},
{0.951056f, -0.162460f, -0.262866f},
{0.147621f, 0.716567f, -0.681718f},
{0.309017f, 0.500000f, -0.809017f},
{0.425325f, 0.688191f, -0.587785f},
{0.442863f, 0.238856f, -0.864188f},
{0.587785f, 0.425325f, -0.688191f},
{0.688191f, 0.587785f, -0.425325f},
{-0.147621f, 0.716567f, -0.681718f},
{-0.309017f, 0.500000f, -0.809017f},
{0.000000f, 0.525731f, -0.850651f},
{-0.525731f, 0.000000f, -0.850651f},
{-0.442863f, 0.238856f, -0.864188f},
{-0.295242f, 0.000000f, -0.955423f},
{-0.162460f, 0.262866f, -0.951056f},
{0.000000f, 0.000000f, -1.000000f},
{0.295242f, 0.000000f, -0.955423f},
{0.162460f, 0.262866f, -0.951056f},
{-0.442863f, -0.238856f, -0.864188f},
{-0.309017f, -0.500000f, -0.809017f},
{-0.162460f, -0.262866f, -0.951056f},
{0.000000f, -0.850651f, -0.525731f},
{-0.147621f, -0.716567f, -0.681718f},
{0.147621f, -0.716567f, -0.681718f},
{0.000000f, -0.525731f, -0.850651f},
{0.309017f, -0.500000f, -0.809017f},
{0.442863f, -0.238856f, -0.864188f},
{0.162460f, -0.262866f, -0.951056f},
{0.238856f, -0.864188f, -0.442863f},
{0.500000f, -0.809017f, -0.309017f},
{0.425325f, -0.688191f, -0.587785f},
{0.716567f, -0.681718f, -0.147621f},
{0.688191f, -0.587785f, -0.425325f},
{0.587785f, -0.425325f, -0.688191f},
{0.000000f, -0.955423f, -0.295242f},
{0.000000f, -1.000000f, 0.000000f},
{0.262866f, -0.951056f, -0.162460f},
{0.000000f, -0.850651f, 0.525731f},
{0.000000f, -0.955423f, 0.295242f},
{0.238856f, -0.864188f, 0.442863f},
{0.262866f, -0.951056f, 0.162460f},
{0.500000f, -0.809017f, 0.309017f},
{0.716567f, -0.681718f, 0.147621f},
{0.525731f, -0.850651f, 0.000000f},
{-0.238856f, -0.864188f, -0.442863f},
{-0.500000f, -0.809017f, -0.309017f},
{-0.262866f, -0.951056f, -0.162460f},
{-0.850651f, -0.525731f, 0.000000f},
{-0.716567f, -0.681718f, -0.147621f},
{-0.716567f, -0.681718f, 0.147621f},
{-0.525731f, -0.850651f, 0.000000f},
{-0.500000f, -0.809017f, 0.309017f},
{-0.238856f, -0.864188f, 0.442863f},
{-0.262866f, -0.951056f, 0.162460f},
{-0.864188f, -0.442863f, 0.238856f},
{-0.809017f, -0.309017f, 0.500000f},
{-0.688191f, -0.587785f, 0.425325f},
{-0.681718f, -0.147621f, 0.716567f},
{-0.442863f, -0.238856f, 0.864188f},
{-0.587785f, -0.425325f, 0.688191f},
{-0.309017f, -0.500000f, 0.809017f},
{-0.147621f, -0.716567f, 0.681718f},
{-0.425325f, -0.688191f, 0.587785f},
{-0.162460f, -0.262866f, 0.951056f},
{0.442863f, -0.238856f, 0.864188f},
{0.162460f, -0.262866f, 0.951056f},
{0.309017f, -0.500000f, 0.809017f},
{0.147621f, -0.716567f, 0.681718f},
{0.000000f, -0.525731f, 0.850651f},
{0.425325f, -0.688191f, 0.587785f},
{0.587785f, -0.425325f, 0.688191f},
{0.688191f, -0.587785f, 0.425325f},
{-0.955423f, 0.295242f, 0.000000f},
{-0.951056f, 0.162460f, 0.262866f},
{-1.000000f, 0.000000f, 0.000000f},
{-0.850651f, 0.000000f, 0.525731f},
{-0.955423f, -0.295242f, 0.000000f},
{-0.951056f, -0.162460f, 0.262866f},
{-0.864188f, 0.442863f, -0.238856f},
{-0.951056f, 0.162460f, -0.262866f},
{-0.809017f, 0.309017f, -0.500000f},
{-0.864188f, -0.442863f, -0.238856f},
{-0.951056f, -0.162460f, -0.262866f},
{-0.809017f, -0.309017f, -0.500000f},
{-0.681718f, 0.147621f, -0.716567f},
{-0.681718f, -0.147621f, -0.716567f},
{-0.850651f, 0.000000f, -0.525731f},
{-0.688191f, 0.587785f, -0.425325f},
{-0.587785f, 0.425325f, -0.688191f},
{-0.425325f, 0.688191f, -0.587785f},
{-0.425325f, -0.688191f, -0.587785f},
{-0.587785f, -0.425325f, -0.688191f},
{-0.688191f, -0.587785f, -0.425325f},
}; 

for(int i=0;i<NUMVERTEXNORMALS;i++)
 for(int j=0;j<3;j++)
   avertexnormals[i][j]=tmp[i][j];
   
  originalModelPoints=NULL;
  originalWeaponPoints=NULL;  

}




CMD2Mesh::~CMD2Mesh()
{
 delete model;
 model=NULL;
 delete weapon;
 weapon=NULL;
 delete originalModelPoints;
 originalModelPoints=NULL;
 delete originalWeaponPoints; 
 originalWeaponPoints=NULL; 
}

// Reset the time back to 0
int CMD2Mesh::resetTime()
{
  frametime=0;
  framestarttime=0;
  return 1;
}

// The main animation.
int CMD2Mesh::animate(float x, float y, float z,float time)
{
  glPushMatrix();

  // Calculate how much time has passed
  newtime = SDL_GetTicks();
  if(framestarttime==0) framestarttime=newtime;
  frametime=newtime-framestarttime;
  float tim=frametime/time;

  // and Display the model
  if(getFrame()+1>model->IntroFrames[1])
  {
    render(x,y,z,getFrame(),model->IntroFrames[0],tim);
    if(isweapon)
      renderWeapon(x,y,z,getFrame(),model->IntroFrames[0],tim);
  } else {
    render(x,y,z,getFrame(),getFrame()+1,tim);
    if(isweapon)
      renderWeapon(x,y,z,getFrame(),getFrame()+1,tim);
  }

  // If the animation has reached it's end start at the beginning and return 2
  if((frametime/time)>=1)
  {
    framestarttime=newtime;
    setFrame(getFrame()+1);
    if(getFrame() > model->IntroFrames[1])
      setFrame(model->IntroFrames[0]);
    return 2;
  }

  // else return 1
  return 1;
}
 

// Animate from frame1 to frame2
int CMD2Mesh::animate2(float x, float y, float z,float frame1,
                                       float frame2,float time)
{
  glPushMatrix();

  newtime = SDL_GetTicks();
  frametime=newtime-framestarttime;
  render(x,y,z,(int)frame1,(int)frame2,frametime/time);
  if(isweapon)
    renderWeapon(x,y,z,(int)frame1,(int)frame2,frametime/time);

  if((frametime/time)>=1)
  {
    framestarttime=newtime;
    return 2;
  }
  return 1;
}

// Set the animation range
int CMD2Mesh::animation(int startframe, int stopframe)
{
  model->IntroFrames[0] = startframe;
  model->IntroFrames[1] = stopframe;
  return 1;
}

// Set the current frame
int CMD2Mesh::setFrame(int frame)
{
  model->CurrFrame = frame;
  return 1;
}

// Get the current frame
int CMD2Mesh::getFrame()
{
  return model->CurrFrame;
}

// Get the number of the last frame
int CMD2Mesh::getLastFrameNum()
{
  return model->numFrames-1;
}

// Render the current frame (no animation)
// (Useful when you have some still statues
//  in the wall that come to life.)
int CMD2Mesh::renderCurrentFrame(float x,float y,float z)
{
  render(x,y,z,getFrame(),getFrame(),1);
  if(isweapon)
    renderWeapon(x,y,z,getFrame(),getFrame(),1);

  return 1;
}


//draw bounding box

// Render the weapon
int CMD2Mesh::renderWeapon(float x, float y, float z, int curframe,
                                            int nextframe,float pol)
{
  float  x1, y1, z1, x2, y2, z2;
  float nx1,ny1,nz1,nx2,ny2,nz2;
  if(pol>1) pol=1;

  // Get the points to the current and the next frame.
 
  CVector3 *vertexListPtr,*vertexListPtr2;
  CVector3 *normalListPtr,*normalListPtr2;
  
  vertexListPtr=&weapon->vertexList[ weapon->numPoints * curframe];
  vertexListPtr2=&weapon->vertexList[ weapon->numPoints * nextframe];
  
  glPushMatrix();
  
  weapont.setActive();
    glTranslatef(getPosition().x,getPosition().y,getPosition().z);
  
  glBegin(GL_TRIANGLES);

  for(int i=0; i<weapon->numTriangles; i++ )
  {
    glTexCoord2f(weapon->st[ weapon->triIndex[i].stIndex[0] ].s, weapon->st[ weapon->triIndex[i].stIndex[0] ].t);
    // Get the points into shorter-named variables.
    x1 = vertexListPtr[ weapon->triIndex[i].meshIndex[0] ].x;
    y1 = vertexListPtr[ weapon->triIndex[i].meshIndex[0] ].y;
    z1 = vertexListPtr[ weapon->triIndex[i].meshIndex[0] ].z;
    x2 = vertexListPtr2[ weapon->triIndex[i].meshIndex[0] ].x;
    y2 = vertexListPtr2[ weapon->triIndex[i].meshIndex[0] ].y;
    z2 = vertexListPtr2[ weapon->triIndex[i].meshIndex[0] ].z;
    
    nx1 = normalListPtr[ weapon->triIndex[i].meshIndex[0] ].x;
    ny1 = normalListPtr[ weapon->triIndex[i].meshIndex[0] ].y;
    nz1 = normalListPtr[ weapon->triIndex[i].meshIndex[0] ].z;
    nx2 = normalListPtr2[ weapon->triIndex[i].meshIndex[0] ].x;
    ny2 = normalListPtr2[ weapon->triIndex[i].meshIndex[0] ].y;
    nz2 = normalListPtr2[ weapon->triIndex[i].meshIndex[0] ].z;

    // Get a normal between the current frame and the next frame.
    // Same with the points.
    glNormal3f( x+nx1 + pol * (nx2 - nx1), y+ny1 + pol * (ny2 - ny1), z+nz1 + pol * (nz2 - nz1) );
    glVertex3f( x+x1 + pol * (x2 - x1), y+y1 + pol * (y2 - y1), z+z1 + pol * (z2 - z1) );
 

    glTexCoord2f( weapon->st[ weapon->triIndex[i].stIndex[1] ].s, weapon->st[ weapon->triIndex[i].stIndex[1] ].t );
    x1 = vertexListPtr[ weapon->triIndex[i].meshIndex[1] ].x;
    y1 = vertexListPtr[ weapon->triIndex[i].meshIndex[1] ].y;
    z1 = vertexListPtr[ weapon->triIndex[i].meshIndex[1] ].z;
    x2 = vertexListPtr2[ weapon->triIndex[i].meshIndex[1] ].x;
    y2 = vertexListPtr2[ weapon->triIndex[i].meshIndex[1] ].y;
    z2 = vertexListPtr2[ weapon->triIndex[i].meshIndex[1] ].z;
    
    nx1 = normalListPtr[ weapon->triIndex[i].meshIndex[1] ].x;
    ny1 = normalListPtr[ weapon->triIndex[i].meshIndex[1] ].y;
    nz1 = normalListPtr[ weapon->triIndex[i].meshIndex[1] ].z;
    nx2 = normalListPtr2[ weapon->triIndex[i].meshIndex[1] ].x;
    ny2 = normalListPtr2[ weapon->triIndex[i].meshIndex[1] ].y;
    nz2 = normalListPtr2[ weapon->triIndex[i].meshIndex[1] ].z;
    glNormal3f( x+nx1 + pol * (nx2 - nx1), y+ny1 + pol * (ny2 - ny1), z+nz1 + pol * (nz2 - nz1) );
    glVertex3f( x+x1 + pol * (x2 - x1), y+y1 + pol * (y2 - y1), z+z1 + pol * (z2 - z1) );
 

    glTexCoord2f( weapon->st[ weapon->triIndex[i].stIndex[2] ].s, weapon->st[ weapon->triIndex[i].stIndex[2] ].t );
    x1 = vertexListPtr[ weapon->triIndex[i].meshIndex[2] ].x;
    y1 = vertexListPtr[ weapon->triIndex[i].meshIndex[2] ].y;
    z1 = vertexListPtr[ weapon->triIndex[i].meshIndex[2] ].z;
    x2 = vertexListPtr2[ weapon->triIndex[i].meshIndex[2] ].x;
    y2 = vertexListPtr2[ weapon->triIndex[i].meshIndex[2] ].y;
    z2 = vertexListPtr2[ weapon->triIndex[i].meshIndex[2] ].z;
    
    nx1 = normalListPtr[ weapon->triIndex[i].meshIndex[2] ].x;
    ny1 = normalListPtr[ weapon->triIndex[i].meshIndex[2] ].y;
    nz1 = normalListPtr[ weapon->triIndex[i].meshIndex[2] ].z;
    nx2 = normalListPtr2[ weapon->triIndex[i].meshIndex[2] ].x;
    ny2 = normalListPtr2[ weapon->triIndex[i].meshIndex[2] ].y;
    nz2 = normalListPtr2[ weapon->triIndex[i].meshIndex[2] ].z;
    
    glNormal3f( x+nx1 + pol * (nx2 - nx1), y+ny1 + pol * (ny2 - ny1), z+nz1 + pol * (nz2 - nz1) );
    glVertex3f( x+x1 + pol * (x2 - x1), y+y1 + pol * (y2 - y1), z+z1 + pol * (z2 - z1) );
  }

  glEnd();

 glPopMatrix();
  
  
  return 1;
}
 

int CMD2Mesh::render(float x, float y, float z, int curframe,int nextframe,float pol)
{
  float  x1, y1, z1, x2, y2, z2;
  float nx1,ny1,nz1,nx2,ny2,nz2;
  currentFrame=curframe;
  if(pol>1) pol=1;
  
  // Get the points to the current and the next frame.

  CVector3* vertexListPtr=&model->vertexList[ model->numPoints * curframe];
  CVector3* vertexListPtr2=&model->vertexList[ model->numPoints * nextframe];
  CVector3* normalListPtr=&model->normalList[ model->numPoints * curframe];
  CVector3* normalListPtr2=&model->normalList[ model->numPoints * nextframe];
  // Bind the texture and begin drawing triangles
  //glBindTexture(GL_TEXTURE_2D, modelt.texID);
  modelt.enableOpenGLTexturing();
  modelt.setActive();
  
  glPushMatrix();
   
   glTranslatef(getPosition().x,getPosition().y,getPosition().z);
   //this->drawBoundingBox();
   //glScalef(getScale().x,getScale().y,getScale().y); 
   //glRotatef(getRotation().x,1,0,0);
   //glRotatef(getRotation().y,0,1,0);
   //glRotatef(getRotation().z,0,0,1);
   
   
  glBegin(GL_TRIANGLES);

  for(int i=0; i<model->numTriangles; i++ )
  {
    glTexCoord2f(model->st[ model->triIndex[i].stIndex[0] ].s, model->st[ model->triIndex[i].stIndex[0] ].t);
    // Get the points into shorter-named variables.
    x1 = vertexListPtr[ model->triIndex[i].meshIndex[0] ].x;
    y1 = vertexListPtr[ model->triIndex[i].meshIndex[0] ].y;
    z1 = vertexListPtr[ model->triIndex[i].meshIndex[0] ].z;
    x2 = vertexListPtr2[ model->triIndex[i].meshIndex[0] ].x;
    y2 = vertexListPtr2[ model->triIndex[i].meshIndex[0] ].y;
    z2 = vertexListPtr2[ model->triIndex[i].meshIndex[0] ].z;
    
    nx1 = normalListPtr[ model->triIndex[i].meshIndex[0] ].x;
    ny1 = normalListPtr[ model->triIndex[i].meshIndex[0] ].y;
    nz1 = normalListPtr[ model->triIndex[i].meshIndex[0] ].z;
    nx2 = normalListPtr2[ model->triIndex[i].meshIndex[0] ].x;
    ny2 = normalListPtr2[ model->triIndex[i].meshIndex[0] ].y;
    nz2 = normalListPtr2[ model->triIndex[i].meshIndex[0] ].z;
    // Get a normal between the current frame and the next frame.
    // Same with the points.
    glNormal3f( x+nx1 + pol * (nx2 - nx1), y+ny1 + pol * (ny2 - ny1), z+nz1 + pol * (nz2 - nz1) );
    glVertex3f( x+x1 + pol * (x2 - x1), y+y1 + pol * (y2 - y1), z+z1 + pol * (z2 - z1) );

    glTexCoord2f( model->st[ model->triIndex[i].stIndex[1] ].s, model->st[ model->triIndex[i].stIndex[1] ].t );
    x1 = vertexListPtr[ model->triIndex[i].meshIndex[1] ].x;
    y1 = vertexListPtr[ model->triIndex[i].meshIndex[1] ].y;
    z1 = vertexListPtr[ model->triIndex[i].meshIndex[1] ].z;
    x2 = vertexListPtr2[ model->triIndex[i].meshIndex[1] ].x;
    y2 = vertexListPtr2[ model->triIndex[i].meshIndex[1] ].y;
    z2 = vertexListPtr2[ model->triIndex[i].meshIndex[1] ].z;
    
    nx1 = normalListPtr[ model->triIndex[i].meshIndex[1] ].x;
    ny1 = normalListPtr[ model->triIndex[i].meshIndex[1] ].y;
    nz1 = normalListPtr[ model->triIndex[i].meshIndex[1] ].z;
    nx2 = normalListPtr2[ model->triIndex[i].meshIndex[1] ].x;
    ny2 = normalListPtr2[ model->triIndex[i].meshIndex[1] ].y;
    nz2 = normalListPtr2[ model->triIndex[i].meshIndex[1] ].z;
    glNormal3f( x+nx1 + pol * (nx2 - nx1), y+ny1 + pol * (ny2 - ny1), z+nz1 + pol * (nz2 - nz1) );
    glVertex3f( x+x1 + pol * (x2 - x1), y+y1 + pol * (y2 - y1), z+z1 + pol * (z2 - z1) );
 

    glTexCoord2f( model->st[ model->triIndex[i].stIndex[2] ].s, model->st[ model->triIndex[i].stIndex[2] ].t );
    
     x1 = vertexListPtr[ model->triIndex[i].meshIndex[2] ].x;
    y1 = vertexListPtr[ model->triIndex[i].meshIndex[2] ].y;
    z1 = vertexListPtr[ model->triIndex[i].meshIndex[2] ].z;
    x2 = vertexListPtr2[ model->triIndex[i].meshIndex[2] ].x;
    y2 = vertexListPtr2[ model->triIndex[i].meshIndex[2] ].y;
    z2 = vertexListPtr2[ model->triIndex[i].meshIndex[2] ].z;
    
    nx1 = normalListPtr[ model->triIndex[i].meshIndex[2] ].x;
    ny1 = normalListPtr[ model->triIndex[i].meshIndex[2] ].y;
    nz1 = normalListPtr[ model->triIndex[i].meshIndex[2] ].z;
    nx2 = normalListPtr2[ model->triIndex[i].meshIndex[2] ].x;
    ny2 = normalListPtr2[ model->triIndex[i].meshIndex[2] ].y;
    nz2 = normalListPtr2[ model->triIndex[i].meshIndex[2] ].z;
    
    glNormal3f( x+nx1 + pol * (nx2 - nx1), y+ny1 + pol * (ny2 - ny1), z+nz1 + pol * (nz2 - nz1) );
    glVertex3f( x+x1 + pol * (x2 - x1), y+y1 + pol * (y2 - y1), z+z1 + pol * (z2 - z1) );

  }

  glEnd();
  
 glPopMatrix();
  return 1;
}
 

// Load the model
int CMD2Mesh::loadModel( const char *fileName, const char *textureName)
{
  FILE *hFile = fopen( fileName, "rb" );

  /* check the file open command */
  if( hFile != NULL )
  {
    int fileLen;
    char *buffer;
    md2modelHeader *mdh;
    md2frame *frm;
    //md2coord *pointList, *pointListPtr;
    CVector3 *vertexList,*vertexListPtr;
    CVector3 *normalList,*normalListPtr;
    CVector3 *overtexList,*overtexListPtr;
    
    md2coordonly *oriPointPtr;
    md2mesh *triIndex, *bufIndexPtr;
    md2stTexCoord *st;
    md2stTexture *stPtr;
    int i, j;

    /* find length of file */
    fseek( hFile, 0, SEEK_END );
    fileLen = ftell( hFile );
    fseek( hFile, 0, SEEK_SET );

    /* read in file */
    buffer = (char *)malloc( fileLen+1 );
    fread( buffer, sizeof( char ), fileLen, hFile );

    /* get pointer to file header */
    mdh = (md2modelHeader *)buffer;

    /* construct the model data structure */
    model = (md2modelData *)malloc( sizeof( md2modelData ));

    /* create a pointlist */
   // pointList = (md2coord *)malloc( sizeof( md2coord ) * mdh->numXYZ * mdh->numFrames );
    //to store original values;
    originalModelPoints=(md2coordonly*)malloc( sizeof( md2coordonly) * mdh->numXYZ * mdh->numFrames );
    
    vertexList =(CVector3 *)malloc(sizeof(CVector3) * mdh->numXYZ * mdh->numFrames );
    overtexList=(CVector3 *)malloc(sizeof(CVector3) * mdh->numXYZ * mdh->numFrames );
    normalList =(CVector3 *)malloc(sizeof(CVector3) * mdh->numXYZ * mdh->numFrames );
    
   //originalWeaponPoints=NULL; 
   // model->pointList = pointList;
    
    model->numPoints = mdh->numXYZ;
    model->numFrames = mdh->numFrames;
    //
    model->vertexList=vertexList;
    model->normalList=normalList;
    model->overtexList=overtexList;
    //
    model->currentmorph = (md2coord *)malloc( sizeof( md2coord ) * mdh->numXYZ);

    /* loop for number of frames in file */
    CVector3 boundMin(100000.0,10000.0,10000.0);
    CVector3 boundMax(-100000.0,-10000.0,-10000.0);
    for( j=0; j<mdh->numFrames; j++ )
    {
      /* offset to points in frame */
      frm = (md2frame *)&buffer[ mdh->offsetFrames + mdh->framesize * j ];
      //pointListPtr = (md2coord *)&pointList[ mdh->numXYZ * j ];
      
      
      vertexListPtr=(CVector3*)&vertexList[mdh->numXYZ*j];
      overtexListPtr=(CVector3*)&overtexList[mdh->numXYZ*j];
      normalListPtr=(CVector3*)&normalList[mdh->numXYZ*j];
      
      
      for( i=0; i<mdh->numXYZ; i++ )
      {
        vertexListPtr[i].x = frm->scale[0] * frm->fp[i].v[0] + frm->translate[0];  //new
        vertexListPtr[i].z = frm->scale[1] * frm->fp[i].v[1] + frm->translate[1];
        vertexListPtr[i].y = frm->scale[2] * frm->fp[i].v[2] + frm->translate[2];
	
	normalListPtr[i].x = avertexnormals[frm->fp[i].lightNormalIndex][0];  //new
        normalListPtr[i].y = avertexnormals[frm->fp[i].lightNormalIndex][1];
        normalListPtr[i].z = avertexnormals[frm->fp[i].lightNormalIndex][2];
	
	
        vertexListPtr[i]=vertexListPtr[i]/64; //new
	
	overtexListPtr[i]=vertexListPtr[i]; //new
	
	
	if (j>40 && j<46)
	 {
	 if(boundMin.x> vertexListPtr[i].x ) boundMin.x= vertexListPtr[i].x;
	 if(boundMax.x< vertexListPtr[i].x ) boundMax.x= vertexListPtr[i].x;
	
	 if(boundMin.y> vertexListPtr[i].y ) boundMin.y= vertexListPtr[i].y;
	 if(boundMax.y< vertexListPtr[i].y ) boundMax.y= vertexListPtr[i].y;
	
	 if(boundMin.z> vertexListPtr[i].z) boundMin.z= vertexListPtr[i].z;
	 if(boundMax.z< vertexListPtr[i].z) boundMax.z= vertexListPtr[i].z;
	}
      }
    }
///
  setBoundryMinMax(boundMin,boundMax);
  

    do {
      /* see if there is a texture associated with the file */
    //  modelt.width = 1;
    //  modelt.height = 1;
      if (modelt.loadPCXTexture((char*)textureName)) //modelt.LoadPCX((char *)textureName))
      {
        /* create the texture list */
        st = (md2stTexCoord *)malloc( sizeof( md2stTexCoord ) * mdh->numST );
        model->numST = mdh->numST;
        model->st = st;

        stPtr = (md2stTexture *)&buffer[mdh->offsetST];
        for( i=0; i<mdh->numST; i++ )
        {
          st[i].s = (float)stPtr[i].s / (float)modelt.getWidth();
          st[i].t = (float)stPtr[i].t / (float)modelt.getWidth();
        }

        model->zoomstop = false;
      }
    } while( 0 );                      /* only do once */

    /* create a mesh list */
    triIndex = (md2mesh *)malloc( sizeof( md2mesh ) * mdh->numTris );
    model->numTriangles = mdh->numTris;
    model->triIndex = triIndex;

    /* point to indexes in buffers */
    bufIndexPtr = (md2mesh *)&buffer[mdh->offsetTris];

    for( i=0; i<mdh->numTris; i++ )
    {
      triIndex[i].meshIndex[0] = bufIndexPtr[i].meshIndex[0];
      triIndex[i].meshIndex[1] = bufIndexPtr[i].meshIndex[1];
      triIndex[i].meshIndex[2] = bufIndexPtr[i].meshIndex[2];
      triIndex[i].stIndex[0] = bufIndexPtr[i].stIndex[0];
      triIndex[i].stIndex[1] = bufIndexPtr[i].stIndex[1];
      triIndex[i].stIndex[2] = bufIndexPtr[i].stIndex[2];
    }

    /* cleanup */
    free( buffer );
   
    fprintf(stdout,"model: %s | vertices:%d\n",fileName,model->numPoints);
    return 1;
  }
  else return 0;
}

// Load the weapon
int CMD2Mesh::loadWeapon( const char *fileName, const char *textureName)
{
  FILE *hFile = fopen( fileName, "rb" );

  /* check the file open command */
  if( hFile != NULL )
  {
    int fileLen;
    char *buffer;
    md2modelHeader *mdh;
    md2frame *frm;
    
    CVector3 *vertexList,*vertexListPtr;
    CVector3 *normalList,*normalListPtr;
    CVector3 *overtexList,*overtexListPtr;    
    md2mesh *triIndex, *bufIndexPtr;
    md2stTexCoord *st;
    md2stTexture *stPtr;
    int i, j;
    /* find length of file */
    fseek( hFile, 0, SEEK_END );
    fileLen = ftell( hFile );
    fseek( hFile, 0, SEEK_SET );

    /* read in file */
    buffer = (char *)malloc( fileLen+1 );
    fread( buffer, sizeof( char ), fileLen, hFile );

    /* get pointer to file header */
    mdh = (md2modelHeader *)buffer;

    /* construct the model data structure */
    weapon = (md2modelData *)malloc( sizeof( md2modelData ));

    /* create a pointlist */
    //pointList = (md2coord *)malloc( sizeof( md2coord ) * mdh->numXYZ * mdh->numFrames );
    vertexList=(CVector3 *)malloc( sizeof( CVector3 ) * mdh->numXYZ * mdh->numFrames );
    normalList=(CVector3 *)malloc( sizeof( CVector3 ) * mdh->numXYZ * mdh->numFrames );
    overtexList=(CVector3 *)malloc( sizeof( CVector3 ) * mdh->numXYZ * mdh->numFrames );
    
    weapon->vertexList=vertexList;
    weapon->normalList=normalList;
    weapon->overtexList=overtexList;
    
    weapon->numPoints = mdh->numXYZ;
    weapon->numFrames = mdh->numFrames;

    weapon->currentmorph = (md2coord *)malloc( sizeof( md2coord ) * mdh->numXYZ);

    /* loop for number of frames in file */
    for( j=0; j<mdh->numFrames; j++ )
    {
      /* offset to points in frame */
      frm = (md2frame *)&buffer[ mdh->offsetFrames + mdh->framesize * j ];
      //pointListPtr =(md2coord *)&pointList[ mdh->numXYZ * j ];
      
      overtexListPtr=(CVector3 *)&vertexList[ mdh->numXYZ * j ];
      vertexListPtr=(CVector3 *)&vertexList[ mdh->numXYZ * j ];
      normalListPtr=(CVector3 *)&vertexList[ mdh->numXYZ * j ];
      
      for( i=0; i<mdh->numXYZ; i++ )
      {
        //pointListPtr[i].pt[0] = frm->scale[0] * frm->fp[i].v[0] + frm->translate[0];
        //pointListPtr[i].pt[2] = frm->scale[1] * frm->fp[i].v[1] + frm->translate[1];
        //pointListPtr[i].pt[1] = frm->scale[2] * frm->fp[i].v[2] + frm->translate[2];

        //pointListPtr[i].pt[0] /= 64;
        //pointListPtr[i].pt[1] /= 64;
        //pointListPtr[i].pt[2] /= 64;
	//if (bo)
      }
    }

    do {
      /* see if there is a texture associated with the file */
     // weapont.width = 1;
     // weapont.height = 1;
      if (weapont.loadPCXTexture((char*)textureName))//.LoadPCX((char *)textureName))
      {
        /* create the texture list */
        st = (md2stTexCoord *)malloc( sizeof( md2stTexCoord ) * mdh->numST );
        weapon->numST = mdh->numST;
        weapon->st = st;

        stPtr = (md2stTexture *)&buffer[mdh->offsetST];
        for( i=0; i<mdh->numST; i++ )
        {
          st[i].s = (float)stPtr[i].s / (float)weapont.getWidth();
          st[i].t = (float)stPtr[i].t / (float)weapont.getWidth();
        }

        weapon->zoomstop = false;
      }
    } while( 0 );                      /* only do once */

    /* create a mesh list */
    triIndex = (md2mesh *)malloc( sizeof( md2mesh ) * mdh->numTris );
    weapon->numTriangles = mdh->numTris;
    weapon->triIndex = triIndex;

    /* point to indexes in buffers */
    bufIndexPtr = (md2mesh *)&buffer[mdh->offsetTris];

    for( i=0; i<mdh->numTris; i++ )
    {
      triIndex[i].meshIndex[0] = bufIndexPtr[i].meshIndex[0];
      triIndex[i].meshIndex[1] = bufIndexPtr[i].meshIndex[1];
      triIndex[i].meshIndex[2] = bufIndexPtr[i].meshIndex[2];
      triIndex[i].stIndex[0] = bufIndexPtr[i].stIndex[0];
      triIndex[i].stIndex[1] = bufIndexPtr[i].stIndex[1];
      triIndex[i].stIndex[2] = bufIndexPtr[i].stIndex[2];
    }

    /* cleanup */
    free( buffer );
   
  }
  isweapon=1;
  return 1;
} 

int CMD2Mesh::getNumOfVertices()
{
 return model->numPoints;
}

bool CMD2Mesh::detectRayTraceCollision(CVector3 start,CVector3 end)
{
  float  x,y,z;
   
  // Get the points to the current and the next frame.
  CVector3 *vertexListPtr;
  vertexListPtr = &model->vertexList[ model->numPoints * currentFrame];
  CVector3 pnts[3];
  //for(int j=0;j<3;j++)
  //  pnts[j]=new CVector3();
  CVector3 pos=getPosition();  
  CVector3 intp;
  for(int i=0; i<model->numTriangles; i++ )
  {
    
    for(int k=0;k<3;k++)
    {
      x = vertexListPtr[ model->triIndex[i].meshIndex[k] ].x;
      y = vertexListPtr[ model->triIndex[i].meshIndex[k] ].y;
      z = vertexListPtr[ model->triIndex[i].meshIndex[k] ].z;
      pnts[k].setValues(x+pos.x,y+pos.y,z+pos.z);
      
    }
    //calculate the face normal for current triangle
   
    
    CVector3 n=faceNormal(pnts);
    if(rayIntersectPlane(start,end,pnts[0],n,&intp))
     {
      if (pointOnPolygon(intp,pnts,3)) 
      {
       
       return true;
      }
     // return true;
    }
  }
  
  return false;
}
void CMD2Mesh::setScale(float x,float y,float z)
{
  CVector3 *vertexListPtr=&model->vertexList[0];
  CVector3 *overtexListPtr=&model->overtexList[0];
    
  //  for(int k=0;k<model->numPoints*model->numFrames;k++)
  //  {
       
 //      vertexListPtr[k].x=overtexListPtr[k].x*x;
 //      vertexListPtr[k].y=overtexListPtr[k].y*y;
 //      vertexListPtr[k].z=overtexListPtr[k].z*z;
      
      
 //   }
 
 CMesh::setScale(x,y,z);
}



};
