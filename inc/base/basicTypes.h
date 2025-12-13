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
