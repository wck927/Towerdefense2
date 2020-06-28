
QT       += core gui multimedia

CONFIG += c++11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TowerDefense
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    towerposition.cpp \
    tower.cpp \
    waypoint.cpp \
    enemy.cpp \
    bullet.cpp \
    audioplayer.cpp \
    plistreader.cpp

HEADERS  += mainwindow.h \
    towerposition.h \
    tower.h \
    waypoint.h \
    utility.h \
    enemy.h \
    bullet.h \
    audioplayer.h \
    plistreader.h

FORMS    += mainwindow.ui

RESOURCES += \
    resource.qrc
