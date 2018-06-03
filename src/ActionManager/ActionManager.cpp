//
// Created by cjreid on 6/2/18.
//

#include "ActionManager.h"

#include <QAction>
ActionManager* ActionManager::instance_ = nullptr;
QMap<ActionManager::ACTION_ID, QAction*> ActionManager::actions_;

ActionManager* ActionManager::get() {
    if (instance_ == nullptr )
        instance_ = new ActionManager();
    return instance_;
}

void ActionManager::createAction(ACTION_ID id, QAction* action, QObject* receiver, const char* member) {
    if (ActionManager::actions_.contains(id)) {
        // TODO: Warning here if id already is taken?
        return;
    } else {
        ActionManager::actions_.insert(id, action);
        connect(action, SIGNAL(triggered()), receiver, member);
    }
}
QAction* ActionManager::getAction(ACTION_ID id) {
    return ActionManager::actions_.value(id);
}
