#pragma once
#include "Eigen/Dense"
#include <vector>
#include <time.h>

/**
 * @brief definition of the network class
 *
 */

class Network{
public:
	Network();
	~Network();

	void setNetwork(std::vector<int> n);

	// number of layers in the Network
	int numLayers = 0;
	// list of how many nodes are in each layer
	std::vector<int> sizes = {};
	// list of the biases for each node in each layer
	std::vector<Eigen::VectorXd> biases;
	// list of weights for each node connecting to another node in each layer
	std::vector<Eigen::MatrixXd> weights;

	void printBiases();

	void printWeights();

	void print();

private:
	int t = (unsigned)time(NULL);

	// used to round all elements in matrix (TODO make num of dp configurable)
	static double rnd(double x);
};

