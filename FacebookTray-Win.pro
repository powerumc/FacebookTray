#-------------------------------------------------
#
# Project created by QtCreator 2013-03-11T20:44:09
#
#-------------------------------------------------

#QMAKE_CXXFLAGS += -std=c++11
#QMAKE_COMPILER_DEFINES += _MSC_VER=1600 WIN32


QT       += core gui network webkitwidgets
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets


TARGET = FacebookTray
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    facebookwebpage.cpp \
    persistentcecookiejar.cpp

HEADERS  += mainwindow.h \
    facebookwebpage.h \
    persistentcecookiejar.h

FORMS    += mainwindow.ui

RESOURCES += \
    IconsResource.qrc


QMAKE_LIBS_QT

LIBS += -Xlinker -Bstatic

win32: LIBS += -lQt5WebKitWidgets -lQt5WebKit

QMAKE_LIBS_QT = qt5webkitwidgets.lib
