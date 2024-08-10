cmake_minimum_required(VERSION 3.10)

# Set the project name and language
project(Glad LANGUAGES C)

# Set C standard if necessary
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

# Set output directories for build
set(OUTPUT_DIR "${CMAKE_BINARY_DIR}/bin/${CMAKE_BUILD_TYPE}-${CMAKE_SYSTEM_NAME}-${CMAKE_SYSTEM_PROCESSOR}")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${OUTPUT_DIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${OUTPUT_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${OUTPUT_DIR})

# Add the main library target
add_library(Glad STATIC
    include/glad/glad.h
    include/KHR/khrplatform.h
    src/glad.c
)

# Include directories
target_include_directories(Glad PUBLIC "${PROJECT_SOURCE_DIR}/include")

# Set platform-specific configurations
if(WIN32)
    set_property(TARGET Glad PROPERTY MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
endif()

# Set configurations for different build types
set_target_properties(Glad PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY_DEBUG "${OUTPUT_DIR}"
    ARCHIVE_OUTPUT_DIRECTORY_RELEASE "${OUTPUT_DIR}"
    ARCHIVE_OUTPUT_DIRECTORY_DIST "${OUTPUT_DIR}"
)

# Debug configuration
target_compile_definitions(Glad PRIVATE $<$<CONFIG:Debug>:DEBUG>)
target_compile_options(Glad PRIVATE $<$<CONFIG:Debug>:-g>)

# Release configuration
target_compile_definitions(Glad PRIVATE $<$<CONFIG:Release>:NDEBUG>)
target_compile_options(Glad PRIVATE $<$<CONFIG:Release>:-O3>)
