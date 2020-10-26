#include <gtest/gtest.h>
#include <controller.hpp>

TEST(Controller_Test1,ComputeErrorTest){
    Controller controller;

    controller.setTargets(10,10);

    EXPECT_EQ(controller.computeError(5,5),std::make_tuple(5,5));
}


