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
#include "ugl_clight.h"
#define TYPE_POSITION  1
#define TYPE_SPOT      2
#define TYPE_DIRECTION 3

namespace umangagl {

CLight::CLight()
{
 //name=NULL;
 strncpy(name,"noname",8);
 ambient[0]=0.0 ; ambient[1]=0.0 ; ambient[2]=0.0 ; ambient[3]=1.0;
 diffuse[0]=1.0 ; diffuse[1]=1.0 ; diffuse[2]=1.0;  diffuse[3]=1.0;
 specular[0]=1.0; specular[1]=1.0; specular[2]=1.0; specular[3]=1.0;
 position[0]=0.0; position[1]=0.0; position[2]=1.0; position[3]=0.0;
 spot_direction[0]=0.0 ; spot_direction[1]=0.0; spot_direction[2]=-1.0;
 spot_exp=0.0;
 spot_cutoff=180.0;
 const_attn=1.0;
 linear_attn=0.0;
 quad_attn=0.0;
 lightnum=GL_LIGHT0;
}
CLight::CLight(const char* name)
{
 CLight();
 strncpy(this->name,name,8);
 //CLight();
}
void CLight::setupLight()
{
  glLightfv(lightnum, GL_AMBIENT, ambient);
  glLightfv(lightnum, GL_DIFFUSE, diffuse);
  glLightfv(lightnum, GL_SPECULAR,specular);
  glLightfv(lightnum, GL_POSITION,position);
  
  glLightfv(lightnum, GL_SPOT_DIRECTION, spot_direction);
  glLightf(lightnum, GL_SPOT_CUTOFF,spot_cutoff);
  glLightf(lightnum, GL_SPOT_EXPONENT,spot_exp);
  
  glLightf(lightnum, GL_CONSTANT_ATTENUATION, const_attn);
  glLightf(lightnum, GL_LINEAR_ATTENUATION, linear_attn);
  glLightf(lightnum, GL_QUADRATIC_ATTENUATION, quad_attn);


}

void CLight::enableLightSource()
{
  glEnable(lightnum);
}

void CLight::disableLightSource()
{
  glDisable(lightnum);
}

void CLight::setLightSource(unsigned int GLLight_source)
{
  lightnum=GLLight_source;
}

void CLight::setAttenuationConst(GLfloat c)
{
 const_attn=c;
}

void CLight::setAttenuationLinear(GLfloat l)
{
 linear_attn=l;
}

void CLight::setAttenuationQuad(GLfloat q)
{
 quad_attn=q;
}

void CLight::setSpotCutoffAngle(GLfloat angle)
{
 spot_cutoff=angle;
}

void CLight::setPosition(GLfloat x,GLfloat y,GLfloat z)
{
 position[0]=x;position[1]=y;position[2]=z;
}

void CLight::setSpotDirection(GLfloat x,GLfloat y,GLfloat z)
{
 spot_direction[0]=x;
 spot_direction[1]=y;
 spot_direction[2]=z;
}

void CLight::setAmbient(GLfloat r,GLfloat g,GLfloat b,GLfloat a)
{
 ambient[0]=r;ambient[1]=g;ambient[2]=b;ambient[3]=a;
}

void CLight::setDiffuse(GLfloat r,GLfloat g,GLfloat b,GLfloat a)
{
 diffuse[0]=r;diffuse[1]=g;diffuse[2]=b;diffuse[3]=a;
}

void CLight::setSpecular(GLfloat r,GLfloat g,GLfloat b,GLfloat a)
{
 specular[0]=r;specular[1]=g;specular[2]=b;specular[3]=a;
}

void CLight::setTypeDirectional()
{
  lighttype=TYPE_DIRECTION;
  spot_cutoff=180.0;
  spot_exp=0.0;
  position[3]=0.0;
}

void CLight::setTypePositional()
{
 lighttype=TYPE_POSITION;
 spot_cutoff=180.0;
 spot_exp=0.0;
 position[3]=1.0;
}

void CLight::setTypeSpotLight()
{
 lighttype=TYPE_SPOT;
 position[3]=1.0;
}

void CLight::enableOpenGLLighting()
{
  glEnable(GL_LIGHTING);
}

void CLight::disableOpenGLLighting()
{
  glDisable(GL_LIGHTING);
}

void CLight::setLightingModelAmbient(GLfloat r,GLfloat g,GLfloat b,GLfloat a)
{
  GLfloat lmodel_ambient[] = {r,g,b,a};
  glLightModelfv(GL_LIGHT_MODEL_AMBIENT, lmodel_ambient);
}

void CLight::setLightingModelInfiniteViewer()
{
 glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, GL_FALSE);
}

void CLight::setLightingModelLocalViewer()
{
  glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, GL_TRUE);
}

void CLight::setLightingModelOneSide()
{
  glLightModeli(GL_LIGHT_MODEL_TWO_SIDE, GL_FALSE);
}

void CLight::setLightingModelTwoSide()
{
 glLightModeli(GL_LIGHT_MODEL_TWO_SIDE, GL_TRUE);
}

CLight::~CLight()
{
 fprintf(stdout,"clearing light : %s\n",name);
}


};
