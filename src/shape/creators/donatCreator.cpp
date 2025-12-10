#include "donatCreator.h"

DonatCreator::DonatCreator(uint16_t xc, uint16_t yc, uint16_t externalRaduis, uint16_t innerRadius):
DiskCreator(xc,yc,externalRaduis),
innerRadius(innerRadius)
{
}

void DonatCreator::setInnerRadius(uint16_t innerRaduis)
{
    this->innerRadius = innerRadius;
}

void DonatCreator::setParametrs(uint16_t xc, uint16_t yc, uint16_t externalRaduis, uint16_t innerRadius)
{
    this->xCenter = xc;
    this->yCenter = yc;
    this->radius = externalRaduis;
    this->innerRadius = innerRadius;
}

std::shared_ptr<Shape> DonatCreator::create()
{
    point pCenter(xCenter,yCenter);
    std::vector<point> pts = circleOutlineCr.createOutline(pCenter.x,pCenter.y, radius);
    filler.fill(pts,innerRadius,xCenter,yCenter);
    std::shared_ptr<Shape> donat = std::make_shared<Donat>(pts,xCenter,yCenter,radius, innerRadius);
    return donat;
}
