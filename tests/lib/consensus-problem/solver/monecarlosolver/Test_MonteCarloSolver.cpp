#include <gtest/gtest.h>
#include <consensusproblem/solver/montecarlosolver/MonteCarloSolver.hpp>


TEST(MonteCarloSolver, sanityCheck) {
	using namespace Consensus Problem;
	std::vector<Rule> rules {
		Rule(std::make_pair(-1, 1), std::make_pair(1, 1)),
		Rule(std::make_pair(1, -1), std::make_pair(1, -1))
	};
	MonteCarloSolver<double> solver(100);
	AgentsState initialState(10, 0, 0);
	double result = solver.solve(rules, initialState);
	// EXPECT_NEAR(result, 0.5, 0.1);
	EXPECT_DOUBLE_EQ(result, 1);
}


TEST(MonteCarloSolver, sanityCheck) {
	using namespace ConsensusProblem;
	std::vector<Rule> rules {
		Rule(std::make_pair(-1, 1), std::make_pair(1, 1)),
		Rule(std::make_pair(1, -1), std::make_pair(1, -1))
	};
	MonteCarloSolver<double> solver(100);
	AgentsState initialState(2, 0, 2);
	double result = solver.solve(rules, initialState);
	// EXPECT_NEAR(result, 0.5, 0.1);
	EXPECT_DOUBLE_EQ(result, 1);
}