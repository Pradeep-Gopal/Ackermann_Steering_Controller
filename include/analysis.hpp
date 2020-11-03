#pragma once
/**
 * @brief      This class instantiates all the objects
 */
class Analysis{
public:
	// Analysis(){};
	/**
     * @brief      shows the convergence from set points to the desired points
     */
	void converge() const;
private:
    double speed_thresh = 0.01;
    double heading_thresh = 0.0174533; // 1 degree
};

