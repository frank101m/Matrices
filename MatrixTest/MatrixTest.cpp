// MatrixTest.cpp: define el punto de entrada de la aplicación de consola.
//

#ifdef _WIN32
#include "stdafx.h"
#endif // 

#include <iostream>
#include "../Matrices/LinearSolver.cpp"
#include "../Matrices/Matrix.cpp"
#include "../Matrices/Report.cpp"



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



	size_t randomOrder = 4;

	for (int i = 0; i < randomOrder; i++) {
		std::ostringstream var;
		var << "a_";
		var << (i + 1);
		vars.push_back(var.str());
	}

	Matrix CO(randomOrder, 1);

	for (int i = 0; i < randomOrder; i++) {
		double randVal = (std::rand()) / (std::rand() + 1.0)*pow(-1, std::rand());
		CO.set(i, 0, randVal);
	}

	std::vector<Matrix> gaussmvec;
	std::vector<std::vector<RowOperationParameter> > ops;

	for (int k = 0; k < randomOrder; k++) {
		Matrix randM(randomOrder, randomOrder);

		for (int i = 0; i < randomOrder ; i++) {
			for (int j = 0; j < randomOrder; j++) {
				double randVal = (std::rand()) / (std::rand() + 1.0)*pow(-1, std::rand());
				randM.set(i, j, randVal);
			}
		}

		std::vector<RowOperationParameter>  rowOps;

		for (int i = 0; i < randomOrder; i++) {
			double randVal = (std::rand())*pow(-1, std::rand());
			RowOperationParameter tempOp;
			tempOp.i = i + 1;
			tempOp.j = k + 1;
			tempOp.m = randVal;
			tempOp.skip = false;

			rowOps.push_back(tempOp);

		}

		gaussmvec.push_back(randM);
		ops.push_back(rowOps);
	}

	Matrix gaussTest(randomOrder, randomOrder + 1);

	for (int i = 0; i < randomOrder; i++) {
		for (int j = 0; j < randomOrder; j++ ) {
			double randVal = (std::rand());
			gaussTest.set(i, j, randVal);
		}
	}

	for (int i = 0; i < randomOrder; i++) {
		double randVal = (std::rand())*pow(-1, std::rand());
		CO.set(i, 0, randVal);
	}


	//std::cout << r.getReportBody() << std::endl;


	Matrix XN = LinearSolver::getJacobiMethod(A, C, X, 0.0001, 100, vars, r);
	Matrix gaussReduc = LinearSolver::getGaussianElimination(gaussTest,CO, vars, r);
	Matrix Xvec = LinearSolver::getBackSubstitution(gaussReduc, vars, r);

	std::cout << r.getReportBody() << std::endl;

	return 0;
}
