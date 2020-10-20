#pragma once
#include <vector>

/**
 * @brief      This class describes an user interface to input the desired
 * 				velocity and the heading
 */	
class UserInterface{
private:
	double target_velocity;//target velocity wished by the user for the robot
	double target_heading;//target heading wished by the user for the robot
public:
	// UserInterface(){};
	/**
 * @brief      Gets the targets from the user
 
 * @return     Outputs the targets as a vector of doubles
 */
	std::vector<double> getTargets();
};

