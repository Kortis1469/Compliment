#include "gradientCreator.h"

GradientPointColorSubtractor::GradientPointColorSubtractor(ColorSettings setings):
    settings(setings)
{

}

uint8_t GradientPointColorSubtractor::calculateColor(point p, point pCenter, int r)
{
    uint8_t color = 0;
    double angle = AngleCalculator::calculateAngle(p, pCenter);
    double
        rightResidualGrid = AngleAdder::sumAngle(settings.greaterThanSignDominateZone, settings.rigthLengthResidualInfluenseZone),
        leftResidualGrid = AngleAdder::sumAngle(settings.lessThanSignDominateZone, -settings.leftLengthResidualInfluenseZone);

    std::shared_ptr<IntervalConditions> dominate = conditionDefiner.defineCondition(settings.lessThanSignDominateZone,settings.greaterThanSignDominateZone);
    std::shared_ptr<IntervalConditions> rightResidual = conditionDefiner.defineCondition(settings.greaterThanSignDominateZone,rightResidualGrid);
    std::shared_ptr<IntervalConditions> leftResidual = conditionDefiner.defineCondition(leftResidualGrid, settings.lessThanSignDominateZone);


    if(dominate->checkPointForCondition(angle))
        color = dominateExecutor.execute(angle,0);

    else if(rightResidual->checkPointForCondition(angle)){
        color = residualInfluenseExecutor.execute(AngleAdder::sumAngle(angle, -settings.greaterThanSignDominateZone), settings.rigthLengthResidualInfluenseZone);
    }
    //вот с этим пиздец разобраться надо
    //очень жидко вычисляет рецесивный цвет
    else if(leftResidual->checkPointForCondition(angle)){
        if(settings.greaterThanSignDominateZone<settings.lessThanSignDominateZone)
            color = residualInfluenseExecutor.execute(AngleAdder::sumAngle(angle,-2*settings.leftLengthResidualInfluenseZone), settings.leftLengthResidualInfluenseZone);
        else color = residualInfluenseExecutor.execute(AngleAdder::sumAngle(angle,settings.leftLengthResidualInfluenseZone), settings.leftLengthResidualInfluenseZone);
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

void IttentGradientCreator::colorizeWithGradient(std::vector<point> &circle, point pCenter, int r)
{
    for(point & p : circle){
        p.color.setRed(red.calculateColor(p,pCenter, r));
        p.color.setGreen(green.calculateColor(p, pCenter, r));
        p.color.setBlue(blue.calculateColor(p, pCenter, r));
    }
}
