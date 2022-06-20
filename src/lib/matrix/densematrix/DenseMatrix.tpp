#include "./DenseMatrix.hpp"


template <typename I>
DenseMatrix<I>::DenseMatrix(MatrixSize size) : Matrix<I>(size) {
	this->rows = new DenseMatrixRow<I>[this->size.rowsCount];
	for (int y = 0; y < this->size.rowsCount; y++) {
		DenseMatrixRow<I> row(this->size.columnsCount);
		this->rows[y] = row;
	}
};

template <typename I>
DenseMatrix<I>::DenseMatrix(MatrixSize size, I *values) : DenseMatrix(size) {
	for (int i = 0, y = 0; y < this->size.rowsCount; ++y) {
		for (int x = 0; x < this->size.columnsCount; ++x, ++i) {
			this->rows[y][x] = values[i];
		}
	}
};

template <typename I>
DenseMatrix<I>::~DenseMatrix() {
	delete[] this->rows;
};

template <typename I>
DenseMatrixRow<I>& DenseMatrix<I>::operator[](int rowIndex) {
	return this->rows[rowIndex];
};

template <typename I>
DenseMatrixRow<I>& DenseMatrix<I>::operator[](int rowIndex) const {
	return this->rows[rowIndex];
};

template <typename I>
DenseMatrix<I> DenseMatrix<I>::operator*(Matrix<I>& other) const {
	DenseMatrix<I> result(this->size * other.size);
	for (int y = 0; y < this->size.rowsCount; ++y) {
		for (int x = 0; x < other.size.columnsCount; ++x) {
			I sum = 0;
			for (int i = 0; i < this->size.columnsCount; ++i) {
				sum += (*this)[y][i] * other[i][x];
			}
			result[y][x] = sum;
		}
	}
	return result;
};
