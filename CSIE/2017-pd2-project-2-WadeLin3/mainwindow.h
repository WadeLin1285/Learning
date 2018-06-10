#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QGraphicsScene>
#include "gamewindow.h"
#include "mainscene.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QString name() const;
    QPushButton *card_1,*card_2,*card_3,*card_4,*card_5,*card_6,*card_7,*card_8;
    // setting background
    void setBackgroundScene(const QString &imagepath);

private slots:
    void PressButton1(bool state);
    void PressButton2(bool state);
    void PressButton3(bool state);
    void PressButton4(bool state);
    void PressButton5(bool state);
    void PressButton6(bool state);
    void PressButton7(bool state);
    void PressButton8(bool state);
    //void PressButton9(bool state);
    void PressButton10(bool state);

    void SelectedCard(int card);
    void OpenGameWindow();
    void setName(const QString &name);
    void setButtomEnable(bool b);
    void displayCards();
    void openMainWindow();

private:
    Ui::MainWindow *ui;
    GameWindow *Game;
    MainScene *scene;
    static int SelectedC[7];
    static int n ; // avoid additional window
    void reset();
    QString card_name(int num);
    QString playername;

};

#endif // MAINWINDOW_H
