QT = core gui widgets

TARGET = image-processing-demo
TEMPLATE = app

mac* | linux*{
	CONFIG(release, debug|release):CONFIG += Release
	CONFIG(debug, debug|release):CONFIG += Debug
}

contains(QT_ARCH, x86_64) {
	ARCHITECTURE = x64
} else {
	ARCHITECTURE = x86
}

Release:OUTPUT_DIR=release/$${ARCHITECTURE}
Debug:OUTPUT_DIR=debug/$${ARCHITECTURE}

DESTDIR  = ../bin/$${OUTPUT_DIR}/
OBJECTS_DIR = ../build/$${OUTPUT_DIR}/$${TARGET}
MOC_DIR     = ../build/$${OUTPUT_DIR}/$${TARGET}
UI_DIR      = ../build/$${OUTPUT_DIR}/$${TARGET}

CONFIG += c++14

win*{
	QMAKE_CXXFLAGS += /MP /FS /openmp
	DEFINES += WIN32_LEAN_AND_MEAN NOMINMAX
	QMAKE_CXXFLAGS_WARN_ON = /W4

	QMAKE_LFLAGS += /DEBUG:FASTLINK

	Debug:QMAKE_LFLAGS += /INCREMENTAL
	Release:QMAKE_LFLAGS += /OPT:REF /OPT:ICF
}

linux*|mac*{
	QMAKE_CXXFLAGS += -pedantic-errors
	QMAKE_CFLAGS += -pedantic-errors
	QMAKE_CXXFLAGS_WARN_ON = -Wall -Wno-c++11-extensions -Wno-local-type-template-args -Wno-deprecated-register

	Release:DEFINES += NDEBUG=1
	Debug:DEFINES += _DEBUG
}

INCLUDEPATH += \
	../cpputils \
	../cpp-template-utils \
	../qtutils\ 
	../image-processing

LIBS += -L$${DESTDIR}
LIBS += -lcpputils -lqtutils -limage-processing

FORMS += \
    src/mainwindow.ui

HEADERS += \
    src/mainwindow.h \
    src/imageviewwidget.h \
    src/qimageadapter.hpp

SOURCES += \
    src/mainwindow.cpp \
    src/main.cpp \
    src/imageviewwidget.cpp \
    src/qimageadapter.cpp