cmake_minimum_required(VERSION 3.5)

project(wavWriter LANGUAGES CXX VERSION 1.0.0)

set(SOURCES wavWriter.cpp)
set(HEADERS wavWriter.h)

add_library(${PROJECT_NAME} STATIC ${SOURCES} ${HEADERS})
target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR})

source_group("Sources" FILES ${SOURCES})
source_group("Headers" FILES ${HEADERS})