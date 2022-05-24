#ifndef DENSEMATRIXROW_HPP_INCLUDED
#define DENSEMATRIXROW_HPP_INCLUDED

#include "../../row/MatrixRow.hpp"

template <typename I>
class DenseMatrix;

template <typename I>
class DenseMatrixRow : public MatrixRow<I> {
	private:
	I *values;
	DenseMatrixRow& operator=(DenseMatrixRow& other);
	public:
	const int size;
	DenseMatrixRow();
	DenseMatrixRow(int size);
	I& operator[](int index) override;
	~DenseMatrixRow();
	friend class DenseMatrix<I>;
};

#include "./DenseMatrixRow.tpp"

#endif // DENSEMATRIXROW_HPP_INCLUDED
