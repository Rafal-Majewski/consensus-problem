#ifndef CONSENSUSPROBLEMSOLVER_HPP_INCLUDED
#define CONSENSUSPROBLEMSOLVER_HPP_INCLUDED


namespace ConsensusProblem {
	template <typename DT>
	class Solver {
		virtual DT solve(
			const int targetState,
			const int statesCount,
			const int startingStates[],
			const int rulesCount,
			const int rules[][4]
		) = 0 const;
	};
}


#endif // CONSENSUSPROBLEMSOLVER_HPP_INCLUDED
