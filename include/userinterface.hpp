#pragma once
#include <vector>

class UserInterface{
private:
	double target_velocity;
	double target_heading;
public:
	// UserInterface(){};
	double getTargets(std::vector<double>);
};

