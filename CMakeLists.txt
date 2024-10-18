cmake_minimum_required(VERSION 3.5)

project(generator LANGUAGES CXX)

#add_subdirectory(sineOscillator)
#add_subdirectory(signalSummator)

add_executable(${PROJECT_NAME} main.cpp)

set(SINEOSCDIR "${CMAKE_SOURCE_DIR}/sineOscillator")
add_library(sineOscillator STATIC ${SINEOSCDIR}/sineOscillator.cpp ${SINEOSCDIR}/sineOscillator.h)
target_link_libraries(${PROJECT_NAME} PUBLIC sineOscillator)


set(NOISEMCDIR "${CMAKE_SOURCE_DIR}/noiseMC")
add_library(noiseMC STATIC ${NOISEMCDIR}/noiseMC.cpp ${NOISEMCDIR}/noiseMC.h)
target_link_libraries(${PROJECT_NAME} PUBLIC noiseMC)


set(SIGSUMMDIR "${CMAKE_SOURCE_DIR}/signalSummator")
add_library(signalSummator STATIC ${SIGSUMMDIR}/signalSummator.cpp ${SIGSUMMDIR}/signalSummator.h)
target_link_libraries(${PROJECT_NAME} PUBLIC signalSummator)
target_link_libraries(signalSummator PUBLIC sineOscillator)
target_link_libraries(signalSummator PUBLIC noiseMC)


set(WAV_WRITER_DIR "${CMAKE_SOURCE_DIR}/wavWriter")
add_library(wavWriter STATIC ${WAV_WRITER_DIR}/wavWriter.cpp ${WAV_WRITER_DIR}/wavWriter.h)
target_link_libraries(${PROJECT_NAME} PUBLIC wavWriter)
