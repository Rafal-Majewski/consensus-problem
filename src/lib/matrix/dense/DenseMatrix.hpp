#ifndef MATRIX_DENSE_HPP_INCLUDED
#define MATRIX_DENSE_HPP_INCLUDED

#include "../Matrix.hpp"
#include "../size/MatrixSize.hpp"


template <typename I>
class DenseMatrix : public Matrix<I> {
	private:
	I* values;
	public:
	DenseMatrix(MatrixSize size);
	DenseMatrix(MatrixSize size, I* values);
	DenseMatrix(const DenseMatrix<I>& other);
	~DenseMatrix();
	I operator()(int y, int x) const override;
	I& operator()(int y, int x) override;
	DenseMatrix<I> operator*(DenseMatrix<I> other) const;
	DenseMatrix<I>* clone() const override;
	void swapRows(int rowIndex1, int rowIndex2) override;
};


#include "./DenseMatrix.tpp"

#endif // MATRIX_DENSE_HPP_INCLUDED
