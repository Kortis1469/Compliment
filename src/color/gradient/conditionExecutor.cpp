#include "conditionExecutor.h"

uint8_t ResidualInfluenseZoneExecutor::execute(double angleOfPoint, double angleGrid) const
{
    return qRound(abs(255*(abs(angleOfPoint/angleGrid)-1)));
}

uint8_t DominateZoneExecutor::execute(double angleOfPoint, double angleGrid) const
{
    return UINT8_MAX;
}
