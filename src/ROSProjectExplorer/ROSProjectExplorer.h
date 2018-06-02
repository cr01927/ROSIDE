//
// Created by cjreid on 3/17/18.
//

#ifndef ROSIDE_ROSPROJECTEXPLORER_H
#define ROSIDE_ROSPROJECTEXPLORER_H

#include <QtWidgets>
#include <ROSProjectModel.h>

// Not sure if this should inherit QMainWindow or just QWidget... depends on the toolbars I think?
class ROSProjectExplorer : public QMainWindow {
    Q_OBJECT
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
public slots:
    void itemDoubleClicked(QModelIndex);
    void customContextMenuRequested(QPoint pos);
private:
    QDir project_dir_;
    QMenu *package_context_menu_, *msg_context_menu_;
    TYPE project_type_;
    QTreeView *tree_view_;
    ROSProjectModel *model;

};


#endif //ROSIDE_ROSPROJECTEXPLORER_H
