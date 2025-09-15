cmake_minimum_required(VERSION 3.22)

project(pthreads-playground)

file(GLOB tasks_src
    ${CMAKE_CURRENT_SOURCE_DIR}/unix_threads_in_c/*.c
    ${CMAKE_CURRENT_SOURCE_DIR}/unix_threads_in_c/*.cpp
)

foreach(file_path ${tasks_src})
    message("Processing file: ${file_path}")
    get_filename_component(EXEC_NAME ${file_path} NAME_WE)

    if(NOT ${EXEC_NAME} MATCHES "^task___.*") 
        continue()
    endif()

    add_executable(${EXEC_NAME} ${file_path})

    # target_link_libraries(${EXEC_NAME} PRIVATE )

    target_include_directories(${EXEC_NAME}
        PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/include
    )

    target_compile_options(${EXEC_NAME}
        PRIVATE
        -pthread
    )
endforeach()