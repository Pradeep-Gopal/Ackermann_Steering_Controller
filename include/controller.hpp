#pragma once

class Controller{
private:
	double max_steering_angle;
	double max_throttle;
public:
	// Controller(){};
	double computeSteering(double ,double);
	double computeThrottle(double, double);
};

