#include "gradientCreator.h"

class IttentGradientCreator{
protected:
    GradientPointColorSubtractor
        red,
        blue,
        green;

public:
    IttentGradientCreator(ColorSettings red, ColorSettings blue, ColorSettings green);
    void colorizeWithGradient(std::vector<point> &circle, point pCenter, int r) const;
};