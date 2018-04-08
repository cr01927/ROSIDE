
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set( PACKAGEXMLPARSER_SRC_FILES
        PackageXml2Components.h
        PackageXml2Components.cpp
        PackageXmlParser.h
        PackageXmlParser.cpp
 )

find_package(Qt5 COMPONENTS Core Xml REQUIRED)

include_directories(
        ${QT_INCLUDES}
        .
)


add_library(PackageXmlParser ${PACKAGEXMLPARSER_SRC_FILES})

qt5_use_modules(PackageXmlParser Xml)
target_link_libraries(PackageXmlParser Qt5::Core Qt5::Xml)