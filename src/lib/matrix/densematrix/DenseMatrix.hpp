#ifndef DENSEMATRIX_HPP_INCLUDED
#define DENSEMATRIX_HPP_INCLUDED

#include "../Matrix.hpp"
#include "../size/MatrixSize.hpp"
#include "./row/DenseMatrixRow.hpp"


template <typename I>
class DenseMatrix : public Matrix<I> {
	private:
	DenseMatrixRow<I>* values;
	public:
	DenseMatrix(MatrixSize size);
	DenseMatrix(MatrixSize size, I* values);
	~DenseMatrix();
	DenseMatrixRow<I>& operator[](int rowIndex);
};

#include "./DenseMatrix.tpp"

#endif // DENSEMATRIX_HPP_INCLUDED
