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
ColorIndicator::ColorIndicator(QWidget *parent, int32_t radius, int32_t innerRadius, Circle * circle, QLabel * output) : QWidget(parent), width(radius * 2), height(radius * 2)
{
    alignToColorCircle(circle);
    setColorOutput(output);
    this->radius = radius;
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
    updateOutput();
}

void ColorIndicator::alignToColorCircle(Circle *c)
{
    circle=c;
    alignToRadius(circle->getXCenter(), circle->getYCenter(), circle->getRadius());
}

void ColorIndicator::alignToRadius(uint16_t xCenter, uint16_t yCenter, uint16_t radius)
{
    this->xCenter = xCenter;
    this->yCenter = yCenter;
    this->radiusAlign = radius;
    move(xCenter-this->radius,yCenter-this->radius);
}

void ColorIndicator::setColorOutput(QLabel *label)
{
    this->label = label;
}

QPoint ColorIndicator::getActualCenter() const
{   
    QPoint center = this->pos();
    center.setX(center.x()+radius);
    center.setY(center.y()+radius);
    return center;
}

QColor ColorIndicator::getColorFromCenterPix()
{
    QPoint p = getActualCenter();
    QColor colorCenter = circle->getColorFromPix({p.x(),p.y()});
    return colorCenter;
}

void ColorIndicator::updateOutput()
{   
    QColor c = getColorFromCenterPix();
    std::string s = std::to_string(c.red()) + " " + std::to_string(c.green()) + " " + std::to_string(c.blue()); 
    label->setText(QString::fromStdString(s));
}

ColorIndicator::~ColorIndicator()
{

}
