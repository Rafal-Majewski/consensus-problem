#ifndef LINEARSYSTEMSOLVER_JACOBI_HPP_INCLUDED
#define LINEARSYSTEMSOLVER_JACOBI_HPP_INCLUDED

#include "../LinearSystemSolver.hpp"


namespace Numalg {
	template <typename DT>
	class Jacobi : public LinearSystemSolver<DT> {
		private:

		const DT tolerance;
		const int maxIterations;

		public:

		Jacobi(
			const DT tolerance,
			const int maxIterations
		);

		virtual void solve(
			LinearSystem<DT>& system,
			DT* solution
		) const override;
	};
}


#include "./Jacobi.tpp"

#endif // LINEARSYSTEMSOLVER_JACOBI_HPP_INCLUDED
