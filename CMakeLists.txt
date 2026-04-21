cmake_minimum_required(VERSION 3.16)
project(MyEngine)

set(CMAKE_CXX_STANDARD 17)

find_package(SDL2 REQUIRED)

add_executable(MyEngine
    src/main.cpp
    src/core/Engine.cpp
    src/core/ECS.cpp
    src/systems/Input.cpp
    src/systems/Renderer.cpp
    src/systems/Physics.cpp
)

target_include_directories(MyEngine PRIVATE
    ${SDL2_INCLUDE_DIRS}
    include/
    include/core
    include/systems
)

target_link_libraries(MyEngine
    ${SDL2_LIBRARIES}
)