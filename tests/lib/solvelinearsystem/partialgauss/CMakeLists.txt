add_executable(test-partialgauss
	${PROJECT_TESTS_INIT_FILE}
	./test_partialGauss.cpp
)

target_include_directories(test-partialgauss
	PRIVATE ${PROJECT_LIB_DIR}
)

target_link_libraries(test-partialgauss PRIVATE gtest)
target_link_libraries(test-partialgauss PRIVATE solvelinearsystem)

add_test(
	NAME test-partialgauss
	COMMAND test-partialgauss
)
