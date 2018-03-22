//
// Created by cjreid on 3/21/18.
//

#ifndef ROSIDE_PACKAGEXML2DATA_H
#define ROSIDE_PACKAGEXML2DATA_H

#include <QString>

class PackageXml2Name;
class PackageXml2Version;
class PackageXml2Description;
class PackageXml2Maintainer;
class PackageXml2License;
class PackageXml2Url;
class PackageXml2Author;
class PackageXml2BuildDepend;
class PackageXml2BuildExportDepend;
class PackageXml2BuildToolDepend;
class PackageXml2BuildToolExportDepend;
class PackageXml2ExecDepend;
class PackageXml2Depend;
class PackageXml2DocDepend;
class PackageXml2TestDepend;
class PackageXml2Conflict;
class PackageXml2Replace;

class PackageXml2Data {

};

/* Stores the package name, under the <name> tag. Should obey the formatting rules laid out in REP 140 */
class PackageXml2Name {
private:
    QString name_;
};

#endif //ROSIDE_PACKAGEXML2DATA_H
