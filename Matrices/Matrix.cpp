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
	initialize(n, m);
}

/*
	Métodos generales para matrices
*/

void Matrix::set(const int i, const int j, const double Aij) {
	mBase.at(i).at(j) = Aij;
}

double Matrix::at(const int i, const int j) {
	return mBase.at(i).at(j);
}