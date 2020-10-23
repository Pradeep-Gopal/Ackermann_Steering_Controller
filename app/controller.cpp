#include <controller.hpp>
#include <numeric>


/**
 * @brief      Sets the targets.
 *
 * @param[in]  ts    The target speed
 * @param[in]  th    The target heading
 *
 */
void Controller::setTargets(double ts,double th){
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
double Controller::computeSteering(){
    double prop_gain = k_p_theta * heading_error[-1];
    double int_gain = k_i_theta * (std::accumulate(heading_error.begin(), heading_error.end(),0)*dt*heading_error.size());
    double deriv_gain = k_d_theta * ((heading_error[-1]-heading_error[-2])/dt);

    double gain = prop_gain+int_gain+deriv_gain;

    return gain;
}

/**
 * @brief      Calculates the new throttle angle.
 *
 * @param[in]  throttle        The throttle given by the user to the vehicle
 * @param[in]  steering_angle  The steering angle for direction change
 *
 * @return     The throttle as a normalized value
 */
double Controller::computeThrottle(){
    double prop_gain = k_p_theta * speed_error[-1];
    double int_gain = k_i_theta * (std::accumulate(speed_error.begin(), speed_error.end(),0)*dt*speed_error.size());
    double deriv_gain = k_d_theta * ((speed_error[-1]-speed_error[-2])/dt);

    double gain = prop_gain+int_gain+deriv_gain;

    return gain;
}

/**
 * @brief      Calculates the totla speed and heading error and updates
 * 				in the private variables
 *
 * @param[in]  speed    The speed
 * @param[in]  heading  The heading
 */
void Controller::computeError(double speed, double heading){
    double cur_speed_error = target_speed - speed;
    double cur_heading_error = target_heading - heading;

    speed_error.push_back(cur_speed_error);
    heading_error.push_back(cur_heading_error);
}
