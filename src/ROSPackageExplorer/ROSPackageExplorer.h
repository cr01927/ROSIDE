//
// Created by cjreid on 3/17/18.
//

#ifndef ROSIDE_ROSPACKAGEEXPLORER_H
#define ROSIDE_ROSPACKAGEEXPLORER_H

#include <QtWidgets>

// Not sure if this should inherit QMainWindow or just QWidget... depends on the toolbars I think?
class ROSPackageExplorer : public QMainWindow {
public:
    ROSPackageExplorer(QWidget *parent = nullptr);
private:

};


#endif //ROSIDE_ROSPACKAGEEXPLORER_H
