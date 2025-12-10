#pragma once
#include "basicTypes.h"
#include "disk.h"

class Donat:public Disk{
    protected:
        uint16_t innerRadius;
        bool checkSetterType(ColorSetter& setter) override;
    public:
        uint16_t getInnerRadius();
        Donat(std::vector<point> shape, uint16_t xCenter, uint16_t yCenter, uint16_t radius,uint16_t innerRadius);
};  