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

double AngleAdder::sumAngle(double leftAngle, double rightAngle)
{
    double sum = leftAngle + rightAngle;

    while(sum>PI)
        sum = (-(2*PI))+sum;
    while(sum<-PI)
        sum = (2*PI)+sum;
    if(sum>PI) qDebug() << sum << leftAngle << rightAngle;
    return sum;
}


bool ComporatorLinScan::compare(const point &l, const point &r)
{
    if(l.y == r.y) return l.x < r.x;
    return l.y < r.y;
}

double AngleCalculator::calculateAngle(const point p, point pCenter)
{
        double
            dx = p.x - pCenter.x,
            dy = p.y - pCenter.y;
        return std::atan2(dy,dx);
}
