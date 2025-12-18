#pragma once
#include "basicTypes.h"
#include <QtCore>

class BrightnessCalculator{
    public:
        static uint16_t calculate(point p, point center, int radius, int color);
};

class ComporatorLinScan{
    public:
        static bool compare(const point& l, const point& r);
};

class VectorLenCalculator{
    public: 
        static uint16_t calculateVectorLen(point p, point center);
};