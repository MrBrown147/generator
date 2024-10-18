cmake_minimum_required(VERSION 3.5)

project(sineOscillator LANGUAGES CXX VERSION 1.0.0)

set(SOURCES sineOscillator.cpp)
set(HEADERS sineOscillator.h)

add_library(${PROJECT_NAME} STATIC ${SOURCES} ${HEADERS})
target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR})

source_group("Sources" FILES ${SOURCES})
source_group("Headers" FILES ${HEADERS})

target_compile_definitions(sineOscillator PRIVATE -D_USE_MATH_DEFINES)
