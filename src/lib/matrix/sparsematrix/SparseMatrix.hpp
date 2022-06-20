#ifndef SPARSEMATRIX_HPP_INCLUDED
#define SPARSEMATRIX_HPP_INCLUDED

#include "../Matrix.hpp"
#include "../size/MatrixSize.hpp"
#include "./row/SparseMatrixRow.hpp"
#include <map>


template <typename I>
class SparseMatrix : public Matrix<I> {
	private:
	std::map<std::pair<int, int>, I> values;
	SparseMatrixRow<I> rows[];
	public:
	SparseMatrix(MatrixSize size) override;
	SparseMatrix(MatrixSize size, I* values) override;
	~SparseMatrix();
	SparseMatrixRow<I>& operator[](int rowIndex) override;
	SparseMatrixRow<I>& operator[](int rowIndex) const override;
	SparseMatrix<I> operator*(Matrix<I>& other) const;
};


#include "./SparseMatrix.tpp"

#endif // SPARSEMATRIX_HPP_INCLUDED
