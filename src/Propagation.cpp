#include "../include/Propagation.h"

double Propagation::sigmoid(double z){
	return 1.0 / (1.0 + exp(-z));
}


Eigen::MatrixXd Propagation::sigmoid(Eigen::MatrixXd mat){
	return mat.unaryExpr([](double z){return sigmoid(z);});
}

Eigen::MatrixXd Propagation::propagate(Eigen::MatrixXd activations, Eigen::MatrixXd weights, Eigen::MatrixXd biases){
	return (weights * activations) + biases;
}

Eigen::MatrixXd Propagation::propagate(Eigen::MatrixXd activation, Network net){
	Eigen::MatrixXd act = activation;
	for(int i = 0; i < net.numLayers - 1; i++){
		act = sigmoid(propagate(act, net.weights.at(i), net.biases.at(i)));
	}
	return act;
}