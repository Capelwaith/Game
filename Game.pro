#-------------------------------------------------
#
# Project created by QtCreator 2011-06-11T14:58:41
#
#-------------------------------------------------

QT       += core gui
QT += multimedia
QT += widgets

TARGET = Game_2
TEMPLATE = app


SOURCES += main.cpp\
        dialog.cpp \
    tank.cpp \
    tank2.cpp \
    bala.cpp \
    mainwindow.cpp

HEADERS  += dialog.h \
    tank.h \
    tank2.h \
    bala.h \
    mainwindow.h

FORMS    += dialog.ui \
    mainwindow.ui

RESOURCES += \
    music.qrc \
    images.qrc
