#! /bin/sh
cd "$IN_PWD"/dist && $(dirname "$QMAKE_QMAKE")/macdeployqt ./Rico.app -sign-for-notarization="ACFAF4D0A0552CB78274F2939913B5D3A838AA41" -always-overwrite -dmg
