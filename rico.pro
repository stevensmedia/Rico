TARGET = Rico

QT += core widgets

CONFIG += c++latest

SOURCES = src/main.cpp src/MainWindow.cpp

HEADERS = src/MainWindow.h

FORMS = src/MainWindow.ui

DESTDIR = dist/

MOC_DIR = build/
OBJECTS_DIR = build/
UI_DIR = build/
