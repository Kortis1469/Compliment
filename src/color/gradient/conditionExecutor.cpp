#include "conditionExecutor.h"

uint8_t ResidualInfluenseZoneExecutor::execute(double angl, double dominateGrid, double length) const
{   
    ShifterToRelativeAngleValues strav;
    angl = strav.biasAngleWithSensitiveLengthSign(angl,dominateGrid,length);
   
    return qRound(255*(1-abs(angl/length)));
}

uint8_t DominateZoneExecutor::execute(double angl, double dominateGrid, double length) const
{
    return UINT8_MAX;
}
