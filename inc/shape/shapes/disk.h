#pragma once
#include "basicTypes.h"
#include "shape.h"

class Disk:public Shape{
    protected:
        int16_t xCenter;
        int16_t yCenter;
        int16_t radius;
        virtual bool checkSetterType(ColorSetter& setter) override;
    public:
        int16_t getXCenter();
        int16_t getYCenter();
        int16_t getRadius();
        Disk(std::vector<point> shape, int16_t xCenter, int16_t yCenter, int16_t radius );
};  