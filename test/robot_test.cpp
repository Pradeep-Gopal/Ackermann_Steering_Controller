#include <gtest/gtest.h>
#include <robot.hpp>

TEST(Robot_Test1,getSpeedTest){
    Robot robot;

    EXPECT_EQ(robot.getSpeed(),0);
}

TEST(Robot_Test2,getHeadingTest){
    Robot robot;

    EXPECT_EQ(robot.getHeading(),0);
}

TEST(Robot_Test3,driveTest){
    Robot robot;

    std::vector<double> values {0.0435704,0.00120946,0.0790541,0.2};

    auto result = robot.drive(1,0.524,.1);

    EXPECT_NEAR(result[0],values[0], 0.001);
    EXPECT_NEAR(result[1],values[1], 0.001);
    EXPECT_NEAR(result[2],values[2], 0.001);
    EXPECT_NEAR(result[3],values[3], 0.001);
}

