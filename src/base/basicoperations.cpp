#include "basicOperations.h"

uint16_t BrightnessCalculator::calculate(point p, point center, int radius, int color)
{
    double lengthOfVector;
    uint16_t
        x = abs(p.x-center.x),
        y = abs(p.y-center.y);

    lengthOfVector = sqrt(x*x+y*y);

    double additionalBrightness = 255 - color;
    uint16_t brightness = qRound(additionalBrightness*abs(((lengthOfVector)/(radius))-1));

    return brightness;
}

bool ComporatorLinScan::compare(const point &l, const point &r)
{
    if(l.y == r.y) return l.x < r.x;
    return l.y < r.y;
}
