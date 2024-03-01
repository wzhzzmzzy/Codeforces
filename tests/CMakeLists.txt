cmake_minimum_required (VERSION 3.20.0)
project(tests VERSION 1.0.0)

aux_source_directory(. TESTS)
set(TESTS_SINGLE main.cpp 1366A_test.cpp)

add_executable(${PROJECT_NAME} ${TESTS})
add_executable(tests_single ${TESTS_SINGLE})

target_link_libraries(${PROJECT_NAME} gtest solutions)
target_link_libraries(tests_single gtest solutions)