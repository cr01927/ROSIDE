add_subdirectory(Editor)
add_subdirectory(Menus)
add_subdirectory(Modes)
add_subdirectory(PackageXMLParser)
add_subdirectory(ROSProjectExplorer)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(ROSIDE_SRC_FILES
        main.cpp
        MainWindow.h
        MainWindow.cpp
        )

find_package(Qt5 COMPONENTS Core Quick REQUIRED)

include_directories(
        ${QT_INCLUDES}
        .
)

add_executable(ROSIDE ${ROSIDE_SRC_FILES})
qt5_use_modules(${PROJECT_NAME} Widgets)
target_link_libraries(ROSIDE Qt5::Core Qt5::Quick Editor Menus Modes ROSProjectExplorer PackageXMLParser)