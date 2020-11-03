#pragma once
#include <vector>

/**
 * @brief      This class describes an user interface to input the desired
 * 				speed and the heading
 */	
class UserInterface{
private:
	double target_speed = 0;//target speed wished by the user for the robot
	double target_heading = 0;//target heading wished by the user for the robot
public:
	// UserInterface(){};
/**
 * @brief      Gets the targets from the user and stores them in the corresponding attributes
 
 * @return     None
 */
	void getTargetsFromUser();

/**
 * @brief      Gets the target speed.
 *
 * @return     The target speed.
 */
    double getTargetSpeed() const;

/**
 * @brief      Gets the target heading.
 *
 * @return     The target heading.
 */
    double getTargetHeading() const;

};

