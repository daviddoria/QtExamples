cmake_minimum_required(VERSION 2.6)

PROJECT(LabeledSliderDemo)

FIND_PACKAGE(Qt4 REQUIRED)
INCLUDE(${QT_USE_FILE})

QT4_WRAP_UI(UISrcs ../LabeledSlider.ui)
QT4_WRAP_CPP(MOCSrcs ../LabeledSlider.h)

include_directories(../ ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_BINARY_DIR})

ADD_EXECUTABLE(LabeledSliderDemo main.cpp ../LabeledSlider.cpp ${MOCSrcs} ${UISrcs})
TARGET_LINK_LIBRARIES(LabeledSliderDemo ${QT_LIBRARIES})

