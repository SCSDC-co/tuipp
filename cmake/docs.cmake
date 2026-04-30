option(TUIPP_BUILD_DOCS "Build the TUI++ docs via: `npm run build`" OFF)

if(TUIPP_BUILD_DOCS)
    add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD COMMAND npm run build)

    add_custom_command(
        TARGET ${PROJECT_NAME}
        POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E echo ""
        COMMAND ${CMAKE_COMMAND} -E echo "All docs build successfully."
        COMMAND
            ${CMAKE_COMMAND} -E echo
            "Output: ${CMAKE_CURRENT_SOURCE_DIR}/docs/.vitepress/dist"
        COMMAND ${CMAKE_COMMAND} -E echo ""
    )
endif()
