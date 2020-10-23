#include <iostream>
#include "robot.hpp"
#include "userinterface.hpp"
#include "controller.hpp"

/**
 * @brief      The main function calls tha analysis class and runs the convergence
 *
 * @return     0
 */
int main()
{
    UserInterface ui;
    ui.getTargets();

    Controller cont;
    cont.setTargets(ui.getTargetSpeed(),ui.getTargetHeading());

    return 0;
}
