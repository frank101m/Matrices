#pragma once
#include "Matrix.h"
#include <stdlib.h>
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

Matrix Matrix::transpose(){
    Matrix m = Matrix(this->getColumnsCount(), this->getRowsCount());
    for(int i = 0; i < this->getColumnsCount(); i++){
        for(int j = 0; j < this->getRowsCount(); j++){
           m.set(i, j, this->at(j, i));
        }
    }
    return m;

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








double Matrix::detGauss( Matrix  *a){
    int n, i, j, k;

    Matrix m = Matrix(a->getRowsCount(), a->getColumnsCount());
    for(int p = 0; p < m.getColumnsCount(); p++){
        for(int q = 0; q < m.getRowsCount(); q++){
            m.set(p, q, a->at(p, q));
        }
    }
    n=m.getColumnsCount();
    double det = 1;
    int flag = 0;
    for(i = 0; i < n; i++)
        for(k=i; k<n; k++)
        if(abs(m.at(i, i)) < abs(m.at(k, i))){
            flag++;
            for(j = 0; j < n; j++){
                double temp = m.at(i, j);
                m.set(i, j, m.at(k, j));
                m.set(k, j, temp);
            }
        }
    for(i = 0; i < n-1; i++)
        for(k=i+1; k<n;k++){
            double t = m.at(k, i) / m.at(i, i);
            for(j = 0; j < n; j++)
                m.set(k, j, (m.at(k, j)- t * m.at(i, j)));

        }
    for(i = 0; i < n; i++){
        det = det*m.at(i, i);
    }
    if(flag%2 ==0){
        det = det;
    }
    else{
        det = -det;
    }
    return det;
}


Matrix Matrix::inverse(){

    //checking if determinant is a number and if the matrix is not singular
    //using compiler standart (nan!=nan) in order to determine the matrix has ivnerse
    //tambien podemos usar el isnan de cmath ahi vean
    int n = this->getColumnsCount();
    Matrix inv = Matrix(n, n);

    if(detGauss(this) != 0  && detGauss(this)==detGauss(this)){



    double ratio, a;
    int i, j, k;

    Matrix *adj = new Matrix(n, 2*n);

    for(int row = 0; row < n; row++){
        for(int col = 0; col < n; col++){
            adj->set(row, col, this->at(row, col));
        }
    }



    for(i = 0; i < n; i++){
            for(j = n; j < 2*n; j++){
                if(i==(j-n))
                    adj->set(i, j, 1);

                else
                    adj->set(i, j, 0);

            }
        }

    for(i = 0; i < n; i++){
            for(j = 0; j < n; j++){
                if(i!=j){
                    ratio = adj->at(j, i) / adj->at(i, i);

                    for(k = 0; k < 2*n; k++){
                        adj->set(j, k, (adj->at(j, k)- ratio * adj->at(i, k)));

                    }
                }
            }
        }
    for(i = 0; i < n; i++){
            a = adj->at(i, i);

            for(j = 0; j < 2*n; j++){

                adj->set(i, j, (adj->at(i, j) / a));
            }
        }

    for(int row = 0; row < n; row++){
        for(int col = 0; col < n; col++ ){
            inv.set(row, col, adj->at(row, col+n));
        }
    }




    }else{
        for(int row = 0; row < n; row++){
            for(int col = 0; col < n; col++ ){
                inv.set(row, col, 0);
            }
        }
    }



    return inv;

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
