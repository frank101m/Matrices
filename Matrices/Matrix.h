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

    int getRowsCount() const;

    int getColumnsCount() const;

	void set(const int, const int, const double);

    double at(const int, const int) const;

	//Los m�todos de Frank van ac�
    static bool validateSizes(const Matrix*, const Matrix&);
    //static Matrix* sum(const Matrix *, const Matrix *);
    Matrix operator+(const Matrix&);
    Matrix operator-(const Matrix&);
    Matrix operator*(const Matrix&);



	//Solucion de sistemas de ecuaciones lineales

	void gaussianElimination();
};
