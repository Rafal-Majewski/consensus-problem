#ifndef LINEARSYSTEMSOLVER_GAUSS_PARTIAL_HPP_INCLUDED
#define LINEARSYSTEMSOLVER_GAUSS_PARTIAL_HPP_INCLUDED

#include "../Gauss.hpp"


namespace Numalg {
	template <typename DT>
	class PartialGauss : public Gauss<DT> {
		private:

		void choose(
			LinearSystem<DT>& system,
			int equationIndex,
			int variableIndex
		) const override;

		public:
	};
}


#include "./PartialGauss.tpp"

#endif // LINEARSYSTEMSOLVER_GAUSS_PARTIAL_HPP_INCLUDED