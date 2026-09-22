add_library(OldCatEngine STATIC
    src/Application.cpp
    src/Window.cpp
    src/Detail/SDLContext.cpp
    src/Input.cpp
    src/Renderer.cpp
    src/Font.cpp
    src/Texture.cpp
    src/AssetManager.cpp
    src/GameContext.cpp
    src/Game.cpp
)

target_include_directories(OldCatEngine
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(OldCatEngine
    PUBLIC
        SDL3::SDL3
        SDL3_ttf::SDL3_ttf
)