#include "./SparseMatrix.hpp"


template <typename I>
SparseMatrix<I>::SparseMatrix(MatrixSize size) : Matrix<I>(size) {
}

template <typename I>
SparseMatrix<I>::SparseMatrix(MatrixSize size, I* values) : SparseMatrix(size) {
	int totalCellsCount = this->size.rowsCount * this->size.columnsCount;
	for (int i = 0, y = 0; y < this->size.rowsCount; ++y) {
		for (int x = 0; x < this->size.columnsCount; ++x, ++i) {
			if (values[i] == 0) continue;
			this->values[std::make_pair(y, x)] = values[i];
		}
	}
}

template <typename I>
SparseMatrix<I>::~SparseMatrix() {
}

template <typename I>
I SparseMatrix<I>::operator()(int y, int x) const {
	auto it = this->values.find(std::make_pair(y, x));
	if (it == this->values.end()) return 0;
	return it->second;
}

template <typename I>
I& SparseMatrix<I>::operator()(int y, int x) {
	return this->values[std::make_pair(y, x)];
}

template <typename I>
SparseMatrix<I> SparseMatrix<I>::operator*(Matrix<I>& other) const {
	SparseMatrix<I> result(MatrixSize(this->size.rowsCount, other.size.columnsCount));
	for (int y = 0; y < this->size.rowsCount; ++y) {
		for (int x = 0; x < other.size.columnsCount; ++x) {
			I sum = 0;
			for (int i = 0; i < this->size.columnsCount; ++i) {
				sum += (*this)(y, i) * other(i, x);
			}
			result(y, x) = sum;
		}
	}
	return result;
}
