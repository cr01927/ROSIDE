//
// Created by cjreid on 3/17/18.
//

#include <ROSProjectExplorer.h>

#include <ROSProjectModel.h>

#include <MainWindow.h>
#include <PackageXmlParser.h>
#include <PackageXml2Data.h>

ROSProjectExplorer::ROSProjectExplorer(QWidget *parent)
    : QMainWindow(parent) {

    tree_view_ = new QTreeView(this);
    setCentralWidget(tree_view_);
    project_type_ = UNSET;

    connect(tree_view_, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(itemDoubleClicked(QModelIndex)));

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

    if (entries.contains(QString(".catkin_workspace"))) {
        project_type_ = WORKSPACE;
    } else {
        // We parse XML here to see if its a meta package or not. We could probably just check for a src directory,
        //   but this feels a little more robust
        QFile file(dir.absolutePath() + "/package.xml");
        PackageXmlParser packageXmlParser;
        PackageXml2Data packageXml2Data;
        packageXmlParser.parse(file, &packageXml2Data);

        if (packageXml2Data.isMetapackage) {
            project_type_ = METAPACKAGE;
        } else {
            project_type_ = PACKAGE;
        }
    }

    auto *model = new ROSProjectModel(tree_view_);
    tree_view_->setModel(model);
    model->populateModel(dir);
    /*
    tree_view_->setRootIndex(model->populateModel(dir));
    tree_view_->setRootIsDecorated(true);
    for (int i = 1; i < model->columnCount(); i++) {
        tree_view_->hideColumn(i);
    }
     */


}

void ROSProjectExplorer::itemDoubleClicked(QModelIndex index) {
    auto fsModel = dynamic_cast<QFileSystemModel*>(tree_view_->model());
    QString filePath = fsModel->filePath(index);
    MainWindow::get().getDevelopWidget()->openFileInTab(filePath);

}
