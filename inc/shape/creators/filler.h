#pragma once
#include "lineCreator.h"

/*
    Нужно сделать общего предка для филлеров
    И навесить защиту в виде проверки что входит в fill 
*/



class SolidFiller{
    private:
        const LineCreator lineCr;
    public:
        SolidFiller();
        void fill(std::vector<point>& pts) const;
};


class DonatFiller{
    private:
        const LineCreator lineCr;
    public:
        DonatFiller();
        void fill(std::vector<point>& externalOutline, int innerRadius, int xc, int yc) const;
};