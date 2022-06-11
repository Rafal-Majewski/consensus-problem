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
LinearSystem<DT>::~LinearSystem() {
	for (int y = 0; y < this->size.equationsCount; ++y) {
		delete[] this->coefficients[y];
	}
	delete[] this->coefficients;
	delete[] this->constants;
}
