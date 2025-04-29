set(Sources 
    main.cpp
    Components.hpp 
    Scene.h 
    Scene.cpp 
    typedefs.h 
    Game.h
    Game.cpp
    Entity.cpp
    Entity.h
    EntityManager.h
    EntityManager.cpp
    ConfigParser.h
    ConfigParser.cpp)

add_library(vector Vector2f.cpp)
# list(APPEND EXTRA_INCLUDES "${PROJECT_SOURCE_DIR}/include/vector")

target_include_directories(vector
                           PUBLIC 
                           ${PROJECT_SOURCE_DIR}/include/vector
)


message("Include directories ${INCLUDE_DIRECTORIES}")

add_executable(game ${Sources})
target_link_libraries(game 
                      PUBLIC
                        ImGui-SFML::ImGui-SFML
                        vector
)
