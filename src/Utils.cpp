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

// Function to convert vector of 0s
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


void writeNet(Network net, std::string file){
	std::ofstream outFile(file);

	outFile << "\n";

	for(int i = 1; i < net.numLayers; i++){
		outFile << net.biases.at(i  - 1).transpose().unaryExpr([](double x){return round(x * 1000) / 1000;});
		outFile  << "\n\n";
	}
	outFile << "\n";
	for(int i = 1; i <  net.numLayers; i++){
		outFile << net.weights.at(i - 1).unaryExpr([](double x){return round(x * 1000) / 1000;});
		outFile << "\n\n";
	}
	outFile.close();
}

Network readNet(std::string file){
	std::ifstream inFile(file);
	std::string input;

	std::vector<std::vector<double>> b;
	std::vector<std::vector<std::vector<double>>> w;
	std::vector<std::vector<double>> weightMat;

	int numLayers = 1;

	bool newline = false;
	bool biasesComplete = false;

	while(getline(inFile, input)){
		if(!biasesComplete){
			std::vector<double> biasVec = {};
			std::string num = "";
			for(int i = 0; i < input.size(); i++){
				// covert char to string
				std::string s(1, input[i]);
				// append digits to the string
				if(s != " "){
					num.append(s);
					if(i == input.size() -1){
						biasVec.push_back(std::stod(num));
						b.push_back(biasVec);
						numLayers++;
					}
				}
				// append number when there's a space
				else if(num != ""){
					biasVec.push_back(std::stod(num));
					num = "";
				}
			}
		}
		else{
			std::vector<double> weightVec = {};
			std::string num = "";
			for(int i = 0; i < input.size(); i++){
				// convert char to string
				std::string s(1, input[i]);
				// append digits to the string
				if(s != " "){
					num.append(s);
					if(i == input.size() -1){
						weightVec.push_back(std::stod(num));
						weightMat.push_back(weightVec);
					}
				}
				// append number when there's a space
				else if(num != ""){
					weightVec.push_back(std::stod(num));
					num = "";
				}
			}

		}

		if(input == ""){
			if(biasesComplete){
				w.push_back(weightMat);
				weightMat = {};
			}
			if(newline){ biasesComplete = true; }
			newline = true;
		}
		else{ newline = false; }

	}

	// network to be returned
	Network net;

	net.numLayers = numLayers;

	std::vector<Eigen::VectorXd> biases;
	std::vector<Eigen::MatrixXd> weights;

	for(auto bias: b){
		Eigen::VectorXd bs = toEigen(bias);
		biases.push_back(bs);
	}

	for(auto weight: w){
		Eigen::MatrixXd ws(weight.size(), weight[0].size());
		for(int i = 0; i < weight.size(); i++){
			for(int j = 0; j < weight[0].size(); j ++){
				ws(i, j) = weight.at(i).at(j);
			}
		}
		weights.push_back(ws);
	}

	net.biases = biases;
	net.weights = weights;

	inFile.close();

	return net;
}



// int sign(double num){
// 	if(num > 0){
// 		return 1;
// 	}
// 	else if (num < 0){
// 		return -1;
// 	}
// 	else{
// 		return 0;
// 	}

// }