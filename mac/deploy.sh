#! /bin/sh
cd "$IN_PWD"/dist && $(dirname "$QMAKE_QMAKE")/macdeployqt ./Rico.app -sign-for-notarization="D353AD23BDF92636AF0E7207A3EDE1F9FA3C7F2A" -always-overwrite -dmg
