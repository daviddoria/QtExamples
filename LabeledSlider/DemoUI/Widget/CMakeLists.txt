include_directories(${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_BINARY_DIR})

message("Widget CMAKE_CURRENT_BINARY_DIR? ${CMAKE_CURRENT_BINARY_DIR}")

QT4_WRAP_UI(LabeledSliderUISrcs LabeledSlider.ui)
QT4_WRAP_CPP(LabeledSliderMOCSrcs LabeledSlider.h)

add_library(libCustomWidget LabeledSlider.cpp ${LabeledSliderMOCSrcs} ${LabeledSliderUISrcs})
