#pragma once

/**
 * @brief      This the Plant for the controller, which is the vehicle.
 */
class Robot{
private:
	double wheel_base = 2;//wheel base of the vehicle
	double wheel_track = 3;//wheel track of the vehicle
	double wheel_radius= .3;//the wheel radius on all the 4 corners
	double heading = 0;//direction in which the robot is heading
	double speed = 0;//the speed of the robot
	double inner_wheel_velocity = 0;//inner wheel's velocity
	double outer_wheel_velocity = 0;//outer wheel's velocity
	double com_offset = 1;//Complete offset
public:
	// Robot(){};
	/**
	 * @brief      The function to drive the robot and move it forwards
	 *
	 * @param[in]  throttle        The throttle
	 * @param[in]  steering_angle  The steering angle
	 */
	void drive(double ,double);
	
	/**
	 * @brief      Gets the robot speed.
	 *
	 * @return     The robot speed.
	 */
	double getSpeed();

	/**
	 * @brief      Gets the robot heading.
	 *
	 * @return     The robot heading.
	 */
	double getHeading();

};


