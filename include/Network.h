#pragma once
#include "Eigen/Dense"
#include <vector>

/**
 * @brief definition of the network class
 *
 */

class Network{
public:
	Network(std::vector<int> n);
	~Network();

	// number of layers in the Network
	int numLayers = 0;
	// list of how many nodes are in each layer
	std::vector<int> sizes = {};
	// list of the biases for each node in each layer
	std::vector<Eigen::VectorXd> biases;
	// list of weights for each node connecting to another node in each layer
	std::vector<Eigen::MatrixXd> weights;

};

