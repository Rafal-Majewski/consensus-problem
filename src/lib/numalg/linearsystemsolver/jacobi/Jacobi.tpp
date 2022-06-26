#include "./Jacobi.hpp"
#include <vector>
#include <stdexcept>
#include <iostream>


namespace Numalg {
	template <typename DT>
	Jacobi<DT>::Jacobi(
		const DT tolerance,
		const int maxIterations
	) : tolerance(tolerance), maxIterations(maxIterations) {
	}

	template <typename DT>
	void Jacobi<DT>::solve(
		LinearSystem<DT>& system,
		DT* solution
	) const {
		std::fill(solution, solution + system.size.variablesCount, 0);
		DT* newSolution = new DT[system.size.variablesCount];
		std::vector<int>* optimizer = new std::vector<int>[system.size.variablesCount];
		// make sure the diagonal line is not 0

		for (int y = 0; y < system.size.equationsCount; ++y) {
			if ((*system.coefficients)(y, y) == 0) {
				for (int y2 = 0; y2 < system.size.equationsCount; ++y2) {
					if ((*system.coefficients)(y2, y) != 0) {
						system.addRows(y, y2);
						break;
					}
				}
				if ((*system.coefficients)(y, y) == 0) {
					throw std::runtime_error("LinearSystem::solve: LinearSystem has only 0 in one of its columns");
				}
			}
			system.divideRow(y, (*system.coefficients)(y, y));
			(*system.coefficients)(y, y) = 0;
			for (int x = 0; x < system.size.variablesCount; ++x) {
				if ((*system.coefficients)(y, x) != 0) {
					optimizer[y].push_back(x);
				}
			}
		}
		// print system
		for (int y = 0; y < system.size.equationsCount; ++y) {
			for (int x = 0; x < system.size.variablesCount; ++x) {
				std::cout << (*system.coefficients)(y, x) << "\t";
			}
			std::cout << "|\t" << system.constants[y] << std::endl;
		}

		for (int i = 0; i < this->maxIterations; ++i) {
			DT tolsum = 0;
			for (int y = 0; y < system.size.equationsCount; ++y) {
				newSolution[y] = system.constants[y];
				for (int oi = 0; oi < optimizer[y].size(); ++oi) {
					newSolution[y] -= (*system.coefficients)(y, optimizer[y][oi]) * solution[optimizer[y][oi]];
				}
				tolsum += std::abs(newSolution[y] - solution[y]);
			}
			// replace solution with newSolution
			std::copy(newSolution, newSolution + system.size.variablesCount, solution);
			if (tolsum < this->tolerance) {
				break;
			}
		}
	}
}
