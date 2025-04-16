include(FetchContent)

FetchContent_Declare(
    sfml
    GIT_REPOSITORY https://github.com/SFML/SFML 
    GIT_TAG 7f1162dfea4969bc17417563ac55d93b72e84c1e #3.0.0
)

FetchContent_Declare(
    imgui 
    GIT_REPOSITORY https://github.com/ocornut/imgui 
    GIT_TAG 4806a1924ff6181180bf5e4b8b79ab4394118875 #1.91.9b
)

FetchContent_MakeAvailable(imgui)

FetchContent_Declare(
    imgui-sfml 
    GIT_REPOSITORY https://github.com/SFML/imgui-sfml 
    GIT_TAG 070d6ab9aa98c997b1fa846175d3faf93de3866e #3.0
)

FetchContent_Declare(
    googletest 
    GIT_REPOSITORY https://github.com/google/googletest 
    GIT_TAG f8d7d77c06936315286eb55f8de22cd23c188571
)

add_subdirectory(sfml)
add_subdirectory(imgui-sfml)
add_subdirectory(googletest)