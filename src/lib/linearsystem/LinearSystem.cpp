#include "./LinearSystem.hpp"


template <typename DT>
LinearSystem<DT>::LinearSystem(LinearSystemSize size, DT* coefficients, DT* constants) :
	size(size),
	coefficients(new DT[size.equationsCount][size.variablesCount]),
	constants(new DT[size.equationsCount])
{
	for (int i = 0, y = 0; y < size.equationsCount; ++y) {
		for (int x = 0; x < size.variablesCount; ++x, ++i) {
			coefficients[i] = coefficients[i];
		}
		constants[y] = constants[y];
	}
}

template <typename DT>
LinearSystem<DT>::~LinearSystem() {
	for (int y = 0; y < size.equationsCount; ++y) {
		delete[] coefficients[y];
	}
	delete[] coefficients;
	delete[] constants;
}