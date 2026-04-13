
# cmake must support Visual Studio 2022
cmake_minimum_required(VERSION 3.21)
project(breakout LANGUAGES CXX)
add_definitions(-D_SILENCE_STDEXT_ARR_ITERS_DEPRECATION_WARNING)

# This line lets Conan take care of setting the dependencies lib and include paths
# removed for 2.x migration - set(CMAKE_MODULE_PATH ${CMAKE_BINARY_DIR}/conan)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/install")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/install/bin")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/install/bin")

set(UNITY_BUILD TRUE)

set(BREAKOUT_FILES
    src/breakout.cpp
    src/Object.h
    src/Object.cpp
    src/Component.h
    src/Component.cpp
    src/Util.h
    src/RenderSystem.h
    src/RenderSystem.cpp
    src/PhysicsSystem.h
    src/PhysicsSystem.cpp
    src/Engine.cpp
    src/Engine.h
    src/Game.cpp
    src/Game.h
    src/Math.cpp
    src/Math.h
    src/ObjectFactory.h
    src/ObjectFactory.cpp
    src/Clock.h
    src/Clock.cpp
    src/InputSystem.h
    src/InputSystem.cpp
    src/CollisionReaction.h
    src/CollisionReaction.cpp)

if(NOT UNITY_BUILD)
    set(BUILD_FILES ${BREAKOUT_FILES})
else(NOT UNITY_BUILD)
    set_source_files_properties(${BREAKOUT_FILES} PROPERTIES HEADER_FILE_ONLY TRUE)
    set(BUILD_FILES src/unity_build.cpp ${BREAKOUT_FILES})
endif(NOT UNITY_BUILD)

add_executable(breakout ${BUILD_FILES})

find_package(fmt REQUIRED)
# find_package(sfml)
find_package(SDL3 REQUIRED)
find_package(SFML REQUIRED COMPONENTS graphics window system)
find_package(Catch2 REQUIRED)
find_package(nlohmann_json REQUIRED)

target_link_libraries(breakout PRIVATE fmt::fmt sfml::sfml nlohmann_json::nlohmann_json Catch2::Catch2WithMain)

if (MSVC)
    target_compile_options(breakout PRIVATE "/W4" "/WX" "/D_CRT_SECURE_NO_WARNINGS")
endif()