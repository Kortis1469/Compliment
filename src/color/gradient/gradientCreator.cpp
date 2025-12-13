#include "gradientCreator.h"

GradientPointColorSubtractor::GradientPointColorSubtractor(ColorSettings setings):
    settings(setings)
{

}

uint8_t GradientPointColorSubtractor::calculateColor(point p, point pCenter, int r) const
{
    uint8_t 
        color = 0;
    
    double 
        angle = AngleCalculator::calculateAngle(p, pCenter),
        rightResidualGrid = AngleAdder::sumAngle(settings.greaterThanSignDominateZone, settings.rigthLengthResidualInfluenseZone),
        leftResidualGrid = AngleAdder::sumAngle(settings.lessThanSignDominateZone, -settings.leftLengthResidualInfluenseZone),
        dominateL = settings.lessThanSignDominateZone,
        dominateG = settings.greaterThanSignDominateZone,
        rightResidualLen = settings.rigthLengthResidualInfluenseZone,
        leftResidualLen = settings.leftLengthResidualInfluenseZone;

    
    std::shared_ptr<IntervalConditions> 
        dominate = conditionDefiner.defineCondition(dominateL,dominateG),
        rightResidual = conditionDefiner.defineCondition(dominateG,rightResidualGrid),
        leftResidual = conditionDefiner.defineCondition(leftResidualGrid, dominateL);



        
    if(dominate->checkPointForCondition(angle))
        color = dominateExecutor.execute(angle,0);

    else if(rightResidual->checkPointForCondition(angle)){
        color = residualInfluenseExecutor.execute(AngleAdder::sumAngle(angle, -dominateG), rightResidualLen);
    }
    //вот с этим пиздец разобраться надо
    //очень жидко вычисляет рецесивный цвет
    else if(leftResidual->checkPointForCondition(angle)){
        if(settings.greaterThanSignDominateZone<settings.lessThanSignDominateZone)
            color = residualInfluenseExecutor.execute(AngleAdder::sumAngle(angle,-2*leftResidualLen), leftResidualLen);
        else color = residualInfluenseExecutor.execute(AngleAdder::sumAngle(angle,leftResidualLen), leftResidualLen);
    }



    color += BrightnessCalculator::calculate(p,pCenter,r,color);

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
        p.color.setRed(red.calculateColor(p,pCenter, r));
        p.color.setGreen(green.calculateColor(p, pCenter, r));
        p.color.setBlue(blue.calculateColor(p, pCenter, r));
    }
}
