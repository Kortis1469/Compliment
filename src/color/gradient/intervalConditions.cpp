#include "intervalConditions.h"


bool FromLessToGreaterIntervalConditions::checkPointForCondition(const double &value) const
{
    return (value>=leftValue && value<=rightValue);
}


bool ExceptingFromLessToGreaterIntervalConditions::checkPointForCondition(const double &value) const
{
    return (value>=leftValue || value<=rightValue);
}

