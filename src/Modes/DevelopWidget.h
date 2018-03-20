//
// Created by cjreid on 3/17/18.
//

#ifndef ROSIDE_DEVELOPWIDGET_H
#define ROSIDE_DEVELOPWIDGET_H

#include <QtWidgets>
#include <Editor/EditorWidget.h>


class DevelopWidget : public QMainWindow {
    Q_OBJECT
public:
    DevelopWidget(QWidget *parent = 0);

    void openNewTab();
    void openFileInTab(QString fileName);

    void saveCurrentTab();
    void saveCurrentTabAs();

    EditorWidget* getActiveTab();

    // temporary
    QDockWidget* getPackageExplorer() {
        return ROS_package_explorer_dock;
    }

private slots:
    void closeTab(int index);

private:
    QDockWidget *ROS_package_explorer_dock;
    QTabWidget *main_tab_widget_;
};


#endif //ROSIDE_DEVELOPWIDGET_H
