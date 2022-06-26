#include "./Gauss.hpp"

namespace Numalg {
	template <typename DT>
	void Gauss<DT>::extractSolution(
		LinearSystem<DT>& system,
		DT* solution
	) const {
		for (int x = system.size.variablesCount - 1; x >= 0; --x) {
			DT value = system.constants[x];
			for (int y = x + 1; y < system.size.variablesCount; ++y) {
				value -= solution[y] * (*system.coefficients)(x, y);
			}
			solution[x] = value / (*system.coefficients)(x, x);
		}
	}

	template <typename DT>
	void Gauss<DT>::eliminate(
		LinearSystem<DT>& system
	) const {
		for (int x = 0; x < system.size.variablesCount; ++x) {
			// poszukaj lepszego współczynnika na miejsce x, x
			// i zamień wiersze jeśli uda się znaleźć
			this->choose(system, x, x);
			for (int y = x + 1; y < system.size.equationsCount; ++y) {
				DT factor = -(*system.coefficients)(y, x) / (*system.coefficients)(x, x);
				// do wiersza y dodaj wiersz x wymnożony razy factor
				system.addRows(y, x, factor);
			}
		}
	}

	template <typename DT>
	void Gauss<DT>::solve(
		LinearSystem<DT>& system,
		DT* solution
	) const {
		this->eliminate(system);
		this->extractSolution(system, solution);
	}
}
