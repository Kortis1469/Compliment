#include <algorithm>
#include <vector>
#include "lineCreator.h"

std::vector<point> CircleOutlineCreator::createOutline(uint16_t xc, uint16_t yc, uint16_t radius) const
{
    std::vector<point> pts;
    uint16_t
        x = 0,
        y = radius;
    int16_t
        error = 0;
    auto makePoints = [&pts, xc, yc, &x, &y](){
        pts.push_back(point(xc + x, yc + y));
        pts.push_back(point(xc - x, yc + y));
        pts.push_back(point(xc + x, yc - y));
        pts.push_back(point(xc - x, yc - y));
        pts.push_back(point(xc + y, yc + x));
        pts.push_back(point(xc - y, yc + x));
        pts.push_back(point(xc + y, yc - x));
        pts.push_back(point(xc - y, yc - x));
    };
    
    while (x <= y) {
        makePoints();
        x++;
        if (error < 0)
            error += 2*x + 1;
        else {
            y--;
            error += 2*(x - y) + 1;
        }
    }
    return pts;
}


std::vector<point> LineCreator::createLine(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2) const
{
    std::vector<point> pts;
    float
        dx = x2 - x1,
        dy = y2 - y1;
    bool isXMajor = qAbs(dx) > qAbs(dy);

    if (!(dx == 0 && dy == 0)){
        float
            err = 0,                                                                    
            df = isXMajor ? qAbs(dy / dx) : qAbs(dx / dy);
        int8_t
            signX = (dx >= 0) ? 1 : -1,
            signY = (dy >= 0) ? 1 : -1,
            *mainSignPtr = isXMajor ? &signX : &signY;
        uint16_t
            *mainFlowValPtr = isXMajor ? &x1 : &y1;

         while (!(x1 == x2 && y1 == y2)){
            pts.push_back({x1,y1});
            err += df;
            if (err >= 0.5f){
                err -= 1.0f;
                x1 += signX;
                y1 += signY;
            }
            else
                *mainFlowValPtr += *mainSignPtr;
        }
    }
    pts.push_back({x1,y1});
    return pts;
}