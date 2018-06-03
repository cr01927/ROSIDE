//
// Created by cjreid on 6/2/18.
//

#ifndef ROSIDE_ACTIONMANAGER_H
#define ROSIDE_ACTIONMANAGER_H


#include <QList>
#include <QAction>

class ActionManager : QObject {

    Q_OBJECT
public:

    static ActionManager* get();
    enum ACTION_ID : short {
        /////////////////
        // New actions //
        /////////////////
                NEW_WORKSPACE = 0,
        NEW_PACKAGE,
        NEW_METAPACKAGE,
        NEW_FILE,
        NEW_PACKAGE_XML,
        NEW_CMAKELISTS_TXT,
        NEW_H,
        NEW_CPP,
        NEW_PY,
        NEW_ACTION,
        NEW_MSG,
        NEW_SRV,

        //////////////////
        // Open actions //
        //////////////////

        OPEN_PROJECT,
        OPEN_FILE,

        //////////////////
        // Save actions //
        //////////////////

        SAVE,
        SAVE_ALL,
    };

    static void createAction(ACTION_ID, QAction*, QObject*, const char* member);
    static QAction* getAction(ACTION_ID);

private:
    static ActionManager* instance_;
    static QMap<ACTION_ID, QAction*> actions_;
};


#endif //ROSIDE_ACTIONMANAGER_H
