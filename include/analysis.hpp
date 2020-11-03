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
    double speed_thresh = 0.05;
    double heading_thresh = 0.03; // ~2 degree
};

