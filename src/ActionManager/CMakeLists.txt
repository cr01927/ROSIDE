
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set( ACTION_MANAGER_SRC_FILES
        ActionManager.h
        ActionManager.cpp
        )

find_package(Qt5 COMPONENTS Core Quick REQUIRED)

include_directories(
        ${QT_INCLUDES}
        .
)


add_library(ActionManager ${ACTION_MANAGER_SRC_FILES})

qt5_use_modules(ActionManager Widgets)
target_link_libraries(ActionManager Qt5::Core Qt5::Quick )