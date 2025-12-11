#include "diskCreator.h"

DiskCreator::DiskCreator(uint16_t xc, uint16_t yc, uint16_t r):
xCenter(xc),
yCenter(yc),
radius(r)
{
}

void DiskCreator::setParametrs(uint16_t xc, uint16_t yc, uint16_t r)
{
    this->xCenter = xc;
    this->yCenter = yc;
    this->radius = r;
}

void DiskCreator::sertCenterX(uint16_t xc)
{
    this->xCenter = xc;
}

void DiskCreator::sertCenterY(uint16_t yc)
{
    this->yCenter = yc;
}

void DiskCreator::sertRaduis(uint16_t r)
{
    this->radius = r;
}

std::shared_ptr<Shape> DiskCreator::create()
{   
    
    point pCenter(xCenter,yCenter);

    std::vector<point> pts = circleOutlineCr.createOutline(pCenter.x,pCenter.y, radius);
    filler.fill(pts);
    std::shared_ptr<Shape> disk = std::make_shared<Disk>(pts,xCenter,yCenter,radius);
    return disk;
}
