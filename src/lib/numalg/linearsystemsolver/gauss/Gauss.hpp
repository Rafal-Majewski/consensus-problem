#ifndef LINEARSYSTEMSOLVER_GAUSS_HPP_INCLUDED
#define LINEARSYSTEMSOLVER_GAUSS_HPP_INCLUDED

#include "../LinearSystemSolver.hpp"


namespace Numalg {
	template <typename DT>
	class Gauss : public LinearSystemSolver<DT> {
		private:

		void extractSolution(
			LinearSystem<DT>& system,
			DT* solution
		) const;

		void eliminate(
			LinearSystem<DT>& system
		) const;

		virtual void choose(
			LinearSystem<DT>& system,
			int equationIndex,
			int variableIndex
		) const;

		public:

		virtual void solve(
			LinearSystem<DT>& system,
			DT* solution
		) const override;
	};
}


#include "./Gauss.tpp"

#endif // LINEARSYSTEMSOLVER_GAUSS_HPP_INCLUDED
