#ifndef SOLVER_HPP_INCLUDED
#define SOLVER_HPP_INCLUDED

#include "../agentsstate/AgentsState.hpp"


namespace ConsensusProblem {
	template<typename DT>
	class Solver {
		public:
		virtual DT solve(AgentsState& agentsState) = 0;
	};
}


#endif
