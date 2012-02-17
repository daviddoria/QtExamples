#! [0] #! [1]
CONFIG      += designer plugin
#! [0]
TARGET      = $$qtLibraryTarget($$TARGET)
#! [2]
TEMPLATE    = lib
#! [1] #! [2]
QTDIR_build:DESTDIR     = $$QT_BUILD_TREE/plugins/designer

#! [3]
HEADERS     = LabeledSlider.h \
              LabeledSliderPlugin.h
SOURCES     = LabeledSlider.cpp \
              LabeledSliderPlugin.cpp
FORMS       = LabeledSlider.ui
#! [3]

# install
target.path = $$[QT_INSTALL_PLUGINS]/designer
sources.files = $$SOURCES $$HEADERS *.pro
sources.path = $$[QT_INSTALL_EXAMPLES]/designer/LabeledSliderPlugin
INSTALLS += target sources

symbian: include($$QT_SOURCE_TREE/examples/symbianpkgrules.pri)
