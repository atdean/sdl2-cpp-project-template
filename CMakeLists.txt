set(PROJECT_NAME sdl2-cpp-project-template)

# http://derekmolloy.ie/hello-world-introductions-to-cmake/

# https://stackoverflow.com/questions/10851247/how-to-activate-c-11-in-cmake
# Fix behavior of CMAKE_CXX_STANDARD when targeting macOS.
if (POLICY CMP0025)
  cmake_policy(SET CMP0025 NEW)
endif ()

# https://trenki2.github.io/blog/2017/06/02/using-sdl2-with-cmake/
# Include the FindSDL2.cmake file in order to find SDL2 on all platforms
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake")

cmake_minimum_required(VERSION 3.15.0)
set(CMAKE_CXX_STANDARD 11)

project(${PROJECT_NAME})

# Can manually add sources as follows if desired:
# set(SOURCES src/main.cpp src/anotherfile.cpp)

# Use wildcard to include all source files under /src
# Can also use GLOB_RECURSE
file(GLOB SOURCES "src/*.cpp")

# set(SDL2_INCLUDE_DIRS /Library/Frameworks/SDL2.framework/Headers)
# set(SDL2_LIBRARIES /Library/Frameworks/SDL2/framework/SDL2)

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS} ${SDL2_IMAGE_INCLUDE_DIRS})

add_executable(${PROJECT_NAME} ${SOURCES})
target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES})