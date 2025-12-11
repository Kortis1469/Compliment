#pragma once
#include <cmath>
#include <QtCore>

class ConditionExecutor{
public:
    virtual uint8_t execute(double angleOfPoint, double angleGrid) const = 0;
};

class DominateZoneExecutor:ConditionExecutor{
public:
    virtual uint8_t execute(double angleOfPoint, double angleGrid) const override;
};
class ResidualInfluenseZoneExecutor:ConditionExecutor{
public:
    virtual uint8_t execute(double angleOfPoint, double angleGrid) const override;
};