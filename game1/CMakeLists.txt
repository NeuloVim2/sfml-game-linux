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

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

message("Set BUILD_SHARED_LIBS to ${BUILD_SHARED_LIBS}")
option(BUILD_SHARED_LIBS "Build shared libraries" OFF)

add_executable(game src/main.cpp)

add_subdirectory(extern/sfml)
add_subdirectory(extern/imgui)
target_link_libraries(game PRIVATE sfml-window 
                                   sfml-graphics 
                                   sfml-system 
                                   sfml-audio
                                   imgui)