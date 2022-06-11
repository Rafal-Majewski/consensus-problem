#include "./run.hpp"
#include "./datatypedRun.hpp"


int run(
	std::string linearSystemSolvingMethod,
	std::string linearSystemDatatype,
) {
	if (linearSystemDatatype == "float") {
		return datatypedRun<float>(linearSystemSolvingMethod, calculatingMethod);
	} else if (linearSystemDatatype == "double") {
		return datatypedRun<double>(linearSystemSolvingMethod, calculatingMethod);
	} else {
		throw std::runtime_error("Unknown linear system datatype: " + linearSystemDatatype);
	}
}
