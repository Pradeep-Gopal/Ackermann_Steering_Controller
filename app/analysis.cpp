// Copyright (c) 2020 Govind Ajith Kumar, Justin Albrecht, Pradeep Gopal

#include <analysis.hpp>
#include <robot.hpp>
#include <userinterface.hpp>
#include <controller.hpp>
#include <visualization.hpp>

/**
 * @brief      shows the convergence from set points to the desired points 
 */
void Analysis::converge() const {
    UserInterface ui;
    Visualization viz;
    ui.getTargetsFromUser();

    Robot robot;
    Controller cont = Controller(robot);

    cont.setTargets(ui.getTargetSpeed(), ui.getTargetHeading());

    double robot_time = 0;
    double dt = cont.getDt();

    std::tuple<double, double> errors;

    while (true) {
        errors = cont.computeError(robot.getSpeed(), robot.getHeading());

        if (std::abs(std::get<0>(errors)) <= speed_thresh &&
            std::abs(std::get<1>(errors)) <= heading_thresh)
            break;

        double throttle = cont.computeThrottle();
        double steering_angle = cont.computeSteering();

        robot.drive(throttle, steering_angle, cont.getDt());

        robot_time += dt;

        viz.show(robot.getSpeed(), robot.getHeading(), robot_time, ui);

        if (robot_time >= 40)
            break;
    }
}
