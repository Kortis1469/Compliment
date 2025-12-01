#ifndef GRADIENTCREATOR_H
#define GRADIENTCREATOR_H
#include "basicTypes.h"
#include "conditionExecutor.h"
#include "intervalConditions.h"
#include "basicoperations.h"

class GradientPointColorSubtractor{
private:
    CyclicRangeConditionDefiner conditionDefiner;
    ColorSettings settings;
    DominateZoneExecutor dominateExecutor;
    ResidualInfluenseZoneExecutor residualInfluenseExecutor;
public:
    GradientPointColorSubtractor(ColorSettings setings);
    uint8_t calculateColor(point p, point pCenter, int r);
};

class IttentGradientCreator{
protected:
    GradientPointColorSubtractor
        red,
        blue,
        green;

public:
    IttentGradientCreator(ColorSettings red, ColorSettings blue, ColorSettings green);
    void colorizeWithGradient(std::vector<point> &circle, point pCenter, int r);
};


#endif // GRADIENTCREATOR_H
