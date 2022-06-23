#ifndef MONTECARLOSOLVER_HPP_INCLUDED
#define MONTECARLOSOLVER_HPP_INCLUDED

#include "./Solver.hpp"


namespace ConsensusProblem {
	typedef std::pair<std::pair<short, short>, std::pair<short, short>> Rule;

	template <typename DT>
	class MonteCarloSolver : public Solver<DT> {
		private:

		const int iterationsCount;

		bool checkIfRuleIsApplicable(
			const short* states,
			const Rule& rule
		) const;

		short findApplicableRules(
			const short statesCount,
			const short* states,
			const short rulesCount,
			const Rule* rules,
			Rule* applicableRules
		) const;
		// returns the count of applicable rules,
		// and fills the applicableRules array with the applicable rules

		bool simulate(
			const short statesCount,
			short* states,
			const short rulesCount,
			const Rule* rules
		) const;

		bool iteration(
			const short targetState,
			const short statesCount,
			const short* startingStates,
			const short rulesCount,
			const Rule* rules
		) const;

		public:

		MonteCarloSolver(const int iterationsCount);

		DT solve(
			const short targetState,
			const short statesCount,
			const short* startingStates,
			const short rulesCount,
			const Rule* rules
		) const override;
	};
}


#include "./MonteCarloSolver.tpp"

#endif // MONTECARLOSOLVER_HPP_INCLUDED
