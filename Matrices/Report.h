#pragma once
#include "Matrix.h"
#include <string>
#include <iomanip>
#include <iostream>
#include <sstream>

class Report {
private:
	//Precision deseada
	int precision;
	std::ostringstream baseStream;

	std::string generateRowSwap(const int, const int);

	std::string generateSeq(const std::vector<std::string> &, const std::string);
	std::string generateVarArray(const std::vector<std::string> &);

	std::string generateRowSeq(const Matrix &, const int, const std::string);
	std::string generateRowArray(const Matrix &, const int);
	std::string generateRegularMatrixArray(const Matrix &);

public:
	Report(const int);
	//Constantes del reporte en Latex
	static const std::string MATRIX_REGULAR_COMMAND;
	static const std::string MATRIX_AUGMENTED_COMMAND;
	static const std::string MATRIX_GAUSSIAN_REDUCTION_COMMAND;
	static const std::string MATRIX_SEPARATOR;
	static const std::string ARRAY_START;
	static const std::string ARRAY_END;

	std::string generateRowOperation(const int, const int, const double);
	std::string generateGaussOpMatrixElement(std::vector<RowOperationParameter> &, Matrix &m);
	std::string generateRegularMatrixElement(const Matrix &);
	std::string generateAugmentedMatrixElement(const std::vector<std::string> &, const Matrix&);
};

struct RowOperationParameter {
	int i;
	int j;
	double m;
};