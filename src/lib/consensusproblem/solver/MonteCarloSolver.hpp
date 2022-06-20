#ifndef MONTECARLOSOLVER_HPP_INCLUDED
#define MONTECARLOSOLVER_HPP_INCLUDED

#include "./Solver.hpp"


namespace ConsensusProblem {
	template <typename DT>
	class MonteCarloSolver : public Solver<DT> {
		const int iterationsCount;
		public:
		MonteCarloSolver(const int iterationsCount);
		DT solve(
			const short targetState,
			const short statesCount,
			const short* startingStates,
			const short rulesCount,
			const std::pair<std::pair<short, short>, std::pair<short, short>>* rules
		) const override;
	};
}


#include "./MonteCarloSolver.tpp"

#endif // MONTECARLOSOLVER_HPP_INCLUDED
