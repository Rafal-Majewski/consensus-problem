#include "./LinearSystem.hpp"


template <typename DT>
LinearSystem<DT>::LinearSystem(LinearSystemSize size, DT* coefficients, DT* constants) :
	size(size),
	coefficients(new DT*[size.equationsCount]),
	constants(new DT[size.equationsCount])
{
	for (int i = 0, y = 0; y < this->size.equationsCount; ++y) {
		this->coefficients[y] = new DT[this->size.variablesCount];
		for (int x = 0; x < this->size.variablesCount; ++x, ++i) {
			this->coefficients[y][x] = coefficients[i];
		}
		this->constants[y] = constants[y];
	}
}

template <typename DT>
LinearSystem<DT>::LinearSystem(const LinearSystem<DT>& other) :
	size(other.size),
	coefficients(new DT*[other.size.equationsCount]),
	constants(new DT[other.size.equationsCount])
{
	for (int y = 0; y < this->size.equationsCount; ++y) {
		this->coefficients[y] = new DT[this->size.variablesCount];
		for (int x = 0; x < this->size.variablesCount; ++x) {
			this->coefficients[y][x] = other.coefficients[y][x];
		}
		this->constants[y] = other.constants[y];
	}
}

template <typename DT>
LinearSystem<DT>::~LinearSystem() {
	for (int y = 0; y < this->size.equationsCount; ++y) {
		delete[] this->coefficients[y];
	}
	delete[] this->coefficients;
	delete[] this->constants;
}

template <typename DT>
void LinearSystem<DT>::addRows(int targetRowIndex, int sourceRowIndex, DT factor) {
	for (int x = 0; x < this->size.variablesCount; ++x) {
		this->coefficients[targetRowIndex][x] += factor * this->coefficients[sourceRowIndex][x];
	}
	this->constants[targetRowIndex] += factor * this->constants[sourceRowIndex];
}

template <typename DT>
void LinearSystem<DT>::swapRows(int rowIndex1, int rowIndex2) {
	DT* tempCoefficients = this->coefficients[rowIndex1];
	this->coefficients[rowIndex1] = this->coefficients[rowIndex2];
	this->coefficients[rowIndex2] = tempCoefficients;
	DT tempConstant = this->constants[rowIndex1];
	this->constants[rowIndex1] = this->constants[rowIndex2];
	this->constants[rowIndex2] = tempConstant;
}
