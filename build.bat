clang++ ^
main.cpp Game.cpp ^
external/imgui/imgui.cpp ^
external/imgui/imgui_draw.cpp ^
external/imgui/imgui_widgets.cpp ^
external/imgui/imgui_tables.cpp ^
external/imgui/backends/imgui_impl_sdl3.cpp ^
external/imgui/backends/imgui_impl_sdlrenderer3.cpp ^
-o main ^
-Iexternal/imgui ^
-Iexternal/imgui/backends ^
-IC:\msys64\ucrt64\include ^
-LC:\msys64\ucrt64\lib ^
-lSDL3
