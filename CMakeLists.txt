cmake_minimum_required(VERSION 3.5)

project(generator LANGUAGES CXX)

#add_subdirectory(sineOscillator)
#add_subdirectory(signalSummator)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(${PROJECT_NAME} main.cpp)

add_subdirectory(${PROJECT_SOURCE_DIR}/sineOscillator)
target_link_libraries(${PROJECT_NAME} PUBLIC sineOscillator)



#set(NOISEMCDIR "${CMAKE_SOURCE_DIR}/noiseMC")
#add_library(noiseMC STATIC ${NOISEMCDIR}/noiseMC.cpp ${NOISEMCDIR}/noiseMC.h)
add_subdirectory(${PROJECT_SOURCE_DIR}/noiseMC)
target_link_libraries(${PROJECT_NAME} PUBLIC noiseMC)


add_subdirectory(${PROJECT_SOURCE_DIR}/signalSummator)
target_link_libraries(${PROJECT_NAME} PUBLIC signalSummator)


add_subdirectory(${PROJECT_SOURCE_DIR}/wavWriter)
target_link_libraries(${PROJECT_NAME} PUBLIC wavWriter)
