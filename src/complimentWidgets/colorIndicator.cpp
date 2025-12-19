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
        QPoint position =  event->globalPos() - dragOffset;
        if (!isValidArea(position)) biasToRadius(position);
        move(position);
    }
}

bool ColorIndicator::isValidArea(QPoint offset)
{ 
    int position = VectorLenCalculator::calculateVectorLen({offset.x(),offset.y()},{xCenter,yCenter});
    return position <= radiusAlign;
}
void ColorIndicator::biasToRadius(QPoint& position)
{
    double len = VectorLenCalculator::calculateVectorLen({position.x(),position.y()},{xCenter,yCenter});
    QPoint center(xCenter, yCenter);
    QPointF relativePosition = position - center;

    relativePosition *= radiusAlign;
    relativePosition /= len;
    position = center + relativePosition.toPoint();

    position.setX(position.x()-radius);
    position.setY(position.y()-radius);
}
ColorIndicator::ColorIndicator(QWidget *parent, int32_t xCenter, int32_t yCenter, int32_t radius, int32_t innerRadius) : QWidget(parent), width(radius * 2), height(radius * 2)
{
    this->radius = radius;
    this->xCenter = xCenter;
    this->yCenter = yCenter;
    resize(radius*2, radius*2);
    
    DonatCreator creator(radius,radius, radius,innerRadius);
    std::shared_ptr<Shape> donat = creator.create();

    move(xCenter-radius,yCenter-radius);

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
    this->radiusAlign = radius;//+this->radius/2;
    move(xCenter-this->radius,yCenter-this->radius);
}


ColorIndicator::~ColorIndicator()
{

}
