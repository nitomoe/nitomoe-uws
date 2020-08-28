cmake_minimum_required (VERSION 3.17)

project (nitomoe)

set (CMAKE_CXX_STANDARD 17)
set (CMAKE_CXX_STANDARD_REQUIRED ON)
set (CMAKE_CXX_EXTENSIONS OFF)

include_directories (${CMAKE_SOURCE_DIR}/include ${CMAKE_SOURCE_DIR}/uSockets/src)

add_executable (${PROJECT_NAME}
    src/main.cpp
    src/Application.cpp
    src/Element.cpp
    src/Env.cpp
    src/Log.cpp
    src/views/Index.cpp
)

target_link_libraries (${PROJECT_NAME}
    ${CMAKE_SOURCE_DIR}/uSockets/uSockets.a
    pthread
    z
)