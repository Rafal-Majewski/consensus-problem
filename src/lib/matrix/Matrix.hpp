#ifndef MATRIX_HPP_INCLUDED
#define MATRIX_HPP_INCLUDED

#include "./size/MatrixSize.hpp"
#include "./row/MatrixRow.hpp"


template <typename I>
class Matrix {
	public:
	const MatrixSize size;
	Matrix<I>(MatrixSize size);
	Matrix<I>(MatrixSize size, I* values);
	virtual MatrixRow<I>& operator[](int rowIndex) = 0;
	virtual MatrixRow<I>& operator[](int rowIndex) const = 0;
};


#include "./Matrix.tpp"

#endif // MATRIX_HPP_INCLUDED
