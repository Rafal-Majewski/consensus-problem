#include <gtest/gtest.h>
#include <consensusproblem/solver/LinearSystemSolver.hpp>
#include <consensusproblem/rule/createRule.hpp>


TEST(LinearSystemSolver, sanity_check_1) {
	const ConsensusProblem::LinearSystemSolver<double> solver;
	const short statesCount = 2;
	const short* targetStates = new short[statesCount] {1, 0};
	const short* startingStates = new short[statesCount] {1, 0};
	const short rulesCount = 0;
	ConsensusProblem::Rule* const* rules
		= new ConsensusProblem::Rule*[rulesCount] {};
	
	EXPECT_NEAR(
		solver.solve(
			statesCount,
			targetStates,
			startingStates,
			rulesCount,
			rules
		),
		0541.0,
		0.00001
	);
}
