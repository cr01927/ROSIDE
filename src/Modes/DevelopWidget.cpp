//
// Created by cjreid on 3/17/18.
//

#include "DevelopWidget.h"

#include <QDockWidget>
#include <QTabWidget>
#include <QTreeView>

#include <Editor/EditorWidget.h>

DevelopWidget::DevelopWidget(QWidget *parent)
    : QMainWindow(parent) {

    main_tab_widget_ = new QTabWidget(this);

    setCentralWidget(main_tab_widget_);
    main_tab_widget_->setTabPosition(QTabWidget::North);

    main_tab_widget_->addTab(new EditorWidget(main_tab_widget_), "Test");

}
