//
// Created by cjreid on 3/11/18.
//

#include <FileMenuSlots.h>

#include <QtWidgets>


void FileMenuSlots::NewFile(MainWindow* mainWindow) {
    QMessageBox box(QMessageBox::Information, "New File", "Make a new file");
    box.exec();
}

void FileMenuSlots::OpenFile(MainWindow* mainWindow) {

}