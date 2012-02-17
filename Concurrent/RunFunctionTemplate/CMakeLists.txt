cmake_minimum_required(VERSION 2.6)

PROJECT(RunFunctionTemplate)

FIND_PACKAGE(Qt4 REQUIRED)
INCLUDE(${QT_USE_FILE})

include_directories(${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_BINARY_DIR})

ADD_EXECUTABLE(RunFunctionTemplate RunFunctionTemplate.cpp)
TARGET_LINK_LIBRARIES(RunFunctionTemplate ${QT_LIBRARIES})
