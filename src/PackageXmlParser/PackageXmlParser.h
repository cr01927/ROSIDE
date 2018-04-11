//
// Created by cjreid on 3/19/18.
//

#ifndef ROSIDE_PACKAGEXMLPARSER_H
#define ROSIDE_PACKAGEXMLPARSER_H

#include <QFile>
#include <QList>

class PackageXml2Data;
namespace PackageXml2 {
    class Dependency;
    typedef QList<Dependency> DependencyList;
}
class QDomElement;


class PackageXmlParser {
public:
    PackageXmlParser();

    void parse(QFile&, PackageXml2Data*);
    void fillDependency(PackageXml2::DependencyList*, QDomElement*);

private:

};


#endif //ROSIDE_PACKAGEXMLPARSER_H
