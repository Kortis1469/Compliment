#include "shifterToRelativeAngleValues.h"
double ShifterToRelativeAngleValues::biasAngleWithSensitiveLengthSign(double angl, double dominateGrid, double length)
{   
    int8_t s = copysign(1,length); angl *= s; dominateGrid *= s;
    angl = angl>dominateGrid ? s*angl-s*dominateGrid : angl + PI*2 - dominateGrid;
    return angl;
}