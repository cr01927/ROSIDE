//
// Created by cjreid on 5/1/18.
//

#ifndef ROSIDE_ROSPROJECTMODEL_H
#define ROSIDE_ROSPROJECTMODEL_H

#include <QDir>
#include <QStandardItemModel>

/*
 * This is a custom class derived from QFileSystemModel because we want more control over header data than what is
 * offered
 */
class ROSProjectModel : public QStandardItemModel {
public:
    ROSProjectModel(QObject *parent = nullptr);

    QModelIndex populateModel(QDir& dir);
    void createAndDescend(QDir *dir, QStandardItem *parent);
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;

private:
    QStandardItem *rootItem;
    QIcon dirIcon;
    QIcon fileIcon;
};


#endif //ROSIDE_ROSPROJECTMODEL_H
