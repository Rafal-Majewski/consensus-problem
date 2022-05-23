#ifndef MATRIX_HPP_INCLUDED
#define MATRIX_HPP_INCLUDED

#include "./size/MatrixSize.hpp"

template <typename I>
class Matrix {
	public:
	const MatrixSize size;
	Matrix<I>(const MatrixSize& size);
};

#include "./Matrix.tpp"

#endif // MATRIX_HPP_INCLUDED
