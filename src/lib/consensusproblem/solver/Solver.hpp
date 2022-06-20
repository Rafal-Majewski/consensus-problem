#ifndef CONSENSUSPROBLEMSOLVER_HPP_INCLUDED
#define CONSENSUSPROBLEMSOLVER_HPP_INCLUDED

#include <utility>


namespace ConsensusProblem {
	template <typename DT>
	class Solver {
		public:
		virtual DT solve(
			const short targetState,
			const short statesCount,
			const short* startingStates,
			const short rulesCount,
			const std::pair<std::pair<short, short>, std::pair<short, short>>* rules
		) const = 0;
	};
}


#endif // CONSENSUSPROBLEMSOLVER_HPP_INCLUDED
