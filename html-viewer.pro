#-------------------------------------------------
#
# Project created by QtCreator 2012-09-07T15:59:59
#
#-------------------------------------------------

# this needs to stay in sync with the Makefile
VERSION = 1.0.1
QT      += widgets
QT      += network webkit
QT += webkitwidgets
QT+= core gui webkit

CONFIG += c++11
TARGET = html-viewer
TEMPLATE = app

# add #define for the version
DEFINES += APP_VERSION=\\\"$$VERSION\\\"

SOURCES += main.cpp\
    mainview.cpp 

HEADERS  += \
    mainview.h \
    systemdefs.h

