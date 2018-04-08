//
// Created by cjreid on 3/19/18.
//

#include <PackageXmlParser.h>
#include <QtXml>

#include <PackageXml2Components.h>

PackageXmlParser::PackageXmlParser() {}

void PackageXmlParser::parse(QFile& packageXml, PackageXml2Data *packageXml2Data) {
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
            packageXml2Data->Name.setName(element.text());

        } else if (element.nodeName() == "version") {
            packageXml2Data->Version.setVersion(element.text());

        } else if (element.nodeName() == "description") {
            packageXml2Data->Description.setDescription(element.text());

        } else if (element.nodeName() == "maintainer") {
            PackageXml2::Maintainer maintainer;
            maintainer.setMaintainer(element.text());
            if (element.hasAttribute("email")) {
                maintainer.setMaintainerEmail(element.attribute("email"));
            }
            packageXml2Data->Maintainers.append(maintainer);

        } else if (element.nodeName() == "license") {
            PackageXml2::License license;
            license.setLicense(element.text());
            packageXml2Data->Licenses.append(license);

        } else if (element.nodeName() == "url") {
            // Could be multiple "url" elements
            // Could have attribute "type" ("website", "repository", "bugtracker")
            PackageXml2::Url url;
            if (element.hasAttribute("type")) {
                url.setUrl(element.text(), element.attribute("type"));
            } else {
                url.setUrl(element.text());
            }
            packageXml2Data->Urls.append(url);

        } else if (element.nodeName() == "author") {
            PackageXml2::Author author;
            if (element.hasAttribute("email")) {
                author.setAuthor(element.text(), element.attribute("email"));
            } else {
                author.setAuthor(element.text());
            }
            packageXml2Data->Authors.append(author);

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
