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
#ifndef UMANGAGLUGL_CMESH_H
#define UMANGAGLUGL_CMESH_H
#include "ugl_oglsdl.h"
#include "ugl_misc.h"
namespace umangagl {

/**
@author Ashika Umanga Umagiliya
*/
class CMesh{
public:
    CMesh();
    void setPosition(float x,float y,float x);
    void setScale(float x,float y,float z);
    void setBoundryMinMax(CVector3 min,CVector3 max);
    void setRotation(float x,float y,float z);
    void setRotationX(float angle,bool useLocalCoords);
    void setRotationY(float angle,bool useLocalCoords);
    void setRotationZ(float angle,bool useLocalCoords);
    void drawBoundingBox();
    bool detectRayTraceCollision(CVector3 start,CVector3 end);
    bool detectBoundingBoxCollision(CVector3 start,CVector3 end);
    CVector3 getPosition();
    CVector3 getScale();
    CVector3 getBoundryMax();
    CVector3 getBoundryMin();
    CVector3 getRotation(); 
    CVector3 *pPnts;
    CVector3 *vertices;
    CVector3 *overtices;
    bool keepCurrent;
    
    ~CMesh();
private:
  CVector3 position;
  CVector3 scale;
  CVector3 rotate;
  CVector3 boundry[8];
  CVector3 oboundry[8]; //stores original bounding box vlaue
  
};

};

#endif
