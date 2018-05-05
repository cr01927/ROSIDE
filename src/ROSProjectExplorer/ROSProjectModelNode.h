//
// Created by cjreid on 5/3/18.
//

#ifndef ROSIDE_ROSPROJECTMODELNODE_H
#define ROSIDE_ROSPROJECTMODELNODE_H

#include <QStandardItem>

class ROSProjectModelNode : public QStandardItem {
public:
    enum NODETYPE {
        PACKAGE = 0,
        PACKAGEXML,
        CMAKELISTSTXT,
        DIRSCRIPTS,
        DIRSRC,
        DIRINCLUDE,
        DIRLAUNCH,
        DIRMSG,
        DIRSRV,
        LAUNCH,
        MSG,
        SRV,
        PY,
        H,
        CPP,
    };
    explicit ROSProjectModelNode(QString fileName);
    int type() const override;
    QStandardItem *clone() const override;

    QString filename() const;
    NODETYPE getNodeType() const;
    void setNodeType(NODETYPE);

private:
    QString filename_;
    NODETYPE node_type_;
};


#endif //ROSIDE_ROSPROJECTMODELNODE_H
