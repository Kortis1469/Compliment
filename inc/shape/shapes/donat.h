#pragma once
#include "basicTypes.h"
#include "disk.h"

class Donat:public Disk{
    protected:
        int16_t innerRadius;
        bool checkSetterType(ColorSetter& setter) override;
    public:
        int16_t getInnerRadius();
        Donat(std::vector<point> shape, int16_t xCenter, int16_t yCenter, int16_t radius,int16_t innerRadius);
};  