#include "./DenseMatrix.hpp"


template <typename I>
DenseMatrix<I>::DenseMatrix(MatrixSize size) : Matrix<I>(size) {
	this->values = new I[this->size.rowsCount * this->size.columnsCount];
};

template <typename I>
DenseMatrix<I>::DenseMatrix(MatrixSize size, I* values) : DenseMatrix(size) {
	int totalCellsCount = this->size.rowsCount * this->size.columnsCount;
	for (int i = 0; i < totalCellsCount; ++i) {
		this->values[i] = values[i];
	}
};

template <typename I>
DenseMatrix<I>::~DenseMatrix() {
	delete[] this->values;
};

template <typename I>
I& DenseMatrix<I>::operator()(int y, int x) {
	return this->values[y * this->size.columnsCount + x];
}

template <typename I>
I DenseMatrix<I>::operator()(int y, int x) const {
	return this->values[y * this->size.columnsCount + x];
}

template <typename I>
DenseMatrix<I> DenseMatrix<I>::operator*(Matrix<I>& other) const {
	DenseMatrix<I> result(MatrixSize(this->size.rowsCount, other.size.columnsCount));
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
};
