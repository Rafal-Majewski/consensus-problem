#include "./LinearSystem.hpp"
#include <algorithm>
#include <utility>


template <typename DT>
LinearSystem<DT>::LinearSystem(
	const LinearSystemSize size,
	const Matrix<DT>& coefficients,
	const DT* constants
) :
	size(size),
	coefficients(coefficients.clone()),
	constants(new DT[size.equationsCount])
{
	std::copy(constants, constants + this->size.equationsCount, this->constants);
}

template <typename DT>
LinearSystem<DT>::~LinearSystem() {
	delete[] this->constants;
}

template <typename DT>
void LinearSystem<DT>::addRows(int targetRowIndex, int sourceRowIndex, DT factor) {
	for (int x = 0; x < this->size.variablesCount; ++x) {
		(*this->coefficients)(targetRowIndex, x) += factor * (*this->coefficients)(sourceRowIndex, x);
	}
	this->constants[targetRowIndex] += factor * this->constants[sourceRowIndex];
}

template <typename DT>
void LinearSystem<DT>::swapRows(int rowIndex1, int rowIndex2) {
	(*this->coefficients).swapRows(rowIndex1, rowIndex2);
	std::swap(this->constants[rowIndex1], this->constants[rowIndex2]);
}
