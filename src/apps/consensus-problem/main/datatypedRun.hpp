#include <string>

template <typename DT>
LinearSystemSolver<DT>* getLinearSystemSolver(std::string linearSystemSolvingMethod);


template <typename DT>
int datatypedRun(
	std::string linearSystemSolvingMethod
);