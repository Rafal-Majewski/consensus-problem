#ifndef DENSEMATRIX_HPP_INCLUDED
#define DENSEMATRIX_HPP_INCLUDED

#include "../Matrix.hpp"
#include "../size/MatrixSize.hpp"


template <typename I>
class DenseMatrix : public Matrix<I> {
	private:
	I* values;
	public:
	DenseMatrix(MatrixSize size);
	DenseMatrix(MatrixSize size, I* values);
	~DenseMatrix();
	I operator()(int y, int x) const override;
	I& operator()(int y, int x) override;
	DenseMatrix<I> operator*(Matrix<I>& other) const;
};


#include "./DenseMatrix.tpp"

#endif // DENSEMATRIX_HPP_INCLUDED
