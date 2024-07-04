set(Sources 
    main.cpp
)

add_library(vector vector.cpp)
target_include_directories(vector
                           PUBLIC 
                           "${PROJECT_BINARY_DIR}/include"
)

add_executable(game ${Sources})
target_link_libraries(game 
                      PRIVATE 
                      ImGui-SFML::ImGui-SFML
                      vector
)