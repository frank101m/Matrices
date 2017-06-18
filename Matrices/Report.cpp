#include "Report.h"

const std::string Report::MATRIX_REGULAR_COMMAND = "\\regematrix";
const std::string Report::MATRIX_AUGMENTED_COMMAND = "\\augmatrix";
const std::string Report::MATRIX_GAUSSIAN_REDUCTION_COMMAND = "\\opmatrix";
const std::string Report::MATRIX_SEPARATOR = ",";
const std::string Report::ARRAY_END = "}";
const std::string Report::ARRAY_START = "{";


Report::Report(const int precision)
{
	this->precision = precision;
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
	for (int i = 0; i < m.getRowsCount() - 1; i++)
	{
		arrayStr << generateRowArray(m, i);
		arrayStr << MATRIX_SEPARATOR;
	}

	arrayStr << generateRowArray(m, m.getColumnsCount() - 1);
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