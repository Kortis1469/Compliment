#ifndef BASICTYPES_H
#define BASICTYPES_H
#pragma once
#include <QColor>

#define PI 3.14159265359

struct point{
    int x;
    int y;
    QColor color;
    point(int x, int y) : x(x), y(y), color("#000000") {}
};

// class angle{
//     private:
//         double value;
//         double biasRadians(double angle);

//     public:
//         template <typename T>
//         angle operator=(const T& a);

//         template <typename T>
//         angle operator+(const T& a);

//         template <typename T>
//         angle operator-(const T& a);

//         template <typename T>
//         angle operator*(const T& a);

//         template <typename T>
//         angle operator/(const T& a);

//         template <typename T>
//         angle operator<(const T& a);

//         template <typename T>
//         angle operator>(const T& a);

//         template <typename T>
//         angle operator<=(const T& a);

//         template <typename T>
//         angle operator>=(const T& a);

//         template <typename T>
//         angle operator==(const T& a);

// };

struct ColorSettings{
    double greaterThanSignDominateZone;
    double lessThanSignDominateZone;
    double rigthLengthResidualInfluenseZone;
    double leftLengthResidualInfluenseZone;
    ColorSettings(double greaterThanSignDominateZone,
                  double lessThanSignDominateZone,
                  double rigthLengthResidualInfluenseZone,
                  double leftLengthResidualInfluenseZone):
        greaterThanSignDominateZone(greaterThanSignDominateZone),
        lessThanSignDominateZone(lessThanSignDominateZone),
        rigthLengthResidualInfluenseZone(rigthLengthResidualInfluenseZone),
        leftLengthResidualInfluenseZone(leftLengthResidualInfluenseZone)
    {};
};


#endif // BASICTYPES_H
