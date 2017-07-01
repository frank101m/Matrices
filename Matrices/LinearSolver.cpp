#include "LinearSolver.h"

namespace LinearSolver {
	Matrix getGaussianElimination(
		Matrix srcMatrix,
		const std::vector<std::string>& vars,
		Report & report
	)
	{
		Matrix t = srcMatrix;

		Matrix currentRow(0, 0);
		int p = 0; //Fila del pivote
		int n = t.getRowsCount();
		double m; //Valor del pivote
		int reportOpIndex = 1;

		for (int i = 0; i < n; i++) {
			std::vector<RowOperationParameter> params;

			for (int paramIndex = 0; paramIndex < n; paramIndex++) {
				RowOperationParameter tempParam;
				tempParam.skip = true;
				params.push_back(tempParam);
			}

			p = i;

			if (t.at(p, i) == 0.0) {
				p = t.rowNonZeroElementIndex(i, i, t);
			}

			//Solucion multiple
			if (p == -1) {
				return t;
			}

			//Intercamio con pivote no nulo
			else if (p != i) {
				std::vector<RowOperationParameter> swapRowParams;

				for (int paramIndex = 0; paramIndex < n; paramIndex++) {
					RowOperationParameter tempSwapRowParam;
					tempSwapRowParam.skip = true;
					swapRowParams.push_back(tempSwapRowParam);
				}

				swapRowParams.at(i).skip = false;
				swapRowParams.at(i).swap = true;
				swapRowParams.at(i).i = i + 1;
				swapRowParams.at(i).j = p + 1;

				t.swapRows(p,i);

				report.addGaussOpMatrix(reportOpIndex, vars, swapRowParams, t);
				reportOpIndex++;
			}

			for (int j = i + 1; j < n; j++) {
				m = t.at(j, i) / t.at(i, i);

				params.at(j).i = i + 1;
				params.at(j).j = j + 1;
				params.at(j).m = m;
				params.at(j).skip = false;

				currentRow = t.getRow(j) - t.getRow(i) * m;
				t.setRow(j, currentRow);
			}

			//if (i != n - 1) {
				report.addGaussOpMatrix(reportOpIndex, vars, params, t);
			//}
			reportOpIndex++;
		}
		return t;
	}

	//Método de Jacobi para solución de ecuaciones lineales
	Matrix getJacobiMethod(
		const Matrix & A,
		const Matrix &CO,
		const Matrix &XO,
		const double tol,
		const size_t NMax,
		const std::vector<std::string> &vars,
		Report &report)
	{
		size_t n = A.getRowsCount();

		Matrix T(n, n);
		Matrix X(n, 1);
		Matrix C(n, 1);

		for (int i = 0; i < n; i++) {
			X.set(i, 0, XO.at(i, 0));
		}


		for (int i = 0; i < n; i++) {
			T.setRow(i, A.getRow(i)*(-1.0 / A.at(i, i)));
			T.set(i, i, 0);
			C.setRow(i, CO.getRow(i)*(1.0 / A.at(i, i)));
		}

		std::vector<Matrix> XN;

		report.addLinEq(Report::DEF_JACOBI_SEL, vars, A, CO);
		report.addMatrix(Report::DEF_JACOBI_MATRIX_A, A);
		report.addMatrix(Report::DEF_JACOBI_MATRIX_T, T);
		report.addMatrix(Report::DEF_JACOBI_MATRIX_C, C);
		report.addMatrix(Report::DEF_JACOBI_MATRIX_XO, XO);

		XN.push_back(XO);

		for (int i = 0; i < NMax; i++) {
			Matrix X_p = X;
			X = (T*X) + C;
			XN.push_back(X);

			if (std::abs(X_p.infNorm() - X.infNorm()) < tol) {
				break;
			}
		}

		report.addJacobiTables(vars, XN);

		return X;
	}
}
