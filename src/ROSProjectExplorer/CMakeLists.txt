
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set( ROSPROJECTEXPLORER_SRC_FILES
        ROSProjectExplorer.h
        ROSProjectExplorer.cpp
        )

find_package(Qt5 COMPONENTS Core Quick REQUIRED)

include_directories(
        ${QT_INCLUDES}
        .
        ..
        ../PackageXmlParser
)


add_library(ROSProjectExplorer ${ROSPROJECTEXPLORER_SRC_FILES})

qt5_use_modules(ROSProjectExplorer Widgets )
target_link_libraries(ROSProjectExplorer Qt5::Core Qt5::Quick)