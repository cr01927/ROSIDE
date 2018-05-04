//
// Created by cjreid on 5/3/18.
//

#ifndef ROSIDE_ROSPROJECTMODELNODE_H
#define ROSIDE_ROSPROJECTMODELNODE_H

#include <QStandardItem>

class ROSProjectModelNode : public QStandardItem {
public:
    explicit ROSProjectModelNode(QString fileName);
    int type() const override;
    QStandardItem *clone() const override;

    QString filename() const;

private:
    QString filename_;
};


#endif //ROSIDE_ROSPROJECTMODELNODE_H
