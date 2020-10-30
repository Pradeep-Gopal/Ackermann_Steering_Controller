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
    ui.getTargets();

    Controller cont;
    cont.setTargets(ui.getTargetSpeed(),ui.getTargetHeading());

    Robot robot;

    double throttle;
    double steering_angle;

    std::tuple<double,double> errors;

//    while (true){
    errors = cont.computeError(robot.getSpeed(),robot.getHeading());

    throttle = cont.computeThrottle();
    steering_angle = cont.computeSteering();

//        robot.drive(throttle,steering_angle);
    auto values = robot.drive(1,0.524);

    std::cout << "Speed: " << values[0] << std::endl;
    std::cout << "Heading: " << values[1] << std::endl;
    std::cout << "IWV: " << values[2] << std::endl;
    std::cout << "OWV: " << values[3] << std::endl;


//        if ((std::get<0>(errors) <= speed_thresh) && (std::get<1>(errors) <= heading_thresh)){
//            break;
//        }

    viz.show(robot.getSpeed(),robot.getHeading(), ui);
//    }
	
}