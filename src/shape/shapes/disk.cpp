#include "disk.h"

bool Disk::checkSetterType(ColorSetter &setter)
{
    return true;
}

int16_t Disk::getXCenter()
{
    return xCenter;
}

int16_t Disk::getYCenter()
{
    return yCenter;
}

int16_t Disk::getRadius()
{
    return radius;
}

Disk::Disk(std::vector<point> shape, int16_t xCenter, int16_t yCenter, int16_t radius) : 
Shape(shape),
xCenter(xCenter),
yCenter(yCenter),
radius(radius)
{
}