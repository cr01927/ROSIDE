//
// Created by cjreid on 3/17/18.
//

#include "ROSProjectExplorer.h"

//#include <QtXml>

#include <PackageXMLParser/PackageXMLParser.h>

ROSProjectExplorer::ROSProjectExplorer(QWidget *parent)
    : QMainWindow(parent) {

    setCentralWidget(new QTreeView(this));
    project_type_ = UNSET;
}

QDir ROSProjectExplorer::getDir() const {
    return project_dir_;
}

void ROSProjectExplorer::setDir(QDir &dir) {
    project_dir_ = dir;

    scanProject(dir);
}

ROSProjectExplorer::TYPE ROSProjectExplorer::getType() const {
    return project_type_;
}

void ROSProjectExplorer::scanProject(QDir &dir) {
    dir.setFilter(QDir::Files | QDir::Hidden | QDir::NoDotAndDotDot);
    QStringList entries = dir.entryList();
    qDebug() << "Entries: " << entries.join(",");
    qDebug() << "Scanning project";

    if (entries.contains(QString(".catkin_workspace"))) {
        project_type_ = WORKSPACE;
        qDebug() << "This is a catkin workspace";
    } else {
        /*
        // We parse XML here to see if its a meta package or not. We could probably just check for a src directory,
        //   but this feels a little more robust
        QDomDocument doc("ROSPackage");
        QFile file(dir.absolutePath() + "/package.xml");
        if (!file.open(QIODevice::ReadOnly)) {
            qDebug() << "Couldn't open package.xml" << file.errorString();
            return;
        }
        if (!doc.setContent(&file)) {
            file.close();
            qDebug() << "Couldn't set QDomDocument content:";
            return;
        }
        file.close();

        QDomNode child = doc.documentElement().elementsByTagName("export").at(0).firstChild();
        while (!child.isNull()) {
            if (child.toElement().tagName() == "metapackage") {
                project_type_ = METAPACKAGE;
                return;
            }
            child = child.nextSibling();
        }

        // Nothing left, must be normal package
        project_type_ = PACKAGE;

         */
        QFile file(dir.absolutePath() + "/package.xml");
        PackageXMLParser packageXMLParser;
        packageXMLParser.parse(file);
    }
}

