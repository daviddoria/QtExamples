cmake_minimum_required(VERSION 2.6)
PROJECT(CriminisiInpainting)

# Where to copy executables when 'make install' is run
SET( INSTALL_DIR ${CMAKE_INSTALL_PREFIX} )
SET(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE) #fix the dynamic linking error (RPATH) that would occur without this

#include_directories(/home/doriad/src/ITK/Wrapping/WrapITK/ExternalProjects/ItkVtkGlue/src/)

INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_BINARY_DIR})
#INCLUDE_DIRECTORIES(${CMAKE_CURRENT_BINARY_DIR})

FIND_PACKAGE(Qt4 REQUIRED)
INCLUDE(${QT_USE_FILE})

QT4_WRAP_UI(UISrcs Form.ui)
QT4_WRAP_CPP(MOCSrcs Form.h ProgressThread.h CriminisiInpainting.h)

FIND_PACKAGE(VTK REQUIRED)
INCLUDE(${VTK_USE_FILE})

FIND_PACKAGE(ITK REQUIRED)
INCLUDE(${ITK_USE_FILE})

# Interactive
ADD_EXECUTABLE(CriminisiInpaintingInteractive
CriminisiInpainting.cpp 
ProgressThread.cpp
Interactive.cpp Helpers.cpp Form.cxx ${UISrcs} ${MOCSrcs})
TARGET_LINK_LIBRARIES(CriminisiInpaintingInteractive ${VTK_LIBRARIES} QVTK ${ITK_LIBRARIES})
INSTALL( TARGETS CriminisiInpaintingInteractive RUNTIME DESTINATION ${INSTALL_DIR} )
