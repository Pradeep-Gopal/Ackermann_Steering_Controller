// Copyright (c) 2020 Govind Ajith Kumar, Justin Albrecht, Pradeep Gopal

#include <iostream>
#include <iomanip>
#include <visualization.hpp>

#define PI 3.14159265

/**
 * @brief      Shows the visualization
 *
 * @param[in]  speed    The speed of the robot
 * @param[in]  heading  The heading of the robot
 */
void Visualization::show(double speed, double heading,
                         double time, UserInterface& ui) {
    std::cout << "Current Time: " << time << " (sec)" << std::endl;

    std::cout << "Current Speed: " << std::setprecision(3)
    << speed << " (m/s)" << " | Target Speed: " << ui.getTargetSpeed()
    << " (m/s)" <<  std::endl;

    std::cout << "Current Heading: " << std::setprecision(4)
    << (heading*180)/PI << " (deg)" << " | Target Heading: "
    << (ui.getTargetHeading()*180)/PI << " (deg)" << "\n" << std::endl;
}
