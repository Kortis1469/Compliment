#pragma once
#include <QtGlobal>
#include "filler.h"
#include "diskCreator.h"
#include "donat.h"

class DonatCreator: public DiskCreator{
    private:
        DonatFiller filler;
    protected:
        
        uint16_t innerRadius;
    public:
        void setParametrs(uint16_t xc, uint16_t yc, uint16_t r) = delete; 
        DonatCreator(uint16_t xc, uint16_t yc, uint16_t externalRaduis, uint16_t innerRadius);
        void setInnerRadius(uint16_t innerRaduis);  
        void setParametrs(uint16_t xc, uint16_t yc, uint16_t externalRaduis, uint16_t innerRadius);
        std::shared_ptr<Shape> create() override;
};