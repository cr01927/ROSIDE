
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set( EDITOR_SRC_FILES
        LineNumberArea.h
        LineNumberArea.cpp
        EditorWidget.h
        EditorWidget.cpp
        )

find_package(Qt5 COMPONENTS Core Quick REQUIRED)

include_directories(
        ${QT_INCLUDES}
        .
)


add_library(Editor ${EDITOR_SRC_FILES})

qt5_use_modules(Editor Widgets)
target_link_libraries(Editor Qt5::Core Qt5::Quick)