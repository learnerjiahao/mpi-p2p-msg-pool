# set binary path and lib storage path for compiling process.
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)

set(EXAMPLE_EXC example)
set(EXAMPLE_SRC
        example.cpp)
add_executable(${EXAMPLE_EXC} ${EXAMPLE_SRC})
target_link_libraries(${EXAMPLE_EXC} ${M_LIB} ${EXTRA_LIBS})