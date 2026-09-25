add_library(OldCatEngine STATIC
    src/Core/Application.cpp
    src/Core/GameContext.cpp
    src/Core/Game.cpp
    src/Graphics/Renderer.cpp
    src/Graphics/Font.cpp
    src/Graphics/Texture.cpp
    src/Graphics/Sprite.cpp
    src/Input/Input.cpp
    src/Assets/AssetManager.cpp
    src/Platform/Window.cpp
    src/Detail/SDLContext.cpp
    src/World/Object.cpp
    src/Math/Rect.cpp
    src/World/World.cpp
    src/Components/Components.cpp
 "src/Components/RenderComponent.cpp" "include/OldCat/Components/SpriteComponent.h" "src/Components/SpriteComponent.cpp")

target_include_directories(OldCatEngine
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(OldCatEngine
    PUBLIC
        SDL3::SDL3
        SDL3_ttf::SDL3_ttf
)