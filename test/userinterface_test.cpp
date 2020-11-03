// Copyright (c) 2020 Govind Ajith Kumar, Justin Albrecht, Pradeep Gopal

#include <gtest/gtest.h>
#include <userinterface.hpp>

TEST(UI_Test1, getTargetSpeedTest) {
    UserInterface ui;

    EXPECT_EQ(ui.getTargetSpeed(), 0);
}

TEST(UI_Test2, getTargetHeadingTest) {
    UserInterface ui;

    EXPECT_EQ(ui.getTargetHeading(), 0);
}

