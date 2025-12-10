#include "circle.h"

Circle::Circle(QWidget *parent, uint16_t width, uint16_t height) : QWidget(parent), width(width/2), height(height/2) {
    radius = width>height ? width/4: height/4;
    resize(radius*2, radius*2);
}

void Circle::paintEvent(QPaintEvent *event) {

    DiskCreator diskCr(radius, radius, radius);
    std::shared_ptr<Shape> disk = diskCr.create();
    disk->setColor(IttenGradientColorSetter());
    
    std::shared_ptr<const std::vector<point>> pts = disk->getPointsOfShapePtr();
    
    QPainter p;
    p.begin(this);
    
    for(point p2:*pts){
        p.setPen(p2.color);
        p.drawPoint(p2.x,p2.y);
    }
    p.end();
    circle = *pts;
}

void Circle::mousePressEvent(QMouseEvent *event)
{
    int x = event->position().x();   // Qt 6
    int y = event->position().y();

    qDebug() << "Clicked pixel:" << x << y;
    for (const auto& p : circle)
    {
        if (p.x == x && p.y == y)
        {
            qDebug() << "Clicked point color:" << p.color.red() << p.color.green() << p.color.blue();
            break;
        }
    }
}


Circle::~Circle(){

}
