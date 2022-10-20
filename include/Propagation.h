#pragma once
#include "Eigen/Dense"
#include <math.h>
#include "Network.h"


class Propagation{

public:
	Propagation();
	~Propagation();

	// sigmoid acting on scalar
	static double sigmoid(double z);

	// sigmoid applied componentwise to matrix
	static Eigen::MatrixXd sigmoid(Eigen::MatrixXd mat);

	/* takes activations of the previous layer,
	weights of the neurons and their biases and
	returns the weighted input (z) of the current layer */
	static Eigen::MatrixXd propagate(Eigen::MatrixXd activations, Eigen::MatrixXd weights, Eigen::MatrixXd biases);

	/* takes activations of the first layer
	and propagates through the entire network,
	the returned activations are normalised*/
	static Eigen::MatrixXd propagate(Eigen::MatrixXd activations, Network net);

};

