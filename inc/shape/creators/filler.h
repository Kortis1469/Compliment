#pragma once
#include "lineCreator.h"

/*
    Нужно сделать общего предка для филлеров
    И навесить защиту в виде проверки что входит в fill 
*/



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