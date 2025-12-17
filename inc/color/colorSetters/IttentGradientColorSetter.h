#pragma once
#include "basicTypes.h"
#include "disk.h"
#include "IttenGradientCreator.h"

class IttenGradientColorSetter:public ColorSetter{
    void colorize(std::vector<point> & pointsOfShape, Shape &shape) const override;
};