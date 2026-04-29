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

include(GNUInstallDirs)

add_library(${PROJECT_NAME} STATIC)

add_subdirectory(./src/tuipp/)

target_include_directories(
    ${PROJECT_NAME}
    PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src/tuipp
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/tuipp>
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)

add_subdirectory(./include/tuipp/)

# This is for preserving the folder structure
foreach(header ${public_headers})
    file(
        RELATIVE_PATH
        header_file_path
        "${CMAKE_CURRENT_SOURCE_DIR}/${PROJECT_NAME}"
        "${header}"
    )
    get_filename_component(
        header_directory_path
        "${header_file_path}"
        DIRECTORY
    )
    install(
        FILES ${header}
        DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}/${header_directory_path}"
    )
endforeach()

set_target_properties(${PROJECT_NAME} PROPERTIES DEBUG_POSTFIX "d")

if(DEFINED CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
    message(
        STATUS
        "CMAKE_INSTALL_PREFIX is not set\n"
        "Default value: ${CMAKE_INSTALL_PREFIX}\n"
        "Will set it to ${CMAKE_SOURCE_DIR}/install"
    )
    set(CMAKE_INSTALL_PREFIX
        "${CMAKE_SOURCE_DIR}/install"
        CACHE PATH
        "Where TUI++ will be installed to"
        FORCE
    )
endif()

install(
    TARGETS ${PROJECT_NAME}
    EXPORT "${PROJECT_NAME}Targets"
    # these get default values from GNUInstallDirs, no need to set them
    #RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR} # bin
    #LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR} # lib
    #ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR} # lib
    PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/${PROJECT_NAME}
    INCLUDES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

include(./cmake/doxygen.cmake)
