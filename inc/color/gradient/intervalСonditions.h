#pragma once
#include "basicTypes.h"


class IntervalConditions{
    protected:
        const double leftValue;
        const double rightValue;
    public:
        IntervalConditions(double leftValue, double rightValue);
        virtual bool checkPointForCondition(const double &value) const = 0;
};

class IntervalConditionsFactory{
    public:
        virtual std::shared_ptr<IntervalConditions> createCondition(double leftValue, double rightValue) const = 0;
};




class FromLessToGreaterIntervalConditions : public IntervalConditions{
public:
    FromLessToGreaterIntervalConditions(double leftValue, double rightValue);
    bool checkPointForCondition(const double &value) const override;
};

class FromLessToGreaterIntervalConditionsFactory : public IntervalConditionsFactory{
public:
    std::shared_ptr<IntervalConditions> createCondition(double leftValue, double rightValue) const override;
};




class ExceptingFromLessToGreaterIntervalConditions : public IntervalConditions{
public:
    ExceptingFromLessToGreaterIntervalConditions(double leftValue, double rightValue);
    bool checkPointForCondition(const double &value) const override;
};

class ExceptingFromLessToGreaterIntervalConditionsFactory : public IntervalConditionsFactory{
    public:
        std::shared_ptr<IntervalConditions> createCondition(double leftValue, double rightValue) const override;
};


class ConditionDefiner{
    public:
        virtual std::shared_ptr<IntervalConditions> defineCondition(double leftValue, double rightValue) const = 0;
};


class CyclicRangeConditionDefiner:public ConditionDefiner{
    public:
        std::shared_ptr<IntervalConditions> defineCondition(double leftValue, double rightValue) const override;
};