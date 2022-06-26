#ifndef LINEARSYSTEMSOLVER_GAUSSSEIDEL_HPP_INCLUDED
#define LINEARSYSTEMSOLVER_GAUSSSEIDEL_HPP_INCLUDED

#include "../LinearSystemSolver.hpp"


namespace Numalg {
	template <typename DT>
	class GaussSeidel : public LinearSystemSolver<DT> {
		private:

		const DT tolerance;
		const int maxIterations;

		public:

		GaussSeidel(
			const DT tolerance,
			const int maxIterations
		);

		virtual void solve(
			LinearSystem<DT>& system,
			DT* solution
		) const override;
	};
}


#include "./GaussSeidel.tpp"

#endif // LINEARSYSTEMSOLVER_GAUSSSEIDEL_HPP_INCLUDED
