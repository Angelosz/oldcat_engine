add_library(OldCatEngine
    src/Application.cpp
    src/Window.cpp
)

target_include_directories(OldCatEngine
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(OldCatEngine
    PUBLIC
        SDL3::SDL3
)