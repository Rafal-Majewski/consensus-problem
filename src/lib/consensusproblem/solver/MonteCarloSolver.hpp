#ifndef MONTECARLOSOLVER_HPP_INCLUDED
#define MONTECARLOSOLVER_HPP_INCLUDED

#include "./Solver.hpp"


namespace ConsensusProblem {
	template <typename DT>
	class MonteCarloSolver : public Solver<DT> {
		DT solve(
			const int targetState,
			const int statesCount,
			const int startingStates[],
			const int rulesCount,
			const int rules[][4]
		) const override;
	};
}


#include "./MonteCarloSolver.tpp"

#endif // MONTECARLOSOLVER_HPP_INCLUDED
