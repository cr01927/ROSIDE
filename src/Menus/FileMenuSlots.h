//
// Created by cjreid on 3/11/18.
//

#ifndef ROSIDE_FILEMENUSLOTS_H
#define ROSIDE_FILEMENUSLOTS_H

#include <QtWidgets>

class MainWindow;

namespace FileMenuSlots {

    void NewFile(MainWindow* mainWindow);
    void OpenFile(MainWindow* mainWindow);
    void SaveFile(MainWindow* mainWindow);
    void SaveFileAs(MainWindow* mainWindow);
}
#endif //ROSIDE_FILEMENUSLOTS_H
