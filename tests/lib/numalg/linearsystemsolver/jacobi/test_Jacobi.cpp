#include <gtest/gtest.h>
#include <linearsystem/LinearSystem.hpp>
#include <linearsystem/size/LinearSystemSize.hpp>
#include <numalg/linearsystemsolver/jacobi/Jacobi.hpp>
#include <matrix/dense/DenseMatrix.hpp>
#include <matrix/size/MatrixSize.hpp>

#define MAX_ERROR 0.001


TEST(Numalg_Jacobi, 1_equation_and_1_variable) {
	LinearSystem<double> system(
		LinearSystemSize(1, 1),
		DenseMatrix<double>(MatrixSize(1, 1), new double[1]{2.5}),
		new double[1]{5.0}
	);
	double* solution = new double[1];
	const Numalg::Jacobi<double> solver(0.0000001, 1000);
	solver.solve(system, solution);
	EXPECT_NEAR(solution[0], 2.0, MAX_ERROR);
}

TEST(Numalg_Jacobi, 2_equations_and_2_variables) {
	LinearSystem<double> system(
		LinearSystemSize(2, 2),
		DenseMatrix<double>(MatrixSize(2, 2), new double[4]{
			-2.0, 1.0,
			5.0, 3.0
		}),
		new double[2]{
			-10.0, 3.0
		}
	);
	double* solution = new double[2];
	const Numalg::Jacobi<double> solver(0.0000001, 1000);
	solver.solve(system, solution);
	EXPECT_NEAR(solution[0], 3.0, MAX_ERROR);
	EXPECT_NEAR(solution[1], -4.0, MAX_ERROR);
}
