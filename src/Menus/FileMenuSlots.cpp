//
// Created by cjreid on 3/11/18.
//

#include <FileMenuSlots.h>

#include <QtWidgets>

#include <MainWindow.h>
#include <ROSProjectExplorer/ROSProjectExplorer.h>

FileMenuSlots::FileMenuSlots(QObject* parent, MainWindow* mainWindow)
    : main_window_(mainWindow), QObject(parent) {

}

void FileMenuSlots::NewFile() {
    main_window_->getDevelopWidget()->openNewTab();
    main_window_->setMode(MODE::DEVELOP);
}

void FileMenuSlots::OpenFile() {
    QString fileName = QFileDialog::getOpenFileName(main_window_, "Open file");
    main_window_->getDevelopWidget()->openFileInTab(fileName);
    main_window_->setMode(MODE::DEVELOP);
}

void FileMenuSlots::OpenProject() {
    qDebug() << "OpenProject:";
    QString dirName = QFileDialog::getExistingDirectory(main_window_, "Select project (workspace, metapackage, or package) directory");
    QDir dir = QDir(dirName);
    ROSProjectExplorer *projExplorer = dynamic_cast<ROSProjectExplorer*>(main_window_->getDevelopWidget()->getPackageExplorer()->widget());
    projExplorer->setDir(dir);

}

void FileMenuSlots::SaveFile() {
    main_window_->getDevelopWidget()->saveCurrentTab();
}
void FileMenuSlots::SaveFileAs() {
    main_window_->getDevelopWidget()->saveCurrentTabAs();
}