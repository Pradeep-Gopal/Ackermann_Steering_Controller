#include <controller.hpp>
/**
 * @brief      Calculates the steering angle
 *
 * @param[in]  throttle        The throttle
 * @param[in]  steering_angle  The steering angle
 *
 * @return     The steering
 */
double Controller::computeSteering(double throttle,double steering_angle){
}

/**
 * @brief      Calculates the new throttle angle.
 *
 * @param[in]  throttle        The throttle given by the user to the vehicle
 * @param[in]  steering_angle  The steering angle for direction change
 *
 * @return     The throttle as a normalized value
 */
double Controller::computeThrottle(double throttle,double steering_angle){
}

/**
 * @brief      Calculates the totla speed and heading error and updates
 * 				in the private variables
 *
 * @param[in]  speed    The speed
 * @param[in]  heading  The heading
 */
void Controller::computeError(double speed, double heading){
    
}
