
#include "include/Network.h"
#include "include/Propagation.h"
#include <iostream>

int main(){

	Network net = Network({3,5,4,2});

	for(int i = 0; i < net.numLayers - 1; i++){
		std::cout << net.biases.at(i) << "\n";
		std::cout << net.weights.at(i) << "\n";
	}

	Eigen::VectorXd a(3);
	a << 1,2,3;

	Eigen::MatrixXd a_prime(net.sizes.at(0), net.sizes.at(1));

	a_prime =  Propagation::propagate(a, net);

	std::cout << a << "\n\n\n" << a_prime << "\n";


	return 0;
}



