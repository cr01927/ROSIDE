//
// Created by cjreid on 3/21/18.
//

#ifndef ROSIDE_PACKAGEXML2DATA_H
#define ROSIDE_PACKAGEXML2DATA_H

#include <QString>

namespace PackageXml2 {

    class Name;

    class Version;

    class Description;

    class Maintainer;

    class License;

    class Url;

    class Author;

    class BuildDepend;

    class BuildExportDepend;

    class BuildToolDepend;

    class BuildToolExportDepend;

    class ExecDepend;

    class Depend;

    class DocDepend;

    class TestDepend;

    class Conflict;

    class Replace;
}

class PackageXml2Data {

};

/* Stores the package name, under the <name> tag. Should obey the formatting rules laid out in REP 140 */
class PackageXml2::Name {
public:
    /* Two functions to set the package name. setName will enforce ROS naming conventions, while importName will not. */
    bool setName(QString name);
    bool importName(QString name);

    QString getName() const;
private:
    QString name_;
};

class PackageXml2::Version {
public:
    bool setVersion(int major, int minor, int patch);
    bool setVersion(QString version);

    QString getVersion() const;
    int getMajor() const;
    int getMinor() const;
    int getPatch() const;

private:
    int major_, minor_, patch_;
};

class PackageXml2::Description {
public:
    void setDescription(QString description);
    QString getDescription() const;
private:
    QString description_;
};

class PackageXml2::Maintainer {
public:
    void setMaintainer(QString maintainer);
    void setMaintainerEmail(QString email);
    QString getMaintainer() const;
    QString getMaintainerEmail() const;
private:
    QString maintainer_, email_;
};

class PackageXml2::License {
public:
    void setLicense(QString license);
    QString getLicense() const;

private:
    QString license_;
};

class PackageXml2::Url {
public:
    void setUrl(QString url, QString type = QString("website"));
    QString getUrl() const;
    QString getType() const;
private:
    QString url_, type_;
};

class PackageXml2::Author {
public:
    void setAuthor(QString author, QString email = QString());
    QString getAuthor() const;
    QString getEmail() const;

private:
    QString author_, email_;
};

/* Class for internal use only, inherited by all of the package relationship tags (depend, conflict, replace, etc) */
namespace PackageXml2 {
    namespace {
        class _PackageRelationship {
        public:
            enum VERSION_REQ {
                LESS_THAN = 0,
                LESS_THAN_EQUAL,
                EQUAL,
                GREATER_THAN_EQUAL,
                GREATER_THAN
            };
            void setPackageName(QString packageName, PackageXml2::Version version, VERSION_REQ version_requirement);
            QString getPackageName() const;
            void setVersionRequirement(PackageXml2::Version &version, VERSION_REQ version_requirement);

        private:
            PackageXml2::Version lt_, lte, eq, gte, gt;
        };
    }
}

typedef PackageXml2::_PackageRelationship PackageXml2::BuildDepend;

class PackageXml2::BuildDepend : public _PackageRelationship {
public:
    void setBuildDepend(QString packageName, PackageXml2::Version version);
    QString getBuildDepend() const;
private:
    QString package_name_;
};

class PackageXml2::BuildExportDepend : public _PackageRelationship {

};
class PackageXml2::BuildToolDepend : public _PackageRelationship {

};
class PackageXml2::BuildToolExportDepend : public _PackageRelationship {

};
class PackageXml2::ExecDepend : public _PackageRelationship {

};
class PackageXml2::Depend : public _PackageRelationship {

};
class PackageXml2::DocDepend : public _PackageRelationship {

};
class PackageXml2::TestDepend : public _PackageRelationship {

};
class PackageXml2::Conflict : public _PackageRelationship {

};
class PackageXml2::Replace : public _PackageRelationship {
};
#endif //ROSIDE_PACKAGEXML2DATA_H
