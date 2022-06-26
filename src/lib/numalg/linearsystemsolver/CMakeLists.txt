add_library(linearsystemsolver
	./LinearSystemSolver.cpp
	./gauss/Gauss.cpp
	./gauss/partial/PartialGauss.cpp
	./jacobi/Jacobi.cpp
)

target_link_libraries(linearsystemsolver
	PRIVATE linearsystem
)

target_include_directories(linearsystemsolver
	PRIVATE ${PROJECT_LIB_DIR}
)
