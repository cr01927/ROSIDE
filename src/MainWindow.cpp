//
// Created by cjreid on 3/11/18.
//

#include <QAction>

#include <MainWindow.h>
#include <Editor/EditorWidget.h>

MainWindow& MainWindow::get() {
    static MainWindow instance;
    return instance;
}



MainWindow::MainWindow()
: QMainWindow(0) {
    setFixedSize(640,480);

    InitMenuBar();
    show();

    main_tabbed_window_ = new QTabWidget(this);
    main_tabbed_window_->addTab(new QWidget(), tr("Design"));
    main_tabbed_window_->addTab(new EditorWidget(this), tr("Develop"));
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