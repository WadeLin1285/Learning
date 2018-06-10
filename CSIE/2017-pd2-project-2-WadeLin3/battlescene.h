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
    void towerStop();
    void towerStart();
    void playerTowerMode(int mode);
    void AITowermode(int mode);
    void destroyTower(QString tower);
    void conti();

private:
    QPixmap bgImage;
    // QPixmap PlayerTowerImage,AITowerImage;
    // Card *playerTower,*AITower;
    QLabel *playerTower,*playerTowerAttack,*AITower,*AITowerAttack;
    QMovie *playerTowerAnimation,*playerTowerAttackAnimation,*AITowerAnimation,*AITowerAttackAnimation;
    QSize   size;
    int playermode,AImode;

    static const QString PlayerTowerImagePath,AITowerImagePath,bgImagePath,
                         PlayerTowerAnimationPath,PlayerTowerAttackAnimationPath,
                         AITowerAnimationPath,AITowerAttackAnimationPath,bgAnimationPath;
};

#endif // BATTLESCENE_H
