#pragma once
#include <cmath>
#include <QtCore>
#include "basicTypes.h"
#include "shifterToRelativeAngleValues.h"

class ConditionExecutor{
public:
    virtual uint8_t execute(double angl, double dominateGrid, double length) const = 0;
};

class DominateZoneExecutor:ConditionExecutor{
public:
    virtual uint8_t execute(double angl, double dominateGrid, double length) const override;
};
class ResidualInfluenseZoneExecutor:ConditionExecutor{
public:
    virtual uint8_t execute(double angl, double dominateGrid, double length) const override;
};