#ifndef CIRCLECREATOR_H
#define CIRCLECREATOR_H

#include <QtGlobal>
#include "intervalconditions.h"
#include "conditionExecutor.h"
#include "lineCreator.h"
#include "gradientCreator.h"
#include "filler.h"






class DonatCreator: public CircleCreator{
    private:
        DonatFiller filler;
        uint16_t externalRaduis;
    public:
        DonatCreator(uint16_t externalRaduis);
        std::vector<point> createCircle(uint16_t xc, uint16_t yc, uint16_t r) override;
        void setExternalRadius(uint16_t externalRaduis);
};

#endif // CIRCLECREATOR_H
