#include "IttentGradientColorSetter.h"
#include "gradientCreator.h"


void IttenGradientColorSetter::colorize(std::vector<point> &pointsOfShape, Shape &shape)
{
    IttentGradientCreator ittenGradientCreator(
        {-PI/3, 2*PI/3, PI/3, PI/3},
        {2*PI/3,PI/6,5*PI/6,PI/6},
        {PI/6,-PI/3,PI/6,PI/3});
    Disk &disk = dynamic_cast<Disk&>(shape);
    ittenGradientCreator.colorizeWithGradient(pointsOfShape,{disk.getXCenter(),disk.getYCenter()},disk.getRadius());
}