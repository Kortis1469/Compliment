#include "circleCreator.h"


DonatCreator::DonatCreator(uint16_t externalRaduis):
    externalRaduis(externalRaduis)
{
}

std::vector<point> DonatCreator::createCircle(uint16_t xc, uint16_t yc, uint16_t innerRadius)
{
    std::vector<point> donat;
    std::vector<point> buffer;

    donat = circleOutlineCr.createOutline(xc,yc,innerRadius);
    buffer = circleOutlineCr.createOutline(xc,yc,externalRaduis);
    donat.insert(donat.end(), buffer.begin(), buffer.end());
    filler.fill(donat,innerRadius, xc, yc);

    return donat;
}

void DonatCreator::setExternalRadius(uint16_t externalRaduis)
{
     this->externalRaduis = externalRaduis;
}
