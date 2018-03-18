
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set( MODES_SRC_FILES
        DevelopWidget.h
        DevelopWidget.cpp
        )

find_package(Qt5 COMPONENTS Core Quick REQUIRED)

include_directories(
        ${QT_INCLUDES}
        .
        ..
)


add_library(Modes ${MODES_SRC_FILES})

qt5_use_modules(Modes Widgets)
target_link_libraries(Modes Qt5::Core Qt5::Quick Editor ROSPackageExplorer)