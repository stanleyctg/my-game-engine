cmake_minimum_required(VERSION 3.16)
project(MyEngine)

set(CMAKE_CXX_STANDARD 17)

find_package(SDL2 REQUIRED)

add_executable(MyEngine
    src/main.cpp
    src/engine.cpp
    src/ECS.cpp
    src/Input.cpp
)

target_include_directories(MyEngine PRIVATE
    ${SDL2_INCLUDE_DIRS}
    src/
)

target_link_libraries(MyEngine
    ${SDL2_LIBRARIES}
)