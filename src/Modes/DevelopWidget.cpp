//
// Created by cjreid on 3/17/18.
//

#include "DevelopWidget.h"

#include <QtWidgets>

#include <Editor/EditorWidget.h>
#include <ROSPackageExplorer/ROSPackageExplorer.h>

DevelopWidget::DevelopWidget(QWidget *parent)
    : QMainWindow(parent) {

    main_tab_widget_ = new QTabWidget(this);

    setCentralWidget(main_tab_widget_);
    main_tab_widget_->setTabPosition(QTabWidget::North);

    main_tab_widget_->addTab(new EditorWidget(main_tab_widget_), "Test");
    main_tab_widget_->setMovable(true);
    main_tab_widget_->setTabsClosable(true);

    ROS_package_explorer_dock = new QDockWidget(tr("ROS Package Explorer"), this);
    ROS_package_explorer_dock->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);
    ROS_package_explorer_dock->setWidget(new ROSPackageExplorer(this));

}

void DevelopWidget::openNewTab() {
    EditorWidget* fileEditor = new EditorWidget(main_tab_widget_);
    main_tab_widget_->addTab(fileEditor, tr("New"));
    main_tab_widget_->setCurrentWidget(fileEditor);
}

void DevelopWidget::openFileInTab(QString fileName) {
    if (fileName.isEmpty())
        return;
    QFile file(fileName);
    if (!file.open(QFile::ReadOnly))
        return;
    QByteArray byteData = file.readAll();
    QTextCodec *textCodec = QTextCodec::codecForUtfText(byteData);
    QString fileText = textCodec->toUnicode(byteData);

    EditorWidget* fileEditor = new EditorWidget(main_tab_widget_);
    main_tab_widget_->addTab(fileEditor, fileName);
    fileEditor->setPlainText(fileText);

    main_tab_widget_->setCurrentWidget(fileEditor);
}
