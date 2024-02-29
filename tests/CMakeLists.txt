cmake_minimum_required (VERSION 3.20.0)
project(tests VERSION 1.0.0)

aux_source_directory(. TESTS)

add_executable(${PROJECT_NAME} ${TESTS})

target_link_libraries(${PROJECT_NAME} gtest solutions)