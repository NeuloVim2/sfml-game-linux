cmake_minimum_required(
    VERSION 
    3.28.0
)

project(sfml_test1 
    VERSION 
    0.1.0 
    LANGUAGES 
    C 
    CXX
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_subdirectory(lib)
add_subdirectory(src)