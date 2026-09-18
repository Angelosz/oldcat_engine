add_library(OldCatEngine
    src/Application.cpp
    src/Window.cpp
    src/Detail/SDLContext.cpp
    src/Input.cpp
    src/Renderer.cpp
)

target_include_directories(OldCatEngine
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(OldCatEngine
    PRIVATE
        SDL3::SDL3
)