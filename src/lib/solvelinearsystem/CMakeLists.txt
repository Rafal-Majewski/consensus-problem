add_library(solvelinearsystem
	./partialGauss.cpp
)

target_link_libraries(solvelinearsystem
	PRIVATE linearsystem
)

target_include_directories(solvelinearsystem
	PRIVATE ${PROJECT_LIB_DIR}
)
