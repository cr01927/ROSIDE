//
// Created by cjreid on 3/17/18.
//

#include "ROSProjectExplorer.h"

ROSProjectExplorer::ROSProjectExplorer(QWidget *parent)
    : QMainWindow(parent) {

    setCentralWidget(new QTreeView(this));
}
