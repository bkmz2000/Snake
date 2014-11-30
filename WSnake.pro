#-------------------------------------------------
#
# Project created by QtCreator 2014-11-27T08:56:20
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = WSnake
TEMPLATE = app


SOURCES += main.cpp\
    field.cpp \
    snake.cpp \
    snakew.cpp \
    mainwindow.cpp

HEADERS  += \
    field.h \
    snake.h \
    snakew.h \
    mainwindow.h

FORMS    += \
    snakew.ui \
    mainwindow.ui

CONFIG += mobility
MOBILITY = 

