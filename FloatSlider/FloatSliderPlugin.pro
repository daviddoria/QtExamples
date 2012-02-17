CONFIG      += designer plugin

TARGET      = $$qtLibraryTarget($$TARGET)

TEMPLATE    = lib

QTDIR_build:DESTDIR     = $$QT_BUILD_TREE/plugins/designer


HEADERS     = FloatSlider.h \
              FloatSliderPlugin.h
SOURCES     = FloatSlider.cpp \
              FloatSliderPlugin.cpp
FORMS       = FloatSlider.ui


# install
target.path = $$[QT_INSTALL_PLUGINS]/designer
sources.files = $$SOURCES $$HEADERS *.pro
sources.path = $$[QT_INSTALL_EXAMPLES]/designer/FloatSliderPlugin
INSTALLS += target sources

symbian: include($$QT_SOURCE_TREE/examples/symbianpkgrules.pri)
