#include "colorIndicator.h"

void ColorIndicator::mousePressEvent(QMouseEvent *event)
 {
         if (event->button() == Qt::LeftButton) {
            dragOffset = event->globalPos() - frameGeometry().topLeft();
        }
}

void ColorIndicator::mouseMoveEvent(QMouseEvent *event)
{
    if (event->buttons() & Qt::LeftButton)
    {
        if(isValidArea(dragOffset)) move(event->globalPos() - dragOffset);
    }
}

bool ColorIndicator::isValidArea(QPoint offset)
{
    int offsetVec = VectorLenCalculator::calculateVectorLen({offset.x(),offset.y()},{xCenter,yCenter});
    return offsetVec <= radius;
}
ColorIndicator::ColorIndicator(QWidget *parent, uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2) : QWidget(parent), width(abs(x2 - x1)), height(abs(y2 - y1))
{
    radius = width<height ? width: height;
    resize(radius*2, radius*2);
    move(x1,y1);
    DonatCreator creator(width/2,height/2,10,8);
    std::shared_ptr<Shape> donat = creator.create();
    indicator = donat->getPointsOfShapePtr();
}

void ColorIndicator::paintEvent(QPaintEvent *event){
   
    QPainter p(this);
    for(point p2:*indicator){
        p.setPen(p2.color);
        p.drawPoint(p2.x,p2.y);
    }
    
}

void ColorIndicator::alignToRadius(uint16_t xCenter, uint16_t yCenter, uint16_t radius)
{
    this->xCenter = xCenter;
    this->yCenter = yCenter;
    this->radius = radius;
    move(xCenter,yCenter);
}


ColorIndicator::~ColorIndicator()
{

}
