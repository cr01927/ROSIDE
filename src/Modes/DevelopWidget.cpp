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
    main_tab_widget_->connect(main_tab_widget_, SIGNAL(tabCloseRequested(int)), this, SLOT(closeTab(int)));

    ROS_package_explorer_dock = new QDockWidget(tr("ROS Package Explorer"), this);
    ROS_package_explorer_dock->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);
    ROS_package_explorer_dock->setWidget(new ROSPackageExplorer(this));
    addDockWidget(Qt::LeftDockWidgetArea, ROS_package_explorer_dock);

}

void DevelopWidget::openNewTab() {
    auto *fileEditor = new EditorWidget(main_tab_widget_);
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

    auto *fileEditor = new EditorWidget(main_tab_widget_);
    main_tab_widget_->addTab(fileEditor, fileName);
    fileEditor->setPlainText(fileText);
    fileEditor->setFileName(fileName);

    main_tab_widget_->setCurrentWidget(fileEditor);
}

void DevelopWidget::closeTab(int index) {
    // Assumes main_tab_widget_ contains only EditorWidgets
    main_tab_widget_->removeTab(index);
}

void DevelopWidget::saveCurrentTab() {
    // This line assumes all tabs are EditorWidgets. May not be the case in the future
    EditorWidget* editorWidget = dynamic_cast<EditorWidget*>(main_tab_widget_->currentWidget());
    QString fileName = editorWidget->getFileName();

    if (fileName.isEmpty()) {
        saveCurrentTabAs();
        return;
    }
    QTextDocumentWriter writer(fileName);
    writer.setFormat("plaintext");
    writer.write(editorWidget->document());

}
  
void DevelopWidget::saveCurrentTabAs() {
    QString fileName = QFileDialog::getSaveFileName(this);
    // This line assumes all tabs are EditorWidgets. May not be the case in the future
    EditorWidget* editorWidget = dynamic_cast<EditorWidget*>(main_tab_widget_->currentWidget());
    editorWidget->setFileName(fileName);
    saveCurrentTab();
}