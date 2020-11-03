#include <analysis.hpp>
#include <robot.hpp>
#include <userinterface.hpp>
#include <controller.hpp>
#include <visualization.hpp>
#include <iostream>

/**
 * @brief      shows the convergence from set points to the desired points 
 */
void Analysis::converge() const{

    UserInterface ui;
    Visualization viz;
    ui.getTargetsFromUser();

    Robot robot;
    Controller cont = Controller(robot);

    cont.setTargets(ui.getTargetSpeed(),ui.getTargetHeading());

    double throttle;
    double steering_angle;

    double robot_time = 0;
    double dt = cont.getDt();

    std::tuple<double,double> errors;

    while (true){
        errors = cont.computeError(robot.getSpeed(),robot.getHeading());

        if (std::abs(std::get<0>(errors)) <= speed_thresh && std::abs(std::get<1>(errors)) <= heading_thresh)
            break;

        throttle = cont.computeThrottle();
        steering_angle = cont.computeSteering();

        robot.drive(throttle,steering_angle,cont.getDt());

        robot_time += dt;

        std::cout << "Throttle: " << throttle << std::endl;
        std::cout << "Steering Angle: " << steering_angle << std::endl;
        viz.show(robot.getSpeed(),robot.getHeading(), robot_time, ui);

//        if (robot_time > 40)
//            break;
    }
	
}