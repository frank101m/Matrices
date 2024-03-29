#include "Report.h"
#include <cmath>


const std::string Report::REPORT_NEWLINE = "\\\\";
const std::string Report::SEL_START = "\\begin{alignedat}";
const std::string Report::SEL_END = "\\end{alignedat}";
const std::string Report::MATRIX_START = "\\begin{matrix}";
const std::string Report::MATRIX_END = "\\end{matrix}";
const std::string Report::BMATRIX_START = "\\begin{bmatrix}";
const std::string Report::BMATRIX_END = "\\end{bmatrix}";
const std::string Report::VMATRIX_START = "\\begin{vmatrix}";
const std::string Report::VMATRIX_END = "\\end{vmatrix}";
const std::string Report::TABLE_PRE_FORMAT = "\\begin{tabular}{";
const std::string Report::TABLE_POST_FORMAT = "}";
const std::string Report::TABLE_END = "\\end{tabular}";
const std::string Report::TABLE_VSPACE = "\\vspace{0.5cm}";

const std::string Report::DEF_ERROR = "\\def\\errormsg{";

//Para las operaciones basicas

const std::string Report::DEF_OP_MATRIX_A = "\\def\\opmatrixA{";
const std::string Report::DEF_OP_MATRIX_AT = "\\def\\opmatrixAT{";
const std::string Report::DEF_OP_MATRIX_DET_A = "\\def\\opmatrixdetA{";
const std::string Report::DEF_OP_VAL_DET_A = "\\def\\opvaldetA{";
const std::string Report::DEF_OP_MATRIX_INV_A = "\\def\\opmatrixinvA{";

const std::string Report::DEF_OP_MATRIX_B = "\\def\\opmatrixB{";
const std::string Report::DEF_OP_MATRIX_A_P_B = "\\def\\opmatrixAPB{";
const std::string Report::DEF_OP_MATRIX_A_M_B = "\\def\\opmatrixAMB{";
const std::string Report::DEF_OP_MATRIX_A_X_B = "\\def\\opmatrixAXB{";
const std::string Report::DEF_OP_MATRIX_B_X_A = "\\def\\opmatrixBXA{";

//Normas vectoriales
const std::string Report::DEF_NORM_EUC = "\\def\\eucnorm{";
const std::string Report::DEF_NORM_INF = "\\def\\infnorm{";
const std::string Report::DEF_NORM_INPUT_VEC = "\\def\\inputvec{";

const std::string Report::DEF_JACOBI_TABLES_PRE = "\\def\\jacobitables{";
const std::string Report::DEF_JACOBI_TABLES_POST = "}";
const std::string Report::DEF_JACOBI_SEL = "\\def\\jacobisel{";
const std::string Report::DEF_JACOBI_MATRIX_A = "\\def\\jacobimatrixA{";
const std::string Report::DEF_JACOBI_MATRIX_T = "\\def\\jacobimatrixT{";
const std::string Report::DEF_JACOBI_MATRIX_C = "\\def\\jacobimatrixC{";
const std::string Report::DEF_JACOBI_MATRIX_XO = "\\def\\jacobimatrixXO{";

const std::string Report::DEF_GAUSS_SEL = "\\def\\gausssel{";
const std::string Report::DEF_GAUSS_MATRICES = "\\def\\gaussmatrices{";
const std::string Report::DEF_GAUSS_TABLE = "\\def\\gausstable{";

const std::string Report::GAUSS_MATRIX_PRE_INDEX = "\\tilde{A}^{(";
const std::string Report::GAUSS_MATRIX_POST_INDEX = ")}=";
const std::string Report::GAUSS_MATRIX_SEGMENT_END = "\\\\ \\vspace{0.5cm} \\\\";

const std::string Report::DEF_END = "}";

Report::Report(const int precision)
{
	this->precision = precision;
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

std::string Report::generateSeq(const std::vector<std::string> &src, const std::string separator)
{
	std::ostringstream seq;

	for (int i = 0; i < src.size() - 1; i++) {
		seq << src.at(i) << separator;
	}

	seq << src.at(src.size() - 1);

	return seq.str();

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
		//seq << std::fixed;
		seq << std::setprecision(precision) << m.at(rowIndex, j);
		seq << separator;
	}

	seq << m.at(rowIndex, m.getColumnsCount() - 1);

	return seq.str();
}
std::string Report::getReportBody() {
	return this->reportBodyStream.str();
}


std::string Report::generateLinEqElement(
	const std::vector<std::string>& vars,
	const Matrix & A,
	const Matrix & C)
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
	const std::vector<std::string>& vars,
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

