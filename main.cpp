
#include "include/Network.h"
#include "include/Propagation.h"
#include "include/BackPropagation.h"
#include "include/OpenData.h"
#include <iostream>

int main(){

	int numImgs = 6000;
	int imgSize = 100;
	unsigned char** imgData = OpenData::read_mnist_images("../train-images.idx3-ubyte", numImgs, imgSize);

	std::cout << imgData[0][0] << "\n";

	// Network net = Network({5, 10, 12, 4});

	// for(int i = 0; i < net.numLayers - 1; i++){
	// 	std::cout << "net biases:\n" << net.biases.at(i) << "\n";
	// 	std::cout << "net weights:\n" << net.weights.at(i) << "\n";
	// }

	// BackPropagation backPropagate = BackPropagation();


	// Eigen::VectorXd input(5);

	// for(int i = 0; i < 5; i++){
	// 	input(i) = i + 1;
	// }

	// Eigen::VectorXd output(4);

	// for(int i = 0; i < 4; i++){
	// 	output(i) = i + 1;
	// }

	// Network newNet = backPropagate.backProp(net, input, output);

	// for(int i = 0; i < net.numLayers - 1; i++){
	// 	std::cout << "back biases:\n" << newNet.biases.at(i) << "\n";
	// 	std::cout << "back weights:\n" << newNet.weights.at(i) << "\n";
	// }

	return 0;
}



