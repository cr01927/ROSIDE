
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set( MENUS_SRC_FILES
        FileMenuSlots.h
        FileMenuSlots.cpp
        EditMenuSlots.cpp EditMenuSlots.h)

find_package(Qt5 COMPONENTS Core Quick REQUIRED)

include_directories(
        ${QT_INCLUDES}
        .
        ..
		../ROSProjectExplorer
		)


add_library(Menus ${MENUS_SRC_FILES})

qt5_use_modules(Menus Widgets)
target_link_libraries(Menus Qt5::Core Qt5::Quick)
