//
// Created by cjreid on 3/11/18.
//

#include <FileMenuSlots.h>

#include <QtWidgets>

#include <MainWindow.h>

FileMenuSlots::FileMenuSlots(MainWindow* mainWindow) {
    main_window_ = mainWindow;
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

void FileMenuSlots::SaveFile() {
    main_window_->getDevelopWidget()->saveCurrentTab();
}
void FileMenuSlots::SaveFileAs() {
    main_window_->getDevelopWidget()->saveCurrentTabAs();
}