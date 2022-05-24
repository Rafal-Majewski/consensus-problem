#ifndef LINEARSYSTEMSOLVER_HPP_INCLUDED
#define LINEARSYSTEMSOLVER_HPP_INCLUDED

#include "../Solver.hpp"


namespace ConsensusProblem {
	template<typename DT>
	class LinearSystemSolver : public Solver<DT> {
		public:
		DT solve(AgentsState& agentsState) override {
			return DT();
		}
	};
}

#endif
