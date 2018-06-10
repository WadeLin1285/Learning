#ifndef MAINSCENE_H
#define MAINSCENE_H

#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include "card.h"

class MainScene :public QGraphicsScene, public QGraphicsPixmapItem
{
    Q_OBJECT

public:
    MainScene();

    // setting background
    QPixmap initBackground(const QString &imagepath);

    // setting minion cards
    void initMinionCard();
    void addMinionCard(int cardnum,int cardpos);
    void deleteMinionCard(int cardpos);
    QPixmap bgimage,mimage;

    // card items
    Card *displaycard_1,*displaycard_2,*displaycard_3,
         *displaycard_4,*displaycard_5,*displaycard_6,*displaycard_7;

private:
    // position of cards
    int pos_x[8] = {0,20,190,360,530,700,870,1040};
    int pos_y[8] = {0,500,500,500,500,500,500,500};
};

#endif // MAINSCENE_H
