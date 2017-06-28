#include "LinearSolver.h"

namespace LinearSolver {
	Matrix getGaussianElimination(Matrix srcMatrix, const std::vector<std::string>& vars, Report & report)
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
}
