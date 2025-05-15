cmake_minimum_required(
    VERSION 
    3.28.0...4.0
)

project(game1
    VERSION 
    0.1.0 
    LANGUAGES 
    C 
    CXX
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

message("Set BUILD_SHARED_LIBS to ${BUILD_SHARED_LIBS}")
option(BUILD_SHARED_LIBS "Build shared libraries" OFF)

enable_testing()

add_subdirectory(extern)
add_subdirectory(src)
add_subdirectory(test)

add_custom_target(copy_resources ALL
            COMMAND ${CMAKE_COMMAND} -E copy_directory
            ${PROJECT_SOURCE_DIR}/resources
            ${PROJECT_BINARY_DIR}/src/resources
            COMMENT "Copying resources into binary directory")

message("project source dir: ${PROJECT_SOURCE_DIR}")
message("project binary dir: ${PROJECT_BINARY_DIR}")

add_custom_target(copy_config ALL
            COMMAND ${CMAKE_COMMAND} -E copy
            ${PROJECT_SOURCE_DIR}/src/config.txt
            ${PROJECT_BINARY_DIR}/src/config.txt
            COMMENT "Copying config into binary directory")
add_dependencies(game copy_resources)
add_dependencies(game copy_config)
