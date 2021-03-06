#include "ugl_misc.h"

namespace umangagl
{
typedef unsigned char byte;
	CVector3 VectorCross(CVector3 vVector1, CVector3 vVector2)
{
    CVector3 vNormal;    
    vNormal.x = ((vVector1.y * vVector2.z) - (vVector1.z * vVector2.y));
    vNormal.y = ((vVector1.z * vVector2.x) - (vVector1.x * vVector2.z));
    vNormal.z = ((vVector1.x * vVector2.y) - (vVector1.y * vVector2.x));
    return vNormal;                                         
}

float VectorMagnitude(CVector3 vNormal)
{
    return (float)sqrt( (vNormal.x * vNormal.x) + 
                        (vNormal.y * vNormal.y) + 
                        (vNormal.z * vNormal.z) );
}

CVector3 VectorNormalize(CVector3 vVector)
{
    
    float magnitude = VectorMagnitude(vVector);                
    vVector = vVector / magnitude;        
    return vVector;                                        
}
CVector3 VectorSubtract(CVector3 vPoint1, CVector3 vPoint2)
{
	CVector3 vVector;
    vVector = (vPoint1 - vPoint2);
    return vVector;                                     
}

CVector3 VectorTriangleNormal(CVector3 vTriangle[]) 
{                                                      
    CVector3 vVector1 = VectorSubtract(vTriangle[2], vTriangle[0]);
    CVector3 vVector2 = VectorSubtract(vTriangle[1], vTriangle[0]);
    CVector3 vNormal = VectorCross(vVector1, vVector2);
    vNormal = VectorNormalize(vNormal);                    
    return vNormal;                                    
}
/*CVector3 operator+ (CVector3 v, CVector3 u)
{
	CVector3 res;
	res.x = v.x+u.x;
	res.y = v.y+u.y;
	res.z = v.z+u.z;
	return res;
}*/

/*CVector3 operator- (CVector3 v, CVector3 u)
{
	CVector3 res;
	res.x = v.x-u.x;
	res.y = v.y-u.y;
	res.z = v.z-u.z;
	return res;
}
CVector3 operator* (CVector3 v, float r)
{
	CVector3 res;
	res.x = v.x*r;
	res.y = v.y*r;
	res.z = v.z*r;
	return res;
}
 
float operator* (CVector3 v, CVector3 u)	//dot product
{
	return v.x*u.x+v.y*u.y+v.z*u.z;
}*/


/////////// Misc Functions ////
void swap(unsigned char & a, unsigned char & b)
{
    unsigned char temp;
    temp = a;
    a    = b;
    b    = temp;
    return;
}

//find face normal
CVector3 faceNormal(CVector3 pnts[])
{
 CVector3 ret;
 //CVector3 v1=*pnts[1]-*pnts[2];
 //CVector3 v2=*pnts[0]-*pnts[2];
 CVector3 v1=pnts[1]-pnts[2];
 CVector3 v2=pnts[0]-pnts[2];
 ret=v2.crossProduct(v1);
 ret.normalize();
 return ret;
}

CVector3 faceNormalByPoints(float x1,float y1,float z1,float x2,float y2,float z2,float x3,float y3,float z3)
{
 CVector3 p[3]; 
 p[0].setValues(x1,y1,z1);
 p[1].setValues(x2,y2,z2);
 p[2].setValues(x3,y2,z3);
 return faceNormal(p);
 
}
/*CVector3 faceNormal(float x1,float y1,float z1,float x2,float y2,float z2,float x3,float y3,float z3)
{
 CVector3 *p[3];
 p[0]=new CVector3;
 p[1]=new CVector3;
 p[2]=new CVector3;
 p[0]->setValues(x1,y1,z1);
 p[1]->setValues(x2,y2,z2);
 p[2]->setValues(x3,y2,z3);
 return faceNormal(p);
 delete p[0];
 delete p[1];
 delete p[2];

}*/



//function to check whether a given line has intersect a given plane
bool rayIntersectPlane(CVector3 linestart,CVector3 lineend,CVector3 vertex,CVector3 normal,CVector3 *intersection)
{
 CVector3 L1;
 float linelength,dist_from_plane,percentage;
 
 CVector3 direction=lineend-linestart;
 linelength=direction.dotProduct(normal);
 
 if(fabsf(linelength)<0.00001)
   return false;
   
  L1=vertex-linestart;
  dist_from_plane=L1.dotProduct( normal);
  percentage=dist_from_plane/linelength;
  
  if(percentage<0)
     return false;
  else if(percentage>1)
     return false;
     
   intersection->x=linestart.x + direction.x*percentage;
   intersection->y=linestart.y + direction.y*percentage;
   intersection->z=linestart.z + direction.z*percentage;
 
 return true;
   
}

//function to check whether a given point is in given polygon (all the vertices of the polygon are passed )
bool pointOnPolygon(CVector3 point,CVector3 vertices[],int numOfVertices)
{
 CVector3 Lines[numOfVertices];
 float total_angles,result,vlength;
 
 for(int a=0;a<numOfVertices;a++)
 {
  Lines[a].x=point.x-vertices[a].x;
  Lines[a].y=point.y-vertices[a].y;
  Lines[a].z=point.z-vertices[a].z;
  Lines[a].normalize();
 }

 total_angles=0.0;
 
 for(int b=0;b<numOfVertices-1;b++)
 {
  total_angles+=acos((Lines[b].dotProduct(Lines[b+1])));
 }
 total_angles+=acos((Lines[numOfVertices-1].dotProduct(Lines[0])));
 //printf("angle:%f %f\n",total_angles*(180/M_PI),total_angles-6.28);
 if(fabsf(total_angles-6.28)<0.01)
  return true;
 
 return false;
}

void log(const char* text)
{
 fprintf(stdout,"%s\n",text);
}
///Create a BMP texuture in OpenGL
int CreateTexture(unsigned int textureArray[],char *strFileName,int textureID)
{
    SDL_Surface *pBitmap[1];

    if( strFileName == NULL )                           // Return from the function if no file name 
        return 0;

    // We need to load the texture data, so we use a cool function that SDL offers.
    
    pBitmap[0] = SDL_LoadBMP(strFileName);              // Load the bitmap and store the data

    if(pBitmap[0] == NULL)               
    {
        fprintf(stderr," Failed loading %s" , SDL_GetError());
        return 0;
    }

    // Generate a texture with the associative texture ID stored in the array
    glGenTextures(1, &textureArray[textureID]);

    // Bind the texture to the texture arrays index and init the texture
    glBindTexture(GL_TEXTURE_2D, textureArray[textureID]);

    // Rearrange the pixelData 
    
    int width  = pBitmap[0] -> w;
    int height = pBitmap[0] -> h;
    unsigned char * data = (unsigned char *) (pBitmap[0] -> pixels);         // the pixel data

    int BytesPerPixel = pBitmap[0] -> format -> BytesPerPixel;

        for( int i = 0 ; i < (height / 2) ; ++i )
        for( int j = 0 ; j < width * BytesPerPixel; j += BytesPerPixel )
            for(int k = 0; k < BytesPerPixel; ++k)
                swap( data[ (i * width * BytesPerPixel) + j + k], data[ ( (height - i - 1) * width * BytesPerPixel ) + j + k]);
    
    unsigned char *pixels = new unsigned char[width * height * 3];

    int count = 0;
    
    // the following lines extract R,G and B values from any bitmap

    for(int i = 0; i < (width * height); ++i)
    {
        byte r,g,b;                                                // R,G and B that we will put into pImage

        Uint32 pixel_value = 0;                                    // 32 bit unsigned int (as dictated by SDL)
    
        for(int j = BytesPerPixel - 1 ; j >=0; --j)                // for each byte in the pixel (from the right)
        {
            pixel_value = pixel_value << 8;                        // left shift pixel value by 8 bits
            pixel_value = pixel_value | data[ (i * BytesPerPixel) + j ];  // then make the last 8 bits of pixel value  =
        }                                                                 // the byte that we extract from pBitmap's data

        SDL_GetRGB(pixel_value, pBitmap[0] -> format, (Uint8 *)&r, (Uint8 *)&g, (Uint8 *)&b);     

        pixels[count++] = r;          // in our tImage classes we store r first
        pixels[count++] = g;          // then g
        pixels[count++] = b;          // and finally b (for bmps - three channels only)
        pixel_value = 0;                                           
    }

    
    gluBuild2DMipmaps(GL_TEXTURE_2D, 3, pBitmap[0]->w, pBitmap[0]->h, GL_RGB, GL_UNSIGNED_BYTE, pixels);

    // Lastly, we need to tell OpenGL the quality of our texture map.  GL_LINEAR is the smoothest.    
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);    
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR_MIPMAP_NEAREST);
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
    SDL_FreeSurface(pBitmap[0]);         
return 1;
}


}
