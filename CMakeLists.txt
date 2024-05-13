cmake_minimum_required(VERSION 3.20)

project(opengl_sdl_glew
    VERSION 0.1
    DESCRIPTION "C++ program using OpenGL and SDL2"
    LANGUAGES CXX)

# Add the path to the directory containing SDL2 headers
include_directories(${SDL2_INCLUDE_DIRS})

# Add the path to the directory containing GLEW headers
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include/GL)

# find packages / dependencies
find_package(SDL2 REQUIRED)
find_package(OpenGL REQUIRED)

# create app lib
add_library(app STATIC src/app.cpp)
target_include_directories(app PRIVATE include)
set_target_properties(app PROPERTIES ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/lib)

# create exec
add_executable(main src/main.cpp)
set_target_properties(main PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)

# link libs
target_link_libraries(main app)
target_link_libraries(main ${SDL2_LIBRARIES})
target_link_libraries(main OpenGL::GL)
target_link_libraries(main ${CMAKE_CURRENT_SOURCE_DIR}/lib/libGLEW.a)

target_compile_features(app PRIVATE cxx_std_20)