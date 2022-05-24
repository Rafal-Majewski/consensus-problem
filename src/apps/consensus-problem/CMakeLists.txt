add_executable(consensus-problem
	./main.cpp
)
target_link_libraries(consensus-problem
	PRIVATE CLI11
)
target_include_directories(consensus-problem
	PRIVATE ${PROJECT_LIB_DIR}
)
