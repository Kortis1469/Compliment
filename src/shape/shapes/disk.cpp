#include "disk.h"

bool Disk::checkSetterType(ColorSetter &setter)
{
    return true;
}

uint16_t Disk::getXCenter()
{
    return this->xCenter;
}

uint16_t Disk::getYCenter()
{
    return this->yCenter;
}

uint16_t Disk::getRadius()
{
    return this->radius;
}

Disk::Disk(std::vector<point> shape, uint16_t xCenter, uint16_t yCenter, uint16_t radius) : 
Shape(shape),
xCenter(xCenter),
yCenter(yCenter),
radius(radius)
{
}