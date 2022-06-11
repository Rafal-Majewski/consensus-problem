#ifndef LINEARSYSTEM_HPP_INCLUDED
#define LINEARSYSTEM_HPP_INCLUDED

#include "./size/LinearSystemSize.hpp"


template <typename DT>
struct LinearSystem {
	const LinearSystemSize size;
	DT** coefficients;
	DT* constants;
	LinearSystem(LinearSystemSize size, DT* coefficients, DT* constants);
	~LinearSystem();
};

#include "./LinearSystem.tpp"

#endif // LINEARSYSTEM_HPP_INCLUDED
