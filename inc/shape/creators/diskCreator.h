#include "basicTypes.h"
#include "lineCreator.h"
#include "filler.h"
#include "disk.h"

class DiskCreator: public ShapeCreator{
protected:
    uint16_t xCenter;
    uint16_t yCenter;
    uint16_t radius;
    CircleOutlineCreator circleOutlineCr;
    SolidFiller filler;

public:
    DiskCreator(uint16_t xc, uint16_t yc, uint16_t r);
    void setParametrs(uint16_t xc, uint16_t yc, uint16_t r);
    void sertCenterX(uint16_t xc);
    void sertCenterY(uint16_t yc);
    void sertRaduis(uint16_t xc);
    std::shared_ptr<Shape> create() override;
};