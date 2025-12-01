#ifndef CONDITIONEXECUTOR_H
#define CONDITIONEXECUTOR_H
#include <cmath>
#include <QtCore>

class ConditionExecutor{
public:
    virtual int execute(double angleOfPoint, double angleGrid) = 0;
};

class DominateZoneExecutor:ConditionExecutor{
public:
    virtual int execute(double angleOfPoint, double angleGrid) override;
};
class ResidualInfluenseZoneExecutor:ConditionExecutor{
public:
    virtual int execute(double angleOfPoint, double angleGrid) override;
};

#endif // CONDITIONEXECUTOR_H
