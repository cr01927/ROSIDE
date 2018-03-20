//
// Created by cjreid on 3/19/18.
//

#include "PackageXMLParser.h"
#include <QtXml>

PackageXMLParser::PackageXMLParser() {}

void PackageXMLParser::parse(QFile &packagexml) {
    QDomDocument doc("PackageXMLParser");

    if (!packagexml.open(QIODevice::ReadOnly)) {
        qDebug() << "Couldn't open package.xml" << packagexml.errorString();
        return;
    }
    if (!doc.setContent(&packagexml)) {
        packagexml.close();
        qDebug() << "Couldn't set QDomDocument content:";
        return;
    }
    packagexml.close();

    QDomElement root = doc.documentElement();

    for (int idx = 0; idx < root.childNodes().count(); idx ++) {
        if (root.childNodes().at(idx).isComment())
            continue;

        QDomElement element = root.childNodes().at(idx).toElement();

        if ( element.nodeName() == "name") {

        } else if (element.nodeName() == "version") {

        } else if (element.nodeName() == "description") {

        } else if (element.nodeName() == "maintainer") {
            // Could be multiple "maintainer" elements
            // Can have attribute "email"

        } else if (element.nodeName() == "license") {
            // Could be multiple "license" elements

        } else if (element.nodeName() == "url") {
            // Could be multiple "url" elements
            // Could have attribute "type" ("website", "repository", "bugtracker")

        } else if (element.nodeName() == "author") {

        } else if (element.nodeName() == "buildtool_depend") {
            // All dependencies and relationships can be expressed in multiple elements
            // They can also have an attribute restricting version usage
            // "version_" with suffix "lt", "lte", "eq", "gte", "gt"

        } else if (element.nodeName() == "export") {

        }
    }

    /*
    QDomNode child = doc.documentElement().elementsByTagName("export").at(0).firstChild();
    while (!child.isNull()) {
        if (child.toElement().tagName() == "metapackage") {
            project_type_ = METAPACKAGE;
            return;
        }
        child = child.nextSibling();
    }
     */
}

const QString &PackageXMLParser::getName_() const {
    return name_;
}

void PackageXMLParser::setName_(const QString &name_) {
    PackageXMLParser::name_ = name_;
}

const QString &PackageXMLParser::getVersion_() const {
    return version_;
}

void PackageXMLParser::setVersion_(const QString &version_) {
    PackageXMLParser::version_ = version_;
}

const QString &PackageXMLParser::getDescription_() const {
    return description_;
}

void PackageXMLParser::setDescription_(const QString &description_) {
    PackageXMLParser::description_ = description_;
}

const QString &PackageXMLParser::getMaintainer_() const {
    return maintainer_;
}

void PackageXMLParser::setMaintainer_(const QString &maintainer_) {
    PackageXMLParser::maintainer_ = maintainer_;
}

const QString &PackageXMLParser::getLicense_() const {
    return license_;
}

void PackageXMLParser::setLicense_(const QString &license_) {
    PackageXMLParser::license_ = license_;
}

const QStringList &PackageXMLParser::getDepend_() const {
    return depend_;
}

void PackageXMLParser::setDepend_(const QStringList &depend_) {
    PackageXMLParser::depend_ = depend_;
}

const QStringList &PackageXMLParser::getBuildtool_depend_() const {
    return buildtool_depend_;
}

void PackageXMLParser::setBuildtool_depend_(const QStringList &buildtool_depend_) {
    PackageXMLParser::buildtool_depend_ = buildtool_depend_;
}

const QStringList &PackageXMLParser::getBuild_depend_() const {
    return build_depend_;
}

void PackageXMLParser::setBuild_depend_(const QStringList &build_depend_) {
    PackageXMLParser::build_depend_ = build_depend_;
}

const QStringList &PackageXMLParser::getBuild_export_depend_() const {
    return build_export_depend_;
}

void PackageXMLParser::setBuild_export_depend_(const QStringList &build_export_depend_) {
    PackageXMLParser::build_export_depend_ = build_export_depend_;
}

const QStringList &PackageXMLParser::getExec_depend_() const {
    return exec_depend_;
}

void PackageXMLParser::setExec_depend_(const QStringList &exec_depend_) {
    PackageXMLParser::exec_depend_ = exec_depend_;
}

const QStringList &PackageXMLParser::getTest_depend_() const {
    return test_depend_;
}

void PackageXMLParser::setTest_depend_(const QStringList &test_depend_) {
    PackageXMLParser::test_depend_ = test_depend_;
}

const QStringList &PackageXMLParser::getDoc_depend_() const {
    return doc_depend_;
}

void PackageXMLParser::setDoc_depend_(const QStringList &doc_depend_) {
    PackageXMLParser::doc_depend_ = doc_depend_;
}

bool PackageXMLParser::isIs_metapackage() const {
    return is_metapackage;
}

void PackageXMLParser::setIs_metapackage(bool is_metapackage) {
    PackageXMLParser::is_metapackage = is_metapackage;
}
