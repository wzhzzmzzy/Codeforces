cmake_minimum_required (VERSION 3.20.0)

project (codeforces VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(src)
add_subdirectory(tests)
add_subdirectory(third_party/gtest)

add_executable(${PROJECT_NAME} src/main.cpp)

target_link_libraries(${PROJECT_NAME} solutions)