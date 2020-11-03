// Copyright (c) 2020 Govind Ajith Kumar, Justin Albrecht, Pradeep Gopal

#include <gtest/gtest.h>
#include <controller.hpp>
#include <robot.hpp>

TEST(Controller_Test1, ComputeErrorTest) {
    Robot robot;
    Controller controller(robot);

    controller.setTargets(10, 10);

    EXPECT_EQ(controller.computeError(5, 5), std::make_tuple(5, 5));
}

TEST(Controller_Test2, ComputeSteeringTest) {
    Robot robot;
    Controller controller(robot);

    controller.setTargets(10, 10);
    controller.computeError(5, 5);

    EXPECT_NEAR(controller.computeSteering(), 0.785, .001);
}

TEST(Controller_Test3, ComputeThrottleTest) {
    Robot robot;
    Controller controller(robot);

    controller.setTargets(10, 10);
    controller.computeError(5, 5);

    EXPECT_NEAR(controller.computeThrottle(), 0.251, .001);
}


