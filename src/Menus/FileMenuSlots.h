//
// Created by cjreid on 3/11/18.
//

#ifndef ROSIDE_FILEMENUSLOTS_H
#define ROSIDE_FILEMENUSLOTS_H

#include <QtWidgets>

class MainWindow;

class FileMenuSlots : public QObject{
    Q_OBJECT
public:
    FileMenuSlots(MainWindow*);

public slots:
    void NewFile();
    void OpenFile();
    void OpenProject();
    void SaveFile();
    void SaveFileAs();

private:
    MainWindow* main_window_;
};
#endif //ROSIDE_FILEMENUSLOTS_H
