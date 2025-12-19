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

void Circle::mousePressEvent(QMouseEvent *event)
{
    int x = event->position().x();   
    int y = event->position().y();

    qDebug() << "Clicked pixel:" << x << y;
    for (const auto& p : *colorDisk)
    {
        if (p.x == x && p.y == y)
        {
            qDebug() << "Clicked point color:" << p.color.red() << p.color.green() << p.color.blue();
            break;
        }
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
