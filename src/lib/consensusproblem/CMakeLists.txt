add_library(consensusproblem
	./solver/MonteCarloSolver.cpp
	./solver/LinearSystemSolver.cpp
	./solver/Solver.cpp
	./rule/Rule.cpp
	./rule/createRule.cpp
	./rule/Rule11.cpp
	./rule/Rule12.cpp
	./rule/Rule21.cpp
	./rule/Rule22.cpp
)

target_link_libraries(consensusproblem
	PRIVATE linearsystem
)

target_link_libraries(consensusproblem
	PRIVATE linearsystemsolver
)

target_include_directories(consensusproblem
	PRIVATE ${PROJECT_LIB_DIR}
)

