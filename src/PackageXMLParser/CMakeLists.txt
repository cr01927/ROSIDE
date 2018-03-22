
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set( PACKAGEXMLPARSER_SRC_FILES
        PackageXMLParser.h
        PackageXMLParser.cpp
        PackageXml2Data.cpp PackageXml2Data.h)

find_package(Qt5 COMPONENTS Core Xml REQUIRED)

include_directories(
        ${QT_INCLUDES}
        .
        ..
)


add_library(PackageXMLParser ${PACKAGEXMLPARSER_SRC_FILES})

qt5_use_modules(PackageXMLParser Xml)
target_link_libraries(PackageXMLParser Qt5::Core Qt5::Xml)