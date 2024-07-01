include(FetchContent)

FetchContent_Declare(
    sfml
    GIT_REPOSITORY https://github.com/SFML/SFML 
    GIT_TAG 69ea0cd863aed1d4092b970b676924a716ff718b #2.6.1
)

FetchContent_Declare(
    imgui 
    GIT_REPOSITORY https://github.com/ocornut/imgui 
    GIT_TAG 6f7b5d0ee2fe9948ab871a530888a6dc5c960700 #1.90.8
)

FetchContent_MakeAvailable(imgui)

FetchContent_Declare(
    imgui-sfml 
    GIT_REPOSITORY https://github.com/SFML/imgui-sfml 
    GIT_TAG de565ac8f2b795dedc0307b60830cb006afd2ecd
)

FetchContent_Declare(
    googletest 
    GIT_REPOSITORY https://github.com/google/googletest 
    GIT_TAG f8d7d77c06936315286eb55f8de22cd23c188571
)

add_subdirectory(sfml)
add_subdirectory(imgui-sfml)
add_subdirectory(googletest)