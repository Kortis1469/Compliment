#include "circle.h"

Circle::Circle(QWidget *parent, uint16_t x1, uint16_t y1,uint16_t x2, uint16_t y2) : QWidget(parent), width(abs(x2-x1)), height(abs(y2-y1)) {
    
    radius = width<height ? width: height;
    resize(radius*2, radius*2);
    move(x1,y1);
    DiskCreator diskCr(radius, radius, radius);
    std::shared_ptr<Shape> disk = diskCr.create();
    disk->setColor(IttenGradientColorSetter());
    
    colorDisk = disk->getPointsOfShapePtr();
}

void Circle::paintEvent(QPaintEvent *event) {

    
    
    QPainter p;
    p.begin(this);
    
    for(point p2:*colorDisk){
        p.setPen(p2.color);
        p.drawPoint(p2.x,p2.y);
    }
    p.end();
}

void Circle::mousePressEvent(QMouseEvent *event)
{
    int x = event->position().x();   // Qt 6
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
