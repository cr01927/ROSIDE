//
// Created by cjreid on 3/11/18.
//

#ifndef ROSIDE_EDITORWIDGET_H
#define ROSIDE_EDITORWIDGET_H

#include <QHBoxLayout>
#include <QScrollBar>
#include <QPaintEvent>
#include <QPlainTextEdit>
#include <QRect>
#include <QWidget>

class LineNumberArea;

class EditorWidget : public QPlainTextEdit {
    Q_OBJECT
public:
    EditorWidget(QWidget *parent = 0);
    ~EditorWidget();

    void lineNumberAreaPaintEvent(QPaintEvent *event);
    int lineNumberAreaWidth();

protected:
    void resizeEvent(QResizeEvent *event) override;

private slots:
    void updateLineNumberAreaWidth(int newBlockCount);
    void highlightCurrentLine();
    void updateLineNumberArea(const QRect&, int);


private:
    QWidget *line_number_area_;



};

#endif //ROSIDE_EDITORWIDGET_H
