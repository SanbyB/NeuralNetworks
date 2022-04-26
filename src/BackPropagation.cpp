#include "../include/BackPropagation.h"
#include <iostream>


BackPropagation::BackPropagation(){}
BackPropagation::~BackPropagation(){}

Eigen::VectorXd BackPropagation::quadCostDerivative(Eigen::VectorXd a, Eigen::VectorXd y){
		return a - y;
}


double BackPropagation::sigmoidDerivative(double z){
	return Propagation::sigmoid(z) * (1 - Propagation::sigmoid(z));
}


Eigen::MatrixXd BackPropagation::sigmoidDerivative(Eigen::MatrixXd mat){
	return mat.unaryExpr([](double z){return sigmoidDerivative(z);});
}

Network BackPropagation::backProp(Network net, Eigen::VectorXd inputActivations, Eigen::VectorXd desiredOutputActivations){
	// change in  bias matrix
	std::vector<Eigen::VectorXd> nablaB(net.numLayers - 1);
	// change in weight matrix
	std::vector<Eigen::MatrixXd> nablaW(net.numLayers  - 1);

	// feedforward
	std::vector<Eigen::VectorXd> activations = {inputActivations};
	std::vector<Eigen::VectorXd> weightedInputs;

	for(int i = 1; i < net.numLayers; i++){
		weightedInputs.push_back(Propagation::propagate(activations.at(i - 1),  net.weights.at(i - 1), net.biases.at(i - 1)));
		activations.push_back(Propagation::sigmoid(weightedInputs.at(i - 1)));
	}
	// activations is the same length as network
	// weightedInputs is the same length as weights

	// backward pass
	Eigen::VectorXd costDerivative = quadCostDerivative(activations.at(net.numLayers - 1), desiredOutputActivations);

	Eigen::VectorXd delta = costDerivative.cwiseProduct(sigmoidDerivative(weightedInputs.at(net.numLayers - 2)));

	nablaB.at(net.numLayers - 2) = delta;

	nablaW.at(net.numLayers - 2) = delta * activations.at(net.numLayers - 2).transpose(); // delta size of columns and activations size of rows

	for(int i = 3; i <= net.numLayers; i++){
		Eigen::VectorXd z = weightedInputs.at(net.numLayers - i);
		Eigen::VectorXd sd = sigmoidDerivative(z);

		delta = (net.weights.at(net.numLayers - i + 1).transpose() * delta).cwiseProduct(sd);
		nablaB.at(net.numLayers - i) = delta;
		nablaW.at(net.numLayers  - i) = delta * activations.at(net.numLayers - i).transpose();
	}

	// for(int i = 0; i < net.numLayers - 1; i++){
	// 	std::cout << "nablaB: \n" << nablaB.at(i) << "\n";
	// 	std::cout << "nablaW: \n" << nablaW.at(i) << "\n";
	// }

	// update weights and biases
	for(int i = 0; i < net.numLayers - 1; i++){
		net.biases.at(i) = net.biases.at(i) - eta * nablaB.at(i);
		net.weights.at(i) = net.weights.at(i) - eta * nablaW.at(i);
	}

	return net;
}