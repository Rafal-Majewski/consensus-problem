#ifndef CONSENSUSPROBLEMSOLVER_HPP_INCLUDED
#define CONSENSUSPROBLEMSOLVER_HPP_INCLUDED

#include <utility>
#include "../rule/Rule.hpp"


namespace ConsensusProblem {
	template <typename DT>
	class Solver {
		public:
		virtual DT solve(
			const short statesCount,
			const short* targetStates,
			const short* startingStates,
			const short rulesCount,
			Rule* const* rules
		) const = 0;
	};
}


#endif // CONSENSUSPROBLEMSOLVER_HPP_INCLUDED
