class ColorSetter{
    public:
        virtual void colorize(std::vector<point> & pointsOfShape, Shape &shape) = 0;
};


class Shape{
    protected:
        std::vector<point> shape;
        virtual bool checkSetterType(ColorSetter& setter) = 0;
    public:
        Shape(std::vector<point> shape);
        const std::shared_ptr<std::vector<point>> getPointsOfShapePtr(); 
        void setColor(ColorSetter& setter);
};

class ShapeCreator{
    public:
        virtual std::shared_ptr<Shape> create() = 0;
};
