#include <iostream>
#include "analysis.hpp"

/**
 * @brief      The main function calls tha analysis class and runs the convergence
 *
 * @return     0
 */
int main()
{
    Analysis sim;
    sim.converge();
    return 0;
}
