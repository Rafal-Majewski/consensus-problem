#ifndef MONTECARLOSOLVER_HPP
#define MONTECARLOSOLVER_HPP

#include "../Solver.hpp"


namespace ConsensusProblem {
	template<typename DT>
	class MonteCarloSolver : public Solver<DT> {
		public:
		DT solve(AgentsState& agentsState) override {
			return DT();
		}
	};
}

#endif
