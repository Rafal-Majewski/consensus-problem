#include "./DenseMatrix.hpp"

template <typename I>
DenseMatrix<I>::DenseMatrix(MatrixSize size) : Matrix<I>(size) {
	this->values = new I*[this->size.rowsCount];
	for (int i = 0; i < this->size.rowsCount; ++i) {
		this->values[i] = new I[this->size.columnsCount];
	}
};


template <typename I>
DenseMatrix<I>::~DenseMatrix() {
	for (int i = 0; i < this->size.rowsCount; ++i) {
		delete[] this->values[i];
	}
	delete[] this->values;
};
