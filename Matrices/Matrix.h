#pragma once
#include <vector>

class Matrix
{

private:
	std::vector<std::vector<double>> mBase;

	void initialize(const int, const int);

public:

	//Métodos generales
	Matrix(const int, const int);


	void set(const int, const int, const double);

	double at(const int, const int);

	//Los métodos de Frank van acá

	static Matrix sum(const Matrix, const Matrix);
};