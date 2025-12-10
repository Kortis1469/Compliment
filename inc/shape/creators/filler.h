#pragma once
#include "lineCreator.h"

class SolidFiller{
    private:
        LineCreator lineCr;
    public:
        void fill(std::vector<point>& pts);
};


class DonatFiller{
    private:
        LineCreator lineCr;
    public:
        void fill(std::vector<point>& externalOutline, int innerRadius, int xc, int yc);
};