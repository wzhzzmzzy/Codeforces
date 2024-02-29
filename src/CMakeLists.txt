cmake_minimum_required (VERSION 3.20.0)
project (solutions VERSION 1.0.0)

aux_source_directory(. SOURCE)
aux_source_directory(solutions SOLUTIONS)

add_library(${PROJECT_NAME} ${SOURCE} ${SOLUTIONS})
target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR})