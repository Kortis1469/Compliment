#ifndef BASICTYPES_H
#define BASICTYPES_H
#pragma once
#include <QColor>
#include <type_traits>


#define PI 3.14159265359

struct point{
    int x;
    int y;
    QColor color;
    point(int x, int y) : x(x), y(y), color("#000000") {}
};


class angle{
    protected:
        double value;
        void biasValue();
    public:
        operator double() const;
        template <typename T>
        void operator=(const T& a);
        
        angle(double value);
        angle(const point& p,const point& pCenter);
        angle();
        angle operator+(const angle& a);
        angle operator-(const  angle& a);
        angle operator*(const  angle& a);
        angle operator/(const  angle& a);
        bool operator<(const  angle& a) const;
        bool operator>(const  angle& a) const;
        bool operator<=(const angle& a) const;
        bool operator>=(const angle& a) const;
        bool operator==(const angle& a) const;

        void pointsToAngle(const point& p,const point& pCenter);

};

template <typename T>
inline void angle::operator=(const T &a)
{
    if constexpr (std::is_same_v<T, angle>) {
        this->value = a.value;  
    }
    else{
        this->value = static_cast<double>(a);
    }
    biasValue();
}


struct ColorSettings{
    angle greaterThanSignDominateZone;
    angle lessThanSignDominateZone;
    angle rigthLengthResidualInfluenseZone;
    angle leftLengthResidualInfluenseZone;

    ColorSettings(angle greaterThanSignDominateZone,
                  angle lessThanSignDominateZone,
                  angle rigthLengthResidualInfluenseZone,
                  angle leftLengthResidualInfluenseZone):
        greaterThanSignDominateZone(greaterThanSignDominateZone),
        lessThanSignDominateZone(lessThanSignDominateZone),
        rigthLengthResidualInfluenseZone(rigthLengthResidualInfluenseZone),
        leftLengthResidualInfluenseZone(leftLengthResidualInfluenseZone)
    {};
};






#endif // BASICTYPES_H
