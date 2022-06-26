add_executable(test-consensusproblem-linearsystemsolver
	${PROJECT_TESTS_INIT_FILE}
	./test_LinearSystemSolver.cpp
)

target_include_directories(test-consensusproblem-linearsystemsolver
	PRIVATE ${PROJECT_LIB_DIR}
)

target_link_libraries(test-consensusproblem-linearsystemsolver PRIVATE gtest)
target_link_libraries(test-consensusproblem-linearsystemsolver PRIVATE consensusproblem)
target_link_libraries(test-consensusproblem-linearsystemsolver PRIVATE matrix)
target_link_libraries(test-consensusproblem-linearsystemsolver PRIVATE linearsystemsolver)

add_test(
	NAME test-consensusproblem-linearsystemsolver
	COMMAND test-consensusproblem-linearsystemsolver
)
