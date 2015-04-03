# -------------------------------------------------
# Project created by QtCreator 2011-11-20T15:01:54
# -------------------------------------------------
QT += xml \
    xmlpatterns \
    phonon \
    multimediawidgets
CONFIG += qtestlib
TARGET = jeopardy
TEMPLATE = app
SOURCES += main.cpp \
    jeopardy.cpp \
    player.cpp \
    gamefield.cpp \
    answer.cpp \
    editor.cpp \
    podium.cpp \
    doublejeopardy.cpp
HEADERS += jeopardy.h \
    player.h \
    gamefield.h \
    answer.h \
    editor.h \
    podium.h \
    doublejeopardy.h
FORMS += answer.ui
