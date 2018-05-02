//
// Created by cjreid on 5/1/18.
//

#include <ROSProjectModel.h>
#include <QtWidgets>

ROSProjectModel::ROSProjectModel(QObject *parent)
    : QStandardItemModel(parent) {
    dirIcon = QApplication::style()->standardIcon(QStyle::SP_DirIcon);
    fileIcon = QApplication::style()->standardIcon(QStyle::SP_FileIcon);

    rootItem = invisibleRootItem();
}

QModelIndex ROSProjectModel::populateModel(QDir &dir) {
    if (dir.exists()) {
        auto realRoot = new QStandardItem(dirIcon, dir.dirName());
        realRoot->setAccessibleDescription(dir.path());
        createAndDescend(&dir, realRoot);
    }

    return rootItem->index();
}

void ROSProjectModel::createAndDescend(QDir *dir, QStandardItem *parent) {
    QFileInfoList subFolders = dir->entryInfoList(QDir::Dirs | QDir::Files | QDir::NoDotAndDotDot);
    foreach (auto folderName, subFolders) {
        if (folderName.isFile()) {
            auto child = new QStandardItem(fileIcon, folderName.fileName());
            child->setAccessibleDescription(folderName.filePath());
            parent->appendRow(child);
        } else {
            auto child = new QStandardItem(dirIcon, folderName.fileName());
            child->setAccessibleDescription(folderName.filePath());
            parent->appendRow(child);
            auto childDir = QDir(folderName.filePath());
            qDebug() << "Descending to " << childDir.dirName();
            createAndDescend(&childDir, child);

        }
    }
}

QVariant ROSProjectModel::headerData(int section, Qt::Orientation orientation, int role) const {


}