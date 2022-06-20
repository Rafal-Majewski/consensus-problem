#include "./MonteCarloSolver.hpp"


namespace ConsensusProblem {
	template <typename DT>
	DT MonteCarloSolver<DT>::solve(
		const int targetState,
		const int statesCount,
		const int startingStates[],
		const int rulesCount,
		const int rules[][4]
	) const override {
		return 0;
	}
}
