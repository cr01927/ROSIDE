cmake_minimum_required(VERSION 2.8.12)

project(ROSIDE LANGUAGES CXX)

add_subdirectory(src)

#set(CMAKE_INCLUDE_CURRENT_DIR ON)
#set(CMAKE_AUTOMOC ON)
#set(CMAKE_AUTORCC ON)

#find_package(Qt5 COMPONENTS Core Quick REQUIRED)

#include_directories(
#    ${QT_INCLUDES}
#    )

#qt5_use_modules(${PROJECT_NAME} Widgets)

#target_link_libraries(${PROJECT_NAME} Qt5::Core Qt5::Quick)
