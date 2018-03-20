//
// Created by cjreid on 3/11/18.
//

#include <QtWidgets>

#include <MainWindow.h>
#include <Editor/EditorWidget.h>
#include <Modes/DevelopWidget.h>

MainWindow& MainWindow::get() {
    static MainWindow instance;
    return instance;
}

MODE MainWindow::getCurrentMode() {
    return mode_tab_index_list_.key(main_tabbed_window_->currentIndex());
}

void MainWindow::setMode(MODE mode) {
    main_tabbed_window_->setCurrentIndex(mode_tab_index_list_.value(mode));
}

DevelopWidget *MainWindow::getDevelopWidget() const {
    return dynamic_cast<DevelopWidget*>(main_tabbed_window_->widget(mode_tab_index_list_.value(MODE::DEVELOP)));
}



MainWindow::MainWindow()
: QMainWindow(0) {
    resize(QDesktopWidget().availableGeometry(this).size() * 0.7);

    file_menu_slots_ = new FileMenuSlots(this);
    edit_menu_slots_ = new EditMenuSlots(this);
    InitMenuBar();
    show();

    main_tabbed_window_ = new QTabWidget(this);
    // Create tabs and store indexes in mode_tab_index_list_
    mode_tab_index_list_.insert(DESIGN, main_tabbed_window_->addTab(new QWidget(), tr("Design")));
    mode_tab_index_list_.insert(DEVELOP, main_tabbed_window_->addTab(new DevelopWidget(main_tabbed_window_), tr("Develop")));

    main_tabbed_window_->setTabPosition(QTabWidget::West);
    main_tabbed_window_->show();
    setCentralWidget(main_tabbed_window_);

}

void MainWindow::InitMenuBar() {
    // Set menu bar to this window
    setMenuBar(&menu_bar_);

    InitFileMenu();
    InitEditMenu();
    menuBar()->show();




}

void MainWindow::InitFileMenu() {
    // Add file dropdown to main menu bar
    file_menu_ = menuBar()->addMenu(tr("&File"));

    // Create actions
    file_menu_->addAction(tr("&New..."), file_menu_slots_, SLOT(NewFile()), Qt::UniqueConnection);
    file_menu_->addAction(tr("&Open..."), file_menu_slots_, SLOT(OpenFile()), Qt::UniqueConnection);
    file_menu_->addAction(tr("Open &Project..."), file_menu_slots_, SLOT(OpenProject()), Qt::UniqueConnection);
    file_menu_->addAction(tr("&Save..."), file_menu_slots_, SLOT(SaveFile()), Qt::UniqueConnection);
    file_menu_->addAction(tr("Save &As..."), file_menu_slots_, SLOT(SaveFileAs()), Qt::UniqueConnection);

}

void MainWindow::InitEditMenu() {
    // Add edit dropdown to main menu bar
    edit_menu_ = menuBar()->addMenu(tr("&Edit"));

    // Create actions
    edit_menu_->addAction(tr("&Undo"), edit_menu_slots_, SLOT(Undo()), Qt::UniqueConnection);
    edit_menu_->addAction(tr("&Redo"), edit_menu_slots_, SLOT(Redo()), Qt::UniqueConnection);

    edit_menu_->addSeparator();

    edit_menu_->addAction(tr("Cu&t"), edit_menu_slots_, SLOT(Cut()), Qt::UniqueConnection);
    edit_menu_->addAction(tr("&Copy"), edit_menu_slots_, SLOT(Copy()), Qt::UniqueConnection);
    edit_menu_->addAction(tr("&Paste"), edit_menu_slots_, SLOT(Paste()), Qt::UniqueConnection);

}
