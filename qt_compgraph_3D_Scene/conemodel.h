#ifndef CONEMODEL_H
#define CONEMODEL_H
#include "modeltool.h"
#include "vector3.h"
#include <vector>

class ConeModel: public Modeltool
{
public:
    double h;
    double r;
    int partition;
    std::vector <vector3> coords;
    ConeModel(vector3 rotate = vector3(1,0,0),vector3 shift = vector3(0,0,0),vector3 scale = vector3(1,1,1),int angle = 0,double h = 1.0,double r = 0.5,int partition = 36);
    void buildCoords();
};


#endif // CONEMODEL_H
