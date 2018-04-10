//
// Created by cjreid on 3/21/18.
//

#ifndef ROSIDE_PACKAGEXML2COMPONENTS_H
#define ROSIDE_PACKAGEXML2COMPONENTS_H

#include <QString>
#include <QMap>

namespace PackageXml2 {

    class Name;

    class Version;

    class Description;

    class Maintainer;

    class License;

    class Url;

    class Author;

    class Dependency;

}


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
    enum VERSION_CAT {
        MAJOR = 0,
        MINOR,
        PATCH
    };
    bool setVersion(int major, int minor, int patch);
    bool setVersion(QString version);
    bool setVersion(QList<int> version);

    QString getVersion() const;
    int getMajor() const;
    int getMinor() const;
    int getPatch() const;

private:
    QList<int> version_;
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

class PackageXml2::Dependency {
public:
    enum VERSION_REQ {
        LESS_THAN = 0,
        LESS_THAN_EQUAL,
        EQUAL,
        GREATER_THAN_EQUAL,
        GREATER_THAN
    };

    static QMap<QString, VERSION_REQ> createVersionmap()
    {
        QMap<QString, VERSION_REQ> versionMap;
        versionMap.insert("version_lt", LESS_THAN);
        versionMap.insert("version_lte", LESS_THAN_EQUAL);

    };

    static const QMap<QString, VERSION_REQ> VERSION_MAP;

    void setPackageName(const QString &packageName) {
        name_ = packageName;
    }
    QString getPackageName() const {
        return name_;
    }
    void setVersionRequirement(PackageXml2::Version &version, VERSION_REQ version_requirement) {
        switch (version_requirement) {
            case (LESS_THAN):
                lt_ = version;
                break;
            case (LESS_THAN_EQUAL):
                lte_ = version;
                break;
            case (EQUAL):
                eq_ = version;
                break;
            case (GREATER_THAN_EQUAL):
                gte_ = version;
                break;
            case (GREATER_THAN):
                gt_ = version;
                break;
        }
    }

private:
    PackageXml2::Version lt_, lte_, eq_, gte_, gt_;
    QString name_;
};

#endif //ROSIDE_PACKAGEXML2DATA_H
