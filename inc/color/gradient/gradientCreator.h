#pragma once
#include "conditionExecutor.h"
#include "basicoperations.h"
#include "conditionDefiner.h"
#include "conditions.h"

class GradientPointColorSubtractor{
private:
    CyclicRangeConditionDefiner conditionDefiner;
    ColorSettings settings;
    DominateZoneExecutor dominateExecutor;
    ResidualInfluenseZoneExecutor residualInfluenseExecutor;
public:
    GradientPointColorSubtractor(ColorSettings setings);
    uint8_t calculateColor(point p, point pCenter, int r) const;
};