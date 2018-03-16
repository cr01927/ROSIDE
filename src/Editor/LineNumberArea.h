//
// Created by cjreid on 3/15/18.
//

#ifndef ROSIDE_LINENUMBERAREA_H
#define ROSIDE_LINENUMBERAREA_H

#include <QPaintEvent>
#include <QPlainTextEdit>
#include <QSize>
#include <QWidget>

#include <EditorWidget.h>


class LineNumberArea : public QWidget {
    Q_OBJECT
public:
    LineNumberArea(EditorWidget *editorWidget);

    QSize sizeHint() const override;
protected:
    void paintEvent(QPaintEvent *event) override;

private:
    EditorWidget *editor_widget_;

};

#endif //ROSIDE_LINENUMBERAREA_H
