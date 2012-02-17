cmake_minimum_required(VERSION 2.6)
PROJECT(ThreadedGUIUpdate)

# Where to copy executables when 'make install' is run
SET( INSTALL_DIR ${CMAKE_INSTALL_PREFIX} )
SET(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE) #fix the dynamic linking error (RPATH) that would occur without this

#include_directories(/home/doriad/src/ITK/Wrapping/WrapITK/ExternalProjects/ItkVtkGlue/src/)

INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_BINARY_DIR})

FIND_PACKAGE(Qt4 REQUIRED)
INCLUDE(${QT_USE_FILE})

QT4_WRAP_UI(UISrcs Form.ui)
QT4_WRAP_CPP(MOCSrcs Form.h ProgressThread.h ComputationClass.h)

# Interactive
ADD_EXECUTABLE(ThreadedGUIUpdate
ComputationClass.cpp 
ProgressThread.cpp
Interactive.cpp 
Form.cxx ${UISrcs} ${MOCSrcs})
TARGET_LINK_LIBRARIES(ThreadedGUIUpdate ${QT_LIBRARIES})
INSTALL( TARGETS ThreadedGUIUpdate RUNTIME DESTINATION ${INSTALL_DIR} )
