cmake_minimum_required(VERSION 3.10)

# Set the project name
project(Hyperion LANGUAGES CXX C)

# Set the architecture and configurations
set(CMAKE_CONFIGURATION_TYPES "Debug;Release;Dist" CACHE STRING "" FORCE)
set(CMAKE_ARCHITECTURE "x64" CACHE STRING "" FORCE)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Specify the output directories
set(OUTPUT_DIR "${CMAKE_BINARY_DIR}/bin/${CMAKE_BUILD_TYPE}-${CMAKE_SYSTEM_NAME}-${CMAKE_SYSTEM_PROCESSOR}")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${OUTPUT_DIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${OUTPUT_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${OUTPUT_DIR})

# Define flags for custom Dist configuration
set(CMAKE_C_FLAGS_DIST "-O3")
set(CMAKE_CXX_FLAGS_DIST "-O3")
set(CMAKE_EXE_LINKER_FLAGS_DIST "")
set(CMAKE_SHARED_LINKER_FLAGS_DIST "")

# Include directories
set(IncludeDir_GLFW "${CMAKE_CURRENT_SOURCE_DIR}/Hyperion/vendor/GLFW/include")
set(IncludeDir_Glad "${CMAKE_CURRENT_SOURCE_DIR}/Hyperion/vendor/Glad/include")
set(IncludeDir_ImGui "${CMAKE_CURRENT_SOURCE_DIR}/Hyperion/vendor/imgui")
set(IncludeDir_glm "${CMAKE_CURRENT_SOURCE_DIR}/Hyperion/vendor/glm")
set(IncludeDir_spdlog "${CMAKE_CURRENT_SOURCE_DIR}/Hyperion/vendor/spdlog/include")

# Add subdirectories for external libraries (assuming they have their own CMakeLists.txt)
add_subdirectory(Hyperion/vendor/GLFW)
add_subdirectory(Hyperion/vendor/Glad)
add_subdirectory(Hyperion/vendor/imgui)
add_subdirectory(Hyperion/vendor/spdlog)
add_subdirectory(Hyperion/vendor/glm)

# ---- Hyperion Library ----
file(GLOB_RECURSE HYPERION_SRC
    "Hyperion/src/*.cpp"
    "Hyperion/src/*.h"
)

if (HYPERION_SRC)
    add_library(Hyperion STATIC ${HYPERION_SRC})
else()
    message(FATAL_ERROR "No source files found for the Hyperion library.")
endif()

# Precompiled headers
target_precompile_headers(Hyperion PRIVATE Hyperion/src/Hypch.h)

# Include directories for Hyperion
target_include_directories(Hyperion PUBLIC
    Hyperion/src
    ${IncludeDir_spdlog}
    ${IncludeDir_GLFW}
    ${IncludeDir_Glad}
    ${IncludeDir_ImGui}
    ${IncludeDir_glm}
)

# Linking external libraries for Hyperion
target_link_libraries(Hyperion
    glfw
    Glad        # Ensure this matches the library name defined in the Glad CMakeLists.txt
    imgui
    opengl32.lib
)

# Platform-specific settings for Hyperion
if(WIN32)
    target_compile_definitions(Hyperion PUBLIC
        HY_PLATFORM_WINDOWS
        HY_BUILD_DLL
        GLFW_INCLUDE_NONE
    )
    set_property(TARGET Hyperion PROPERTY MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
endif()

# Set configurations for different build types in Hyperion
target_compile_definitions(Hyperion PRIVATE
    $<$<CONFIG:Debug>:HY_DEBUG>
    $<$<CONFIG:Release>:HY_RELEASE>
    $<$<CONFIG:Dist>:HY_DIST>
)

# ---- Sandbox Application ----
file(GLOB_RECURSE SANDBOX_SRC
    "Sandbox/src/*.cpp"
    "Sandbox/src/*.h"
)

if (SANDBOX_SRC)
    add_executable(Sandbox ${SANDBOX_SRC})
else()
    message(FATAL_ERROR "No source files found for the Sandbox application.")
endif()

# Include directories for Sandbox
target_include_directories(Sandbox PUBLIC
    ${IncludeDir_spdlog}
    ${CMAKE_CURRENT_SOURCE_DIR}/Hyperion/src
    ${CMAKE_CURRENT_SOURCE_DIR}/Hyperion/vendor
    ${IncludeDir_glm}
    ${IncludeDir_GLFW}
    ${IncludeDir_Glad}
    ${IncludeDir_ImGui}
)

# Linking the Hyperion library and other dependencies to Sandbox
target_link_libraries(Sandbox
    Hyperion
    glfw
    Glad        # Ensure this is linked properly
    imgui
    opengl32.lib
)

# Platform-specific settings for Sandbox
if(WIN32)
    target_compile_definitions(Sandbox PUBLIC HY_PLATFORM_WINDOWS)
    set_property(TARGET Sandbox PROPERTY MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
endif()

# Set configurations for different build types in Sandbox
target_compile_definitions(Sandbox PRIVATE
    $<$<CONFIG:Debug>:HY_DEBUG>
    $<$<CONFIG:Release>:HY_RELEASE>
    $<$<CONFIG:Dist>:HY_DIST>
)

# Set the startup project for IDEs like Visual Studio
set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT Sandbox)

# Suppress warnings for third-party libraries
set_source_files_properties(
    Hyperion/vendor/imgui/*.cpp
    Hyperion/vendor/GLFW/*.cpp
    Hyperion/vendor/Glad/src/*.c
    PROPERTIES COMPILE_FLAGS "/w"  # Suppress warnings
)
