//
// Created by cjreid on 3/15/18.
//

#include <LineNumberArea.h>

LineNumberArea::LineNumberArea(EditorWidget* editorWidget)
        : QWidget(editorWidget), editor_widget_(editorWidget) {

}

QSize LineNumberArea::sizeHint() const {
    return QSize(editor_widget_->lineNumberAreaWidth(), 0);
}

void LineNumberArea::paintEvent(QPaintEvent *event) {
    editor_widget_->lineNumberAreaPaintEvent(event);
}