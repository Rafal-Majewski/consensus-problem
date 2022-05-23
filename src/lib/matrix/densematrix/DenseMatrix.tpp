#include "./DenseMatrix.hpp"


template <typename I>
DenseMatrix<I>::DenseMatrix(MatrixSize size) : Matrix<I>(size) {
	values = new DenseMatrixRow<I>[size.rowsCount];
	for (int y = 0; y < size.rowsCount; y++) {
		values[y] = DenseMatrixRow<I>(size.columnsCount);
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
	// todo
};

template <typename I>
DenseMatrixRow<I>& DenseMatrix<I>::operator[](int rowIndex) {
	return values[rowIndex];
};