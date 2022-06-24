#ifndef MONTECARLOSOLVER_HPP_INCLUDED
#define MONTECARLOSOLVER_HPP_INCLUDED

#include "./Solver.hpp"


namespace ConsensusProblem {
	template <typename DT>
	class MonteCarloSolver : public Solver<DT> {
		private:

		const int iterationsCount;

		short findApplicableRules(
			const short statesCount,
			const short* states,
			const short rulesCount,
			Rule* const* rules,
			Rule** applicableRules
		) const;
		// returns the count of applicable rules,
		// and fills the applicableRules array with the applicable rules
		
		void updateStates(
			const short statesCount,
			short* states,
			const short applicableRulesCount,
			Rule* const* applicableRules
		) const;

		void simulate(
			const short statesCount,
			short* states,
			const short rulesCount,
			Rule* const* rules
		) const;

		bool iteration(
			const short statesCount,
			const short* targetStates,
			const short* startingStates,
			const short rulesCount,
			Rule* const* rules
		) const;

		public:

		MonteCarloSolver(const int iterationsCount);

		DT solve(
			const short statesCount,
			const short* targetStates,
			const short* startingStates,
			const short rulesCount,
			Rule* const* rules
		) const override;
	};
}


#include "./MonteCarloSolver.tpp"

#endif // MONTECARLOSOLVER_HPP_INCLUDED
