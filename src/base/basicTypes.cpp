#include "basicTypes.h"

bool point::operator<(const point& a)const{
    if(this->y == a.y) return this->x < a.x;
    return this->y < a.y;
}

void angle::biasValue()
{
    while(value>2*PI) value-=2*PI;
    while(value<0) value+=2*PI;
}

angle::operator double() const
{
        return value;   
}

angle::angle(double value)
{
    this->value = value;
    biasValue();
}

angle::angle(const point &p, const point &pCenter)
{
    pointsToAngle(p, pCenter);
}

angle::angle()
{
}

void angle::pointsToAngle(const point &p, const point &pCenter)
{
    this->value = std::atan2(p.y - pCenter.y, p.x - pCenter.x);
    biasValue();
}

double angle::getValueShiftedTo2PI()
{   
    if(value<0) return value+2*PI;
    return value;
}


