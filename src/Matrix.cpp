
#include "../include/Matrix.h"
#include <vector>


Matrix::Matrix(std::vector<std::vector<double>> mat){

	int size = mat.at(0).size();

	for(std::vector<double> vec: mat){
		if(vec.size() != size){
			std::cout << "Not a valid input, the matrix must be n x m\n";
			return;
		}
	}
	matrix = mat;
}

Matrix::Matrix(int num){
	std::vector<std::vector<double>> mat {};

	for(int i = 0; i < num; i++){
		mat.push_back({});
	}
	matrix = mat;
}

void Matrix::print(){
	for(std::vector<double> vec : matrix){
		for(double num : vec){
			std::cout << num << ", ";
		}
		std::cout << "\n";
	}
	std::cout << "\n";
}

Matrix Matrix::operator+(const Matrix& mat) const{
	std::vector<std::vector<double>> m = mat.getMatrix();
	if(m.size() != matrix.size() || m.at(0).size() != matrix.at(0).size()){
		std::cout << "Matrices cannot be added as both need to be of size n x m\n";
		Matrix out {{{}}};
		return out;
	}
	std::vector<std::vector<double>> out {matrix};
	for(int i = 0; i < m.size(); i++){
		std::vector<double> vec {};
		for(int j = 0; j < m.at(0).size(); j++){
			vec.push_back(matrix.at(i).at(j) + m.at(i).at(j));
		}
		out.at(i) = vec;
	}
	return Matrix(out);

}


Matrix Matrix::operator*(const Matrix& mat)const{
	std::vector<std::vector<double>> m = mat.getMatrix();
	if(matrix.at(0).size() != m.size()){
		std::cout << "Matrices cannot be multiplied as they need to be of size n x m, and m x l\n";
		Matrix out {{{}}};
		return out;
	}
	Matrix out = Matrix(matrix.size());
	for(int i = 0; i < matrix.size(); i++){
		std::vector<double> vec {};
		for(int j = 0; j < m.at(0).size(); j++){
			double num = 0;
			for(int k = 0; k <  m.size(); k++){
				num += matrix.at(i).at(k) * m.at(k).at(j);
			}
			vec.push_back(num);
		}
		out.setMatrix(i, vec);
	}

	return out;
}