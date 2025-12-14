#include "gradientCreator.h"

GradientPointColorSubtractor::GradientPointColorSubtractor(ColorSettings setings):
    settings(setings)
{

}

uint8_t GradientPointColorSubtractor::calculateColor(point p, point pCenter, int r) const
{
    uint8_t 
        color = 0;

    angle 
        angl(p, pCenter),
        angl1(2),
        rightResidualGrid = settings.greaterThanSignDominateZone + settings.rigthLengthResidualInfluenseZone,
        leftResidualGrid = settings.lessThanSignDominateZone - settings.leftLengthResidualInfluenseZone,
        dominateL = settings.lessThanSignDominateZone,
        dominateG = settings.greaterThanSignDominateZone,
        rightResidualLen = settings.rigthLengthResidualInfluenseZone,
        leftResidualLen = settings.leftLengthResidualInfluenseZone;
    
    std::shared_ptr<IntervalConditions> 
        dominate = conditionDefiner.defineCondition(dominateL,dominateG),
        rightResidual = conditionDefiner.defineCondition(dominateG,rightResidualGrid),
        leftResidual = conditionDefiner.defineCondition(leftResidualGrid, dominateL);


    /*  ColorSettings 
        redSettings(-PI/3, 2*PI/3, PI/3, PI/3),
        greenSettings(2*PI/3, PI/6, 5*PI/6, PI/6),
        blueSettings(PI/6, -PI/3, PI/6, PI/3);
    */


    if(dominate->checkPointForCondition(angl))
        color = dominateExecutor.execute(angl,0);

    else if(rightResidual->checkPointForCondition(angl)){
        double an = angl;
        double an1 = dominateG;
        if(an<0) an+=2*PI;
        color = residualInfluenseExecutor.execute((an-an1), rightResidualLen);
    }

    else if(leftResidual->checkPointForCondition(angl)){
        if(dominateG<dominateL)
            color = residualInfluenseExecutor.execute((angl - (angl1*leftResidualLen)), leftResidualLen);
        else color = residualInfluenseExecutor.execute((angl+leftResidualLen), leftResidualLen);
    }



    //color += BrightnessCalculator::calculate(p,pCenter,r,color);

    return color;
}



IttentGradientCreator::IttentGradientCreator(ColorSettings redSettings, ColorSettings greenSettings, ColorSettings blueSettings) :
    red(redSettings),
    green(greenSettings),
    blue(blueSettings)
{

}

void IttentGradientCreator::colorizeWithGradient(std::vector<point> &circle, point pCenter, int r) const
{
    for(point & p : circle){
        //p.color.setRed(red.calculateColor(p,pCenter, r));
        p.color.setGreen(green.calculateColor(p, pCenter, r));
        //p.color.setBlue(blue.calculateColor(p, pCenter, r));
    }
}
