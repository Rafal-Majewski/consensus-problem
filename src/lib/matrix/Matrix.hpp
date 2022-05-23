#ifndef MATRIX_H_INCLUDED
#define MATRIX_H_INCLUDED

#include "./size/MatrixSize.hpp"

template <typename I>
class Matrix {
	public:
	const MatrixSize size;
	Matrix<I>(const MatrixSize& size);
};

#include "./Matrix.tpp"

#endif // MATRIX_H_INCLUDED
