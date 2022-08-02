// Defines useful functions used throught the project
#pragma once
#include "Eigen/Dense"
#include <vector>
#include <iostream>
#include <fstream>

// Function to convert integer [0, 9]
// to a vector of 0s length 10 with a 1
// in the integers position
Eigen::VectorXd output(int n);

// Function to convert vectoor of 0s
// length 10 with a 1 in the i'th position
// to the integer i [0, 9]
int output(Eigen::VectorXd v);

// Takes an std vector and converts it to an Eigen:: vector
Eigen::VectorXd toEigen(std::vector<double> vec);


void readData(std::vector<std::vector<double>>& data, std::string path);

void readAns(std::vector<double>& ans, std::string path);