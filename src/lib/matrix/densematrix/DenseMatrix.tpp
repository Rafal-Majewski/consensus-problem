#include "./DenseMatrix.hpp"


template <typename I>
DenseMatrix<I>::DenseMatrix(MatrixSize a_size) : Matrix<I>(a_size) {
	values = new DenseMatrixRow<I>[this->size.rowsCount];
	for (int y = 0; y < this->size.rowsCount; y++) {
		DenseMatrixRow<I> row(this->size.columnsCount);
		values[y] = row;
	}
};

template <typename I>
DenseMatrix<I>::DenseMatrix(MatrixSize a_size, I *a_values) : DenseMatrix(a_size) {
	for (int i = 0, y = 0; y < this->size.rowsCount; ++y) {
		for (int x = 0; x < this->size.columnsCount; ++x, ++i) {
			values[y][x] = a_values[i];
		}
	}
};

template <typename I>
DenseMatrix<I>::~DenseMatrix() {
	delete[] values;
};

template <typename I>
DenseMatrixRow<I>& DenseMatrix<I>::operator[](int rowIndex) {
	return values[rowIndex];
};

template <typename I>
DenseMatrixRow<I>& DenseMatrix<I>::operator[](int rowIndex) const {
	return values[rowIndex];
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
