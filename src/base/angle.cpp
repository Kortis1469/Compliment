#include "angle.h"

void angle::biasValue()
{
    while(value>PI) value-2*PI;
    while(value<-PI) value-2*PI;
}

angle::operator double() const
{
        return value;   
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
