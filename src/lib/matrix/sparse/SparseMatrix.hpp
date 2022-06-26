#ifndef MATRIX_SPARSE_HPP_INCLUDED
#define MATRIX_SPARSE_HPP_INCLUDED

#include "../Matrix.hpp"
#include "../size/MatrixSize.hpp"
#include <map>


template <typename I>
class SparseMatrix : public Matrix<I> {
	private:
	std::map<std::pair<int, int>, I> values;
	public:
	SparseMatrix(MatrixSize size);
	SparseMatrix(MatrixSize size, I* values);
	SparseMatrix(MatrixSize size, const std::map<std::pair<int, int>, I>& values);
	SparseMatrix(const SparseMatrix<I>& other);
	~SparseMatrix();
	I operator()(int y, int x) const override;
	I& operator()(int y, int x) override;
	SparseMatrix<I> operator*(SparseMatrix<I> other) const;
	SparseMatrix<I>* clone() const override;
	void swapRows(int rowIndex1, int rowIndex2) override;
	static SparseMatrix<I> zero(MatrixSize size);
};


#include "./SparseMatrix.tpp"

#endif // MATRIX_SPARSE_HPP_INCLUDED
