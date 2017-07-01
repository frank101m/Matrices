#include "Report.h"

const std::string Report::MATRIX_REGULAR_COMMAND = "\\regmatrix";
const std::string Report::MATRIX_AUGMENTED_COMMAND = "\\augmatrix";
const std::string Report::MATRIX_GAUSSIAN_REDUCTION_COMMAND = "\\opmatrix";
const std::string Report::MATRIX_SEPARATOR = ",";
const std::string Report::ARRAY_END = "}";
const std::string Report::ARRAY_START = "{";
const std::string Report::REPORT_BODY_START = "\\def\\reportbody{";
const std::string Report::REPORT_BODY_END = "}";
const std::string Report::REPORT_NEWLINE = "\\\\";
const std::string Report::SEL_START = "\\[\\begin{alignedat}";
const std::string Report::SEL_END = "\\end{alignedat}\\]";
const std::string Report::BMATRIX_PRE_VAR = "\\[\\mathbf{";
const std::string Report::BMATRIX_POST_VAR = "}=\\begin{bmatrix}";
const std::string Report::BMATRIX_END = "\\end{bmatrix}\\]";

Report::Report(const int precision)
{
	this->precision = precision;
}

std::string Report::getReportBody() {
	return this->reportBodyStream.str();
}

void Report::initializeReportBody()
{
	if (this->initialized = true) {
		this->reportBodyStream.clear();
	} else {
		this->reportBodyStream << REPORT_BODY_START;
	}

	this->initialized = true;
}

void Report::endReportBody()
{
	if (this->initialized) {
		this->reportBodyStream << REPORT_BODY_END;
	}
}

void Report::addAugmentMatrixElement(const std::vector<std::string>& vars, const Matrix & m)
{
	this->reportBodyStream << generateAugmentedMatrixElement(vars, m);
}

void Report::addGaussOpMatrix(
	const int index,
	const std::vector<std::string> &vars,
	const std::vector<RowOperationParameter> &params,
	const Matrix & m)
{
	this->reportBodyStream << generateGaussOpMatrixElement(index, vars, params, m);
}

std::string Report::generateLinEqElement(
	std::vector<std::string>& vars,
	Matrix & A,
	Matrix & C)
{
	std::ostringstream linEqElementStream;

	size_t n = vars.size();
	Matrix currentEq(0, 0);

	linEqElementStream << SEL_START;
	linEqElementStream << "{" << (n + 1) << "}";
	linEqElementStream << std::endl;

	for (int i = 0; i < n - 1; i++) {
		currentEq = A.getRow(i);

		linEqElementStream << generateEq(vars, currentEq, C.at(i, 0));
		linEqElementStream << REPORT_NEWLINE;
		linEqElementStream << std::endl;
	}



	currentEq = A.getRow(n - 1);
	linEqElementStream << generateEq(vars, currentEq, C.at(n-1,0));
	linEqElementStream << std::endl;

	linEqElementStream << SEL_END;

	return linEqElementStream.str();
}

std::string Report::generateEq(
	std::vector<std::string>& vars,
	Matrix & E,
	const double c)
{
	std::ostringstream eqStream;
	size_t n = vars.size();

	for (int i = 0; i < n; i++) {
		double currentX = E.at(0, i);
		if (currentX > 0 && i != 0) {
			eqStream << "+";
		}

		//No obviar
		if (currentX != 0) {
			//No colocar el numero 1
			if (std::abs(currentX) == 1.0) {
				if (currentX == -1.0) {
					eqStream << "-";
				}
			} else {
				eqStream << currentX << std::setprecision(precision);
			}

			eqStream << vars.at(i) << "&";

		} else {
			eqStream << " &";
		}
	}

	eqStream << "\\;&=&\\;" << c << std::setprecision(precision);

	return eqStream.str();
}

std::string Report::generateMatrixEl(std::string & var, const Matrix & M)
{
	std::ostringstream matrixElStream;

	matrixElStream << BMATRIX_PRE_VAR;
	matrixElStream << var;
	matrixElStream << BMATRIX_POST_VAR;
	matrixElStream << std::endl;

	size_t n = M.getRowsCount();

	for (int i = 0; i < n -1; i++) {
		matrixElStream << generateRowSeq(M, i, "&");
		matrixElStream << REPORT_NEWLINE;
		matrixElStream << std::endl;
		
	}

	matrixElStream << generateRowSeq(M, n - 1, "&");
	matrixElStream << std::endl;

	matrixElStream << BMATRIX_END;
	return matrixElStream.str();
}

std::string Report::generateRowOperation(const RowOperationParameter &param) {
	std::ostringstream rowOpStream;

	if (!param.skip) {

		if (param.swap) {
			rowOpStream << "\\quad ";
			//rowOpStream << "\\left(";
			rowOpStream << "E_" << param.j;
			rowOpStream << " \\quad \\longleftrightarrow \\quad ";
			rowOpStream << "E_" << param.i;
		} else {
			rowOpStream << "\\quad ";
			//rowOpStream << "\\left(";
			rowOpStream << "E_" << param.j;
			rowOpStream << "-";
			rowOpStream << "\\left(";
			rowOpStream << param.m << std::setprecision(precision);
			rowOpStream << "\\right)";
			rowOpStream << "E_" << param.i;
			//rowOpStream << "\\right)";
			rowOpStream << " \\quad \\rightarrow \\quad ";
			rowOpStream << "E_" << param.j;
		}

	}

	return rowOpStream.str();
}

