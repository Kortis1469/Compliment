#include "donat.h"

bool Donat::checkSetterType(ColorSetter &setter)
{
    return false;
}

int16_t Donat::getInnerRadius()
{
    return innerRadius;
}

Donat::Donat(
            std::vector<point> shape, 
            int16_t xCenter, 
            int16_t yCenter, 
            int16_t radius, 
            int16_t innerRadius)

:Disk(shape, xCenter, yCenter, radius),
innerRadius(innerRadius)                                                                                                          
{
    
}
