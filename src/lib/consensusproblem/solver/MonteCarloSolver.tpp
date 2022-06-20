#include "./MonteCarloSolver.hpp"


namespace ConsensusProblem {
	template <typename DT>
	MonteCarloSolver<DT>::MonteCarloSolver(
		const int iterationsCount
	) : iterationsCount(iterationsCount) {}

	template <typename DT>
	DT MonteCarloSolver<DT>::solve(
		const short targetState,
		const short statesCount,
		const short* startingStates,
		const short rulesCount,
		const std::pair<std::pair<short, short>, std::pair<short, short>>* rules
	) const {
		return 0;
	}
}
