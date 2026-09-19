add_executable(OldCatSandbox
    main.cpp
    Game_ClickCounter.cpp
)

target_link_libraries(OldCatSandbox
    PRIVATE
        OldCatEngine
)

add_custom_command(TARGET OldCatSandbox POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        $<TARGET_FILE:SDL3::SDL3-shared>
        $<TARGET_FILE_DIR:OldCatSandbox>

    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        $<TARGET_FILE:SDL3_ttf::SDL3_ttf-shared>
        $<TARGET_FILE_DIR:OldCatSandbox>

    COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_CURRENT_SOURCE_DIR}/assets
        $<TARGET_FILE_DIR:OldCatSandbox>/assets
)