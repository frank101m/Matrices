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

	std::string generateRegularMatrixElement(const Matrix &m);
};
