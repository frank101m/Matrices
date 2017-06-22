// MatrixTest.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"
#include <iostream>
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

	Matrix c(4,5);


	c.set(0, 0, 1.0);
	c.set(0, 1, 1.0);
	c.set(0, 2, 0.0);
	c.set(0, 3, 3.0);
	c.set(0, 4, 4.0);

	c.set(1, 0, 2.0);
	c.set(1, 1, 1.0);
	c.set(1, 2, -1.0);
	c.set(1, 3, 1.0);
	c.set(1, 4, 1.0);

	c.set(2, 0, 3.0);
	c.set(2, 1, -1.0);
	c.set(2, 2, -1.0);
	c.set(2, 3, 2.0);
	c.set(2, 4, -3.0);

	c.set(3, 0, -1.0);
	c.set(3, 1, 2.0);
	c.set(3, 2, 3.0);
	c.set(3, 3, -1.0);
	c.set(3, 4, 4.0);



	std::cout << "Matriz c" << std::endl;
	printMatrix(c);


	Matrix d = c.getGaussianElimination();
	std::cout << "Matriz d" << std::endl;

	printMatrix(d);

	Report r(10);

	std::vector<std::string> vars;

	vars.push_back("a_1");
	vars.push_back("a_2");
	vars.push_back("a_3");
	vars.push_back("a_4");

	std::cout << r.generateAugmentedMatrixElement(vars, d) << std::endl;

	std::cout << r.generateRowOperation(1, 2, 12314.82371) << std::endl;

	getchar();
	return 0;
}
