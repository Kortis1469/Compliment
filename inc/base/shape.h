#pragma once
#include <vector>
#include <memory>
#include "basicTypes.h"


class Shape;

class ColorSetter{
    public:
        virtual void colorize(std::vector<point> & pointsOfShape, Shape &shape) const = 0;
};


class Shape{
    protected:
        std::vector<point> shape;
        virtual bool checkSetterType(ColorSetter& setter) = 0;
    public:
        Shape(std::vector<point> shape);
        std::shared_ptr<const std::vector<point>> getPointsOfShapePtr() const; 
        void setColor(const ColorSetter& setter);
};

class ShapeCreator{
    public:
        virtual std::shared_ptr<Shape> create() = 0;
};
