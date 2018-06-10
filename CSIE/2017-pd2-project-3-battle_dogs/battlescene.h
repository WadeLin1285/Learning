#ifndef BATTLESCENE_H
#define BATTLESCENE_H

#include<QGraphicsScene>
#include<QGraphicsPixmapItem>

#include<qgraphicsproxywidget.h>
#include<QMovie>
#include<QLabel>

#include"card.h"

class BattleScene :public QGraphicsScene, public QGraphicsPixmapItem
{
public:
    BattleScene();
    ~BattleScene();
    QPixmap initBackground();
    void initPlayerTower();
    void initAITower();
    void initMagic();
    void towerStop();
    void towerStart();
    void playerTowerMode(int mode);
    void AITowermode(int mode);
    void destroyTower(QString tower);
    void fireAnimate();
    QLabel *fire;
    QMovie *fireAnimation;
    void fireEnd();
    void showTower();

private:
    QPixmap bgImage;
    // QPixmap PlayerTowerImage,AITowerImage;
    // Card *playerTower,*AITower;
    QLabel *playerTower,*playerTowerAttack,*AITower,*AITowerAttack;
    QMovie *playerTowerAnimation,*playerTowerAttackAnimation,*AITowerAnimation,*AITowerAttackAnimation;
    QSize   size,size2;
    int playermode,AImode;

    static const QString PlayerTowerImagePath,AITowerImagePath,bgImagePath,
                         PlayerTowerAnimationPath,PlayerTowerAttackAnimationPath,
                         AITowerAnimationPath,AITowerAttackAnimationPath,bgAnimationPath,
                         FireAnimationPath;
};

#endif // BATTLESCENE_H
