set(Sources 
    main.cpp
    Components.hpp 
    Scene.h 
    Scene.cpp 
    ScenePlay.h 
    ScenePlay.cpp
    typedefs.h 
    GameEngine.h
    GameEngine.cpp
    Entity.cpp
    Entity.h
    EntityManager.h
    EntityManager.cpp
    ConfigParser.h
    ConfigParser.cpp
    Action.hpp
)

add_library(vector Vector2f.cpp)
# list(APPEND EXTRA_INCLUDES "${PROJECT_SOURCE_DIR}/include/vector")

target_include_directories(vector
                           PUBLIC 
                           ${PROJECT_SOURCE_DIR}/include/vector
)
target_link_libraries(vector
                      PUBLIC
                        SFML::System)


message("Include directories ${INCLUDE_DIRECTORIES}")

add_executable(game ${Sources})
target_link_libraries(game 
                      PUBLIC
                        ImGui-SFML::ImGui-SFML
                        vector
)
