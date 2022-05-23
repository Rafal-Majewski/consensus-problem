#ifndef DENSEMATRIX_HPP_INCLUDED
#define DENSEMATRIX_HPP_INCLUDED

#include "../Matrix.hpp"
#include "../size/MatrixSize.hpp"


template <typename I>
class DenseMatrix : public Matrix<I> {
	private:
	I **values;
	public:
	DenseMatrix(MatrixSize size);
	DenseMatrix(MatrixSize size, I *values);
	~DenseMatrix();
};

#include "./DenseMatrix.tpp"

#endif // DENSEMATRIX_HPP_INCLUDED
