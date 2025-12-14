#include "conditionDefiner.h"
#include "intervalConditionsFactories.h"


std::shared_ptr<IntervalConditions> CyclicRangeConditionDefiner::defineCondition(double leftValue, double rightValue) const
{
    std::shared_ptr<IntervalConditionsFactory> conditionFactory;
    if(leftValue<rightValue)
        conditionFactory = std::make_shared<FromLessToGreaterIntervalConditionsFactory>();

    else
        conditionFactory = std::make_shared<ExceptingFromLessToGreaterIntervalConditionsFactory>();

    return conditionFactory->createCondition(leftValue,rightValue);
}

