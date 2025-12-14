#include "intervalConditions.h"

class IntervalConditionsFactory{
    public:
        virtual std::shared_ptr<IntervalConditions> createCondition(double leftValue, double rightValue) const = 0;
};

class FromLessToGreaterIntervalConditionsFactory : public IntervalConditionsFactory{
public:
    std::shared_ptr<IntervalConditions> createCondition(double leftValue, double rightValue) const override;
};

class ExceptingFromLessToGreaterIntervalConditionsFactory : public IntervalConditionsFactory{
    public:
        std::shared_ptr<IntervalConditions> createCondition(double leftValue, double rightValue) const override;
};
