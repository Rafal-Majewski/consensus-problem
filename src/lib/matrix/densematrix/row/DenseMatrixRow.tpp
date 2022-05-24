#include "./DenseMatrixRow.hpp"


template <typename I>
I& DenseMatrixRow<I>::operator[](int index) {
	return values[index];
}

template <typename I>
DenseMatrixRow<I>::DenseMatrixRow() : size(0) {
	values = nullptr;
}

template <typename I>
DenseMatrixRow<I>::DenseMatrixRow(int a_size) : size(a_size) {
	values = new I[size];
}

template <typename I>
DenseMatrixRow<I>::~DenseMatrixRow() {
	delete[] values;
}

template <typename I>
DenseMatrixRow<I>& DenseMatrixRow<I>::operator=(DenseMatrixRow& other) {
	if (this == &other) return *this;
	delete[] values;
	values = new I[other.size];
	for (int i = 0; i < other.size; ++i) {
		values[i] = other.values[i];
	}
	return *this;
}
