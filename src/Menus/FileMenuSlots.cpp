//
// Created by cjreid on 3/11/18.
//

#include <FileMenuSlots.h>

#include <QtWidgets>

#include <MainWindow.h>


void FileMenuSlots::NewFile(MainWindow* mainWindow) {
    QMessageBox box(QMessageBox::Information, "New File", "Make a new file");
    box.exec();
}

void FileMenuSlots::OpenFile(MainWindow* mainWindow) {
    QString fileName = QFileDialog::getOpenFileName(mainWindow, "Open file");
    mainWindow->getDevelopWidget()->openFileInTab(fileName);
}