cmake_minimum_required(VERSION 2.6)

PROJECT(ComputationThread)

FIND_PACKAGE(Qt4 REQUIRED)
INCLUDE(${QT_USE_FILE})

include_directories(${include_directories} ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_BINARY_DIR})

QT4_WRAP_UI(UISrcs main.ui)
QT4_WRAP_CPP(MOCSrcs main.h ComputationThread.h TestComputationThread.h)

ADD_EXECUTABLE(ComputationThread demo.cpp main.cpp ComputationThread.cpp TestComputationThread.cpp MyObject.cpp ${MOCSrcs} ${UISrcs})
TARGET_LINK_LIBRARIES(ComputationThread ${QT_LIBRARIES})

