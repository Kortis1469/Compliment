#include "donat.h"

bool Donat::checkSetterType(ColorSetter &setter)
{
    return false;
}

uint16_t Donat::getInnerRadius()
{
    return this->innerRadius;
}

Donat::Donat(
            std::vector<point> shape, 
            uint16_t xCenter, 
            uint16_t yCenter, 
            uint16_t radius, 
            uint16_t innerRadius)

:Disk(shape, xCenter, yCenter, radius),
innerRadius(innerRadius)                                                                                                          
{
    
}
