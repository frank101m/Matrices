#pragma once
#include <string>
#include <iomanip>
#include <string>
#include <iostream>
#include <vector>
#include <sstream>
#include "Matrix.h"


struct RowOperationParameter {
	bool skip = false;
	bool swap = false;
	int i;
	int j;
	double m;
} typedef RowOperationParameter;

class Report {
private:
	//Precision deseada
	bool initialized = false;
	int precision;
	std::ostringstream reportBodyStream;



public:
	Report(const int);
	//Constantes del reporte en Latex
	static const std::string MATRIX_REGULAR_COMMAND;
	static const std::string MATRIX_AUGMENTED_COMMAND;
	static const std::string MATRIX_GAUSSIAN_REDUCTION_COMMAND;
	static const std::string MATRIX_SEPARATOR;
	static const std::string ARRAY_START;
	static const std::string ARRAY_END;
	static const std::string REPORT_BODY_START;
	static const std::string REPORT_BODY_END;
	static const std::string REPORT_NEWLINE;
	static const std::string SEL_START;
	static const std::string SEL_END;
	static const std::string BMATRIX_START;
	static const std::string BMATRIX_END;
	static const std::string TABLE_PRE_FORMAT;
	static const std::string TABLE_POST_FORMAT;
	static const std::string TABLE_END;
	static const std::string TABLE_VSPACE;
	static const std::string DEF_JACOBI_TABLES_PRE;
	static const std::string DEF_JACOBI_TABLES_POST;

	static const std::string DEF_JACOBI_SEL;
	static const std::string DEF_JACOBI_MATRIX_A;
	static const std::string DEF_JACOBI_MATRIX_T;
	static const std::string DEF_JACOBI_MATRIX_C;
	static const std::string DEF_JACOBI_MATRIX_XO;

	static const std::string DEF_END;

	std::string generateRowSwap(const int, const int);
	std::string generateSeq(const std::vector<std::string> &, const std::string);
	std::string generateVarArray(const std::vector<std::string> &);
	std::string generateRowSeq(const Matrix &, const int, const std::string);
	std::string generateRowArray(const Matrix &, const int);
	std::string generateRegularMatrixArray(const Matrix &);
	std::string generateGaussOpMatrixArray(const std::vector<RowOperationParameter> &, const Matrix &);
	std::string generateRowOperation(const RowOperationParameter &);

	std::string generateGaussOpMatrixElement(
		const int,
		const std::vector<std::string> &,
		const std::vector<RowOperationParameter> &, 
		const Matrix &m);

	std::string generateRegularMatrixElement(const Matrix &);
	std::string generateAugmentedMatrixElement(const std::vector<std::string> &, const Matrix&);

	std::string getReportBody();

	void initializeReportBody();
	void endReportBody();

	void addAugmentMatrixElement(
		const std::vector<std::string> &vars,
		const Matrix &m
	);

	void addGaussOpMatrix(
		const int,
		const std::vector<std::string> &,
		const std::vector<RowOperationParameter> &,
		const Matrix &
	);

	//Generacion de sistema de ecuaciones lineales
	std::string generateLinEqElement(
		const std::vector<std::string> &vars,
		const Matrix &A,
		const Matrix &C
	);

	std::string generateEq(
		const std::vector<std::string> &vars,
		Matrix &E,
		const double c
	);

	std::string generateMatrixEl(
		const Matrix &M
	);

	std::string generateJacobiTable(
		const std::vector<std::string> &vars,
		const std::vector<Matrix> &Xvec,
		const size_t initialIndex
	);

	std::string generateJacobiTableRow(
		const std::string &var,
		const Matrix &row
	);

	void addJacobiTables(
		const std::vector<std::string> &vars,
		const std::vector<Matrix> &Xvec
	);

	void addLinEq(
		const std::string &tag,
		const std::vector<std::string> &vars,
		const Matrix &A,
		const Matrix &C
	);

	void addMatrix(
		const std::string &tag,
		const Matrix &M
	);
};

