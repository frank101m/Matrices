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
	static double jacobiInitialGuess[4][1] = { {0}, {0}, {0}, {0} };

	size_t n = 4;
	Matrix a(n, n);
	Matrix x(n, 1);
	Matrix t(n, 4);
	Matrix c(n, 1);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			a.set(i, j, jacobiTest[i][j]);
		}
	}

	for (int i = 0; i < n; i++) {
		x.set(i, 0, jacobiInitialGuess[i][0]);
		c.set(i, 0, jacobiC[i][0]);
	}

	printMatrix(a);

	std::cout << "Matriz T:" << std::endl;

	for (int i = 0; i < n; i++) {
		t.setRow(i, a.getRow(i)* (-1.0/a.at(i, i)));
		c.setRow(i, c.getRow(i)* (-1.0/a.at(i, i)));
		t.set(i, i, 0);
	}

	std::cout << std::endl;

	for (int i = 0; i < n; i++) {
		std::cout << "Iteracion: " << (i + 1) << std::endl;
		x = (t*x) + c;
		printMatrix(x);
	}

	system("pause");
	return 0;
}
