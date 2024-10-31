cmake_minimum_required(VERSION 3.25)
project(TankTek)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

file(GLOB_RECURSE SOURCES "src/*.cpp")

set(GLAD_SOURCES "vendor/glad/glad.c")

# Fetch Dependencies
include(FetchContent)

FetchContent_Declare(
    glfw
    GIT_REPOSITORY "https://github.com/glfw/glfw.git"
    GIT_TAG "3.4"
)

FetchContent_MakeAvailable(glfw)

add_library(${PROJECT_NAME} ${GLAD_SOURCES} ${SOURCES})

target_include_directories(${PROJECT_NAME} PUBLIC "include")
target_link_libraries(${PROJECT_NAME} glfw)

if(APPLE)
    target_link_libraries(${PROJECT_NAME} "-framework IOKit")
    target_link_libraries(${PROJECT_NAME} "-framework Cocoa")
    target_link_libraries(${PROJECT_NAME} "-framework OpenGL")
endif()

file(GLOB_RECURSE SANDBOX_SOURCES "sandbox/*.cpp")

add_executable(Sandbox ${SANDBOX_SOURCES})

target_include_directories(Sandbox PUBLIC "include")
target_link_libraries(Sandbox ${PROJECT_NAME})
