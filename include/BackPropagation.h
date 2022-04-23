#pragma once
#include "Eigen/Dense"
#include "Propagation.h"
#include "Network.h"


class BackPropagation{
public:
	BackPropagation();
	~BackPropagation();

	// learning rate
	double eta = 1;

	/*
	a is a vector of the output activations from the network,
	y is the vector of desired output activations,
	returns the derivative of the cost function vector
	*/
	static Eigen::VectorXd quadCostDerivative(Eigen::VectorXd a, Eigen::VectorXd y);

	// derivative of sigmoid function acting on a scalar
	static double sigmoidDerivative(double z);

	// derivative of sigmoid function applied to Matrix componentwise
	static Eigen::MatrixXd sigmoidDerivative(Eigen::MatrixXd mat);

	/*
	Takes single set of input activations
	and corresponding output activations
	returns updated network
	*/
	Network backProp(Network net, Eigen::VectorXd inputActivations, Eigen::VectorXd desiredOutputActivations);

};


