//
// Created by cjreid on 4/10/18.
//

#ifndef ROSIDE_PACKAGEXML2DATA_H
#define ROSIDE_PACKAGEXML2DATA_H

#include <PackageXml2Components.h>


class PackageXml2Data {
    public:

    PackageXml2::Name Name;
    PackageXml2::Version Version;
    PackageXml2::Description Description;
    QList<PackageXml2::Maintainer> Maintainers;
    QList<PackageXml2::License> Licenses;
    QList<PackageXml2::Url> Urls;
    QList<PackageXml2::Author> Authors;
    QList<PackageXml2::Dependency> BuildDepends;
    QList<PackageXml2::Dependency> BuildExportDepends;
    QList<PackageXml2::Dependency> BuildToolDepends;
    QList<PackageXml2::Dependency> BuildToolExportDepends;
    QList<PackageXml2::Dependency> ExecDepends;
    QList<PackageXml2::Dependency> Depends;
    QList<PackageXml2::Dependency> DocDepends;
    QList<PackageXml2::Dependency> TestDepends;
    QList<PackageXml2::Dependency> Conflicts;
    // TODO: QList<PackageXml2::Export> Exports;
};


#endif //ROSIDE_PACKAGEXML2DATA_H
