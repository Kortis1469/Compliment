#pragma once
#include "conditionExecutor.h"
#include "basicoperations.h"
#include "conditionDefiner.h"

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

class IttentGradientCreator{
protected:
    GradientPointColorSubtractor
        red,
        blue,
        green;

public:
    IttentGradientCreator(ColorSettings red, ColorSettings blue, ColorSettings green);
    void colorizeWithGradient(std::vector<point> &circle, point pCenter, int r) const;
};