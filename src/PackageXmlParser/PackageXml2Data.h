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
    PackageXml2::DependencyList BuildDepends;
    //QList<PackageXml2::Dependency> BuildDepends;
    PackageXml2::DependencyList BuildExportDepends;
    PackageXml2::DependencyList BuildToolDepends;
    PackageXml2::DependencyList BuildToolExportDepends;
    PackageXml2::DependencyList ExecDepends;
    PackageXml2::DependencyList Depends;
    PackageXml2::DependencyList DocDepends;
    PackageXml2::DependencyList TestDepends;
    PackageXml2::DependencyList Conflicts;
    PackageXml2::DependencyList Replaces;
    // TODO: QList<PackageXml2::Export> Exports;
};


#endif //ROSIDE_PACKAGEXML2DATA_H
