#ifndef CONSENSUSPROBLEM_LINEARSYSTEMSOLVER_HPP_INCLUDED
#define CONSENSUSPROBLEM_LINEARSYSTEMSOLVER_HPP_INCLUDED

#include "./Solver.hpp"


namespace ConsensusProblem {
	template <typename DT>
	class LinearSystemSolver : public Solver<DT> {
		public:
		void solve(
			const short statesCount,
			const short* targetStates,
			const short* startingStates,
			const short rulesCount,
			Rule* const* rules
		) const override;
	};
}


#endif // CONSENSUSPROBLEM_LINEARSYSTEMSOLVER_HPP_INCLUDED
