//
// Created by cjreid on 3/17/18.
//

#ifndef ROSIDE_DEVELOPWIDGET_H
#define ROSIDE_DEVELOPWIDGET_H

#include <QtWidgets>


class DevelopWidget : public QMainWindow {
    Q_OBJECT
public:
    DevelopWidget(QWidget *parent = 0);

    void openNewTab();
    void openFileInTab(QString fileName);
    void saveCurrentTab();
    void saveCurrentTabAs();
private:
    QTabWidget *main_tab_widget_;
};


#endif //ROSIDE_DEVELOPWIDGET_H
