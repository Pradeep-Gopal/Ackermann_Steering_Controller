#pragma once

/**
 * @brief      This the Plant for the controller, which is the vehicle.
 */
class Robot{
private:
	double wheel_base;//wheel base of the vehicle
	double wheel_track;//wheel track of the vehicle
	double wheel_radius;//the wheel radius on all the 4 corners
	double robot_heading;//direction in which the robot is heading
	double robot_velocity;//the velocity of the robot
	double inner_wheel_velocity;//inner wheel's velocity
	double outer_wheel_velocity;//outer wheel's velocity
	double com_offset;//Complete offset
public:
	// Robot(){};
	/**
 * @brief      The function to drive the robot and move it forwards
 *
 * @param[in]  throttle        The throttle
 * @param[in]  steering_angle  The steering angle
 */
	void drive(double ,double);
};