//*********************************
// Generacion de una matriz regular
//*********************************
std::string Report::generateBMatrixEl(const Matrix & M)
{
	std::ostringstream matrixElStream;

	matrixElStream << BMATRIX_START;
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

std::string Report::generateVMatrixEl(const Matrix & M)
{
	std::ostringstream matrixElStream;

	matrixElStream << VMATRIX_START;
	matrixElStream << std::endl;
	size_t n = M.getRowsCount();

	for (int i = 0; i < n -1; i++) {
		matrixElStream << generateRowSeq(M, i, "&");
		matrixElStream << REPORT_NEWLINE;
		matrixElStream << std::endl;
	}

	matrixElStream << generateRowSeq(M, n - 1, "&");
	matrixElStream << std::endl;
	matrixElStream << VMATRIX_END;

	return matrixElStream.str();
}

std::string Report::generateAugmentedMatrixEl(const Matrix & M)
{
	std::ostringstream augmentedMatrixElStream;

	size_t n = M.getRowsCount();
	size_t m = M.getColumnsCount();

	augmentedMatrixElStream << BMATRIX_START;

	augmentedMatrixElStream << "[";

	for (int i = 0; i < n; i++) {
		augmentedMatrixElStream << "r";
	}

	augmentedMatrixElStream << "|r";
	augmentedMatrixElStream << "]";
	augmentedMatrixElStream << std::endl;

	for (int i = 0; i < n; i++) {
		augmentedMatrixElStream << generateRowSeq(M, i, "&");
		augmentedMatrixElStream << REPORT_NEWLINE;
		augmentedMatrixElStream << std::endl;
	}

	augmentedMatrixElStream << BMATRIX_END;

	return augmentedMatrixElStream.str();
}

std::string Report::generateOperationMatrixEl(
	const std::vector<RowOperationParameter>& params
)
{
	std::ostringstream operationMatrixElStream;
	operationMatrixElStream << MATRIX_START;
	operationMatrixElStream << std::endl;

	for (int i = 0; i < params.size(); i++) {
		operationMatrixElStream << generateRowOperation(params.at(i));
		operationMatrixElStream << REPORT_NEWLINE;
		operationMatrixElStream << std::endl;
	}

	operationMatrixElStream << MATRIX_END;

	return operationMatrixElStream.str();
}

std::string Report::generateGaussReduction(
	const std::vector<Matrix> & Mvec,
	const std::vector<std::vector<RowOperationParameter> > &paramsM
)
{
	std::ostringstream gaussReductionStream;
	
	for (int i = 0; i < Mvec.size(); i++) {
		gaussReductionStream << GAUSS_MATRIX_PRE_INDEX;
		gaussReductionStream << (i + 1);
		gaussReductionStream << GAUSS_MATRIX_POST_INDEX;
		gaussReductionStream << std::endl;
		gaussReductionStream << generateAugmentedMatrixEl(Mvec.at(i));
		gaussReductionStream << "\\quad";
		gaussReductionStream << std::endl;
		gaussReductionStream << generateOperationMatrixEl(paramsM.at(i));

		if (i != Mvec.size() - 1) {
			gaussReductionStream << std::endl;
			gaussReductionStream << GAUSS_MATRIX_SEGMENT_END;
			gaussReductionStream << std::endl;
		} 
	}

	return gaussReductionStream.str();
}

std::string Report::generateJacobiTable(
	const std::vector<std::string>& vars,
	const std::vector<Matrix>& Xvec,
	const size_t initialIndex)
{
	size_t n = vars.size();
	size_t m = Xvec.size();

	std::ostringstream jacobiTableStream;

	jacobiTableStream << TABLE_PRE_FORMAT;

	for (int i = 0; i < m+1; i++) {

		jacobiTableStream << "c";

		if (i != m) {
			jacobiTableStream << "|";
		}
	}

	jacobiTableStream << TABLE_POST_FORMAT;
	jacobiTableStream << std::endl;
	jacobiTableStream << "\\hline" << std::endl;
	jacobiTableStream << "$k$ &";

	for (int i = 0; i < m; i++) {
		jacobiTableStream << (i + initialIndex);

		if (i != m - 1) {
			jacobiTableStream << "&";
		}
	}

	jacobiTableStream << REPORT_NEWLINE;
	jacobiTableStream << std::endl;
	jacobiTableStream << "\\hline";
	jacobiTableStream << std::endl;

	for (int i = 0; i < n; i++) {
		Matrix currentRowM(1, m);

		for (int j = 0; j < m; j++) {
			currentRowM.set(0, j, Xvec.at(j).at(i,0));
		}

		jacobiTableStream << generateJacobiTableRow(vars.at(i), currentRowM);
		jacobiTableStream << REPORT_NEWLINE;
		jacobiTableStream << std::endl;

		jacobiTableStream << "\\hline" << std::endl;
	}

	jacobiTableStream << TABLE_END;

	return jacobiTableStream.str();
}

std::string Report::generateGaussTable(const std::vector<std::string>& vars, const Matrix resultVec)
{
	std::ostringstream gaussTableStream;
	gaussTableStream << TABLE_PRE_FORMAT;
	size_t n = vars.size();

	for (int i = 0; i < n; i++) {
		gaussTableStream << "c";
		if (i != n - 1) {
			gaussTableStream << "|";
		}
	}

	gaussTableStream << TABLE_POST_FORMAT;
	gaussTableStream << std::endl;

	for (int i = 0; i < n; i++) {
		gaussTableStream << "$";
		gaussTableStream << vars.at(i);
		gaussTableStream << "$";
		if (i != n - 1) {
			gaussTableStream << "&";
		}
	}

	gaussTableStream << REPORT_NEWLINE;
	gaussTableStream << " \\hline";
	gaussTableStream << std::endl;
	gaussTableStream << generateRowSeq(resultVec, 0, "&");
	gaussTableStream << std::endl;
	gaussTableStream << TABLE_END;

	return gaussTableStream.str();
}

std::string Report::generateJacobiTableRow(
	const std::string &var,
	const Matrix & row
)
{
	std::ostringstream jacobiTableRow;

	jacobiTableRow << "$";
	jacobiTableRow << var;
	jacobiTableRow << "^{(k)}$ &";
	jacobiTableRow << generateRowSeq(row, 0, std::string("&"));

	return jacobiTableRow.str();
}

void Report::addDefinition(const std::string & tag, const std::string & value)
{
	reportBodyStream << std::endl;
	reportBodyStream << tag;
	reportBodyStream << std::endl;
	reportBodyStream << value;
	reportBodyStream << DEF_END;
	reportBodyStream << std::endl;
}

void Report::addJacobiTables(
	const std::vector<std::string>& vars,
	const std::vector<Matrix>& Xvec)
{
	std::ostringstream jacobiTablesStream;

	size_t m = Xvec.size();

	jacobiTablesStream << DEF_JACOBI_TABLES_PRE;
	jacobiTablesStream << std::endl;
	size_t step = m / 7 + 1;
	if (m <= 7) {
		jacobiTablesStream << generateJacobiTable(vars, Xvec, 1);
	} else {

		size_t itr_start_offset = 0;
		size_t itr_end_offset = 7;

		for (int i = 0; i < step; i++) {

			if (itr_start_offset >= m) {
				break;
			}

			std::vector <Matrix> tableSlice;

			if (itr_end_offset < m) {
				//Trozo del vector de matrices
				tableSlice = std::vector<Matrix>(
					Xvec.begin() + itr_start_offset,
					Xvec.begin() + itr_end_offset
				);
			} else {
				//Ultimo trozo
				tableSlice = std::vector<Matrix>(
					Xvec.begin() + itr_start_offset,
					Xvec.end()
				);
			}
					
			jacobiTablesStream << generateJacobiTable(vars,tableSlice,itr_start_offset + 1);
			jacobiTablesStream << std::endl;

			if (i != step - 1) {
				jacobiTablesStream << REPORT_NEWLINE;
				jacobiTablesStream << std::endl;
				jacobiTablesStream << TABLE_VSPACE;
				jacobiTablesStream << std::endl;
			}
			itr_start_offset += 7;
			itr_end_offset += 7;
		}
	}



	jacobiTablesStream << std::endl;
	jacobiTablesStream << DEF_JACOBI_TABLES_POST;

	reportBodyStream << std::endl;
	reportBodyStream << jacobiTablesStream.str();
	reportBodyStream << std::endl;
}

void Report::addLinEq(const std::string & tag, const std::vector<std::string> &vars, const Matrix & A, const Matrix & C)
{
	reportBodyStream << std::endl;
	reportBodyStream << tag;
	reportBodyStream << generateLinEqElement(vars, A, C);
	reportBodyStream << std::endl;
	reportBodyStream << DEF_END;
}

void Report::addGaussMatrices(const std::vector<Matrix>& Mvec, const std::vector<std::vector<RowOperationParameter>>& params)
{
	reportBodyStream << std::endl;
	reportBodyStream << DEF_GAUSS_MATRICES;
	reportBodyStream << generateGaussReduction(Mvec, params);
	reportBodyStream << std::endl;
	reportBodyStream << DEF_END;
}

void Report::addGaussTable(const std::vector<std::string>& vars, const Matrix & xvec)
{
	reportBodyStream << std::endl;
	reportBodyStream << DEF_GAUSS_TABLE;
	reportBodyStream << generateGaussTable(vars, xvec);
	reportBodyStream << std::endl;
	reportBodyStream << DEF_END;
}

void Report::addBMatrix(const std::string & tag, const Matrix & M)
{
	addDefinition(tag, generateBMatrixEl(M));
}

void Report::addVMatrix(const std::string & tag, const Matrix & M)
{
	addDefinition(tag, generateVMatrixEl(M));
}
