#include <analysis.hpp>
#include <robot.hpp>
#include <userinterface.hpp>
#include <controller.hpp>
#include <visualization.hpp>
#include <iostream>

/**
 * @brief      shows the convergence from set points to the desired points 
 */
void Analysis::converge(){

    UserInterface ui;
    Visualization viz;
    ui.getTargetsFromUser();

    Robot robot;
    Controller cont = Controller(robot);

    cont.setTargets(ui.getTargetSpeed(),ui.getTargetHeading());

    double throttle;
    double steering_angle;

    std::tuple<double,double> errors;

    while (true){
        errors = cont.computeError(robot.getSpeed(),robot.getHeading());

        throttle = cont.computeThrottle();
        steering_angle = cont.computeSteering();

        std::cout << "Throttle: " << throttle << std::endl;
        std::cout << "Gamma: " << steering_angle << std::endl;

        robot.drive(throttle,steering_angle,cont.getDt());

        if ((std::get<0>(errors) <= speed_thresh) && (std::get<1>(errors) <= heading_thresh)){
            break;
        }

    viz.show(robot.getSpeed(),robot.getHeading(), ui);
    }
	
}