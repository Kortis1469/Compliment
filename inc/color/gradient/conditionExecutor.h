#pragma once
#include <cmath>
#include <QtCore>
#include "basicTypes.h"

class ConditionExecutor{
public:
    virtual uint8_t execute(angle angleOfPoint, angle angleGrid) const = 0;
};

class DominateZoneExecutor:ConditionExecutor{
public:
    virtual uint8_t execute(angle angleOfPoint, angle angleGrid) const override;
};
class ResidualInfluenseZoneExecutor:ConditionExecutor{
public:
    virtual uint8_t execute(angle angleOfPoint, angle angleGrid) const override;
};