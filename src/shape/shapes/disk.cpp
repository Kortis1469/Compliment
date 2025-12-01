#include "disk.h"

bool Disk::checkSetterType(ColorSetter &setter)
{
    return true;
}

uint16_t Disk::getXCenter()
{
    this->xCenter;
}

uint16_t Disk::getYCenter()
{
    this->yCenter;
}

uint16_t Disk::getRadius()
{
    this->radius;
}

Disk::Disk(std::vector<point> shape, uint16_t xCenter, uint16_t yCenter, uint16_t radius) : 
Shape(shape),
xCenter(xCenter),
yCenter(yCenter),
radius(radius)
{
}