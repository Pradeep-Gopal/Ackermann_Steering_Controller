#include <iostream>
#include "robot.hpp"
#include "userinterface.hpp"

/**
 * @brief      The main function calls tha analysis class and runs the convergence
 *
 * @return     0
 */
int main()
{
    UserInterface ui;
    ui.getTargets();
    return 0;
}
