// Copyright (c) 2020 Govind Ajith Kumar, Justin Albrecht, Pradeep Gopal
#include <controller.hpp>
/**
 * @brief User Defined Constructor
 *
 * @param robot
 */
Controller::Controller(Robot &robot) {
    max_throttle = robot.getAlphaWheelMax()*dt;
}

/**
 * @brief      Sets the targets.
 *
 * @param[in]  ts    The target speed
 * @param[in]  th    The target heading
 *
 */
void Controller::setTargets(double ts, double th) {
    target_speed = ts;
    target_heading = th;
}

/**
 * @brief      Calculates the steering angle
 *
 * @param[in]  throttle        The throttle
 * @param[in]  steering_angle  The steering angle
 *
 * @return     The steering
 */
double Controller::computeSteering() {
    double p_gain = k_p_theta * heading_error.end()[-1];

    double sum = 0;
    for (auto err : heading_error) {
        sum += err * dt;
    }
    double i_gain = k_i_theta * sum;

    double d_gain;
    if (heading_error.size() < 2)
        d_gain = 0;
    else
        d_gain = k_d_theta * ((heading_error.end()[-1]-
                heading_error.end()[-2])/dt);

    double gamma = p_gain+i_gain+d_gain;

    if (gamma > max_steering_angle) {
        gamma = max_steering_angle;
    } else if (gamma < -max_steering_angle) {
        gamma = -max_steering_angle;
    }

    return gamma;
}

/**
 * @brief      Calculates the new throttle angle.
 *
 * @param[in]  throttle        The throttle given by the user to the vehicle
 * @param[in]  steering_angle  The steering angle for direction change
 *
 * @return     The throttle as a normalized value
 */
double Controller::computeThrottle() {
    double p_gain = k_p_s * speed_error.end()[-1];
    double sum = 0;
    for (auto err : speed_error) {
        sum += err * dt;
    }
    double i_gain = k_i_s * sum;

    double d_gain;
    if (speed_error.size() < 2)
        d_gain = 0;
    else
        d_gain = k_d_s * ((speed_error.end()[-1]-speed_error.end()[-2])/dt);

    double throttle = p_gain+i_gain+d_gain;

    if (throttle > max_throttle) {
        throttle = max_throttle;
    } else if (throttle < -max_throttle) {
        throttle = -max_throttle;
    }

    return throttle;
}

/**
 * @brief      Calculates the speed and heading error and updates
 *              in the private variables
 *
 * @param[in]  speed    The speed
 * @param[in]  heading  The heading
 *
 * @return     The error as a tuple 
 */
std::tuple<double, double> Controller::computeError(double speed,
                                                   double heading) {
    double cur_speed_error = target_speed - speed;
    double cur_heading_error = target_heading - heading;

    speed_error.push_back(cur_speed_error);
    heading_error.push_back(cur_heading_error);

    return std::make_tuple(cur_speed_error, cur_heading_error);
}

double Controller::getDt() {
    return dt;
}
