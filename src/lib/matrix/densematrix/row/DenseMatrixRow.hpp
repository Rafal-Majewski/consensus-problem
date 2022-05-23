#ifndef DENSEMATRIXROW_HPP_INCLUDED
#define DENSEMATRIXROW_HPP_INCLUDED

#include "../../row/MatrixRow.hpp"


template <typename I>
class DenseMatrixRow : public MatrixRow<I> {
	private:
	I *values;
	public:
	DenseMatrixRow();
	DenseMatrixRow(int size);
	I& operator[](int index) override;
};

#include "./DenseMatrixRow.tpp"

#endif // DENSEMATRIXROW_HPP_INCLUDED
