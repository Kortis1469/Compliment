#pragma once
#include "basicTypes.h"
#include "shape.h"

class Disk:public Shape{
    protected:
        uint16_t xCenter;
        uint16_t yCenter;
        uint16_t radius;
        virtual bool checkSetterType(ColorSetter& setter) override;
    public:
        uint16_t getXCenter();
        uint16_t getYCenter();
        uint16_t getRadius();
        Disk(std::vector<point> shape, uint16_t xCenter, uint16_t yCenter, uint16_t radius );
};  