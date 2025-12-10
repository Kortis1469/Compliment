#include "colorIndicator.h"


ColorIndicator::ColorIndicator(QWidget *parent):QWidget(parent)
{
    resize(1080, 720);
}

void ColorIndicator::paintEvent(QPaintEvent *event){
    int
        magicX = 1080/2,
        magicY = 720/2,
        magicR = 8;
    int
        height = abs(magicR-magicY),
        width = abs(magicR-magicX);

    DonatCreator creator(magicX,magicY,10,magicR);
    std::shared_ptr<Shape> donat = creator.create();
    std::shared_ptr<const std::vector<point>> pts = donat->getPointsOfShapePtr();


    QPainter p;
    p.begin(this);
    for(point p2:*pts){
        p.setPen(p2.color);
        p.drawPoint(p2.x,p2.y);
    }
    p.end();
}

ColorIndicator::~ColorIndicator()
{

}
