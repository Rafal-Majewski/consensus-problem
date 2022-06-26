#include <vector>
#include "./SparseMatrix.hpp"


template <typename I>
SparseMatrix<I>::SparseMatrix(MatrixSize size) : Matrix<I>(size) {
}

template <typename I>
SparseMatrix<I>::SparseMatrix(MatrixSize size, I* values) : SparseMatrix<I>(size) {
	int totalCellsCount = this->size.rowsCount * this->size.columnsCount;
	for (int i = 0, y = 0; y < this->size.rowsCount; ++y) {
		for (int x = 0; x < this->size.columnsCount; ++x, ++i) {
			if (values[i] == 0) continue;
			this->values[std::make_pair(y, x)] = values[i];
		}
	}
}

template <typename I>
SparseMatrix<I>::SparseMatrix(
	MatrixSize size,
	const std::map<std::pair<int, int>, I>& values
) : SparseMatrix<I>(size) {
	this->values = values;
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
SparseMatrix<I> SparseMatrix<I>::operator*(SparseMatrix<I> other) const {
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

template <typename I>
SparseMatrix<I>* SparseMatrix<I>::clone() const {
	return new SparseMatrix<I>(*this);
}

template <typename I>
void SparseMatrix<I>::swapRows(int rowIndex1, int rowIndex2) {
	std::vector<std::pair<int, int>> keysToRemove;
	std::vector<std::pair<std::pair<int, int>, I>> entriesToAdd;
	for (auto& entry : this->values) {
		if (entry.first.first == rowIndex1) {
			keysToRemove.push_back(entry.first);
			entriesToAdd.push_back(std::make_pair(std::make_pair(rowIndex2, entry.first.second), entry.second));
		} else if (entry.first.first == rowIndex2) {
			keysToRemove.push_back(entry.first);
			entriesToAdd.push_back(std::make_pair(std::make_pair(rowIndex1, entry.first.second), entry.second));
		}
	}
	for (auto& key : keysToRemove) {
		this->values.erase(key);
	}
	for (auto& entry : entriesToAdd) {
		this->values[entry.first] = entry.second;
	}
}

template <typename I>
SparseMatrix<I>::SparseMatrix(
	const SparseMatrix<I>& other
) : SparseMatrix<I>(other.size, other.values) {
}

template <typename I>
SparseMatrix<I> SparseMatrix<I>::zero(MatrixSize size) {
	return SparseMatrix<I>(size);
}
