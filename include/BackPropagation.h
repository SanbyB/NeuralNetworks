#pragma once
#include "Eigen/Dense"


class BackPropagation{
public:
	BackPropagation();
	~BackPropagation();


	/*
	n is the total number of training inputs,
	a is a vector of the output activations from the network,
	y is the vector of desired output activations,
	returns the cost function vector
	*/
	Eigen::VectorXd quadCostFunct(int n, Eigen::VectorXd a, Eigen::VectorXd y){
		Eigen::VectorXd diff = y - a;
		return diff.dot(diff) / (2  * n)
	}

};


