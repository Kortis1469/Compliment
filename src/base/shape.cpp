#include "shape.h"
#include "basicTypes.h"




Shape::Shape(std::vector<point> shape)
{
    this->shape = shape;
}

std::shared_ptr<const std::vector<point>> Shape::getPointsOfShapePtr() const
{
    return std::make_shared<std::vector<point>>(shape);
}
void Shape::setColor(const ColorSetter& setter)
{
    setter.colorize(shape, *this);
}

