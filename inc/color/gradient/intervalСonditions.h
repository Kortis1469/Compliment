#pragma once
#include "basicTypes.h"


class IntervalConditions{
    protected:
        const double leftValue;
        const double rightValue;
    public:
        IntervalConditions(double leftValue, double rightValue);
        virtual bool checkPointForCondition(const double &value) = 0;
};

class IntervalConditionsFactory{
    public:
        virtual std::shared_ptr<IntervalConditions> createCondition(double leftValue, double rightValue);
};




class FromLessToGreaterIntervalConditions : public IntervalConditions{
public:
    FromLessToGreaterIntervalConditions(double leftValue, double rightValue);
    bool checkPointForCondition(const double &value) override;
};

class FromLessToGreaterIntervalConditionsFactory : public IntervalConditionsFactory{
public:
    std::shared_ptr<IntervalConditions> createCondition(double leftValue, double rightValue) override;
};




class ExceptingFromLessToGreaterIntervalConditions : public IntervalConditions{
public:
    ExceptingFromLessToGreaterIntervalConditions(double leftValue, double rightValue);
    bool checkPointForCondition(const double &value) override;
};

class ExceptingFromLessToGreaterIntervalConditionsFactory : public IntervalConditionsFactory{
    public:
        std::shared_ptr<IntervalConditions> createCondition(double leftValue, double rightValue) override;
};


class ConditionDefiner{
    public:
        virtual std::shared_ptr<IntervalConditions> defineCondition(double leftValue, double rightValue) = 0;
};


class CyclicRangeConditionDefiner:public ConditionDefiner{
    private:
        std::shared_ptr<IntervalConditionsFactory> conditionFactory;
    public:
        std::shared_ptr<IntervalConditions> defineCondition(double leftValue, double rightValue) override;
};