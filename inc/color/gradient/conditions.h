#include "basicTypes.h"
#include "conditionDefiner.h"

class Conditions{
    protected:
        std::shared_ptr<IntervalConditions> dominate;
        std::shared_ptr<IntervalConditions> rightResidual;
        std::shared_ptr<IntervalConditions> leftResidual;
    public:
        Conditions(ColorSettings settings);
        bool isDominate(angle ang);
        bool isRightResidual(angle ang);
        bool isLeftResidual(angle ang);
};