//
// Created by cjreid on 3/19/18.
//

#include <PackageXmlParser.h>
#include <QtXml>

#include <PackageXml2Components.h>
#include <PackageXml2Data.h>

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

        } else if (element.nodeName() == "build_depend") {
            // All dependencies and relationships can be expressed in multiple elements
            // They can also have an attribute restricting version usage
            // "version_" with suffix "lt", "lte", "eq", "gte", "gt"

            fillDependency(&packageXml2Data->BuildDepends, &element);

        } else if (element.nodeName() == "build_export_depend") {
            // All dependencies and relationships can be expressed in multiple elements
            // They can also have an attribute restricting version usage
            // "version_" with suffix "lt", "lte", "eq", "gte", "gt"

            fillDependency(&packageXml2Data->BuildExportDepends, &element);

        } else if (element.nodeName() == "buildtool_depend") {
            // All dependencies and relationships can be expressed in multiple elements
            // They can also have an attribute restricting version usage
            // "version_" with suffix "lt", "lte", "eq", "gte", "gt"

            fillDependency(&packageXml2Data->BuildToolDepends, &element);

        } else if (element.nodeName() == "buildtool_export_depend") {
            // All dependencies and relationships can be expressed in multiple elements
            // They can also have an attribute restricting version usage
            // "version_" with suffix "lt", "lte", "eq", "gte", "gt"

            fillDependency(&packageXml2Data->BuildToolExportDepends, &element);

        } else if (element.nodeName() == "exec_depend") {
            // All dependencies and relationships can be expressed in multiple elements
            // They can also have an attribute restricting version usage
            // "version_" with suffix "lt", "lte", "eq", "gte", "gt"

            fillDependency(&packageXml2Data->ExecDepends, &element);

        } else if (element.nodeName() == "depend") {
            // All dependencies and relationships can be expressed in multiple elements
            // They can also have an attribute restricting version usage
            // "version_" with suffix "lt", "lte", "eq", "gte", "gt"

            fillDependency(&packageXml2Data->Depends, &element);

        } else if (element.nodeName() == "doc_depend") {
            // All dependencies and relationships can be expressed in multiple elements
            // They can also have an attribute restricting version usage
            // "version_" with suffix "lt", "lte", "eq", "gte", "gt"

            fillDependency(&packageXml2Data->DocDepends, &element);

        } else if (element.nodeName() == "test_depend") {
            // All dependencies and relationships can be expressed in multiple elements
            // They can also have an attribute restricting version usage
            // "version_" with suffix "lt", "lte", "eq", "gte", "gt"

            fillDependency(&packageXml2Data->TestDepends, &element);

        } else if (element.nodeName() == "conflict") {
            // All dependencies and relationships can be expressed in multiple elements
            // They can also have an attribute restricting version usage
            // "version_" with suffix "lt", "lte", "eq", "gte", "gt"

            fillDependency(&packageXml2Data->Conflicts, &element);

        } else if (element.nodeName() == "replace") {
            // All dependencies and relationships can be expressed in multiple elements
            // They can also have an attribute restricting version usage
            // "version_" with suffix "lt", "lte", "eq", "gte", "gt"

            fillDependency(&packageXml2Data->Replaces, &element);

        }else if (element.nodeName() == "export") {
            for (int idxExport = 0; idxExport < element.childNodes().count(); idxExport ++) {
                if (element.childNodes().at(idx).isComment())
                    continue;

                QDomElement elementExport = element.childNodes().at(idx).toElement();

                if (element.nodeName() == "architecture_independent") {
                    packageXml2Data->isArchitectureIndependent = true;
                }  else if (element.nodeName() == "build_type") {
                    packageXml2Data->buildType = element.text();
                } else if (element.nodeName() == "deprecated") {
                    packageXml2Data->isDeprecated = true;
                } else if (element.nodeName() == "message_generator") {
                    packageXml2Data->messageGenerator = element.text();
                } else if (element.nodeName() == "metapackage") {
                    packageXml2Data->isMetapackage = true;
                }
            }
        }
    }
}

void PackageXmlParser::fillDependency(PackageXml2::DependencyList *dependencyList, QDomElement *element) {
    QMap<QString, PackageXml2::Dependency::VERSION_REQ>::const_iterator iter;
    for (iter = PackageXml2::Dependency::VERSION_MAP.constBegin(); iter != PackageXml2::Dependency::VERSION_MAP.constEnd(); ++iter) {
        if (element->hasAttribute(iter.key())) { // If the attribute is present
            // Create a version object
            PackageXml2::Version version;
            version.setVersion(element->attribute(iter.key()));
            PackageXml2::Dependency depends;
            depends.setVersionRequirement(version, iter.value());
            dependencyList->append(depends);
        }
    }
}
