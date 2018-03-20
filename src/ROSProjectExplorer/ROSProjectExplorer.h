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

    enum TYPE {
        UNSET, // Used when no project is open yet
        PACKAGE,
        METAPACKAGE,
        WORKSPACE
    };

    QDir getDir() const;
    void setDir(QDir &dir);
    TYPE getType() const;

    void scanProject(QDir& dir);
private:
    QDir project_dir_;
    TYPE project_type_;

};


#endif //ROSIDE_ROSPROJECTEXPLORER_H
