#include <gtest/gtest.h>
#include <consensusproblem/solver/MonteCarloSolver.hpp>
#include <consensusproblem/rule/createRule.hpp>


TEST(MonteCarloSolver, sanity_check_1) {
	const ConsensusProblem::MonteCarloSolver<double> solver(10);
	const short statesCount = 2;
	const short* targetStates = new short[statesCount] {1, 0};
	const short* startingStates = new short[statesCount] {1, 0};
	const short rulesCount = 0;
	ConsensusProblem::Rule* const* rules =
			new ConsensusProblem::Rule*[rulesCount] {};
	
	EXPECT_NEAR(
		solver.solve(
			statesCount,
			targetStates,
			startingStates,
			rulesCount,
			rules
		),
		1.0,
		0.00001
	);
}

TEST(MonteCarloSolver, sanity_check_2) {
	const ConsensusProblem::MonteCarloSolver<double> solver(10);
	const short statesCount = 2;
	const short* targetStates = new short[statesCount] {0, 1};
	const short* startingStates = new short[statesCount] {1, 0};
	const short rulesCount = 0;
	ConsensusProblem::Rule* const* rules =
		new ConsensusProblem::Rule*[rulesCount] {};

	EXPECT_NEAR(
		solver.solve(
			statesCount,
			targetStates,
			startingStates,
			rulesCount,
			rules
		),
		0.0,  // not possible to reach the target state
		0.00001
	);
}


TEST(MonteCarloSolver, task_4_0_4) {
	const ConsensusProblem::MonteCarloSolver<double> solver(10000);
	// more iterations to make sure
	// the result value is not affected by randomness

	const short statesCount = 3;
	const short* targetStates = new short[statesCount] {8, 0, 0};
	const short* startingStates = new short[statesCount] {4, 0, 4};
	const short rulesCount = 3;
	ConsensusProblem::Rule* const* rules =
		new ConsensusProblem::Rule*[rulesCount] {
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
		0.5,
		0.08  // allow some error
	);
}
