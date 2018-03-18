//
// Created by cjreid on 3/17/18.
//

#include "ROSPackageExplorer.h"

ROSPackageExplorer::ROSPackageExplorer(QWidget *parent)
    : QMainWindow(parent) {

    setCentralWidget(new QTreeView(this));
}
