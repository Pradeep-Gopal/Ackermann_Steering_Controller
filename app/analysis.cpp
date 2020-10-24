#include <analysis.hpp>
#include "robot.hpp"
#include "userinterface.hpp"
#include "controller.hpp"


/**
 * @brief      shows the convergence from set points to the desired points 
 */
void Analysis::converge(){

    UserInterface ui;
    ui.getTargets();

    Controller cont;
    cont.setTargets(ui.getTargetSpeed(),ui.getTargetHeading());

    Robot robot;

    double throttle;
    double steering_angle;

    std::tuple<double,double> errors;

    while (true){
        errors = cont.computeError(robot.getSpeed(),robot.getHeading());

        throttle = cont.computeThrottle();
        steering_angle = cont.computeSteering();

        robot.drive(throttle,steering_angle);

        if ((std::get<0>(errors) <= speed_thresh) && (std::get<1>(errors) <= heading_thresh)){
            break;
        }

        //vis.show()
    }
	
}