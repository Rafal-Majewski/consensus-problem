#ifndef CONSENSUSPROBLEM_LINEARSYSTEMSOLVER_HPP_INCLUDED
#define CONSENSUSPROBLEM_LINEARSYSTEMSOLVER_HPP_INCLUDED

#include "./Solver.hpp"
#include <vector>
#include <map>


namespace ConsensusProblem {
	template <typename DT>
	class LinearSystemSolver : public Solver<DT> {
		private:

		void buildRec(
			const std::vector<short> states,
			const short rulesCount,
			Rule* const* rules,
			std::map<std::vector<short>, std::vector<Rule*>>* rulesByStates
		) const;

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


#include "./LinearSystemSolver.tpp"

#endif // CONSENSUSPROBLEM_LINEARSYSTEMSOLVER_HPP_INCLUDED
