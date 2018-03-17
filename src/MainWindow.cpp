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
    setFixedSize(640,480);

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
    menuBar()->show();




}

void MainWindow::InitFileMenu() {
    // Add file dropdown to main menu bar
    file_menu_ = menuBar()->addMenu(tr("&File"));

    // Create actions
    file_menu_->addAction(tr("&New..."), this, SLOT(SlotNewFile()));
    file_menu_->addAction(tr("&Open..."), this, SLOT(SlotOpenFile()));

}

void MainWindow::SlotNewFile() {
    FileMenuSlots::NewFile(this);
}

void MainWindow::SlotOpenFile() {
    FileMenuSlots::OpenFile(this);
}
