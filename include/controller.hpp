#pragma once
#include <vector>
#include <tuple>
#include "userinterface.hpp"
#include "robot.hpp"
/**
 * @brief      Class that comprises of the two 
 * 				PID Controllers for speed and heading.
 */

class Controller{
private:
	double max_steering_angle = 0.785398;// maximum steering angle of the vehicle for turn (45 deg)
	double max_throttle;// max_throttle as a normalized value
	double k_p_theta = .5;//Proportional error constant for Theta
	double k_i_theta = .001;//Integral error constant for Theta
	double k_d_theta = .01;//Derivative error constant for Theta
	double k_p_s = .05;//Proportional error constant for Speed
	double k_i_s = .001;//Integral error constant for Speed
	double k_d_s = .1;//Derivative error constant for Speed
	std::vector<double> heading_error;//Vector holding the heading error
	std::vector<double> speed_error;//Vector holding the Speed error
	double target_speed = 0;//target speed wished by the user for the robot
	double target_heading = 0;//target heading wished by the user for the robot
	double dt = .1; //tick rate for the controller
public:
	 explicit Controller(Robot& robot);
//	 Controller() = delete;

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
	 * @brief      Calculates the speed and heading error and updates
	 *              in the private variables
	 *
	 * @param[in]  speed    The speed
	 * @param[in]  heading  The heading
	 *
	 * @return     The error as a tuple 
	 */
	std::tuple<double,double> computeError(double, double);

	/**
	 *
	 * @return
	 */
	double getDt();
};

