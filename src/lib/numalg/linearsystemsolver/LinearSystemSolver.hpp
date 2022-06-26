#ifndef LINEARSYSTEMSOLVER_HPP_INCLUDED
#define LINEARSYSTEMSOLVER_HPP_INCLUDED

#include <linearsystem/LinearSystem.hpp>


namespace Numalg {
	template <typename DT>
	class LinearSystemSolver {
		public:

		virtual void solve(LinearSystem<DT>& system, DT* solution) const = 0;
	};
}


#include "./LinearSystemSolver.tpp"

#endif // LINEARSYSTEMSOLVER_HPP_INCLUDED
