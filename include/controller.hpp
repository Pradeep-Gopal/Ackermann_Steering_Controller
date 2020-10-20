#pragma once

/**
 * @brief      Class that comprises of the two 
 * 				PID Controllers for speed and heading.
 */
class Controller{
private:
	double max_steering_angle;// maximum steering angle of the vehicle for turn
	double max_throttle;// max_throttle as a normalized value
	double k_p_theta;//Proportional error constant for Theta
	double k_i_theta;//Integral error constant for Theta
	double k_d_theta;//Derivative error constant for Theta
	double k_p_s;//Proportional error constant for Speed
	double k_i_s;//Integral error constant for Speed
	double k_d_s;//Derivative error constant for Speed
	std::vector<double> heading_error;//Vector holding the heading error
	std::vector<double> speed_error;//Vector holding the Speed error
public:
	// Controller(){};
	/**
 * @brief      Calculates the steering angle
 *
 * @param[in]  throttle        The throttle
 * @param[in]  steering_angle  The steering angle
 *
 * @return     The steering
 */
	double computeSteering(double ,double);
	/**
 * @brief      Calculates the new throttle angle.
 *
 * @param[in]  throttle        The throttle given by the user to the vehicle
 * @param[in]  steering_angle  The steering angle for direction change
 *
 * @return     The throttle as a normalized value
 */
	double computeThrottle(double, double);
	/**
 * @brief      Calculates the totla speed and heading error and updates
 * 				in the private variables
 *
 * @param[in]  speed    The speed
 * @param[in]  heading  The heading
 */
	void computeError(double, double);
};

