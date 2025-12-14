#pragma once
#include "basicTypes.h"
#include "intervalConditions.h"

class ConditionDefiner{
    public:
        virtual std::shared_ptr<IntervalConditions> defineCondition(double leftValue, double rightValue) const = 0;
};


class CyclicRangeConditionDefiner:public ConditionDefiner{
    public:
        std::shared_ptr<IntervalConditions> defineCondition(double leftValue, double rightValue) const override;
};