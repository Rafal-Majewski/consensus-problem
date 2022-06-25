#ifndef LINEARSYSTEM_HPP_INCLUDED
#define LINEARSYSTEM_HPP_INCLUDED

#include "./size/LinearSystemSize.hpp"
#include <matrix/Matrix.hpp>


template <typename DT>
struct LinearSystem {
	const LinearSystemSize size;
	// DT** coefficients;
	Matrix<DT>* coefficients;
	DT* constants;
	// LinearSystem(LinearSystemSize size, DT* coefficients, DT* constants);
	LinearSystem(
		const LinearSystemSize size,
		const Matrix<DT>& coefficients,
		const DT* constants
	);

		//  DT* coefficients, DT* constants);
	LinearSystem(const LinearSystem<DT>& other);
	~LinearSystem();
	void addRows(int targetRowIndex, int sourceRowIndex, DT factor);
	void swapRows(int rowIndex1, int rowIndex2);
};

#include "./LinearSystem.tpp"

#endif // LINEARSYSTEM_HPP_INCLUDED
