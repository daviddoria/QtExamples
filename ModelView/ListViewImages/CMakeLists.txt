cmake_minimum_required(VERSION 2.6)

PROJECT(ListViewImages)

FIND_PACKAGE(Qt4 REQUIRED)
INCLUDE(${QT_USE_FILE})

QT4_WRAP_UI(UISrcs form.ui)
QT4_WRAP_CPP(MOCSrcs form.h PixmapDelegate.h)

include_directories(${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_BINARY_DIR})

ADD_EXECUTABLE(ListViewImages main.cpp MyListModel.cpp PixmapDelegate.cpp form.cpp ${MOCSrcs} ${UISrcs})
TARGET_LINK_LIBRARIES(ListViewImages ${QT_LIBRARIES})

