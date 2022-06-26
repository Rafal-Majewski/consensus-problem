add_executable(test-numalg-jacobi
	${PROJECT_TESTS_INIT_FILE}
	./test_Jacobi.cpp
)

target_include_directories(test-numalg-jacobi
	PRIVATE ${PROJECT_LIB_DIR}
)

target_link_libraries(test-numalg-jacobi PRIVATE gtest)
target_link_libraries(test-numalg-jacobi PRIVATE linearsystemsolver)

add_test(
	NAME test-numalg-jacobi
	COMMAND test-numalg-jacobi
)
