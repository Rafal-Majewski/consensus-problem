#ifndef MONTECARLOSOLVER_HPP_INCLUDED
#define MONTECARLOSOLVER_HPP_INCLUDED

#include "./Solver.hpp"


namespace ConsensusProblem {
	template <typename DT>
	class MonteCarloSolver : public Solver<DT> {
		private:

		const int iterationsCount;

		// short findApplicableRules(
		// 	const short statesCount,
		// 	const short* states,
		// 	const short rulesCount,
		// 	const Rule* const* rules,
		// 	Rule* const* applicableRules
		// ) const;
		// // returns the count of applicable rules,
		// // and fills the applicableRules array with the applicable rules
	
		// void applyRule(
		// 	short* states,
		// 	const Rule const* rule
		// ) const;
		

		// void simulate(
		// 	const short statesCount,
		// 	short* states,
		// 	const short rulesCount,
		// 	const Rule** rules
		// ) const;

		// void tmp(
		// 	short statesCount,
		// 	short* states,
		// 	const short applicableRulesCount,
		// 	const Rule** applicableRules
		// ) const;

		// bool iteration(
		// 	const short statesCount,
		// 	const short* targetStates,
		// 	const short* startingStates,
		// 	const short rulesCount,
		// 	const Rule* const* rules
		// ) const;

		public:

		MonteCarloSolver(const int iterationsCount);

		DT solve(
			const short statesCount,
			const short* targetStates,
			const short* startingStates,
			const short rulesCount,
			const Rule* const* rules
		) const override;
	};
}


#include "./MonteCarloSolver.tpp"

#endif // MONTECARLOSOLVER_HPP_INCLUDED
