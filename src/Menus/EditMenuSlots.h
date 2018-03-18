//
// Created by cjreid on 3/18/18.
//

#ifndef ROSIDE_EDITMENUSLOTS_H
#define ROSIDE_EDITMENUSLOTS_H

#include <QtWidgets>

class MainWindow;

class EditMenuSlots : public QObject {
    Q_OBJECT
public:
    EditMenuSlots(MainWindow* mainWindow);

public slots:
    void Undo();
    void Redo();

    void Cut();
    void Copy();
    void Paste();

private:
    MainWindow* main_window_;

};


#endif //ROSIDE_EDITMENUSLOTS_H
