#include "circle.h"

Circle::Circle(QWidget *parent, int32_t xCenter, int32_t yCenter, int32_t radius) : QWidget(parent), width(radius*2), height(radius*2) {
    
    this->radius = radius;
    this->xCenter = xCenter;
    this->yCenter = yCenter;
    resize(radius*2, radius*2);
    
    DiskCreator diskCr(radius, radius, radius);
    std::shared_ptr<Shape> disk = diskCr.create();
    disk->setColor(IttenGradientColorSetter());


    move(xCenter-radius,yCenter-radius);
    colorDisk = disk->getPointsOfShapePtr();
}

void Circle::paintEvent(QPaintEvent *event) {

    QPainter p(this);
    for(point p2:*colorDisk){
        p.setPen(p2.color);
        p.drawPoint(p2.x,p2.y);
    }
}

uint16_t Circle::getRadius()
{
    return this->radius; 
    
}

uint16_t Circle::getXCenter()
{
    return this->xCenter;
}

uint16_t Circle::getYCenter()
{
    return this->yCenter;
}

QColor Circle::getColorFromPix(point p)
{
    //пиксель приходит неудачный
    //нужно что-то придумать чтобы x и y сдвигались на обратно и только тогда уже искать.
    p.x -= (xCenter-radius);
    p.y -= (yCenter-radius);
    auto it = std::lower_bound(colorDisk->begin(), colorDisk->end(), p);
    return it->color;
}
