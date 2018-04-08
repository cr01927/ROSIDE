//
// Created by cjreid on 3/19/18.
//

#include <PackageXmlParser.h>
#include <QtXml>

PackageXmlParser::PackageXmlParser() {}

void PackageXmlParser::parse(QFile& packageXml, PackageXml2Data& packageXml2Data) {
    QDomDocument doc("PackageXMLParser");

    if (!packageXml.open(QIODevice::ReadOnly)) {
        qDebug() << "Couldn't open package.xml" << packageXml.errorString();
        return;
    }
    if (!doc.setContent(&packageXml)) {
        packageXml.close();
        qDebug() << "PackageXmlParser: Couldn't set QDomDocument content:";
        return;
    }
    packageXml.close();

    QDomElement root = doc.documentElement();

    for (int idx = 0; idx < root.childNodes().count(); idx ++) {
        if (root.childNodes().at(idx).isComment())
            continue;

        QDomElement element = root.childNodes().at(idx).toElement();

        if ( element.nodeName() == "name") {
            packageXml2Data.Name.setName(element.nodeValue());
            qDebug() << "Stored Name as " + packageXml2Data.Name.getName();

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
