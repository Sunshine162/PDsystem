#-------------------------------------------------
#
# Project created by QtCreator 2017-12-02T21:54:13
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = PDtool01
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0



INCLUDEPATH+=D:/IDE/opencv3.0_QT/include/opencv \
             D:/IDE/opencv3.0_QT/include/opencv2 \
             D:/IDE/opencv3.0_QT/include
LIBS += -L D:/IDE/opencv3.0_QT/x86/mingw/lib/libopencv_*.a


SOURCES += main.cpp\
    src/view/mainwindow.cpp \
    src/view/menu_file.cpp \
    src/view/menu_process.cpp \
    src/view/menu_foreground.cpp \
    src/view/menu_detect.cpp \
    src/view/menu_model.cpp \
    src/event/event_file.cpp \
    src/event/event_main.cpp \
    src/core/videoplay.cpp \
    src/model/md_file.cpp \
    src/model/md_process.cpp \
    src/model/md_foreground.cpp \
    src/model/md_model.cpp \
    src/model/md_detect.cpp \
    src/event/event_foreground.cpp \
    src/model/encodingconvert.cpp \
    src/core/visualbgextractor.cpp \
    src/core/framedifference.cpp \
    src/event/event_detect.cpp \
    src/core/hogsvmdetect.cpp

HEADERS  += \
    header/view/mainwindow.h \
    header/view/menu_file.h \
    header/view/menu_process.h \
    header/view/menu_foreground.h \
    header/view/menu_model.h \
    header/view/menu_detect.h \
    header/model/encodingconvert.h \
    header/core/videoplay.h \
    header/model/md_detect.h \
    header/model/md_file.h \
    header/model/md_foreground.h \
    header/model/md_process.h \
    header/model/md_model.h \
    header/core/framedifference.h \
    header/core/visualbgextractor.h \
    header/core/gaussbackgroundmodel.h \
    header/core/hogsvmdetect.h



FORMS    += \
    ui/mainwindow.ui \
    ui/menu_file.ui
