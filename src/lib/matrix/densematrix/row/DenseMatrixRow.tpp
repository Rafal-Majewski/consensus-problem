#include "./DenseMatrixRow.hpp"

template <typename I>
I& DenseMatrixRow<I>::operator[](int index) {
	return values[index];
}

template <typename I>
DenseMatrixRow<I>::DenseMatrixRow() {}

template <typename I>
DenseMatrixRow<I>::DenseMatrixRow(int size) {
	values = new I[size];
}
