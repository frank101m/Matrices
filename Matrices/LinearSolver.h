#pragma once
#include "Report.h"

namespace LinearSolver {
	Matrix getGaussianElimination(
		Matrix srcMatrix,
		const std::vector<std::string> &vars,
		Report &report
	);

	Matrix getJacobiMethod(
		const Matrix &srcMatrix,
		const Matrix &initialGuess
	);
};