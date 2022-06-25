#include "./Gauss.hpp"

#include <iostream>


template <typename DT>
void Gauss<DT>::extractSolution(
	LinearSystem<DT>& system,
	DT* solution
) const {
	std::cout << "extractSolution" << std::endl;
	for (int x = system.size.variablesCount - 1; x >= 0; --x) {
		
		DT value = system.constants[x];
		std::cout << "x: " << x << ' ' << value << std::endl;
		for (int y = x + 1; y < system.size.variablesCount; ++y) {
			value -= solution[y] * (*system.coefficients)(x, y);
			std::cout << "y: " << y << ' ' << value << std::endl;
		}
		std::cout << value << '/' << (*system.coefficients)(x, x) << std::endl;
		solution[x] = value / (*system.coefficients)(x, x);
		std::cout << "solution: " << x << ' ' << solution[x] << std::endl;
	}
	std::cout << "extractSolution end" << std::endl;
}

template <typename DT>
void Gauss<DT>::eliminate(
	LinearSystem<DT>& system
) const {
	for (int x = 0; x < system.size.variablesCount; ++x) {
		this->choose(system, x, x);
		for (int y = x + 1; y < system.size.equationsCount; ++y) {
			DT factor = -(*system.coefficients)(y, x) / (*system.coefficients)(x, x);
			system.addRows(y, x, factor);
		}
	}
}

template <typename DT>
void Gauss<DT>::solve(
	LinearSystem<DT>& system,
	DT* solution
) const {
	std::cout << "Gauss::solve" << std::endl;
	for (int x = 0; x < system.size.equationsCount; ++x) {
		for (int y = 0; y < system.size.variablesCount; ++y) {
			std::cout << (*system.coefficients)(x, y) << " ";
		}
		std::cout << "| " << system.constants[x] << std::endl;
	}
	this->eliminate(system);
	std::cout << "After elimination:" << std::endl;
		for (int x = 0; x < system.size.equationsCount; ++x) {
		for (int y = 0; y < system.size.variablesCount; ++y) {
			std::cout << (*system.coefficients)(x, y) << " ";
		}
		std::cout << "| " << system.constants[x] << std::endl;
	}
	this->extractSolution(system, solution);

}
