// MatrixTest.cpp: define el punto de entrada de la aplicación de consola.
//

#ifdef _WIN32
#include "stdafx.h"
#endif // 

#include <iostream>
#include "..\Matrices\LinearSolver.cpp"
#include "..\Matrices\Matrix.cpp"
#include "..\Matrices\Report.cpp"


void printMatrix(Matrix &m) {
	for (int i = 0; i < m.getRowsCount(); i++) {
		for (int j = 0; j < m.getColumnsCount(); j++) {
			std::cout << m.at(i, j) << " ";
		}
		std::cout << std::endl;
	}
}

int main()
{
	static double jacobiTest[4][4] = { {10,-1,2,0}, {-1,11,-1,3}, {2,-1,10,-1}, {0,3,-1,8}};
	static double jacobiC[4][1] = { {6}, {25}, {-11}, {15} };
	static double jacobiInitialGuess[4][1] = { {10000000}, {1003243240}, {1234000}, {123142000} };

	size_t n = 4;

	Matrix A(n, n);
	Matrix C(n, 1);
	Matrix X(n, 1);


	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			A.set(i, j, jacobiTest[i][j]);
		}
	}

	for (int i = 0; i < n; i++) {
		C.set(i, 0, jacobiC[i][0]);
	}


	for (int i = 0; i < n; i++) {
		X.set(i, 0, jacobiInitialGuess[i][0]);
	}


	Report r(10);

	std::vector<std::string> vars;

	for (int i = 0; i < n; i++) {
		std::ostringstream var;
		var << "a_";
		var << (i + 1);
		vars.push_back(var.str());
	}

	Matrix XN = LinearSolver::getJacobiMethod(A, C, X, 0.0001, 100, vars, r);

	std::vector<Matrix> XI;
	std::cout << r.getReportBody() << std::endl;

	return 0;
}