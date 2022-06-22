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
#include <iostream>
#include <fstream>
// #include <string>
// #include <vector>
// #include <sstream>

Eigen::VectorXd output(int n){
	Eigen::VectorXd v(10);
	for(int i = 0; i < 10; i++){
		if(i == n){
			v(i) = 1;
		}
		else{
			v(i) = 0;
		}
	}
	return v;
}

int output(Eigen::VectorXd v){
	int n = 0;
	double max = 0;
	for(int i = 0; i < 10; i++){
		if(v[i] > max){
			n = i;
			max = v[i];
		}
	}
	return n;
}

Eigen::VectorXd toEigen(std::vector<double> vec){
	int size = vec.size();
	Eigen::VectorXd v(size);
	for(int i = 0; i < size; i++){
		v[i] = vec[i];
	}
	return v;
}

int main () {
	std::string line;
	std::ifstream trainD ("../neural-networks-and-deep-learning-master/data/trainData.csv");

	std::vector<std::string> trainData = {};
	if (trainD.is_open()){

	while ( getline (trainD,line) ){

		trainData.push_back(line);
	}
	trainD.close();

	}else std::cout << "Unable to open trainData\n";

	std::vector<std::vector<double>> td= {};

	for(int j = 0; j < trainData.size(); j++){

		std::string str = trainData[j];

		std::stringstream ss(str);

		std::vector<double> temp = {};

		double i;

		while(ss >> i) {
			temp.push_back(i);
			if (ss.peek() == ',')
				ss.ignore();
		}

		td.push_back(temp);
	}

	std::cout << "Training data{ Loaded: " << td.size() << " arrays of size " << td[0].size() << "}\n";


	std::ifstream trainA ("../neural-networks-and-deep-learning-master/data/trainAnswers.csv");

	std::vector<double> trainAns = {};
	if (trainA.is_open()){

	while ( getline (trainA,line) ){
		trainAns.push_back(stod(line));
	}
	trainA.close();


	}else std::cout << "Unable to open trainAns\n";

	std::cout << "Training data answers{ Loaded: " << trainAns.size() << " entries}\n";

	std::ifstream testD ("../neural-networks-and-deep-learning-master/data/testData.csv");

	std::vector<std::string> testData = {};
	if (testD.is_open()){

	while ( getline (testD,line) ){

		testData.push_back(line);
	}
	testD.close();

	}else std::cout << "Unable to open testData\n";

	std::vector<std::vector<double>> tsd= {};

	for(int j = 0; j < testData.size(); j++){

		std::string str = testData[j];

		std::stringstream ss(str);

		std::vector<double> temp = {};

		double i;

		while(ss >> i) {
			temp.push_back(i);
			if (ss.peek() == ',')
				ss.ignore();
		}

		tsd.push_back(temp);
	}

	std::cout << "Test data{ Loaded: " << tsd.size() << " arrays of size " << tsd[0].size() << "}\n";


	std::ifstream testA ("../neural-networks-and-deep-learning-master/data/testAnswers.csv");

	std::vector<double> testAns = {};
	if (testA.is_open()){

	while ( getline (testA,line) ){
		testAns.push_back(stod(line));
	}
	testA.close();


	}else std::cout << "Unable to open testAns\n";

	std::cout << "Test data answers{ Loaded: " << testAns.size() << " entries}\n";


	std::ifstream valD ("../neural-networks-and-deep-learning-master/data/valData.csv");

	std::vector<std::string> valData = {};
	if (valD.is_open()){

	while ( getline (valD,line) ){

		valData.push_back(line);
	}
	valD.close();

	}else std::cout << "Unable to open valData\n";

	std::vector<std::vector<double>> vd= {};

	for(int j = 0; j < valData.size(); j++){

		std::string str = valData[j];

		std::stringstream ss(str);

		std::vector<double> temp = {};

		double i;

		while(ss >> i) {
			temp.push_back(i);
			if (ss.peek() == ',')
				ss.ignore();
		}

		vd.push_back(temp);
	}

	std::cout << "Validation data{ Loaded: " << vd.size() << " arrays of size " << vd[0].size() << "}\n";


	std::ifstream valA ("../neural-networks-and-deep-learning-master/data/valAnswers.csv");

	std::vector<double> valAns = {};
	if (valA.is_open()){

	while ( getline (valA,line) ){
		valAns.push_back(stod(line));
	}
	valA.close();


	}else std::cout << "Unable to open valAns\n";

	std::cout << "Validation data answers{ Loaded: " << valAns.size() << " entries}\n";

	std::vector<int> n = {784, 100, 10};

	Network net = Network(n);

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

	return 0;
}

