TARGET = Rico

QT += core widgets webenginecore webenginewidgets

CONFIG += c++latest

SOURCES = src/main.cpp src/MainWindow.cpp

HEADERS = src/MainWindow.h

DESTDIR = dist/

MOC_DIR = build/
OBJECTS_DIR = build/
UI_DIR = build/

mac {
QMAKE_EXTRA_TARGETS += dmg
dmg.commands = IN_PWD="$${IN_PWD}" QMAKE_QMAKE="$${QMAKE_QMAKE}" mac/deploy.sh
}
