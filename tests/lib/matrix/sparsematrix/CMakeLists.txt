add_executable(test-sparsematrix
	${PROJECT_TESTS_INIT_FILE}
	./test_SparseMatrix.cpp
)
target_include_directories(test-sparsematrix
	PRIVATE ${PROJECT_LIB_DIR}
)
target_link_libraries(test-sparsematrix PRIVATE gtest)
target_link_libraries(test-sparsematrix PRIVATE matrix)



add_test(
	NAME test-sparsematrix
	COMMAND test-sparsematrix
)
