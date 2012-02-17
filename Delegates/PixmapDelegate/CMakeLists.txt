cmake_minimum_required(VERSION 2.6)

PROJECT(PixmapDelegate)

FIND_PACKAGE(Qt4 REQUIRED)
INCLUDE(${QT_USE_FILE})

QT4_WRAP_CPP(MOCSrcs PixmapDelegate.h)

include_directories(${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_BINARY_DIR})

ADD_EXECUTABLE(PixmapDelegate main.cpp PixmapDelegate.cpp
${MOCSrcs}
)
TARGET_LINK_LIBRARIES(PixmapDelegate ${QT_LIBRARIES})
