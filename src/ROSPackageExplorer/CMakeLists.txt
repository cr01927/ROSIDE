
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set( ROSPACKAGEEXPLORER_SRC_FILES
        ROSPackageExplorer.h
        ROSPackageExplorer.cpp
        )

find_package(Qt5 COMPONENTS Core Quick REQUIRED)

include_directories(
        ${QT_INCLUDES}
        .
        ..
)


add_library(ROSPackageExplorer ${ROSPACKAGEEXPLORER_SRC_FILES})

qt5_use_modules(ROSPackageExplorer Widgets)
target_link_libraries(ROSPackageExplorer Qt5::Core Qt5::Quick)