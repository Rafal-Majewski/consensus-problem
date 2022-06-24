#include <gtest/gtest.h>
#include <consensusproblem/solver/MonteCarloSolver.hpp>


TEST(MonteCarloSolver, sanity_check_1) {
	const ConsensusProblem::MonteCarloSolver<double> solver(10);
	const short statesCount = 2;
	const short* targetStates = new short[statesCount] {1, 0};
	const short* startingStates = new short[statesCount] {1, 0};
	const short rulesCount = 0;
	const ConsensusProblem::Rule* const* rules = new ConsensusProblem::Rule*[rulesCount];
	rules[0]->test = 3;
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

// TEST(MonteCarloSolver, sanity_check_2) {
// 	ConsensusProblem::MonteCarloSolver<double> solver(10);
// 	short statesCount = 2;
// 	short* targetStates = new short[statesCount] {0, 1};
// 	short* startingStates = new short[statesCount] {1, 0};
// 	short rulesCount = 0;
// 	ConsensusProblem::Rule* rules = new ConsensusProblem::Rule[rulesCount];
// 	EXPECT_NEAR(
// 		solver.solve(
// 			statesCount,
// 			targetStates,
// 			startingStates,
// 			rulesCount,
// 			rules
// 		),
// 		0.0,  // not possible to reach the target state
// 		0.00001
// 	);
// }


// TEST(MonteCarloSolver, sanity_check_3) {
// 	ConsensusProblem::MonteCarloSolver<double> solver(1000);
// 	// more iterations to make sure
// 	// the result value is not affected by randomness

// 	short statesCount = 2;
// 	short* targetStates = new short[statesCount] {10, 0};
// 	short* startingStates = new short[statesCount] {5, 5};
// 	short rulesCount = 2;
// 	ConsensusProblem::Rule* rules = new ConsensusProblem::Rule[rulesCount] {
// 		{{0, 1}, {0, 0}},
// 		{{1, 0}, {1, 1}}
// 	};
// 	EXPECT_NEAR(
// 		solver.solve(
// 			statesCount,
// 			targetStates,
// 			startingStates,
// 			rulesCount,
// 			rules
// 		),
// 		0.5,
// 		0.1  // allow some error
// 	);
// }

// TEST(MonteCarloSolver, complex_check_1) {
// 	ConsensusProblem::MonteCarloSolver<double> solver(800000);

// 	short statesCount = 3;
// 	short* targetStates = new short[statesCount] {26, 0, 0};
// 	short* startingStates = new short[statesCount] {10, 4, 12};
// 	short rulesCount = 3;
// 	ConsensusProblem::Rule* rules = new ConsensusProblem::Rule[rulesCount] {
// 		{{0, 1}, {0, 0}},
// 		{{2, 1}, {2, 2}},
// 		{{0, 2}, {1, 1}}
// 	};
// 	EXPECT_NEAR(
// 		solver.solve(
// 			statesCount,
// 			targetStates,
// 			startingStates,
// 			rulesCount,
// 			rules
// 		),
// 		111,
// 		0.0005  // allow some error
// 	);
// }
