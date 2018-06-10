#ifndef ANIMATE_H
#define ANIMATE_H

#include <QMovie>
#include <QLabel>
#include <QProgressBar>

#include "battlescene.h"

class Animate : public QMovie, public QLabel
{

public:
    Animate();
    Animate(int cls);
    Animate(int cls,BattleScene *battlescene,int group);
    ~Animate();
    QGraphicsProxyWidget *proxy;
    BattleScene *scene;
    void setAnimate();
    // QMovie
    void pause();
    void resume();
    void walking();
    void attacking();
    void stopAction();
    // QLabel
    void setPos(int x, int y);
    // Minion Actions
    void walk();
    void attack();
    void dead();

    // animate file path of cards
    static const QString walkanimate_1, walkanimate_2, walkanimate_3, walkanimate_4, walkanimate_5,
                         walkanimate_6, walkanimate_7, walkanimate_8, walkanimate_9, walkanimate_10,
                         walkanimate_11,walkanimate_12,walkanimate_13,walkanimate_14,walkanimate_15,
                         walkanimate_16,walkanimate_17,walkanimate_18,walkanimate_19,walkanimate_20,
                         walkanimate_1_2, walkanimate_2_2, walkanimate_3_2, walkanimate_4_2, walkanimate_5_2,
                         walkanimate_6_2, walkanimate_7_2, walkanimate_8_2, walkanimate_9_2, walkanimate_10_2,
                         walkanimate_11_2,walkanimate_12_2,walkanimate_13_2,walkanimate_14_2,walkanimate_15_2,
                         walkanimate_16_2,walkanimate_17_2,walkanimate_18_2,walkanimate_19_2,walkanimate_20_2;

    static const QString attackanimate_1, attackanimate_2, attackanimate_3, attackanimate_4, attackanimate_5,
                         attackanimate_6, attackanimate_7, attackanimate_8, attackanimate_9, attackanimate_10,
                         attackanimate_11,attackanimate_12,attackanimate_13,attackanimate_14,attackanimate_15,
                         attackanimate_16,attackanimate_17,attackanimate_18,attackanimate_19,attackanimate_20,
                         attackanimate_1_2, attackanimate_2_2, attackanimate_3_2, attackanimate_4_2, attackanimate_5_2,
                         attackanimate_6_2, attackanimate_7_2, attackanimate_8_2, attackanimate_9_2, attackanimate_10_2,
                         attackanimate_11_2,attackanimate_12_2,attackanimate_13_2,attackanimate_14_2,attackanimate_15_2,
                         attackanimate_16_2,attackanimate_17_2,attackanimate_18_2,attackanimate_19_2,attackanimate_20_2;

    QLabel *walkLabel,*attackLabel;
    QMovie *walkMovie,*attackMovie;
    QProgressBar *HPBar;
    void display();
    int getY();
private:
    QString walkfile,attackfile,deadfile;
    QSize   size;
    int h,w,x,y,ww,hh,yy;
    int barx,bary;
    int state; // 0 for walk; 1 for attack
    int position_y;
};

#endif // ANIMATE_H
