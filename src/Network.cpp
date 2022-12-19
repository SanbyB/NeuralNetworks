
#include "../include/Network.h"
#include <time.h>
#include <math.h>
#include <iostream>


void Network::setNetwork(std::vector<int> n){
	// initalise the private variables
	sizes = n;
	numLayers = n.size();

	// init biases
	for(int i = 1; i < numLayers; i++){
		Eigen::VectorXd biasVector(sizes.at(i));
		for(int j = 0; j < sizes.at(i); j++){
			biasVector(j) = 2 * ((double) rand()/RAND_MAX) - 1;
		}
		biases.push_back(biasVector);
	}

	// init weights
	for(int i = 1; i <  numLayers; i++){
		Eigen::MatrixXd weightMatrix(sizes.at(i),  sizes.at(i - 1));
		for(int j = 0; j < sizes.at(i - 1); j++){
			for(int k = 0; k < sizes.at(i); k++){
				weightMatrix(k, j) = 2 * ((double) rand()/RAND_MAX) - 1;
			}
		}
		weights.push_back(weightMatrix);
	}



}

Network::Network(){}

Network::~Network(){}

void Network::printBiases(){
	for(int i = 1; i < numLayers; i++){
		std::cout << biases.at(i - 1).transpose().unaryExpr(&rnd);
		std::cout << "\n";
	}
}

void Network::printWeights(){
	for(int i = 1; i <  numLayers; i++){
		std::cout << weights.at(i - 1).unaryExpr(&rnd);
		std::cout << "\n\n\n";
	}
}

void Network::print(){
	std::cout << "Biases:\n";
	printBiases();
	std::cout << "\nWeights:\n";
	printWeights();
}

double Network::rnd(double x){
	return round(x * 1000) / 1000;
}