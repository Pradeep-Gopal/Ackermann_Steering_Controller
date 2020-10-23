#pragma once
#include <vector>
#include "userinterface.hpp"
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
	double target_speed;//target speed wished by the user for the robot
	double target_heading;//target heading wished by the user for the robot
	double dt = .1; //tick rate for the controller
public:
	// Controller(){};

	/**
	 * @brief      Sets the targets.
	 *
	 * @param[in]  th target heading
	 * @param[in]  ts target speed
	*/
	void setTargets(double,double);
	
	/**
	 * @brief      Calculates the steering angle
	 *
	 * @return     The steering
	 */
	double computeSteering();
	
	/**
	 * @brief      Calculates the new throttle angle.
	 *
	 * @return     The throttle as a normalized value
	 */
	double computeThrottle();
	
	/**
	 * @brief      Calculates the totla speed and heading error and updates
	 * 				in the private variables
	 *
	 * @param[in]  speed    The speed
	 * @param[in]  heading  The heading
	 */
	void computeError(double, double);
};

