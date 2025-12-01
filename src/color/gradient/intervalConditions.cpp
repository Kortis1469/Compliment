#include "intervalСonditions.h"


IntervalConditions::IntervalConditions(double leftValue, double rightValue):
    leftValue(leftValue),
    rightValue(rightValue)
{

}

FromLessToGreaterIntervalConditions::FromLessToGreaterIntervalConditions(double leftValue, double rightValue):IntervalConditions(leftValue,rightValue){

}

bool FromLessToGreaterIntervalConditions::checkPointForCondition(const double &value)
{
    return (value>=leftValue && value<=rightValue);
}

ExceptingFromLessToGreaterIntervalConditions::ExceptingFromLessToGreaterIntervalConditions(double leftValue, double rightValue):IntervalConditions(leftValue,rightValue){

}

bool ExceptingFromLessToGreaterIntervalConditions::checkPointForCondition(const double &value)
{
    return (value>=leftValue || value<=rightValue);
}

std::shared_ptr<IntervalConditions> FromLessToGreaterIntervalConditionsFactory::createCondition(double leftValue, double rightValue){
    std::shared_ptr<IntervalConditions> ptr(new FromLessToGreaterIntervalConditions(leftValue,rightValue));
    return ptr;
}

std::shared_ptr<IntervalConditions> ExceptingFromLessToGreaterIntervalConditionsFactory::createCondition(double leftValue, double rightValue)
{
    std::shared_ptr<IntervalConditions> ptr(new ExceptingFromLessToGreaterIntervalConditions(leftValue,rightValue));
    return ptr;
}

std::shared_ptr<IntervalConditions> CyclicRangeConditionDefiner::defineCondition(double leftValue, double rightValue)
{
    if(leftValue<rightValue)
        conditionFactory = std::make_shared<FromLessToGreaterIntervalConditionsFactory>();

    else
        conditionFactory = std::make_shared<ExceptingFromLessToGreaterIntervalConditionsFactory>();

    return conditionFactory->createCondition(leftValue,rightValue);
}

std::shared_ptr<IntervalConditions> IntervalConditionsFactory::createCondition(double leftValue, double rightValue)
{
    return nullptr;
}
