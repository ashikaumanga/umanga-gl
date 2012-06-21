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
#ifndef UMANGAGLUGL_MD2MESH_H
#define UMANGAGLUGL_MD2MESH_H
#include "ugl_oglsdl.h"
#include "ugl_ctexture.h"
#include "ugl_cmesh.h"
#define NUMVERTEXNORMALS 162
namespace umangagl {

/**
Load and render MD2 models.Addopted from Cone3D tutorials

@author Ashika Umanga Umagiliya
*/
typedef struct _modelHeader 
{ 
  int ident;        // A "magic number" that's used to identify the .md2 file 
  int version;      // The version of the file, always 8 
  int skinwidth;    // Width of the skin(s) in pixels 
  int skinheight;   // Height of the skin(s) in pixels 
  int framesize;    // Size of each frame in bytes 
  int numSkins;     // Number of skins with the model 
  int numXYZ;       // Number of vertices in each frame 
  int numST;        // Number of texture coordinates in each frame. 
  int numTris;      // Number of triangles in each frame 
  int numGLcmds;    // Number of dwords (4 bytes) in the gl command list. 
  int numFrames;    // Number of frames 
  int offsetSkins;  // Bytes from the start to the list of skin names. 
  int offsetST;     // Bytes from the start to the list of texture coordinates 
  int offsetTris;   // Bytes from the start to the list of triangles 
  int offsetFrames; // Bytes from the start to the list of frames 
  int offsetGLcmds; // Bytes from the start to the list of gl commands 
  int offsetEnd;    // Bytes from the start to the end of the file (filesize) 
} md2modelHeader; 

typedef struct _coord 
{ 
  float pt[3];      // XYZ of a point 
  float ln[3];      // XYZ of a the normal for the point 
} md2coord; 
typedef struct _coordonly
{
 float pt[3];
} md2coordonly;

typedef struct _mesh 
{ 
  unsigned short meshIndex[3]; // indices into the array of vertices in each frames 
  unsigned short stIndex[3];   // indices into the array of texture coordinates 
} md2mesh; 

typedef struct _stTexCoord 
{ 
  float s; 
  float t; 
} md2stTexCoord; 

typedef struct _stTexture 
{ 
   short s; 
   short t; 
} md2stTexture; 

typedef struct _modelData 
{ 
  int numPoints;            // Number of points 
  //md2coord *pointList;      // List of points 
  md2coord *currentmorph;   // Current morph points 
  CVector3 *vertexList;      //my modifications (vertex list ,changes when scaled,rotated
  CVector3 *normalList;      //my modifications
  CVector3 *overtexList;    //original vertex list (not change when scaled,rotated...
  int numTriangles;         // Number of triangles 
  int numFrames;            // Number of frames 
  md2mesh *triIndex;        // Triangle Index 
  int numST;                // Number of texture coordinates 
  md2stTexCoord *st;        // List of texture coordinates 
  int texWidth, texHeight;  // Texture width and height 
  char *texture;            // Not used 
  int CurrFrame;            // Current Frames 
  int IntroFrames[2];       // Animation start/stop 
  int GameFrames[2];        // Not used 
  float xscale;             // Not used 
  float yscale;             // Not used 
  float zscale;             // Not used 
  int introzoom;            // Not used 
  bool zoomstop;            // Not used 
  long zoomstoptime;        // Not used 
} md2modelData; 


typedef struct _framePoint 
{ 
  unsigned char v[3];             // Scaled vertices. You'll need to multiply 
                                  // them with scale[x] (md2frame) to make them normal. 
  unsigned char lightNormalIndex; // Index to the array of normals 
} md2framePoint; 

typedef struct _frame 
{ 
  float scale[3];      // Used by the v member in the md2framePoint structure 
  float translate[3];  // Used by the v member in the md2framePoint structure 
  char name[16];       // Name of the frame 
  md2framePoint fp[1]; // An array of numXYZ (from header) md2framePoint structures 
} md2frame; 




class CMD2Mesh :public CMesh
 {
private:
  CTexture modelt,weapont;
  md2modelData *model,*weapon;
  md2coordonly *originalModelPoints;
  md2coordonly *originalWeaponPoints;  
  int isweapon;
  int currentFrame;
  long newtime,frametime,framestarttime;
  float avertexnormals[NUMVERTEXNORMALS][3];
    
public:
    CMD2Mesh();

    ~CMD2Mesh();
       // Load the Model 
  int loadModel(const char *fileName, const char *textureName);
  // Load the Texture 
  int loadWeapon(const char *fileName, const char *textureName); 
  // This is the function that draws the model on screen. You shouldn't have to call it directly 
  int render(float x, float y, float z, int curframe,int nextframe,float pol); 
  // This is the function that draws the weapon on screen. You shouldn't have to call it directly 
  int renderWeapon(float x, float y, float z, int curframe,int nextframe,float pol); 
  // This renders the current frame of the model (as non animated) 
  int renderCurrentFrame(float x,float y,float z); 
  // Set the current frame 
  int setFrame(int frame); 
  // Get the current frame 
  int getFrame(); 
  // Get the number of frames 
  int getLastFrameNum(); 
  // Reset the frame time (you won't need it) 
  int resetTime(); 
  // Set the range of the animation. Check out 
  // http://www.planetquake.com/polycount/resources/quake2/q2frameslist.shtml 
  // for details on frames. Note: you'll have to divide 1 from the numbers in 
  // the last column of the table to make it work. 
  int animation(int startframe, int stopframe); 
  // Animate the model in the range specified with Animation() 
  int animate(float x, float y, float z,float time); 
  // Animate the model from frame1 to frame2 in time. 
  int animate2(float x, float y, float z,float frame1,float frame2,float time); 
  int getNumOfVertices();  
  bool detectRayTraceCollision(CVector3 start,CVector3 end);
 // bool detectBoundingBoxCollision(CVector3 start,CVector3 end);
  void setScale(float x,float y,float z); 
  void setRotation(float x,float y,float z); 
  //void setRotationX(float angle,bool useLocalCoords);
 // void setRotationY(float angle,bool useLocalCoords);
 // void setRotationZ(float angle,bool useLocalCoords);

};

};

#endif
