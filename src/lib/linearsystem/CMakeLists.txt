add_library(linearsystem
	./LinearSystem.cpp
	./size/LinearSystemSize.cpp
)

target_link_libraries(linearsystem
	PRIVATE matrix
)

target_include_directories(linearsystem
	PRIVATE ${PROJECT_LIB_DIR}
)
