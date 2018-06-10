#include "mousebutton.h"

MouseButton::MouseButton(QWidget *parent) :
    QPushButton(parent)
{

}

void MouseButton::enterEvent(QEvent *)
{
    emit mouseTouch();
}

void MouseButton::leaveEvent(QEvent *)
{
    emit mouseLeft();
}
