//
// Created by cjreid on 3/18/18.
//

#include "EditMenuSlots.h"

#include <MainWindow.h>

EditMenuSlots::EditMenuSlots(QObject* parent, MainWindow *mainWindow)
    : main_window_(mainWindow), QObject(parent) {

}

EditMenuSlots::~EditMenuSlots() {
    qDebug() << "Destroying EditMenuSlots";
}

void EditMenuSlots::Undo() {
    if (main_window_->getCurrentMode() == MODE::DEVELOP) {
        main_window_->getDevelopWidget()->getActiveTab()->undo();
    }
}

void EditMenuSlots::Redo() {
    if (main_window_->getCurrentMode() == MODE::DEVELOP) {
        main_window_->getDevelopWidget()->getActiveTab()->redo();
    }
}

void EditMenuSlots::Cut() {
    if (main_window_->getCurrentMode() == MODE::DEVELOP) {
        main_window_->getDevelopWidget()->getActiveTab()->cut();
    }
}

void EditMenuSlots::Copy() {
    if (main_window_->getCurrentMode() == MODE::DEVELOP) {
        main_window_->getDevelopWidget()->getActiveTab()->copy();
    }
}

void EditMenuSlots::Paste() {
    if (main_window_->getCurrentMode() == MODE::DEVELOP) {
        main_window_->getDevelopWidget()->getActiveTab()->paste();
    }
}


