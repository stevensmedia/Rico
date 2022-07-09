TARGET = Rico

QT += core widgets webenginecore webenginewidgets

CONFIG += c++latest

SOURCES = src/main.cpp src/MainWindow.cpp

HEADERS = src/MainWindow.h

DESTDIR = dist/

MOC_DIR = build/
OBJECTS_DIR = build/
UI_DIR = build/
