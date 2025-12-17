#include "gradientCreator.h"
GradientPointColorSubtractor::GradientPointColorSubtractor(ColorSettings setings):
    settings(setings)
{

}

uint8_t GradientPointColorSubtractor::calculateColor(point p, point pCenter, int r) const
{
    Conditions 
        conds(settings);

    uint8_t 
        color = 0;
    
    angle 
        angl(p, pCenter);

    if(conds.isDominate(angl)) color = dominateExecutor.execute(0,0,0);
    else if(conds.isRightResidual(angl)) {
        color = residualInfluenseExecutor.execute(angl, settings.greaterThanSignDominateZone, settings.rigthLengthResidualInfluenseZone);
    }
    else if(conds.isLeftResidual(angl)) {
        color = residualInfluenseExecutor.execute(angl, settings.lessThanSignDominateZone, -settings.leftLengthResidualInfluenseZone);
    }
    //color += BrightnessCalculator::calculate(p,pCenter,r,color);

    return color;
}



