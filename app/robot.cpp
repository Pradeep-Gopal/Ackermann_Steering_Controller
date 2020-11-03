// Copyright (c) 2020 Govind Ajith Kumar, Justin Albrecht, Pradeep Gopal

#include <cmath>
#include <iostream>
#include <robot.hpp>

#define PI 3.14159265

/**
 * @brief      The function to drive the robot and move it forwards
 *
 * @param[in]  throttle        The throttle
 * @param[in]  steering_angle  The steering angle
 */
std::vector<double> Robot::drive(double throttle,
                                 double steering_angle, double t) {
    char turn;
    double R;
    double R1;
    double delta_theta = 0;
    double new_speed = 0;

    if (steering_angle > 0)
        turn = 'L';
    else if (steering_angle < 0)
        turn = 'R';
    else
        turn = 'S';

    switch (turn) {
        default:
            std::cout << "Not a valid steering angle" << std::endl;

        case 'L':
//            std::cout << "Turning left" << std::endl;
            R = sqrt(pow(com_offset, 2) + (pow(wheel_base, 2)
                    * pow((1 / tan(steering_angle)), 2)));
            R1 = sqrt(pow(R, 2) - pow(com_offset, 2));
            left_wheel_angle = atan(wheel_base / (R1 - (wheel_track / 2)));
            right_wheel_angle = atan(wheel_base / (R1 + (wheel_track / 2)));
            right_wheel_velocity += throttle;
            delta_theta = (wheel_radius * right_wheel_velocity * t)
                    / (R1 + (wheel_track / 2));
            left_wheel_velocity = (delta_theta * (R1 - (wheel_track / 2)))
                    / (wheel_radius * t);
            new_speed = std::abs((R * delta_theta) / t);
            break;
        case 'R':
//            std::cout << "Turning right" << std::endl;
            R = sqrt(pow(com_offset, 2) + (pow(wheel_base, 2)
                    * pow((1 / tan(-steering_angle)), 2)));
            R1 = sqrt(pow(R, 2) - pow(com_offset, 2));
            right_wheel_angle = atan(wheel_base / (R1 - (wheel_track / 2)));
            left_wheel_angle = atan(wheel_base / (R1 + (wheel_track / 2)));
            left_wheel_velocity += throttle;
            delta_theta = -(wheel_radius * left_wheel_velocity * t)
                    / (R1 + (wheel_track / 2));
            right_wheel_velocity = (delta_theta * (R1 - (wheel_track / 2)))
                    / (wheel_radius * t);
            new_speed = std::abs((R * delta_theta) / t);
            break;
        case 'S':
//            std::cout << "Going straight" << std::endl;
            right_wheel_angle = 0;
            left_wheel_angle = 0;
            if (left_wheel_velocity >= right_wheel_velocity) {
                left_wheel_velocity += throttle;
                right_wheel_velocity = left_wheel_velocity;
            } else {
                right_wheel_velocity += throttle;
                left_wheel_velocity = right_wheel_velocity;
            }
            new_speed = right_wheel_velocity*wheel_radius;
            break;
    }
    heading += delta_theta;
    speed = new_speed;
    return std::vector<double> {speed, heading,
                                left_wheel_velocity, right_wheel_velocity};
}

double Robot::getSpeed() const {
    return speed;
}

double Robot::getHeading() const {
    return heading;
}

double Robot::getAlphaWheelMax() const {
    return alpha_wheel_max;
}

