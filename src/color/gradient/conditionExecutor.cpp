#include "conditionExecutor.h"

int ResidualInfluenseZoneExecutor::execute(double angleOfPoint, double angleGrid)
{
    return qRound(abs(255*(abs(angleOfPoint/angleGrid)-1)));
}

int DominateZoneExecutor::execute(double angleOfPoint, double angleGrid)
{
    return 255;
}
