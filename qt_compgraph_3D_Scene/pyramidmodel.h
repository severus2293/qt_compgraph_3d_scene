#ifndef PYRAMIDMODEL_H
#define PYRAMIDMODEL_H
#include "modeltool.h"
#include "vector3.h"
#include <vector>

class PyramidModel: public Modeltool
{
public:
    double h;
    double r;
    int partition;
    std::vector <vector3> coords;
    PyramidModel(vector3 rotate = vector3(1,0,0),vector3 shift = vector3(0,0,0),vector3 scale = vector3(1,1,1),int angle = 0,double h = 1.0,double r = 0.5,int partition = 6);
    void buildCoords();
};

#endif // PYRAMIDMODEL_H
