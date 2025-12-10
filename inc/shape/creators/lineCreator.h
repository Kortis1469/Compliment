#pragma once
#include "basicOperations.h"
#include "basicTypes.h"
#include <algorithm>

class LineCreator{
public:
    std::vector<point> createLine(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2);
};


class CircleOutlineCreator{
public:
    std::vector<point> createOutline(uint16_t xc, uint16_t yc, uint16_t radius);
};