std::string Report::generateGaussOpMatrixArray(
	const std::vector<RowOperationParameter> &params,
	const Matrix &m
)
{
	std::ostringstream gaussOpMatrixArrayStream;

	gaussOpMatrixArrayStream << ARRAY_START;

	for (int i = 0; i < m.getRowsCount(); i++) {
		gaussOpMatrixArrayStream << ARRAY_START;
		gaussOpMatrixArrayStream << generateRowSeq(m, i, MATRIX_SEPARATOR);

		//Se agrega el parametro estilizado de la operacion
		gaussOpMatrixArrayStream << MATRIX_SEPARATOR;
		gaussOpMatrixArrayStream << generateRowOperation(params.at(i));
		gaussOpMatrixArrayStream << ARRAY_END;

		if (i != m.getRowsCount() - 1) {
			gaussOpMatrixArrayStream << MATRIX_SEPARATOR;
		}
	}

	gaussOpMatrixArrayStream << ARRAY_END;

	return gaussOpMatrixArrayStream.str();
}

std::string Report::generateGaussOpMatrixElement(
	const int index,
	const std::vector<std::string> &vars,
	const std::vector<RowOperationParameter> &params,
	const Matrix & m
)
{
	std::ostringstream gaussOpMatrixStream;

	//Encabezado
	gaussOpMatrixStream << MATRIX_GAUSSIAN_REDUCTION_COMMAND;

	//Parametro de indice de la matriz
	gaussOpMatrixStream << ARRAY_START;
	gaussOpMatrixStream << index;
	gaussOpMatrixStream << ARRAY_END;

	//Parametro de variables
	gaussOpMatrixStream << ARRAY_START;
	gaussOpMatrixStream << generateVarArray(vars);
	gaussOpMatrixStream << ARRAY_END;

	//Parametro de matriz
	gaussOpMatrixStream << ARRAY_START;
	gaussOpMatrixStream << generateGaussOpMatrixArray(params, m);
	gaussOpMatrixStream << ARRAY_END;

	return gaussOpMatrixStream.str();
}


std::string Report::generateSeq(const std::vector<std::string> &src, const std::string separator)
{
	std::ostringstream seq;

	for (int i = 0; i < src.size() - 1; i++) {
		seq << src.at(i) << separator;
	}

	seq << src.at(src.size() - 1);

	return seq.str();

}

std::string Report::generateVarArray(const std::vector<std::string> &src)
{
	std::ostringstream arrayStr;

	arrayStr << ARRAY_START;
	arrayStr << generateSeq(src, MATRIX_SEPARATOR);
	arrayStr << ARRAY_END;

	return arrayStr.str();
}

std::string Report::generateRowSeq(
	const Matrix &m, //Matriz base
	const int rowIndex, //Indice de la fila a generar
	const std::string separator //Separado
)
{
	std::ostringstream seq;

	for (int j = 0; j < m.getColumnsCount() - 1; j++)
	{
		seq << std::setprecision(precision) << m.at(rowIndex, j);
		seq << separator;
	}

	seq << m.at(rowIndex, m.getColumnsCount() - 1);

	return seq.str();
}

std::string Report::generateRowArray(const Matrix &m, const int rowIndex)
{
	std::ostringstream arrayStr;

	arrayStr << ARRAY_START;
	arrayStr << generateRowSeq(m, rowIndex, MATRIX_SEPARATOR);
	arrayStr << ARRAY_END;

	return arrayStr.str();
}

std::string Report::generateRegularMatrixArray(const Matrix &m)
{
	std::ostringstream arrayStr;

	arrayStr << ARRAY_START;
	arrayStr << ARRAY_START;
	for (int i = 0; i < m.getRowsCount() - 1; i++)
	{
		arrayStr << generateRowArray(m, i);
		arrayStr << MATRIX_SEPARATOR;
	}

	arrayStr << generateRowArray(m, m.getRowsCount() - 1);
	arrayStr << ARRAY_END;
	arrayStr << ARRAY_END;

	return arrayStr.str();
}

std::string Report::generateRegularMatrixElement(const Matrix &m)
{
	std::ostringstream regularMatrixCommand;

	regularMatrixCommand << MATRIX_REGULAR_COMMAND;
	regularMatrixCommand << ARRAY_START;
	regularMatrixCommand << m.getColumnsCount();
	regularMatrixCommand << ARRAY_END;
	regularMatrixCommand << generateRegularMatrixArray(m);

	return regularMatrixCommand.str();

}

std::string Report::generateAugmentedMatrixElement(
	const std::vector<std::string> &vars,
	const Matrix &m)
{
	std::ostringstream augmentedMatrixCommand;

	augmentedMatrixCommand << MATRIX_AUGMENTED_COMMAND;
	augmentedMatrixCommand << ARRAY_START;
	augmentedMatrixCommand << generateVarArray(vars);
	augmentedMatrixCommand << ARRAY_END;

	augmentedMatrixCommand << generateRegularMatrixArray(m);

	return augmentedMatrixCommand.str();
}
