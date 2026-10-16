add_library(OldCatEngine STATIC
    src/Core/Application.cpp
    src/Core/GameContext.cpp
    src/Core/Scene.cpp
    src/Core/Time.cpp
    src/Graphics/Renderer.cpp
    src/Graphics/Font.cpp
    src/Graphics/Texture.cpp
    src/Graphics/Sprite.cpp
    src/Input/Input.cpp
    src/Assets/AssetManager.cpp
    src/Platform/Window.cpp
    src/Detail/SDLContext.cpp
    src/Math/Rect.cpp
    src/UI/UI.cpp
    src/UI/Widget.cpp
    src/UI/Button.cpp
    src/UI/TextWidget.cpp
    src/World/Object.cpp
    src/World/World.cpp
    src/World/SpriteObject.cpp
    src/Components/Components.cpp
    src/Components/RenderComponent.cpp
    src/Components/SpriteComponent.cpp
    src/Components/ColliderComponent.cpp
    src/Events/EventDispatcher.cpp
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