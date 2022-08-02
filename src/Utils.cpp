#include "../include/Utils.h"

// Function to convert integer [0, 9]
// to a vector of 0s length 10 with a 1
// in the integers position
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

// Function to convert vectoor of 0s
// length 10 with a 1 in the i'th position
// to the integer i [0, 9]
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

// Takes an std vector and converts it to an Eigen:: vector
Eigen::VectorXd toEigen(std::vector<double> vec){
	int size = vec.size();
	Eigen::VectorXd v(size);
	for(int i = 0; i < size; i++){
		v[i] = vec[i];
	}
	return v;
}


void readData(std::vector<std::vector<double>>& data, std::string path){
	std::string line;
	std::ifstream trainD (path);

	std::vector<std::string> trainData = {};
	if (trainD.is_open()){

	while ( getline (trainD,line) ){

		trainData.push_back(line);
	}
	trainD.close();

	}else std::cout << "Unable to open " << path << "\n";

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

		data.push_back(temp);
	}

	std::cout << path << " data{ Loaded: " << data.size() << " arrays of size " << data[0].size() << "}\n";
}



void readAns(std::vector<double>& ans, std::string path){
	std::string line;
	std::ifstream trainA (path);

	if (trainA.is_open()){

	while ( getline (trainA,line) ){
		ans.push_back(stod(line));
	}
	trainA.close();


	}else std::cout << "Unable to open " << path << "\n";

	std::cout << path << " data answers{ Loaded: " << ans.size() << " entries}\n";
}