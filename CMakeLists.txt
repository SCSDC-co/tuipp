cmake_minimum_required(VERSION 4.0)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

project(
    tuipp
    LANGUAGES CXX
    VERSION 0.0.1
    DESCRIPTION
        "A header-only simple TUI library heavily inspired by rich and Spectre.Console"
)

option(TUIPP_BUILD_TESTS "Build tests" OFF)
option(TUIPP_BUILD_DOCS "Build the docs" OFF)

if(TUIPP_BUILD_TESTS)
    add_executable(tuipp test/main.cpp)

    target_include_directories(tuipp PUBLIC ${CMAKE_SOURCE_DIR}/include)
    set_target_properties(tuipp PROPERTIES CXX_EXTENSIONS OFF)
endif()

if(TUIPP_BUILD_DOCS)
    find_package(Doxygen)

    if(Doxygen_FOUND)
        set(DOXYGEN_PROJECT_NAME TUI++)
        set(DOXYGEN_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/docs/)
        set(DOXYGEN_JAVADOC_AUTOBRIEF YES)
        set(DOXYGEN_MULTILINE_CPP_IS_BRIEF YES)
        set(DOXYGEN_CPP_CLI_SUPPORT YES)
        set(DOXYGEN_EXTRACT_ALL YES)
        set(DOXYGEN_SHOW_HEADERFILE NO)
        set(DOXYGEN_SHOW_INCLUDE_FILES NO)
        set(DOXYGEN_QUIET YES)
        set(DOXYGEN_RECURSIVE YES)
        set(DOXYGEN_GENERATE_MAN YES)
        set(DOXYGEN_GENERATE_TREEVIEW YES)
        set(DOXYGEN_EXCLUDE_PATTERNS *private/*)

        doxygen_add_docs(tuipp_docs ${CMAKE_SOURCE_DIR}/include/tuipp/ ALL)

        add_custom_command(
            TARGET tuipp_docs
            POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E echo ""
            COMMAND ${CMAKE_COMMAND} -E echo "All docs build successfully."
            COMMAND
                ${CMAKE_COMMAND} -E echo "Output: ${DOXYGEN_OUTPUT_DIRECTORY}"
            COMMAND ${CMAKE_COMMAND} -E echo ""
        )
    else()
        message(FATAL_ERROR "Doxygen not found. Please install it")
    endif()
endif()
