// Copyright (c) 2020 Govind Ajith Kumar, Justin Albrecht, Pradeep Gopal
#pragma once
#include <vector>

/**
 * @brief      This the Plant for the controller, which is the vehicle.
 */
class Robot{
 private:
    double wheel_base = 4;  // wheel base of the vehicle
    double wheel_track = 2;  // wheel track of the vehicle
    double wheel_radius = .3;  // the wheel radius on all the 4 corners
    double heading = 0;  // direction in which the robot is heading
    double speed = 0;  // the speed of the robot
    double left_wheel_velocity = 0;  // inner wheel's velocity
    double right_wheel_velocity = 0;  // outer wheel's velocity
    double left_wheel_angle = 0;
    double right_wheel_angle = 0;
    double com_offset = 1;  // Complete offset
    double alpha_wheel_max = 20;  // Maximum acceleration of the
                                  // wheel in rad/s^2

 public:
    // Robot(){};
    /**
     * @brief      The function to drive the robot and move it forwards
     *
     * @param[in]  throttle        The throttle
     * @param[in]  steering_angle  The steering angle
     * @param[in]  t              The amount of time to drive
     */
    std::vector<double> drive(double, double, double);

    /**
     * @brief      Gets the robot speed.
     *
     * @return     The robot speed.
     */
    double getSpeed() const;

    /**
     * @brief      Gets the robot heading.
     *
     * @return     The robot heading.
     */
    double getHeading() const;

    /**
     * @brief      Gets the max angular acceleration of the wheel.
     *
     * @return     The max angular acceleration of the wheel.
     */
    double getAlphaWheelMax() const;
};


