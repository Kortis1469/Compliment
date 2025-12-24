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
    bool operator<(const point&a) const;
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

        template <typename T>
        angle operator+(const T& a);
         template <typename T>
        angle operator-(const T& a);
         template <typename T>
        angle operator*(const T& a);
         template <typename T>
        angle operator/(const T& a);
    
         template <typename T>
        bool operator<(const T& a);
         template <typename T>
        bool operator>(const T& a);
         template <typename T>
        bool operator<=(const T& a);
         template <typename T>
        bool operator>=(const T& a);
         template <typename T>
        bool operator==(const T& a);
    

        void pointsToAngle(const point& p,const point& pCenter);
        double getValueShiftedTo2PI();

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

template <typename T>
inline angle angle::operator+(const T &a)
{
    angle res;
    if constexpr (std::is_same_v<T, angle>) {
        res = this->value + a.value;  
    }
    else{
        res = this->value + static_cast<double>(a);
    }
    biasValue();
    return res;
}

template <typename T>
inline angle angle::operator-(const T &a)
{
    angle res;
    if constexpr (std::is_same_v<T, angle>) {
        res = this->value - a.value;  
    }
    else{
        res = this->value - static_cast<double>(a);
    }
    biasValue();
    return res;
}

template <typename T>
inline angle angle::operator*(const T &a)
{
    angle res;
    if constexpr (std::is_same_v<T, angle>) {
        res = this->value * a.value;  
    }
    else{
        res = this->value * static_cast<double>(a);
    }
    biasValue();
    return res;
}

template <typename T>
inline angle angle::operator/(const T &a)
{
    angle res;
    if constexpr (std::is_same_v<T, angle>) {
        res = this->value / a.value;  
    }
    else{
        res = this->value / static_cast<double>(a);
    }
    biasValue();
    return res;
}

template <typename T>
inline bool angle::operator<(const T &a)
{
  
    if constexpr (std::is_same_v<T, angle>) {
        return this->value < a.value;  
    }
    else{
        return this->value < static_cast<double>(a);
    }
    
}

template <typename T>
inline bool angle::operator>(const T &a)
{
  
    if constexpr (std::is_same_v<T, angle>) {
        return this->value > a.value;  
    }
    else{
        return this->value > static_cast<double>(a);
    }
    
}
template <typename T>
inline bool angle::operator<=(const T &a)
{
  
    if constexpr (std::is_same_v<T, angle>) {
        return this->value <= a.value;  
    }
    else{
        return this->value <= static_cast<double>(a);
    }
    
}

template <typename T>
inline bool angle::operator>=(const T &a)
{
  
    if constexpr (std::is_same_v<T, angle>) {
        return this->value >= a.value;  
    }
    else{
        return this->value >= static_cast<double>(a);
    }
    
}

template <typename T>
inline bool angle::operator==(const T &a)
{
  
    if constexpr (std::is_same_v<T, angle>) {
        return this->value == a.value;  
    }
    else{
        return this->value == static_cast<double>(a);
    }
    
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
