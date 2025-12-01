#include "basicTypes.h"
#include "disk.h"
class IttenGradientColorSetter:public ColorSetter{
    void colorize(std::vector<point> & pointsOfShape, Shape &shape) override;
};