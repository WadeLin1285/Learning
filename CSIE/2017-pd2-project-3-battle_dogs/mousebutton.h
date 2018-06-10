#ifndef MOUSEBUTTON_H
#define MOUSEBUTTON_H

#include <QPushButton>
#include <QMouseEvent>
#include <QEvent>

class MouseButton : public QPushButton
{
    Q_OBJECT

public:
    explicit MouseButton(QWidget *parent = 0);

    void enterEvent(QEvent *);
    void leaveEvent(QEvent *);

signals:
    void mouseTouch();
    void mouseLeft();

};

#endif // MOUSEBUTTON_H
