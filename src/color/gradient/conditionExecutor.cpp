#include "conditionExecutor.h"

uint8_t ResidualInfluenseZoneExecutor::execute(angle angleOfPoint, angle angleGrid) const
{   
    double AngleRatio = abs(angleOfPoint/angleGrid);
    return qRound(abs(255*(AngleRatio-1)));
}

uint8_t DominateZoneExecutor::execute(angle angleOfPoint, angle angleGrid) const
{
    return UINT8_MAX;
}
