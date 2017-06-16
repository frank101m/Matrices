#pragma once
#include <vector>

class Matrix
{

private:
	int rowsCount;
	int columnsCount;

	std::vector<std::vector<double>> mBase;

	void initialize(const int, const int);

public:

	//M�todos generales
	Matrix(const int, const int);

	int getRowsCount();

	int getColumnsCount();

	void set(const int, const int, const double);

	double at(const int, const int);

	//Los m�todos de Frank van ac�

	static Matrix sum(const Matrix, const Matrix);

	//Solucion de sistemas de ecuaciones lineales

	void gaussianElimination();
};