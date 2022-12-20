/**
 * This is the main file which is used to train
 * a neural network on the MNIST data of hand written
 * digits. The technique used is back propagation,and
 * is currently set up without optimisation but it can achieve
 * over 90% accuracy when idenifying a digit.
 */


#include "include/Network.h"
#include "include/Propagation.h"
#include "include/BackPropagation.h"
#include "include/Utils.h"
#include <iostream>
#include <fstream>
// #include <string>
// #include <vector>
// #include <sstream>


int main () {

	std::vector<std::vector<double>> td= {};
	readData(td, "../neural-networks-and-deep-learning-master/data/trainData.csv");


	std::vector<double> trainAns = {};
	readAns(trainAns, "../neural-networks-and-deep-learning-master/data/trainAnswers.csv");


	std::vector<std::vector<double>> tsd= {};
	readData(tsd, "../neural-networks-and-deep-learning-master/data/testData.csv");


	std::vector<double> testAns = {};
	readAns(testAns, "../neural-networks-and-deep-learning-master/data/testAnswers.csv");


	std::vector<std::vector<double>> vd= {};
	readData(vd, "../neural-networks-and-deep-learning-master/data/valData.csv");


	std::vector<double> valAns = {};
	readAns(valAns, "../neural-networks-and-deep-learning-master/data/valAnswers.csv");

	std::vector<int> n = {784, 100, 10};

	Network net;

	net.setNetwork(n);

	std::cout << "Neural Network of size: ";

	for(int i = 0; i < n.size(); i++){
		std::cout << n.at(i) << ", ";
	}

	std::cout << "\n";

	BackPropagation bp  = BackPropagation();

	std::cout << "Training data used to tune the network\n";

	for(int i = 0; i < 50000; i++){
		net = bp.backProp(net, toEigen(td[i]), output(trainAns[i]));
	}

	std::cout << "Validation data used to check the network\n";

	int count = 0;

	for(int i = 0; i < 10000; i++){
	Eigen::MatrixXd ans = Propagation::propagate(toEigen(vd[i]), net);
	if(valAns[i] == output(ans)){
		count++;
	}
	}

	std::cout << count << " out of 10,000 images identified correctly\n";

	std::string file = "./output.txt";
	writeNet(net, file);
	std::cout << "Network saved to " << file << "\n";

	return 0;
}

