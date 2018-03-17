cmake_minimum_required(VERSION 2.8.12)

project(ROSIDE LANGUAGES CXX)

set(Qt5Core_DIR "/opt/qt58/lib/cmake/Qt5Core")
set(Qt5_DIR "/opt/qt58/lib/cmake/Qt5")
set(QT_QMAKE_EXECUTABLE "/opt/qt58/bin/qmake")

add_subdirectory(src)

