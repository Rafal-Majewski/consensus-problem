#include <gtest/gtest.h>
#include <consensusproblem/solver/LinearSystemSolver.hpp>
#include <consensusproblem/rule/createRule.hpp>
#include <matrix/dense/DenseMatrix.hpp>
#include <numalg/linearsystemsolver/gauss/partial/PartialGauss.hpp>


// TEST(ConsensusProblem_LinearSystemSolver, sanity_check_1) {
// 	const ConsensusProblem::LinearSystemSolver<double> solver;
// 	const short statesCount = 2;
// 	const short* targetStates = new short[statesCount] {1, 0};
// 	const short* startingStates = new short[statesCount] {1, 0};
// 	const short rulesCount = 0;
// 	ConsensusProblem::Rule* const* rules
// 		= new ConsensusProblem::Rule*[rulesCount] {};
	
// 	EXPECT_NEAR(
// 		solver.solve(
// 			statesCount,
// 			targetStates,
// 			startingStates,
// 			rulesCount,
// 			rules
// 		),
// 		0541.0,
// 		0.00001
// 	);
// }

TEST(ConsensusProblem_LinearSystemSolver, task_1_1_1) {
	const Numalg::PartialGauss<double> partialGauss;
	const ConsensusProblem::LinearSystemSolver<double, DenseMatrix<double>> solver(&partialGauss);
	// more iterations to make sure
	// the result value is not affected by randomness

	const short statesCount = 3;
	const short* targetStates = new short[statesCount] {3, 0, 0};
	const short* startingStates = new short[statesCount] {1, 1, 1};
	const short rulesCount = 3;
	ConsensusProblem::Rule* const* rules
		= new ConsensusProblem::Rule*[rulesCount] {
			ConsensusProblem::createRule(
				{0, 1},
				{0, 0}
			),
			ConsensusProblem::createRule(
				{2, 1},
				{2, 2}
			),
			ConsensusProblem::createRule(
				{0, 2},
				{1, 1}
			)
		};
	EXPECT_NEAR(
		solver.solve(
			statesCount,
			targetStates,
			startingStates,
			rulesCount,
			rules
		),
		1.0/3.0,
		0.0000001
	);
}
