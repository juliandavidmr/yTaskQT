#-------------------------------------------------
#
# Project created by QtCreator 2016-01-13T09:42:07
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ytask
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    sql.cpp \
    dialognuevatarea.cpp \
    clase_tarea.cpp

HEADERS  += mainwindow.h \
    sqlite.h \
    dialognuevatarea.h \
    clase_tarea.h

FORMS    += mainwindow.ui \
    dialognuevatarea.ui
