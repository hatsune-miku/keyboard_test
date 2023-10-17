#include "lineedit.h"

LineEdit::LineEdit(QWidget* parent) : QLineEdit(parent)
{

}

void LineEdit::keyPressEvent(QKeyEvent* event) {
    QLineEdit::keyPressEvent(event);
    emit onKeyPressEvent(event);
}

void LineEdit::keyReleaseEvent(QKeyEvent* event) {
    QLineEdit::keyReleaseEvent(event);
    emit onKeyReleaseEvent(event);
}
