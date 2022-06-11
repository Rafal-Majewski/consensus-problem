#include <gtest/gtest.h>
#include <linearsystem/LinearSystem.hpp>
#include <linearsystem/size/LinearSystemSize.hpp>
#include <solvelinearsystem/partialGauss.hpp>


#include <iostream>

TEST(partialGauss, 1_equation_and_1_variable) {
	LinearSystem<double> system(
		LinearSystemSize(1, 1),
		new double[1]{2.5},
		new double[1]{5.0}
	);
	double* solution = new double[1];
	partialGauss(system, solution);
	EXPECT_NEAR(solution[0], 2.5, 0.00001);
}
