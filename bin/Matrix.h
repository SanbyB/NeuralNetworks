#pragma once
#include <iostream>
#include <vector>



class Matrix{

	public:
	// construct matrix with vector of vectors
	Matrix(std::vector<std::vector<double>> mat);
	// construct empty n x n matrix
	Matrix(int num);

	// return the matrix
	std::vector<std::vector<double>> getMatrix() const{return matrix;}

	// set matrix row to given vector
	void setMatrix(int row, std::vector<double> vec){matrix.at(row) = vec;}

	// print the matrix
	void print();

	// add two matricies
	Matrix operator+(const Matrix& mat)const;

	// multiply two matricies
	Matrix operator*(const Matrix& mat)const;


	private:
	// the matrix
	std::vector<std::vector<double>> matrix;

};