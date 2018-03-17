//
// Created by cjreid on 3/11/18.
//

#include <FileMenuSlots.h>

#include <QtWidgets>

#include <MainWindow.h>


void FileMenuSlots::NewFile(MainWindow* mainWindow) {
    mainWindow->getDevelopWidget()->openNewTab();
    mainWindow->setMode(MODE::DEVELOP);
}

void FileMenuSlots::OpenFile(MainWindow* mainWindow) {
    QString fileName = QFileDialog::getOpenFileName(mainWindow, "Open file");
    mainWindow->getDevelopWidget()->openFileInTab(fileName);
    mainWindow->setMode(MODE::DEVELOP);
}

void FileMenuSlots::SaveFile(MainWindow* mainWindow) {

}
void FileMenuSlots::SaveFileAs(MainWindow* mainWindow) {
    
}