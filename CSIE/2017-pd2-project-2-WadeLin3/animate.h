#ifndef ANIMATE_H
#define ANIMATE_H

#include<QMovie>
#include<QLabel>

#include"battlescene.h"

class Animate : public QMovie, public QLabel
{
public:
    Animate();
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
                         walkanimate_1_2, walkanimate_2_2, walkanimate_3_2, walkanimate_4_2, walkanimate_5_2,
                         walkanimate_6_2, walkanimate_7_2, walkanimate_8_2, walkanimate_9_2, walkanimate_10_2;

    static const QString attackanimate_1, attackanimate_2, attackanimate_3, attackanimate_4,
                         attackanimate_5, attackanimate_6, attackanimate_7, attackanimate_8,
                         attackanimate_9, attackanimate_10,attackanimate_1_2, attackanimate_2_2,
                         attackanimate_3_2, attackanimate_4_2, attackanimate_5_2, attackanimate_6_2,
                         attackanimate_7_2, attackanimate_8_2, attackanimate_9_2, attackanimate_10_2;

private:
    QString walkfile,attackfile,deadfile;
    QSize   size;
    int h,w;
    QLabel *walkLabel,*attackLabel;
    QMovie *walkMovie,*attackMovie;
    int state; // 0 for walk; 1 for attack

};

#endif // ANIMATE_H
