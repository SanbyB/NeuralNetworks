
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
		for(int j = 0; j < sizes.at(i); j++){
			std::cout << (round(biases.at(i  - 1)(j) * 1000.0) / 1000) << ",  ";
		}
		std::cout << "\n";
	}
}

void Network::printWeights(){
	for(int i = 1; i <  numLayers; i++){
		std::cout << weights.at(i - 1);
		std::cout << "\n\n\n";
	}
}