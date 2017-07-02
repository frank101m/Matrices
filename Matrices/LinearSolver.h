#pragma once
#include "Report.h"

namespace LinearSolver {
	Matrix getGaussianElimination(
		const Matrix &srcMatrix,
		const Matrix &CO,
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

	Matrix getBackSubstitution(
		const Matrix &gaussReduc,
		const std::vector<std::string> &vars,
		Report &report
	);
};