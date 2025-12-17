#include "IttenGradientCreator.h"

IttentGradientCreator::IttentGradientCreator(ColorSettings redSettings, ColorSettings greenSettings, ColorSettings blueSettings) :
    red(redSettings),
    green(greenSettings),
    blue(blueSettings)
{

}

void IttentGradientCreator::colorizeWithGradient(std::vector<point> &circle, point pCenter, int r) const
{
    for(point & p : circle){
        p.color.setRed(red.calculateColor(p,pCenter, r));
        p.color.setGreen(green.calculateColor(p, pCenter, r));
        p.color.setBlue(blue.calculateColor(p, pCenter, r));
    }
}
