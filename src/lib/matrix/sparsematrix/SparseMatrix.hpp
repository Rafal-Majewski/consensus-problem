#ifndef SPARSEMATRIX_HPP_INCLUDED
#define SPARSEMATRIX_HPP_INCLUDED

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
	~SparseMatrix();
	I operator()(int y, int x) const override;
	I& operator()(int y, int x) override;
	SparseMatrix<I> operator*(Matrix<I>& other) const;
};


#include "./SparseMatrix.tpp"

#endif // SPARSEMATRIX_HPP_INCLUDED
