cmake_minimum_required(VERSION 3.31)
project(lexan LANGUAGES C VERSION 0.1.0)

set(CMAKE_C_STANDARD 23)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

option(LEX_BUILD_EXAMPLES "Build the examples." OFF)

if(LEX_BUILD_EXAMPLES)
    add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/examples)
endif()

add_library(${PROJECT_NAME} STATIC)

target_compile_options(${PROJECT_NAME} PRIVATE
    -Wall -Wextra -Werror)

target_sources(${PROJECT_NAME} PRIVATE
    ${PROJECT_SOURCE_DIR}/src/lex_logger.c)

target_include_directories(${PROJECT_NAME} PUBLIC
    ${PROJECT_SOURCE_DIR}/include)

target_link_directories(${PROJECT_NAME} INTERFACE
    ${PROJECT_BINARY_DIR})

add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E create_symlink
    ${CMAKE_BINARY_DIR}/compile_commands.json
    ${CMAKE_SOURCE_DIR}/compile_commands.json
)
