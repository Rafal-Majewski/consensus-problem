#include "./LinearSystemSize.hpp"


LinearSystemSize::LinearSystemSize(int equationsCount, int variablesCount) :
	equationsCount(equationsCount),
	variablesCount(variablesCount)
{
}

bool LinearSystemSize::operator==(const LinearSystemSize& other) const {
	return equationsCount == other.equationsCount && variablesCount == other.variablesCount;
}

bool LinearSystemSize::operator!=(const LinearSystemSize& other) const {
	return !(*this == other);
}
