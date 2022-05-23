add_executable(test-densematrix
	${PROJECT_TESTS_INIT_FILE}
	./test_DenseMatrix.cpp
)
target_include_directories(test-densematrix
	PRIVATE ${PROJECT_LIB_DIR}
)
target_link_libraries(test-densematrix PRIVATE gtest)
target_link_libraries(test-densematrix PRIVATE matrix)



add_test(
	NAME test-densematrix
	COMMAND test-densematrix
)
