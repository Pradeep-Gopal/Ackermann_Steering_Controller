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
//    ui.getTargetsFromUser();

    Controller cont;
    cont.setTargets(10,10);
    cont.computeError(5,5);

    std::cout << "Throttle: " << cont.computeThrottle() << std::endl;

//    Robot robot;
//
//    double throttle;
//    double steering_angle;
//
//    std::tuple<double,double> errors;

//    while (true){
//        errors = cont.computeError(robot.getSpeed(),robot.getHeading());
//
//        throttle = cont.computeThrottle();
//        steering_angle = cont.computeSteering();
//        robot.drive(throttle,steering_angle);


//        if ((std::get<0>(errors) <= speed_thresh) && (std::get<1>(errors) <= heading_thresh)){
//            break;
//        }

//    viz.show(robot.getSpeed(),robot.getHeading(), ui);
//    }
	
}