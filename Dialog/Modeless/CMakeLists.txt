cmake_minimum_required(VERSION 2.6)

PROJECT(ModelessDialog)

FIND_PACKAGE(Qt4 REQUIRED)
INCLUDE(${QT_USE_FILE})

QT4_WRAP_UI(UISrcs dialog.ui form.ui)
QT4_WRAP_CPP(MOCSrcs dialog.h form.h)

include_directories(${include_directories} ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_BINARY_DIR})

ADD_EXECUTABLE(ModelessDialog main.cpp dialog.cpp form.cpp ${MOCSrcs} ${UISrcs})
TARGET_LINK_LIBRARIES(ModelessDialog ${QT_LIBRARIES})

