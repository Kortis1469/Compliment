#pragma once
#include "lineCreator.h"

class Filler{
    protected:
        const LineCreator lineCr;
    public:
        Filler();
};


class SolidFiller: public Filler{
    public:
        void fill(std::vector<point>& pts) const;
};


class DonatFiller: public Filler{
    public:
        void fill(std::vector<point>& externalOutline, int innerRadius, int xc, int yc) const;
};