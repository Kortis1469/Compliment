#include "conditions.h"

Conditions::Conditions(ColorSettings settings)
{
    angle
        rightResidualGrid = settings.greaterThanSignDominateZone + settings.rigthLengthResidualInfluenseZone,
        leftResidualGrid = settings.lessThanSignDominateZone - settings.leftLengthResidualInfluenseZone,
        dominateL = settings.lessThanSignDominateZone,
        dominateG = settings.greaterThanSignDominateZone;
    
    CyclicRangeConditionDefiner conditionDefiner;
    
    dominate = conditionDefiner.defineCondition(dominateL,dominateG),
    rightResidual = conditionDefiner.defineCondition(dominateG,rightResidualGrid),
    leftResidual = conditionDefiner.defineCondition(leftResidualGrid, dominateL);
}

bool Conditions::isDominate(angle ang)
{
    return dominate->checkPointForCondition(ang);
}

bool Conditions::isRightResidual(angle ang)
{
    return rightResidual->checkPointForCondition(ang);
}

bool Conditions::isLeftResidual(angle ang)
{
    return leftResidual->checkPointForCondition(ang);
}
