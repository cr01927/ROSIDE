//
// Created by cjreid on 3/17/18.
//

#ifndef ROSIDE_ROSPROJECTEXPLORER_H
#define ROSIDE_ROSPROJECTEXPLORER_H

#include <QtWidgets>

// Not sure if this should inherit QMainWindow or just QWidget... depends on the toolbars I think?
class ROSProjectExplorer : public QMainWindow {
public:
    ROSProjectExplorer(QWidget *parent = nullptr);
private:

};


#endif //ROSIDE_ROSPROJECTEXPLORER_H
