cmake_minimum_required(VERSION 2.8)
project(SandBox)

# add the headers to the project
set(HEADER_FILES graphs/my_graph.hpp
                 src/my_list.hpp)

include_directories(graphs src)
add_subdirectory(src)



set(SOURCES main.cpp
            graphs/my_graph.cpp
            src/my_list.cpp
            ${HEADER_FILES})

add_executable(${PROJECT_NAME} ${SOURCES})
target_link_libraries(${PROJECT_NAME} m)
