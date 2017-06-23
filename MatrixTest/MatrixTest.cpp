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


	Report r(10);

	std::vector<std::string> vars;

	vars.push_back("a_1");
	vars.push_back("a_2");
	vars.push_back("a_3");
	vars.push_back("a_4");


	std::vector<RowOperationParameter> params;

	for (int i = 0; i < 4; i++) {
		RowOperationParameter tempParam;
		tempParam.i = i + 1;
		tempParam.j = i;
		tempParam.m = i / 3.0;
		params.push_back(tempParam);
	}

	r.initializeReportBody();
	Matrix d = c.getGaussianElimination(vars, r);
	r.endReportBody();

	std::cout << r.getReportBody() << std::endl;

	return 0;
}
