#include "basicTypes.h"

void angle::biasValue()
{
    while(value>PI) value-=2*PI;
    while(value<-PI) value+=2*PI;
}

angle::operator double() const
{
        return value;   
}

angle::angle(double value)
{
    this->value = value;
}

angle::angle(const point &p, const point &pCenter)
{
    pointsToAngle(p, pCenter);
}

angle::angle()
{
}

angle angle::operator+(const angle &a)
{   
    angle res;
    res.value = this->value+a.value;
    res.biasValue();
    return res;
}

angle angle::operator-(const angle &a)
{
    angle res;
    res.value = this->value-a.value;
    res.biasValue();
    return res;
}

angle angle::operator*(const angle &a)
{
    angle res;
    res.value = this->value*a.value;
    res.biasValue();
    return res;
}

angle angle::operator/(const angle &a)
{   
    angle res;
    res.value = this->value/a.value;
    res.biasValue();
    return res;
}

bool angle::operator==(const angle &a) const
{
    return this->value == a.value;
}


bool angle::operator<(const angle &a) const
{
    return this->value < a.value;
}

bool angle::operator>(const angle &a) const
{
    return this->value > a.value;
}

bool angle::operator<=(const angle &a) const
{
    return this->value <= a.value;
}

bool angle::operator>=(const angle &a) const
{
    return this->value >= a.value;
}

void angle::pointsToAngle(const point &p, const point &pCenter)
{
    this->value = std::atan2(p.y - pCenter.y, p.x - pCenter.x);
}
