//
// Created by cjreid on 3/11/18.
//

#ifndef ROSIDE_MAINWINDOW_H
#define ROSIDE_MAINWINDOW_H

#include <QtWidgets>

#include <Menus/FileMenuSlots.h>
#include <Menus/EditMenuSlots.h>
#include <Modes/DevelopWidget.h>

enum MODE {
    DESIGN,
    DEVELOP
};

class MainWindow : public QMainWindow {

Q_OBJECT
public:
    static MainWindow& get();

    MainWindow(MainWindow const&) = delete;
    void operator=(MainWindow const&) = delete;

    MODE getCurrentMode();
    void setMode(MODE mode);

    DevelopWidget* getDevelopWidget() const;


private:
    MainWindow();

    void InitMenuBar();
    void InitFileMenu();
    void InitEditMenu();


    FileMenuSlots* file_menu_slots_;
    EditMenuSlots* edit_menu_slots_;
    MainWindow *main_window_;
    QMap<MODE, int> mode_tab_index_list_;
    QMenuBar menu_bar_;
    QMenu *file_menu_, *edit_menu_;
    QTabWidget *main_tabbed_window_;


};

#endif //ROSIDE_MAINWINDOW_H
