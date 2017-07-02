#pragma once
#include "Report.h"

namespace LinearSolver {
	Matrix getGaussianElimination(
		Matrix srcMatrix,
		const std::vector<std::string> &vars,
		Report &report
	);

	Matrix getJacobiMethod(
		const Matrix &A,
		const Matrix &CO,
		const Matrix &XO,
		const double tol,
		const size_t NMax,
		const std::vector<std::string> &vars,
		Report &report
	);

	std::vector<double> getBackSubstitution(
		const Matrix &gaussReduc,
		const std::vector<std::string> &vars,
		Report &report
	);
};