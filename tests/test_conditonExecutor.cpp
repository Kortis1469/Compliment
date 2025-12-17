#include "conditionExecutor.h"
#include <gtest/gtest.h>


//  ColorSettings 
//         redSettings(-PI/3, 2*PI/3, PI/3, PI/3),
//         greenSettings(2*PI/3, PI/6, 5*PI/6, PI/6),
//         blueSettings(PI/6, -PI/3, PI/6, PI/3);

TEST(ConditionTest, Range){
    angle angleGrid = PI/6;
    double len = PI/6;
    
    int color;
    ResidualInfluenseZoneExecutor residualExecutor;
    for (double i = angleGrid; i <= angleGrid+len; i+=0.01){
        color = residualExecutor.execute(i, angleGrid, len);
        EXPECT_GT(color, 0);
    }
}