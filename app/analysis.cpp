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
    int flag_1 = 0;
    int flag_2 = 0;
    while (true){
        if (flag_1 ==1 && flag_2 ==1){
            break;
        }
        errors = cont.computeError(robot.getSpeed(),robot.getHeading());

//        throttle = cont.computeThrottle();
        if(std::get<0>(errors) > speed_thresh){
            throttle = cont.computeThrottle();
        }
        else if(std::get<0>(errors) <= speed_thresh){
            throttle = 0;
            flag_1 = 1;
        }
        if(std::get<1>(errors) > heading_thresh){
            steering_angle = cont.computeSteering();
        }
        else if((std::get<1>(errors) < heading_thresh)){
            steering_angle = 0;
            flag_2 = 1;
        }

        robot.drive(throttle,steering_angle,cont.getDt());

//        if ((std::get<0>(errors) <= speed_thresh) && (std::get<1>(errors) <= heading_thresh)){
//            break;
//        }



    viz.show(robot.getSpeed(),robot.getHeading(), ui);
    }
	
}