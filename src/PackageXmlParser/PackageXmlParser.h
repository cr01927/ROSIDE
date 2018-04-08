//
// Created by cjreid on 3/19/18.
//

#ifndef ROSIDE_PACKAGEXMLPARSER_H
#define ROSIDE_PACKAGEXMLPARSER_H

#include <QFile>

class PackageXml2Data;


class PackageXmlParser {
public:
    PackageXmlParser();

    void parse(QFile&, PackageXml2Data*);

private:

};


#endif //ROSIDE_PACKAGEXMLPARSER_H
