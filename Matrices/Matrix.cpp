#pragma once
#include "Matrix.h"
/*
	Métodos privados
*/

void Matrix::initialize(const int n, const int m) {

    mBase.reserve(n);
	mBase.resize(n);

	for (std::vector<double> &column : mBase) {
		column.reserve(m);
		column.resize(m);
	}

	//Inicializar matriz con 0
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			mBase[i][j] = 0.0;
		}
	}
}


/*
	Constructores
*/

Matrix::Matrix(const int n, const int m) {
	rowsCount = n;
	columnsCount = m;

	initialize(n, m);
}

/*
    Metodos generales para matrices
*/

int Matrix::getColumnsCount() const {
	return columnsCount;
}

int Matrix::getRowsCount() const {
	return rowsCount;
}

void Matrix::set(const int i, const int j, const double Aij) {
	mBase.at(i).at(j) = Aij;
}

double Matrix::at(const int i, const int j) const {
	return mBase.at(i).at(j);
}

Matrix Matrix::getRow(const int i) const {
	Matrix t(1, getColumnsCount());
	t.mBase.at(0) = this->mBase.at(i);
	return t;
}

std::vector<double> Matrix::getRowVector(const int rowIndex) const
{
	return mBase.at(rowIndex);
}

void Matrix::setRow(const int rowIndex, const Matrix &m) {
	mBase.at(rowIndex) = m.getRowVector(0);
}

/*Matrix* Matrix::sum(const Matrix *a, const Matrix *b){
    if(validateSizes(a, b)){
        Matrix *result = new Matrix(a->getRowsCount(), b->getColumnsCount());
        for(int i = 0; i < a->getRowsCount(); i++)
            for(int j = 0; j < a->getColumnsCount(); j++)
                result->set(i, j, (a->at(i, j) + b->at(i, j)));
        return result;
    }
    return nullptr;

}*/


bool Matrix::validateSizes(const Matrix *a, const Matrix &b){
    return(a->columnsCount == b.columnsCount && a->rowsCount == b.rowsCount);
}

Matrix Matrix::operator+(const Matrix& m){
        Matrix res = Matrix(m.getRowsCount(), m.getColumnsCount());
        for(int i = 0; i < m.getRowsCount(); i++)
            for(int j = 0; j < m.getColumnsCount(); j++)
                res.set(i, j, this->at(i, j) + m.at(i, j));
        return res;

}
Matrix Matrix::operator-(const Matrix& m){
        Matrix res = Matrix(m.getRowsCount(), m.getColumnsCount());
        for(int i = 0; i < m.getRowsCount(); i++)
            for(int j = 0; j < m.getColumnsCount(); j++)
                res.set(i, j, this->at(i, j) - m.at(i, j));
        return res;
}
Matrix Matrix::operator*(const Matrix& m){
        Matrix res = Matrix(this->getRowsCount(), m.getColumnsCount());
        double s;
        for(int i = 0; i < this->getRowsCount(); i++)
            for(int j = 0; j < m.getColumnsCount(); j++){
                s=0;
                for(int k = 0; k < this->getColumnsCount(); k++)
                    s+=this->at(i, k) * m.at(k, j);
                res.set(i, j, s);
            }

        return res;
}

Matrix Matrix::operator*(const double a) {
	Matrix t(getRowsCount(), getColumnsCount());

	for (int i = 0; i < getRowsCount(); i++) {
		for (int j = 0; j < getColumnsCount(); j++) {
			t.set(i, j, at(i, j) * a);
		}
	}

	return t;
}
/*
    Eliminacion gaussiana con sustitución hacia atras
*/

void Matrix::swapRows(const int a, const int b) {
	std::vector<double> rowT = mBase.at(a);

	mBase.at(a) = mBase.at(b);
	mBase.at(b) = rowT;
}

int Matrix::rowNonZeroElementIndex(const int initialIndex, const int columnIndex, const Matrix &m)
{
	int p;

	for (p = initialIndex; p < m.getRowsCount(); p++) {
		if (m.at(p, columnIndex) != 0.0) {
			return p;
		}
	}

	return -1;
}

//Matrix Matrix::getGaussianElimination(
//	const std::vector<std::string> &vars,
//	Report &report) {
//	Matrix t = *this;
//	Matrix currentRow(0,0);
//	int p = 0; //Indice del pivote
//	int n = getRowsCount();
//	double m;
//
//
//	for (int i = 0; i < n-1; i++) {
//		std::vector<RowOperationParameter> params;
//
//		for (int paramIndex = 0; paramIndex < n; paramIndex++) {
//			RowOperationParameter tempParam;
//			tempParam.skip = true;
//			params.push_back(tempParam);
//		}
//
//		p = i;
//
//		if (t.at(p, i) == 0.0) {
//			p = rowNonZeroElementIndex(i,i,t);
//		}
//
//		//Solucion multiple
//		if (p == -1) {
//			return t;
//		} else if (p != i) {
//			t.swapRows(p, i);
//		}
//
//		for (int j = i + 1; j < n; j++) {
//			m = t.at(j, i) / t.at(i, i);
//
//#include "Report.h"
//			params.at(j).i = i + 1;
//			params.at(j).j = j + 1;
//			params.at(j).m = m;
//			params.at(j).skip = false;
//
//			currentRow = t.getRow(j) - t.getRow(i) * m;
//			t.setRow(j, currentRow);
//		}
//
//		report.addGaussOpMatrix(i + 1, vars, params, t);
//
//
//	}
//
//
//	return t;
//
//}
