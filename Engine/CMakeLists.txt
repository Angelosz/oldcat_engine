add_library(OldCatEngine
    Engine.cpp
)

target_link_libraries(OldCatEngine
    PUBLIC
        SDL3::SDL3
)