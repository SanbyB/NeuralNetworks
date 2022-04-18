
#include "../include/Network.h"
#include <time.h>
#include <iostream>

/**
 * @brief Construct a new Network:: Network object
 *
 * @param n
 */

Network::Network(std::vector<int> n){
	// initalise the private variables

	sizes = n;
	numLayers = n.size();

	// randomises network setup based on time
    srand( (unsigned)time( NULL ) );

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

Network::~Network(){

}
