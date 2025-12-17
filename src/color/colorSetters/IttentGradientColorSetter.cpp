#include "IttentGradientColorSetter.h"



void IttenGradientColorSetter::colorize(std::vector<point> &pointsOfShape, Shape &shape) const
{
    ColorSettings 
        redSettings(-PI/3, 2*PI/3, PI/3, PI/3),
        greenSettings(2*PI/3, PI/6, 2*PI/3, PI/6),
        blueSettings(PI/6, -PI/3, PI/6, PI/3);

    IttentGradientCreator ittenGradientCreator(redSettings, greenSettings, blueSettings);

    Disk &disk = dynamic_cast<Disk&>(shape);
    ittenGradientCreator.colorizeWithGradient(pointsOfShape,{disk.getXCenter(),disk.getYCenter()},disk.getRadius());
}