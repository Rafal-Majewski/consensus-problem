#include <gtest/gtest.h>
#include <consensusproblem/solver/MonteCarloSolver.hpp>


TEST(MonteCarloSolver, sanity_check_1) {
	ConsensusProblem::MonteCarloSolver<int> solver(10);
	short targetState = 0;
	short statesCount = 2;
	short* startingStates = new short[statesCount] {1, 0};
	short rulesCount = 0;
	std::pair<std::pair<short, short>, std::pair<short, short>>* rules = {};
	EXPECT_NEAR(
		solver.solve(
			targetState,
			statesCount,
			startingStates,
			rulesCount,
			rules
		),
		1.0,
		0.00001
	);
}
