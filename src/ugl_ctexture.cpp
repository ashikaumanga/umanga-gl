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
#include "ugl_ctexture.h"
#include "ugl_misc.h"
namespace umangagl {

/*typedef struct tagBITMAPFILEHEADER {
        WORD    bfType;
        DWORD   bfSize;
        WORD    bfReserved1;
        WORD    bfReserved2;
        DWORD   bfOffBits;
} BITMAPFILEHEADER

typedef struct tagBITMAPINFOHEADER{
        DWORD      biSize;
        LONG       biWidth;
        LONG       biHeight;
        WORD       biPlanes;
        WORD       biBitCount;
        DWORD      biCompression;
        DWORD      biSizeImage;
        LONG       biXPelsPerMeter;
        LONG       biYPelsPerMeter;
        DWORD      biClrUsed;
        DWORD      biClrImportant;
} BITMAPINFOHEADER
*/




CTexture::CTexture()
{
 pixels=NULL;
 strncpy(name,"noname",8);
}
CTexture::CTexture(const char* txtName)
{
 CTexture();
 strncpy(name,txtName,8);
 }
bool CTexture::loadPCXTexture(char *strFileName)
{
  FILE *hTexFile = fopen( strFileName, "rb" ); 
  if( hTexFile != NULL ) 
  { 
    int imgWidth, imgHeight, texFileLen, imgBufferPtr, i; 
    pcxHeader *pcxPtr; 
    unsigned char *imgBuffer, *texBuffer, *pcxBufferPtr, *paletteBuffer; 


    /* find length of file */ 
    fseek( hTexFile, 0, SEEK_END ); 
    texFileLen = ftell( hTexFile ); 
    fseek( hTexFile, 0, SEEK_SET ); 


    /* read in file */ 
    texBuffer = (unsigned char *)malloc( texFileLen+1 ); 
    fread( texBuffer, sizeof( char ), texFileLen, hTexFile ); 


    /* get the image dimensions */ 
    pcxPtr = (pcxHeader *)texBuffer; 
    imgWidth = pcxPtr->size[0] - pcxPtr->offset[0] + 1; 
    imgHeight = pcxPtr->size[1] - pcxPtr->offset[1] + 1; 
    
    
     /* image starts at 128 from the beginning of the buffer */ 
    imgBuffer = (unsigned char *)malloc( imgWidth * imgHeight ); 
    imgBufferPtr = 0; 
    pcxBufferPtr = &texBuffer[128]; 


    /* decode the pcx image */ 
    while( imgBufferPtr < (imgWidth * imgHeight) ) 
    { 
      if( *pcxBufferPtr > 0xbf ) 
      { 
        int repeat = *pcxBufferPtr++ & 0x3f; 
        for( i=0; i<repeat; i++ ) 
        { 
          imgBuffer[imgBufferPtr++] = *pcxBufferPtr; 
        } 
      } else { 
        imgBuffer[imgBufferPtr++] = *pcxBufferPtr; 
      } 
      pcxBufferPtr++; 
    } 


    /* read in the image palette */ 
    paletteBuffer = (unsigned char *)malloc( 768 ); 
    for( i=0; i<768; i++ ) 
      paletteBuffer[i] = texBuffer[ texFileLen-768+i ]; 


    width=imgWidth; 
    height=imgHeight; 


    /* now create the OpenGL texture */ 
    { 
      int i, j; 
      pixels = (unsigned char *)malloc( width * height * 3 ); 
      for (j = 0; j < imgHeight; j++) 
      { 
        for (i = 0; i < imgWidth; i++) 
        { 
          pixels[3*(j * width + i)+0] 
            = paletteBuffer[ 3*imgBuffer[j*imgWidth+i]+0 ]; 
          pixels[3*(j * width + i)+1] 
            = paletteBuffer[ 3*imgBuffer[j*imgWidth+i]+1 ]; 
          pixels[3*(j * width + i)+2] 
            = paletteBuffer[ 3*imgBuffer[j*imgWidth+i]+2 ]; 
        } 
      } 
    } 
    /* cleanup */ 
    free( paletteBuffer ); 
    free( imgBuffer ); 
    glGenTextures(1, &textureID); 
    glBindTexture(GL_TEXTURE_2D, textureID); 
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR ); 
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR ); 
    glTexImage2D(GL_TEXTURE_2D,0,3,width,height,0,GL_RGB, 
    GL_UNSIGNED_BYTE,pixels); 
    //bpp=24; 



  } else { 
    /* skip the texture setup functions */ 
    return false; 
  } 


  return true; 
 
 
}
bool CTexture::loadBMPTexture(char *strFileName)
{
  SDL_Surface *pBitmap[1];
  if(strFileName==NULL) return false ;
  
  pBitmap[0]=SDL_LoadBMP(strFileName);
  
  if(pBitmap[0]==NULL)
  {
      fprintf(stderr,"Failed to load texture %s",SDL_GetError());
      return false;
  }
  fprintf(stdout,"file ok");
  glGenTextures(1,&textureID);
  glBindTexture(GL_TEXTURE_2D,textureID);
  
  int width=pBitmap[0]->w;
  int height=pBitmap[0]->h;
  unsigned char *data=(unsigned char*)(pBitmap[0]->pixels);
  //this->width=width;
  //this->height=height;
  int BytesPerPixel=pBitmap[0]->format->BytesPerPixel;
  
  for(int i=0;i<(height/2);i++)
   for(int j=0;j<width*BytesPerPixel;j+=BytesPerPixel)
     for(int k=0;k<BytesPerPixel;++k)
        swap( data[ (i * width * BytesPerPixel) + j + k], data[ ( (height - i - 1) * width * BytesPerPixel ) + j + k]);
      
  unsigned char *pixel=new unsigned char[width*height*3];
  int count=0;

  
  for(int i=0;i< (width*height);++i)
  {
    unsigned int r,g,b;
    Uint32 pixel_value=0;
    
    for(int j=BytesPerPixel-1;j>=0;--j)
    {
      pixel_value=pixel_value<<8;
      pixel_value=pixel_value | data[(i*BytesPerPixel)+j];      
    }
      fprintf(stdout,"OK");
    SDL_GetRGB(pixel_value,pBitmap[0]->format,(Uint8 *)&r,(Uint8 *)&g,(Uint8 *)&b );
    
    pixels[count++]=r;
    pixels[count++]=g;
    pixels[count++]=b;
    pixel_value=0;
      //rintf(stdout,"OK");
  }
 
     
   gluBuild2DMipmaps(GL_TEXTURE_2D,3,pBitmap[0]->w,pBitmap[0]->h,GL_RGB,GL_UNSIGNED_BYTE,pixels);
   glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);    
   glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR_MIPMAP_NEAREST);
   glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
   SDL_FreeSurface(pBitmap[0]);        
   fprintf(stdout,"texture load ok");
   return true; 
 }
  
void CTexture::clear()
 {
  delete pixels;
  pixels=0;
  glDeleteTextures(1,&textureID);
 }

unsigned int CTexture::getTextureID()
{
 return textureID;
}

void CTexture::setActive()
{
 glBindTexture( GL_TEXTURE_2D, textureID);
}
unsigned int CTexture::getWidth()
{
 return width;
}

unsigned int CTexture::getHeight()
{
  return height;
}

void CTexture::enableOpenGLTexturing()
{
 glEnable(GL_TEXTURE_2D);
 
}

void CTexture::disbleOpenGLTextureing()
{
 glDisable(GL_TEXTURE_2D);
}
CTexture::~CTexture()
{
 delete pixels;
 fprintf(stdout,"clearing texture: %s\n",name);
 //clear();
 
}


};
