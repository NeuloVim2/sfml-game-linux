set(Sources 
    main.cpp
)

add_library(vector vector.cpp)
# list(APPEND EXTRA_INCLUDES "${PROJECT_SOURCE_DIR}/include/vector")

target_include_directories(vector
                           PUBLIC 
                           ${PROJECT_SOURCE_DIR}/include/vector
)


message("Include directories ${INCLUDE_DIRECTORIES}")

add_executable(game ${Sources})
target_link_libraries(game 
                      PRIVATE 
                      ImGui-SFML::ImGui-SFML
                      vector
)
