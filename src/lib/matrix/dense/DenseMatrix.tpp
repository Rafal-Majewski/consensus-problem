#include "./DenseMatrix.hpp"
#include <utility>


template <typename I>
DenseMatrix<I>::DenseMatrix(MatrixSize size) : Matrix<I>(size) {
	this->values = new I[this->size.rowsCount * this->size.columnsCount];
};

template <typename I>
DenseMatrix<I>::DenseMatrix(MatrixSize size, I* values) : DenseMatrix<I>(size) {
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
DenseMatrix<I>::DenseMatrix(
	const DenseMatrix<I>& matrix
) :
	DenseMatrix(matrix.size, matrix.values) {
};

template <typename I>
I DenseMatrix<I>::operator()(int y, int x) const {
	return this->values[y * this->size.columnsCount + x];
}

template <typename I>
I& DenseMatrix<I>::operator()(int y, int x) {
	return this->values[y * this->size.columnsCount + x];
}

template <typename I>
DenseMatrix<I> DenseMatrix<I>::operator*(DenseMatrix<I> other) const {
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

template <typename I>
DenseMatrix<I>* DenseMatrix<I>::clone() const {
	return new DenseMatrix<I>(*this);
}

template <typename I>
void DenseMatrix<I>::swapRows(int rowIndex1, int rowIndex2) {
	for (int x = 0; x < this->size.columnsCount; ++x) {
		std::swap(
			this->values[rowIndex1 * this->size.columnsCount + x],
			this->values[rowIndex2 * this->size.columnsCount + x]
		);
	}
}

template <typename I>
DenseMatrix<I> DenseMatrix<I>::zero(MatrixSize size) {
	DenseMatrix<I> result(size);
	for (int i = 0; i < size.rowsCount * size.columnsCount; ++i) {
		result.values[i] = 0;
	}
	return result;
}
