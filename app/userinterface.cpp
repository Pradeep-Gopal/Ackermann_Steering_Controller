#include <userinterface.hpp>
#include <iostream>

#define PI 3.14159265

/**
 * @brief      Gets the targets from the user and stores them in the corresponding attributes
 
 * @return     None
 */
void  UserInterface::getTargets(){
    std::cout << "Enter the target heading (in degrees): ";
    double target_heading_deg;
    std::cin >> target_heading_deg;
    target_heading = (target_heading_deg*PI)/180;
    std::cout << "Enter the target speed (in m/s): ";
    std::cin >> target_speed;

    // std::cout << target_heading << " " << target_speed << std::endl;
}
