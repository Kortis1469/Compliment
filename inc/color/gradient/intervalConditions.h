#pragma once
#include "basicTypes.h"


class IntervalConditions{
    protected:
        const double leftValue;
        const double rightValue;
    public:
        IntervalConditions(double leftValue, double rightValue):
        leftValue(leftValue),
        rightValue(rightValue)
        {}

        virtual bool checkPointForCondition(const double &value) const = 0;
};

class FromLessToGreaterIntervalConditions : public IntervalConditions{
public:
    FromLessToGreaterIntervalConditions(double leftValue, double rightValue):IntervalConditions(leftValue,rightValue){}
    bool checkPointForCondition(const double &value) const override;
};


class ExceptingFromLessToGreaterIntervalConditions : public IntervalConditions{
public:
    ExceptingFromLessToGreaterIntervalConditions(double leftValue, double rightValue):IntervalConditions(leftValue,rightValue){}
    bool checkPointForCondition(const double &value) const override;
};

