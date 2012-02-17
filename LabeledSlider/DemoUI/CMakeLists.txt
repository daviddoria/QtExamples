cmake_minimum_required(VERSION 2.6)

PROJECT(LabeledSliderDemoUI)

FIND_PACKAGE(Qt4 REQUIRED)
INCLUDE(${QT_USE_FILE})

add_subdirectory(Widget)

include_directories(${CMAKE_CURRENT_BINARY_DIR}/Widget) # without this, LabeledSlider.h can't find ui_LabeledSlider.h
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/Widget) # without this, main.cpp can't find LabeledSlider.h
include_directories(${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_BINARY_DIR})

QT4_WRAP_UI(UISrcs form.ui)
QT4_WRAP_CPP(MOCSrcs form.h)

ADD_EXECUTABLE(LabeledSliderDemoUI main.cpp form.cpp ${MOCSrcs} ${UISrcs})
TARGET_LINK_LIBRARIES(LabeledSliderDemoUI ${QT_LIBRARIES} libCustomWidget)

