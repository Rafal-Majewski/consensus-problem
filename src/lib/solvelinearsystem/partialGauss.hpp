#ifndef PARTIALGAUSS_HPP_INCLUDED
#define PARTIALGAUSS_HPP_INCLUDED

#include <linearsystem/LinearSystem.hpp>


template <typename DT>
void partialGauss(
	LinearSystem<DT> system,
	DT* solution
);


#include "./partialGauss.tpp"

#endif // PARTIALGAUSS_HPP_INCLUDED
