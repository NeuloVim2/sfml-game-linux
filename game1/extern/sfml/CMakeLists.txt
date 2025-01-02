project(sfml
    VERSION 
    2.6.0 
    LANGUAGES 
    C 
    CXX
)

add_library(sfml-window STATIC IMPORTED)
add_library(sfml-graphics STATIC IMPORTED)
add_library(sfml-network STATIC IMPORTED)
add_library(sfml-system STATIC IMPORTED)
add_library(sfml-audio STATIC IMPORTED)

set_target_properties(sfml-graphics PROPERTIES
    IMPORTED_LOCATION src/linux/sfml-graphics-s.a
)
set_target_properties(sfml-window PROPERTIES
    IMPORTED_LOCATION src/linux/sfml-window-s.a
)
set_target_properties(sfml-system PROPERTIES
    IMPORTED_LOCATION src/linux/sfml-system-s.a
)
set_target_properties(sfml-network PROPERTIES
    IMPORTED_LOCATION src/linux/sfml-network-s.a
)
set_target_properties(sfml-audio PROPERTIES
    IMPORTED_LOCATION src/linux/sfml-audio-s.a
)