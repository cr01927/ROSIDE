//
// Created by cjreid on 3/21/18.
//

#include <QStringList>
#include "PackageXml2Components.h"


const QMap<QString, PackageXml2::Dependency::VERSION_REQ> PackageXml2::Dependency::VERSION_MAP = PackageXml2::Dependency::createVersionmap();


bool PackageXml2::Name::setName(QString name) {
    // TODO: Check format of name ( REP 140 ) and enforce the format (don't allow setting an improper name)
    // This function will be called when creating a package
    name_ = name;
    return true;
}

bool PackageXml2::Name::importName(QString name) {
    // TODO: Check format of name ( REP 140 ) but only show a warning when there are formatting issues
    // This function will be called when importing an existing package
    name_ = name;
    return true;
}

QString PackageXml2::Name::getName() const {
    return name_;
}

bool PackageXml2::Version::setVersion(int major, int minor, int patch) {
    version_.replace(MAJOR, major);
    version_.replace(MINOR, minor);
    version_.replace(PATCH, patch);
    return true;
}

bool PackageXml2::Version::setVersion(QString version) {
    QStringList splitVersion = version.split('.');
    // REP 140 requires MAJOR.MINOR.PATCH, so the below statement filters for an incorrect number of version specifiers
    if ( splitVersion.count() != 3)
        return false;
    for (int idx = MAJOR; idx <= PATCH; idx++) {
        bool conversionPassed;
        int versionPart = splitVersion.at(idx).toInt(&conversionPassed);
        if (!conversionPassed)
            return false;
        version_.insert(idx, versionPart);
    }
    return true;

}

bool PackageXml2::Version::setVersion(QList<int> version) {
    version_ = version;
}

QString PackageXml2::Version::getVersion() const {
    QString version;
    foreach(auto versionCat, version_) {
        version += QString::number(versionCat) + '.';
    }
    // Remove last '.'
    version.remove(version.count()-1, 1);
    return version;
}

int PackageXml2::Version::getMajor() const {
    return version_.at(MAJOR);
}

int PackageXml2::Version::getMinor() const {
    return version_.at(MINOR);
}

int PackageXml2::Version::getPatch() const {
    return version_.at(PATCH);
}

void PackageXml2::Description::setDescription(QString description) {
    description_ = description;
}

QString PackageXml2::Description::getDescription() const {
    return description_;
}

void PackageXml2::Maintainer::setMaintainer(QString maintainer) {
    maintainer_ = maintainer;
}

void PackageXml2::Maintainer::setMaintainerEmail(QString email) {
    email_ = email;
}

QString PackageXml2::Maintainer::getMaintainer() const {
    return maintainer_;
}

QString PackageXml2::Maintainer::getMaintainerEmail() const {
    return email_;
}

void PackageXml2::License::setLicense(QString license) {
    license_ = license;
}

QString PackageXml2::License::getLicense() const {
    return license_;
}

void PackageXml2::Url::setUrl(QString url, QString type) {
    url_ = url;
    // TODO: enforce REP 140 types (website, bugtracker, repository
    type_ = type;
}

QString PackageXml2::Url::getUrl() const {
    return url_;
}

QString PackageXml2::Url::getType() const {
    return type_;
}

void PackageXml2::Author::setAuthor(QString author, QString email) {
    author_ = author;
    email_ = email;
}

QString PackageXml2::Author::getAuthor() const {
    return author_;
}

QString PackageXml2::Author::getEmail() const {
    return email_;
}
