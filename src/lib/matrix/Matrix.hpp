#ifndef MATRIX_HPP_INCLUDED
#define MATRIX_HPP_INCLUDED

#include "./size/MatrixSize.hpp"


template <typename I>
class Matrix {
	public:
	const MatrixSize size;
	Matrix(MatrixSize size);
	Matrix(MatrixSize size, I* values);
	virtual I operator()(int y, int x) const = 0;
	virtual I& operator()(int y, int x) = 0;
};


#include "./Matrix.tpp"

#endif // MATRIX_HPP_INCLUDED
