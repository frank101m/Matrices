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
        int s;
        for(int i = 0; i < this->getRowsCount(); i++)
            for(int j = 0; j < m.getColumnsCount(); j++){
                s=0;
                for(int k = 0; k < this->getColumnsCount(); k++)
                    s+=this->at(i, k) * m.at(k, j);
                res.set(i, j, s);
            }

        return res;


}
/*
    Eliminacion gaussiana con sustitución hacia atras
*/

void Matrix::gaussianElimination() {

	int p = 0; //Pivote nulificador
	int n = getRowsCount();

	for (int i = 0; i < getRowsCount() - 1; i++) {

	}
}
