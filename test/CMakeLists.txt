enable_testing()
set(M_UINT_TEST_NAME unit-test)

if(NOT TARGET gtest)
    add_subdirectory(${PROJECT_SOURCE_DIR}/vendor/src/googletest/googletest ${PROJECT_BINARY_DIR}/vendor/googletest)
endif()
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

#googlemock
#add_subdirectory("${source_dir}/googlemock")
#include_directories(${gmock_SOURCE_DIR}/include ${gmock_SOURCE_DIR})

# Standard linking to gtest stuff.
set(EXTRA_LIBS ${EXTRA_LIBS} gtest gtest_main)
MESSAGE(STATUS "Set googletest as test library.")

set(TEST_SRC
        test_msg.cpp)

add_executable(${M_UINT_TEST_NAME} ${TEST_SRC})
# Extra linking for the project.
target_link_libraries(${M_UINT_TEST_NAME} ${M_LIB} ${EXTRA_LIBS})

# This is so you can do 'make test' to see all your tests run, instead of
# manually running the executable runUnitTests to see those specific tests.
add_test(NAME exampleTests COMMAND ${M_UINT_TEST_NAME})
##########################
##### install files
##########################
install(TARGETS ${M_UINT_TEST_NAME}
        RUNTIME DESTINATION bin
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib
        )