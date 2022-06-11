add_executable(test-linearsystem
	${PROJECT_TESTS_INIT_FILE}
	./test_LinearSystem.cpp
)

target_include_directories(test-linearsystem
	PRIVATE ${PROJECT_LIB_DIR}
)

target_link_libraries(test-linearsystem PRIVATE gtest)
target_link_libraries(test-linearsystem PRIVATE linearsystem)

add_test(
	NAME test-linearsystem
	COMMAND test-linearsystem
)
