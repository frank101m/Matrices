#pragma once
#include <vector>


class Matrix
{

private:
	int rowsCount;
	int columnsCount;

	std::vector<std::vector<double>> mBase;

	void initialize(const int, const int);

	int rowNonZeroElementIndex(const int, const int, const Matrix &);

	void swapRows(const int, const int);

public:

	//Métodos generales
	Matrix(const int, const int);

    int getRowsCount() const;
    int getColumnsCount() const;
	void set(const int, const int, const double);
    double at(const int, const int) const;

	Matrix getRow(const int) const;
	std::vector<double> getRowVector(const int) const;
	Matrix getColumn(const int) const;

	void setRow(const int, const Matrix &m);

	//Los métodos de Frank van acá
    static bool validateSizes(const Matrix*, const Matrix&);
    //static Matrix* sum(const Matrix *, const Matrix *);
    Matrix operator+(const Matrix&);
    Matrix operator-(const Matrix&);
    Matrix operator*(const Matrix&);
	Matrix operator*(const double a);


	//Solucion de sistemas de ecuaciones lineales

	//Matrix getGaussianElimination(const std::vector<std::string> &, Report &);
};
