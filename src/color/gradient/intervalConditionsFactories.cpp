#include "intervalConditionsFactories.h"

std::shared_ptr<IntervalConditions> FromLessToGreaterIntervalConditionsFactory::createCondition(double leftValue, double rightValue) const
{
    std::shared_ptr<IntervalConditions> ptr(new FromLessToGreaterIntervalConditions(leftValue,rightValue));
    return ptr;
}

std::shared_ptr<IntervalConditions> ExceptingFromLessToGreaterIntervalConditionsFactory::createCondition(double leftValue, double rightValue) const
{
    std::shared_ptr<IntervalConditions> ptr(new ExceptingFromLessToGreaterIntervalConditions(leftValue,rightValue));
    return ptr;
}

