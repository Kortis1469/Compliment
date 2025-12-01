#include "shape.h"
#include "basicTypes.h"




Shape::Shape(std::vector<point> shape)
{
    this->shape = shape;
}

const std::shared_ptr<std::vector<point>> Shape::getPointsOfShapePtr()
{
    return std::make_shared<std::vector<point>>(shape);
}
void Shape::setColor(ColorSetter& setter)
{
    setter.colorize(shape, *this);
}

