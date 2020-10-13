#pragma once

class Robot{
private:
	double wheel_base;
	double wheel_track;
	double wheel_radius;
	double robot_heading;
	double robot_velocity;
	double inner_wheel_velocity;
	double outer_wheel_velocity;
public:
	// Robot(){};
	void drive(double ,double);
};


