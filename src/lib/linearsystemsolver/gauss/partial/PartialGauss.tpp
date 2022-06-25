#include "./PartialGauss.hpp"


template <typename DT>
void PartialGauss<DT>::choose(
	LinearSystem<DT>& system,
	int equationIndex,
	int variableIndex
) const {
	DT maxCoefficient = std::abs((*system.coefficients)(equationIndex, variableIndex));
	int maxCoefficientEquationIndex = equationIndex;
	for (int y = equationIndex + 1; y < system.size.equationsCount; ++y) {
		DT coefficient = std::abs((*system.coefficients)(y, variableIndex));
		if (coefficient > maxCoefficient) {
			maxCoefficient = coefficient;
			maxCoefficientEquationIndex = y;
		}
	}
	if (maxCoefficientEquationIndex != equationIndex) {
		system.swapRows(equationIndex, maxCoefficientEquationIndex);
	}
}
