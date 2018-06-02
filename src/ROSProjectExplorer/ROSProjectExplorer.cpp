//
// Created by cjreid on 3/17/18.
//

#include <ROSProjectExplorer.h>

#include <ROSProjectModel.h>

#include <MainWindow.h>
#include <PackageXmlParser.h>
#include <PackageXml2Data.h>

ROSProjectExplorer::ROSProjectExplorer(QWidget *parent)
    : QMainWindow(parent), model(nullptr) {

    tree_view_ = new QTreeView(this);
    setCentralWidget(tree_view_);
    project_type_ = UNSET;

    package_context_menu_ = new QMenu(tree_view_);
    msg_context_menu_ = new QMenu(tree_view_);

    package_context_menu_->addAction(tr("Edit Dependencies"));
    msg_context_menu_->addAction(tr("New MSG"));
    tree_view_->setContextMenuPolicy(Qt::CustomContextMenu);


    connect(tree_view_, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(itemDoubleClicked(QModelIndex)));
    connect(tree_view_, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(customContextMenuRequested(QPoint)));

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
    } else if (entries.contains(QString("package.xml"))) {
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
    } else {
        // TODO: Raise error for no ROS project structure found
        QMessageBox::warning(
                this,
                tr("Not a ROS Project"),
                tr("No ROS project found at this directory. No project will be opened.") );
        return;
    }

    if (model != nullptr) {
        model->clear();
    }
    model = new ROSProjectModel(this);
    tree_view_->setModel(model);
    model->populateModel(dir);
    tree_view_->setRootIsDecorated(true);
    tree_view_->header()->hide();


}

void ROSProjectExplorer::itemDoubleClicked(QModelIndex index) {
    auto fsModel = dynamic_cast<ROSProjectModel*>(tree_view_->model());
    QString filePath = fsModel->filename(index);
    MainWindow::get()->getDevelopWidget()->openFileInTab(filePath);

}

void ROSProjectExplorer::customContextMenuRequested(QPoint pos) {
    QModelIndex idx = tree_view_->indexAt(pos);
    auto rpmodel = dynamic_cast<ROSProjectModel*>(tree_view_->model());
    if (rpmodel->itemFromIndex(idx)->getNodeType() == ROSProjectModelNode::PACKAGE) {
        package_context_menu_->exec(tree_view_->mapToGlobal(pos));
    } else if (rpmodel->itemFromIndex(idx)->getNodeType() == ROSProjectModelNode::MSG) {
        msg_context_menu_->exec(tree_view_->mapToGlobal(pos));
    }
}
