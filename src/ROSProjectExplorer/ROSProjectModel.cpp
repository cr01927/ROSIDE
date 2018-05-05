//
// Created by cjreid on 5/1/18.
//

#include <ROSProjectModel.h>
#include <QtWidgets>


ROSProjectModel::ROSProjectModel(QObject *parent)
    : QStandardItemModel(parent) {
    dirIcon = QApplication::style()->standardIcon(QStyle::SP_DirIcon);
    fileIcon = QApplication::style()->standardIcon(QStyle::SP_FileIcon);

    setItemPrototype(new ROSProjectModelNode(""));

}

void ROSProjectModel::populateModel(QDir &dir) {
    if (dir.exists()) {
        root_path_ = dir.absolutePath();
        rootItem = this->invisibleRootItem();
        auto realRoot = new ROSProjectModelNode(dir.dirName());
        realRoot->setIcon(dirIcon);
        realRoot->setEditable(false);
        if (rootItem == nullptr) {
            qDebug() << "rootItem is null";
            return;
        }
        rootItem->appendRow(realRoot);
        createAndDescend(&dir, realRoot);
    }

}

void ROSProjectModel::createAndDescend(QDir *dir, QStandardItem *parent) {
    QFileInfoList subFolders = dir->entryInfoList(QDir::Dirs | QDir::Files | QDir::NoDotAndDotDot);
    foreach (auto folderName, subFolders) {
        if (folderName.isFile()) {
            auto child = new ROSProjectModelNode(folderName.fileName());
            child->setEditable(false);
            child->setIcon(fileIcon);
            parent->appendRow(child);

            // Set node type
            // TODO: set custom icons
            if (folderName.fileName() == "package.xml") {
                child->setNodeType(ROSProjectModelNode::PACKAGEXML);
                child->setIcon(QApplication::style()->standardIcon(QStyle::SP_DriveFDIcon));
            } else if (folderName.fileName() == "CMakeLists.txt") {
                child->setNodeType(ROSProjectModelNode::CMAKELISTSTXT);
                child->setIcon(QApplication::style()->standardIcon(QStyle::SP_DialogResetButton));
            } else if (folderName.fileName().endsWith(".launch")) {
                child->setNodeType(ROSProjectModelNode::LAUNCH);
                child->setIcon(QApplication::style()->standardIcon(QStyle::SP_MediaPause));
            } else if (folderName.fileName().endsWith(".msg")) {
                child->setNodeType(ROSProjectModelNode::MSG);
                child->setIcon(QApplication::style()->standardIcon(QStyle::SP_MediaPlay));
            } else if (folderName.fileName().endsWith(".srv")) {
                child->setNodeType(ROSProjectModelNode::SRV);
                child->setIcon(QApplication::style()->standardIcon(QStyle::SP_MediaSeekBackward));
            } else if (folderName.fileName().endsWith(".py")) {
                child->setNodeType(ROSProjectModelNode::PY);
                child->setIcon(QApplication::style()->standardIcon(QStyle::SP_MediaSeekForward));
            } else if (folderName.fileName().endsWith(".h")) {
                child->setNodeType(ROSProjectModelNode::H);
                child->setIcon(QApplication::style()->standardIcon(QStyle::SP_ArrowBack));
            } else if (folderName.fileName().endsWith(".cpp")) {
                child->setNodeType(ROSProjectModelNode::CPP);
                child->setIcon(QApplication::style()->standardIcon(QStyle::SP_ArrowDown));
            }
        } else {
            auto child = new ROSProjectModelNode(folderName.fileName());
            child->setEditable(false);
            child->setIcon(dirIcon);
            parent->appendRow(child);
            auto childDir = QDir(folderName.filePath());

            if (childDir.entryList(QDir::Files).contains("package.xml")) {
                child->setNodeType(ROSProjectModelNode::PACKAGE);
                child->setIcon(QIcon("../resources/icons/ROSPackage.svg"));
            } else if (folderName.fileName() == "scripts" ) {
                child->setNodeType(ROSProjectModelNode::DIRSCRIPTS);
            } else if (folderName.fileName() == "src") {
                child->setNodeType(ROSProjectModelNode::DIRSRC);
            } else if (folderName.fileName() == "include") {
                child->setNodeType(ROSProjectModelNode::DIRINCLUDE);
            } else if (folderName.fileName() == "launch") {
                child->setNodeType(ROSProjectModelNode::DIRLAUNCH);
                child->setIcon(QApplication::style()->standardIcon(QStyle::SP_DesktopIcon));
            } else if (folderName.fileName()== "msg") {
                child->setNodeType(ROSProjectModelNode::DIRMSG);
            } else if (folderName.fileName() == "srv") {
                child->setNodeType(ROSProjectModelNode::DIRSRV);
            }

            createAndDescend(&childDir, child);

        }
    }
}

QString ROSProjectModel::filename(const QModelIndex &index) {
    QStringList path;
    QModelIndex idx = index;
    while (idx.isValid() && idx.parent().isValid()) {
        ROSProjectModelNode *modelNode = itemFromIndex(idx);
        if (modelNode != nullptr) {
            path.prepend(modelNode->filename());
        }
        idx = idx.parent();
    }

    QString fullPath = QDir::fromNativeSeparators(path.join(QDir::separator()));
    fullPath = QDir(root_path_).absolutePath() + QDir::separator() + fullPath;
#if !defined(Q_OS_WIN)
    if ((fullPath.length() > 2) && fullPath[0] == QLatin1Char('/') && fullPath[1] == QLatin1Char('/'))
        fullPath = fullPath.mid(1);
#else
    if (fullPath.length() == 2 && fullPath.endsWith(QLatin1Char(':')))
        fullPath.append(QLatin1Char('/'));
#endif
    return fullPath;


}

ROSProjectModelNode* ROSProjectModel::itemFromIndex(const QModelIndex &index) const {
    QStandardItem* item = QStandardItemModel::itemFromIndex(index);
    return dynamic_cast<ROSProjectModelNode*>(item);
}

/*
QVariant ROSProjectModel::headerData(int section, Qt::Orientation orientation, int role) const {


}
 */