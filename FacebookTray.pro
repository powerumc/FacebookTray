#-------------------------------------------------
#
# Project created by QtCreator 2013-03-11T20:44:09
#
#-------------------------------------------------



QT       += core gui network webkitwidgets xml svg
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets


TARGET = FacebookTray
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    persistentcecookiejar.cpp \
    common.cpp \
    sslnetworkaccessmanager.cpp \
    hostwebpage.cpp \
    hostsystemcountertrayicon.cpp

HEADERS  += mainwindow.h \
    persistentcecookiejar.h \
    common.h \
    sslnetworkaccessmanager.h \
    hostwebpage.h \
    hostsystemcountertrayicon.h

FORMS    += mainwindow.ui

RESOURCES += \
    IconsResource.qrc



macx {
    QMAKE_CXXFLAGS_RELEASE += -fvisibility=hidden
    QMAKE_CXXFLAGS_DEBUG += -fvisibility=hidden
#    QMAKE_MACOSX_DEPLOYMENT_TARGET = 10.3
#    QMAKE_MAC_SDK = /Developer/SDKs/MacOSX10.6.sdk
}

