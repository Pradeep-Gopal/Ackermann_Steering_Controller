#include <visualization.hpp>
#include <iostream>

#define PI 3.14159265

/**
 * @brief      Shows the visualization
 *
 * @param[in]  speed    The speed of the robot
 * @param[in]  heading  The heading of the robot
 */
void Visualization::show(double speed,double heading, UserInterface& ui){
    std::cout << "Current Speed: " << speed
              << " | Target Speed: " << ui.getTargetSpeed() << std::endl;
    std::cout << "Current Heading: " << (heading*180)/PI
              << " | Target Heading: " << (ui.getTargetHeading()*180)/PI << "\n" << std::endl;
}