// MatrixTest.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"
#include <iostream>
#include "..\Matrices\Matrix.cpp"


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
	Matrix a(4, 4);
	Matrix b(4, 4);

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			a.set(i, j, i + j + 2);
		}
	}

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			b.set(i, j, (i + 1) * (j + 1));
		}
	}

	std::cout << "Matriz a" << std::endl;
	printMatrix(a);

	std::cout << "Matriz b" << std::endl;
	printMatrix(b);

	Matrix c = a * b;
	std::cout << "Matriz c" << std::endl;
	printMatrix(c);


	Matrix d = a.getRow(0) * 2;
	std::cout << "Matriz d" << std::endl;
	printMatrix(d);

	return 0;
}
