set(Sources 
    main.cpp
     
    
 "components.hpp" "Scene.h" "typedefs.h" "ComponentManager.cpp" "ComponentManager.h")

add_library(vector vector.cpp "ComponentManager.cpp" "ComponentManager.h")
# list(APPEND EXTRA_INCLUDES "${PROJECT_SOURCE_DIR}/include/vector")

target_include_directories(vector
                           PUBLIC 
                           ${PROJECT_SOURCE_DIR}/include/vector
)


message("Include directories ${INCLUDE_DIRECTORIES}")

add_executable(game ${Sources} "ComponentManager.cpp" "ComponentManager.h")
target_link_libraries(game 
                      PRIVATE 
                      ImGui-SFML::ImGui-SFML
                      vector
)
