//
// Created by cjreid on 5/3/18.
//

#include "ROSProjectModelNode.h"

ROSProjectModelNode::ROSProjectModelNode(QString fileName) {
    filename_ = fileName;
    setText(fileName);
}

int ROSProjectModelNode::type() const {
    return QStandardItem::UserType;
}

QStandardItem *ROSProjectModelNode::clone() const {
    return new ROSProjectModelNode(filename_);
}

QString ROSProjectModelNode::filename() const {
    return filename_;
}

ROSProjectModelNode::NODETYPE ROSProjectModelNode::getNodeType() const {
    return node_type_;
}

void ROSProjectModelNode::setNodeType(NODETYPE type) {
    node_type_ = type;
}