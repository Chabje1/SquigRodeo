cmake_minimum_required(VERSION 3.16)
project(squigrodeo)

# set the output directory for built objects.
# This makes sure that the dynamic library goes into the build directory automatically.
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/server/$<CONFIGURATION>")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/server/$<CONFIGURATION>")

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_USE_RESPONSE_FILE_FOR_INCLUDES 0)

# on Web targets, we need CMake to generate a HTML webpage. 
set(CMAKE_EXECUTABLE_SUFFIX ".html" CACHE INTERNAL "")

# This assumes the SDL source is available in vendored/SDL
add_subdirectory(ext/SDL3 EXCLUDE_FROM_ALL)

file(GLOB_RECURSE CPP_SOURCE_FILES ${CMAKE_SOURCE_DIR}/src/*.cpp)

# Create your game executable target as usual
add_executable(index ${CPP_SOURCE_FILES} ${IMGUI_SOURCE_FILES})

target_include_directories(index PUBLIC ${CMAKE_SOURCE_DIR}/include)

target_link_options(index PUBLIC --shell-file ${CMAKE_SOURCE_DIR}/src/shell_minimal.html)

# Link to the actual SDL3 library.
target_link_libraries(index PRIVATE SDL3::SDL3)

# ===================================================================
# =                              IMGUI                              =
# ===================================================================
set(IMGUI_DIR_PATH ${CMAKE_SOURCE_DIR}/ext/imgui)

file(GLOB IMGUI_SOURCE_FILES ${IMGUI_DIR_PATH}/*.cpp)

list(APPEND IMGUI_SOURCE_FILES
  ${IMGUI_DIR_PATH}/misc/cpp/imgui_stdlib.cpp
  ${IMGUI_DIR_PATH}/backends/imgui_impl_sdl3.cpp
  ${IMGUI_DIR_PATH}/backends/imgui_impl_opengl3.cpp
)

set(IMGUI_INCLUDES ${IMGUI_DIR_PATH} ${IMGUI_DIR_PATH}/misc/cpp/ ${IMGUI_DIR_PATH}/backends/)

target_include_directories(index PUBLIC ${IMGUI_INCLUDES})

target_sources(index PUBLIC ${IMGUI_SOURCE_FILES})

# ===================================================================
# =                          SERVER FILES                           =
# ===================================================================
file(GLOB SERVER_FILES ${CMAKE_SOURCE_DIR}/public/*)

foreach(SERVER_FILE ${SERVER_FILES})
    add_custom_command(
        TARGET index POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy
                ${SERVER_FILE}
                ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})
endforeach()