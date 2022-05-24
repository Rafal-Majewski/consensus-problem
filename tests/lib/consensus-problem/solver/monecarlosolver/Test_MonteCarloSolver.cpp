#include <gtest/gtest.h>
#include <consensusproblem/solver/montecarlosolver/MonteCarloSolver.hpp>


TEST(MonteCarloSolver, sanityCheck) {
	using namespace ConsensusProblem;
	std::vector<Rule> rules;
	MonteCarloSolver<double> solver(100);

}