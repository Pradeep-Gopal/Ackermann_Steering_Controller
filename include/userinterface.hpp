#pragma once
#include <vector>

/**
 * @brief      This class describes an user interface to input the desired
 * 				speed and the heading
 */	
class UserInterface{
private:
	double target_speed;//target speed wished by the user for the robot
	double target_heading;//target heading wished by the user for the robot
public:
	// UserInterface(){};
	/**
 * @brief      Gets the targets from the user and stores them in the corresponding attributes
 
 * @return     None
 */
	void getTargets();
};

