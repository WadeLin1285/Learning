#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QGraphicsScene>
#include <QFile>
#include <QTextStream>

#include "gamewindow.h"
#include "mainscene.h"
#include "mousebutton.h"
#include "animate.h"

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
    void setRankFile();

private slots:
    void PressButton1(bool state);
    void PressButton2(bool state);
    void PressButton3(bool state);
    void PressButton4(bool state);
    void PressButton5(bool state);
    void PressButton6(bool state);
    void PressButton7(bool state);
    void PressButton8(bool state);
    void PressButton9(bool state);
    void PressButton10(bool state);
    void PressButton11(bool state);
    void PressButton12(bool state);
    void PressButton13(bool state);
    void PressButton14(bool state);
    void PressButton15(bool state);
    void PressButton16(bool state);
    void PressButton17(bool state);
    void PressButton18(bool state);
    void PressButton19(bool state);
    void PressButton20(bool state);

    void Information1();
    void Information2();
    void Information3();
    void Information4();
    void Information5();
    void Information6();
    void Information7();
    void Information8();
    void Information9();
    void Information10();
    void Information11();
    void Information12();
    void Information13();
    void Information14();
    void Information15();
    void Information16();
    void Information17();
    void Information18();
    void Information19();
    void Information20();
    void DefaultInformation();

    void ranking(bool button);
    void SelectedCard(int card);
    void OpenGameWindow();
    void setName(const QString &name);
    void setButtomEnable(bool b);
    void displayCards();
    void openMainWindow();

private:
    void setup();
    void reset();
    Ui::MainWindow *ui;
    GameWindow *Game;
    MainScene *scene;
    static int SelectedC[7];
    static int n ; // avoid additional window
    QString card_name(int num);
    QString playername,rank[14];
    QSize buttomSize;
    Animate *minion1, *minion2, *minion3, *minion4, *minion5,
            *minion6, *minion7, *minion8, *minion9,*minion10,
           *minion11,*minion12,*minion13,*minion14,*minion15,
           *minion16,*minion17,*minion18,*minion19,*minion20;
};

#endif // MAINWINDOW_H
