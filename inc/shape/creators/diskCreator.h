#pragma once
#include "basicTypes.h"
#include "filler.h"
#include "disk.h"

class DiskCreator: public ShapeCreator{
    private:
        const SolidFiller filler;
    protected:
        const CircleOutlineCreator circleOutlineCr;
        uint16_t xCenter;
        uint16_t yCenter;
        uint16_t radius;
    public:
        DiskCreator(uint16_t xc, uint16_t yc, uint16_t r);
        void setParametrs(uint16_t xc, uint16_t yc, uint16_t r);
        void sertCenterX(uint16_t xc);
        void sertCenterY(uint16_t yc);
        void sertRaduis(uint16_t xc);
        virtual std::shared_ptr<Shape> create() const  override;
};