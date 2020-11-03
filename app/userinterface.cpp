#include <userinterface.hpp>
#include <iostream>

#define PI 3.14159265

/**
 * @brief      Gets the targets from the user and stores them in the corresponding attributes
 
 * @return     None
 */
void  UserInterface::getTargetsFromUser() {
    std::cout << "Enter the target heading (in degrees): ";
    double target_heading_deg;
    std::cin >> target_heading_deg;
    if(target_heading_deg < 0)
        target_heading_deg = 360 - abs(target_heading_deg);
    target_heading = (target_heading_deg*PI)/180;
    std::cout << "Enter the target speed (in m/s): ";
    std::cin >> target_speed;

    // std::cout << target_heading << " " << target_speed << std::endl;
}

/**
 * @brief      Gets the target speed.
 *
 * @return     The target speed.
 */
double UserInterface::getTargetSpeed(){
    return target_speed;
}

/**
 * @brief      Gets the target heading.
 *
 * @return     The target heading.
 */
double UserInterface::getTargetHeading(){
    return target_heading;
}


