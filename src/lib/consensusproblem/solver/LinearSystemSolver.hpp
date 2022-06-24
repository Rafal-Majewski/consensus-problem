#ifndef CONSENSUSPROBLEM_LINEARSYSTEMSOLVER_HPP_INCLUDED
#define CONSENSUSPROBLEM_LINEARSYSTEMSOLVER_HPP_INCLUDED

#include "./Solver.hpp"
#include <vector>
#include <map>


namespace ConsensusProblem {
	template <typename DT>
	class LinearSystemSolver : public Solver<DT> {
		private:

		std::vector<Rule*> findApplicableRules(
			const std::vector<short> states,
			const short rulesCount,
			Rule* const* rules
		) const;

		public:

		DT solve(
			const short statesCount,
			const short* targetStates,
			const short* startingStates,
			const short rulesCount,
			Rule* const* rules
		) const override;
	};
}


#endif // CONSENSUSPROBLEM_LINEARSYSTEMSOLVER_HPP_INCLUDED
