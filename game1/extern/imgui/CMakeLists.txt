add_library(imgui STATIC src/imgui_draw.cpp
                         src/imgui_tables.cpp
                         src/imgui_widgets.cpp
                         src/imgui.cpp
                         src/imgui-SFML.cpp
                         src/imgui_stdlib.cpp
                         include/imconfig.h
                         include/imgui_internal.h
                         include/imgui_stdlib.h
                         include/imgui-SFML_export.h
                         include/imgui-SFML.h
                         include/imgui.h
                         include/imstb_rectpack.h
                         include/imstb_textedit.h
                         include/imstb_truetype.h)

target_include_directories(imgui PUBLIC include)