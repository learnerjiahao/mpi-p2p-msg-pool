set(SRC_FILES
        msg_pool.cpp
        msg.cpp
        )
set(HEAD_FILES
        msg_pool.h
        msg.h
        recv_msg_pool.h
        msg_meta.h
        )

# set binary path and lib storage path for compiling process.
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)

add_library(${M_LIB} ${SRC_FILES} ${HEAD_FILES})
target_link_libraries(${M_LIB} ${EXTRA_LIBS})

# install bin and libs.
install(TARGETS ${M_EXECUTE_BIN_NAME}
        RUNTIME DESTINATION bin
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib
        )

# install header.
install(DIRECTORY "./"
        DESTINATION "include"
        FILES_MATCHING PATTERN "*.h"
        )