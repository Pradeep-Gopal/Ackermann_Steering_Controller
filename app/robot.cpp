#include <robot.hpp>
#include <cmath> 
#include <iostream>
#include <gtest/gtest.h>

#define PI 3.14159265

/**
 * @brief      The function to drive the robot and move it forwards
 *
 * @param[in]  throttle        The throttle
 * @param[in]  steering_angle  The steering angle
 */
std::vector<double> Robot::drive(double throttle,double steering_angle){
    double R = sqrt(pow(com_offset, 2) + (pow(wheel_base, 2) * pow((1 / tan(steering_angle)), 2)));

    // std::cout  << "R: "<< R << std::endl;

    double R1 = sqrt(pow(R, 2) - pow(com_offset, 2));
    double alpha_i = atan(wheel_base / (R1 - (wheel_track / 2)));
    double alpha_o = atan(wheel_base / (R1 + (wheel_track / 2)));

    // std::cout << "alpha_i: " << (alpha_i*180)/PI << std::endl;
    // std::cout << "alpha_o: " << (alpha_o*180)/PI << std::endl;

    double k_t = .2;
    double dt = .1;

    double delta_w = k_t * throttle;

    outer_wheel_velocity += delta_w;

    double delta_theta = (wheel_radius * outer_wheel_velocity * dt) / (R1 + (wheel_track / 2));

    inner_wheel_velocity = (delta_theta * (R1 - (wheel_track / 2))) / (wheel_radius * dt);

    // std::cout << "inner_wheel_velocity: " << inner_wheel_velocity << std::endl;
    // std::cout << "outer_wheel_velocity: " << outer_wheel_velocity << std::endl;

    speed = (R * delta_theta) / dt;
    heading += delta_theta;

    // std::cout << "robot_speed: " << robot_speed << std::endl;
    // std::cout << "robot_heading: " << robot_heading << std::endl;

    return std::vector<double> {speed,heading,inner_wheel_velocity,outer_wheel_velocity};

}

double Robot::getSpeed(){
    return speed;
}

double Robot::getHeading(){
    return heading;
}

