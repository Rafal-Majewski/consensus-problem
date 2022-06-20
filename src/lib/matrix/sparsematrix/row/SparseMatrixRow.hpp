#ifndef SPARSEMATRIXROW_HPP_INCLUDED
#define SPARSEMATRIXROW_HPP_INCLUDED

#include "../../row/MatrixRow.hpp"


template <typename I>
class SparseMatrix;

template <typename I>
class SparseMatrixRow : public MatrixRow<I> {
	private:
	public:
};


#include "./SparseMatrixRow.tpp"

#endif // SPARSEMATRIXROW_HPP_INCLUDED
