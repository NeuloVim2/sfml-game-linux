cmake_minimum_required(
    VERSION 
    3.28.0
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