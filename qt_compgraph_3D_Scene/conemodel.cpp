#include "conemodel.h"
#include <cmath>
ConeModel::ConeModel(vector3 rotate,vector3 shift,vector3 scale,int angle,double h,double r,int partition):
    Modeltool(rotate,shift,scale,angle)
{
 this->h = h;
 this->r = r;
 this->partition = partition;
    buildCoords();
}

void ConeModel::buildCoords(){
    coords.clear();
    double step =  360 / partition;
    double p;
    for (int i = 0;i < partition;i++) {
        p = step * i * 3.14 / 180;
        coords.push_back(vector3(r * sin(p),r * cos(p),1.0));
    }
}
