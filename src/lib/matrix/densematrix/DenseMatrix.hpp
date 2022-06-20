#ifndef DENSEMATRIX_HPP_INCLUDED
#define DENSEMATRIX_HPP_INCLUDED

#include "../Matrix.hpp"
#include "../size/MatrixSize.hpp"
#include "./row/DenseMatrixRow.hpp"


template <typename I>
class DenseMatrix : public Matrix<I> {
	private:
	DenseMatrixRow<I>* rows;
	public:
	DenseMatrix(MatrixSize size);
	DenseMatrix(MatrixSize size, I* values);
	~DenseMatrix();
	DenseMatrixRow<I>& operator[](int rowIndex) override;
	DenseMatrixRow<I>& operator[](int rowIndex) const override;
	DenseMatrix<I> operator*(Matrix<I>& other) const;
};


#include "./DenseMatrix.tpp"

#endif // DENSEMATRIX_HPP_INCLUDED
