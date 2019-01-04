cmake_minimum_required(VERSION 3.12)
set(M_LIB mpi_msg_pool)
project(${M_LIB})

set(CMAKE_CXX_STANDARD 11)

find_package(MPI REQUIRED)
MESSAGE(STATUS "MPI_INCLUDE dir:" ${MPI_INCLUDE_PATH})
MESSAGE(STATUS "MPI_LIBRARIES dir:" ${MPI_LIBRARIES})
if (MPI_CXX_COMPILE_FLAGS)
    set(COMPILE_FLAGS "${COMPILE_FLAGS} ${MPI_CXX_COMPILE_FLAGS}")
endif ()
if (MPI_CXX_LINK_FLAGS)
    set(LINK_FLAGS "${LINK_FLAGS} ${MPI_CXX_LINK_FLAGS}")
endif ()
include_directories(${MPI_CXX_INCLUDE_PATH})
set(EXTRA_LIBS ${EXTRA_LIBS} ${MPI_CXX_LIBRARIES}) #add mpi lib

add_subdirectory(src)

#if (TEST_BUILD_ENABLE_FLAG)
    MESSAGE(STATUS "TEST is enabled")
    add_subdirectory(test)
#endif ()