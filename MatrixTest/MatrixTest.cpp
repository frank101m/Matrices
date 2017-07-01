// MatrixTest.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"
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
	static double jacobiInitialGuess[4][1] = { {1}, {1}, {1}, {1} };

	size_t n = 4;

	Matrix A(n, n);
	Matrix C(n, 1);
	Matrix X(n, 1);


	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			A.set(i, j, jacobiTest[i][j]);
		}
	}

	std::cout << "Matriz A:" << std::endl;
	printMatrix(A);
	std::cout << std::endl;
	std::cout << "Norma matricial infinita: " << A.infNorm() << std::endl;

	for (int i = 0; i < n; i++) {
		C.set(i, 0, jacobiC[i][0]);
	}


	for (int i = 0; i < n; i++) {
		X.set(i, 0, jacobiInitialGuess[i][0]);
	}

	std::cout << "Matriz C:" << std::endl;
	printMatrix(C);
	std::cout << std::endl;

	std::cout << "Matriz X:" << std::endl;
	printMatrix(X);
	std::cout << std::endl;


	Matrix XN = LinearSolver::getJacobiMethod(A, C, X, 0.0001, 10);

	Report r(10);

	std::vector<std::string> vars;

	for (int i = 0; i < 4; i++) {
		std::ostringstream var;
		var << "a_";
		var << (i + 1);
		vars.push_back(var.str());
	}

	std::cout << r.generateLinEqElement(vars, A, C) << std::endl;
	std::cout << r.generateMatrixEl(std::string("A"), A) << std::endl;

	printMatrix(XN);

	system("pause");
	return 0;
}
