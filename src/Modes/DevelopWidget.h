//
// Created by cjreid on 3/17/18.
//

#ifndef ROSIDE_DEVELOPWIDGET_H
#define ROSIDE_DEVELOPWIDGET_H

#include <QMainWindow>

class QTabWidget;
class QWidget;


class DevelopWidget : public QMainWindow {
    Q_OBJECT
public:
    DevelopWidget(QWidget *parent = 0);
private:
    QTabWidget *main_tab_widget_;
};


#endif //ROSIDE_DEVELOPWIDGET_H
