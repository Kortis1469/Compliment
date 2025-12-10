#pragma once
#include "basicTypes.h"
#include <QtCore>

class BrightnessCalculator{
    public:
        static uint16_t calculate(point p, point center, int radius, int color);
};

class AngleAdder{
    public:
        static double sumAngle(double leftAngle, double rightAngle);
};

class AngleCalculator{
    public:
    static double calculateAngle(const point p, point pCenter);
};

class ComporatorLinScan{
    public:
        static bool compare(const point& l, const point& r);
};
