#include <math.h>


template <typename DT>
void partialGaussChoose(
	LinearSystem<DT>* system,
	int equationIndex,
	int variableIndex
) {
	DT maxCoefficient = std::abs(system->coefficients[equationIndex][variableIndex]);
	int maxCoefficientEquationIndex = equationIndex;
	for (int y = equationIndex + 1; y < system->size.equationsCount; ++y) {
		DT coefficient = std::abs(system->coefficients[y][variableIndex]);
		if (coefficient > maxCoefficient) {
			maxCoefficient = coefficient;
			maxCoefficientEquationIndex = y;
		}
	}
	if (maxCoefficientEquationIndex != equationIndex) {
		system->swapRows(equationIndex, maxCoefficientEquationIndex);
	}
}

template <typename DT>
void partialGaussEliminate(
	LinearSystem<DT>* system
) {
	for (int x = 0; x < system->size.variablesCount; ++x) {
		partialGaussChoose(system, x, x);
		for (int y = x + 1; y < system->size.equationsCount; ++y) {
			DT factor = -system->coefficients[y][x] / system->coefficients[x][x];
			system->addRows(y, x, factor);
		}
	}
}

template <typename DT>
void partialGaussExtractSolution(
	LinearSystem<DT>* system,
	DT* solution
) {
	for (int x = system->size.variablesCount - 1; x >= 0; --x) {
		DT value = system->constants[x];
		for (int y = x + 1; y < system->size.variablesCount; ++y) {
			value -= solution[y] * system->coefficients[x][y];
		}
		solution[x] = value / system->coefficients[x][x];
	}
}

#include <iostream>

template <typename DT>
void partialGauss(
	LinearSystem<DT> system,
	DT* solution
) {
	partialGaussEliminate(&system);
	for (int y = 0; y < system.size.equationsCount; ++y) {
		for (int x = 0; x < system.size.variablesCount; ++x) {
			std::cout << system.coefficients[y][x] << " ";
		}
		std::cout << "| " << system.constants[y] << std::endl;
	}
	partialGaussExtractSolution(&system, solution);
}
