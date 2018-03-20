//
// Created by cjreid on 3/19/18.
//

#ifndef ROSIDE_PACKAGEXMLPARSER_H
#define ROSIDE_PACKAGEXMLPARSER_H

#include <QFile>


class PackageXMLParser {
public:
    PackageXMLParser();


    void parse(QFile &packagexml);

    const QString &getName_() const;
    void setName_(const QString &name_);

    const QString &getVersion_() const;
    void setVersion_(const QString &version_);

    const QString &getDescription_() const;
    void setDescription_(const QString &description_);

    const QString &getMaintainer_() const;
    void setMaintainer_(const QString &maintainer_);

    const QString &getLicense_() const;
    void setLicense_(const QString &license_);

    const QStringList &getDepend_() const;
    void setDepend_(const QStringList &depend_);

    const QStringList &getBuildtool_depend_() const;
    void setBuildtool_depend_(const QStringList &buildtool_depend_);

    const QStringList &getBuild_depend_() const;
    void setBuild_depend_(const QStringList &build_depend_);

    const QStringList &getBuild_export_depend_() const;
    void setBuild_export_depend_(const QStringList &build_export_depend_);

    const QStringList &getExec_depend_() const;
    void setExec_depend_(const QStringList &exec_depend_);

    const QStringList &getTest_depend_() const;
    void setTest_depend_(const QStringList &test_depend_);

    const QStringList &getDoc_depend_() const;
    void setDoc_depend_(const QStringList &doc_depend_);

    bool isIs_metapackage() const;
    void setIs_metapackage(bool is_metapackage);


private:

    QString name_;
    QString version_;
    QString description_;
    QString maintainer_;
    QString license_;
    QStringList depend_;
    QStringList buildtool_depend_;
    QStringList build_depend_;
    QStringList build_export_depend_;
    QStringList exec_depend_;
    QStringList test_depend_;
    QStringList doc_depend_;

    bool is_metapackage = false;
};


#endif //ROSIDE_PACKAGEXMLPARSER_H
