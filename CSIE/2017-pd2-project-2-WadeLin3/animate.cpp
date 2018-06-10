#include "animate.h"

Animate::Animate()
{
    size = QSize(50,50);
}

Animate::Animate(int cls, BattleScene *battlescene, int group) :
    scene(battlescene)
{
    if (group == 1)
    {
        switch (cls) {
        case 1:
            walkfile   = walkanimate_1;
            attackfile = attackanimate_1;
            break;
        case 2:
            walkfile   = walkanimate_2;
            attackfile = attackanimate_2;
            break;
        case 3:
            walkfile   = walkanimate_3;
            attackfile = attackanimate_3;
            break;
        case 4:
            walkfile   = walkanimate_4;
            attackfile = attackanimate_4;
            break;
        case 5:
            walkfile   = walkanimate_5;
            attackfile = attackanimate_5;
            break;
        case 6:
            walkfile   = walkanimate_6;
            attackfile = attackanimate_6;
            break;
        case 7:
            walkfile   = walkanimate_7;
            attackfile = attackanimate_7;
            break;
        case 8:
            walkfile   = walkanimate_8;
            attackfile = attackanimate_8;
            break;
        case 9:
            walkfile   = walkanimate_9;
            attackfile = attackanimate_9;
            break;
        case 10:
            walkfile   = walkanimate_10;
            attackfile = attackanimate_10;
            break;
        default:
            break;
        }
    }
    if (group == 2)
    {
        switch (cls) {
        case 1:
            walkfile   = walkanimate_1_2;
            attackfile = attackanimate_1_2;
            break;
        case 2:
            walkfile   = walkanimate_2_2;
            attackfile = attackanimate_2_2;
            break;
        case 3:
            walkfile   = walkanimate_3_2;
            attackfile = attackanimate_3_2;
            break;
        case 4:
            walkfile   = walkanimate_4_2;
            attackfile = attackanimate_4_2;
            break;
        case 5:
            walkfile   = walkanimate_5_2;
            attackfile = attackanimate_5_2;
            break;
        case 6:
            walkfile   = walkanimate_6_2;
            attackfile = attackanimate_6_2;
            break;
        case 7:
            walkfile   = walkanimate_7_2;
            attackfile = attackanimate_7_2;
            break;
        case 8:
            walkfile   = walkanimate_8_2;
            attackfile = attackanimate_8_2;
            break;
        case 9:
            walkfile   = walkanimate_9_2;
            attackfile = attackanimate_9_2;
            break;
        case 10:
            walkfile   = walkanimate_10_2;
            attackfile = attackanimate_10_2;
            break;
        default:
            break;
        }
    }
    if (cls == 1)
    {
        size = QSize(85,85);
        w = 85;
        h = 85;
    }
    else
    {
        w = QPixmap(walkfile).width()*0.15;
        h = QPixmap(walkfile).height()*0.15;
        size = QSize(w,h);
    }

    setAnimate();
}

void Animate::setAnimate()
{
    state = 0;
    proxy = new QGraphicsProxyWidget(scene);

    // define the QLabel object
    walkLabel = new QLabel();
    attackLabel = new QLabel();
    walkLabel->setAttribute(Qt::WA_NoSystemBackground);
    attackLabel->setAttribute(Qt::WA_NoSystemBackground);

    // define the QMovie object
    walkMovie  = new QMovie(walkfile);
    attackMovie = new QMovie(attackfile);
    walkMovie->setScaledSize(size);
    attackMovie->setScaledSize(size);

    // set the widget object
    walkLabel->setMovie(walkMovie);
    attackLabel->setMovie(attackMovie);

    proxy->setWidget(walkLabel);
    walking();
}

Animate::~Animate()
{
    delete walkMovie;
    delete attackMovie;
    delete walkLabel;
    delete attackLabel;
}

// QMovie
void Animate::pause()
{
    walkMovie->setPaused(true);
    attackMovie->setPaused(true);
}

void Animate::resume()
{
    walkMovie->setPaused(false);
    attackMovie->setPaused(false);
}

void Animate::walking()
{
    attackMovie->stop();
    walkMovie->start();
    attackLabel->hide();
    walkLabel->show();
}

void Animate::attacking()
{
    walkMovie->stop();
    attackMovie->start();
    walkLabel->hide();
    attackLabel->show();
}
void Animate::stopAction()
{
    walkMovie->stop();
    attackMovie->stop();
}

void Animate::setPos(int x, int y)
{
    walkLabel->setGeometry(x,y,600-w,500-h);
    attackLabel->setGeometry(x,y,600-w,500-h);
}

void Animate::walk()
{
    if (state == 1)
    {
        proxy->setWidget(walkLabel);
        walking();
        state = 0;
    }
    walkMovie->start();
}

void Animate::attack()
{
    if (state == 0)
    {
        proxy->setWidget(attackLabel);
        attacking();
        state = 1;
    }
    attackMovie->start();
}

// set the card walking animation file path
const QString Animate::walkanimate_1 = ":/animates/Doggy-walk.gif";
const QString Animate::walkanimate_2 = ":/animates/Soldier-walk.gif";
const QString Animate::walkanimate_3 = ":/animates/Tall-walk.gif";
const QString Animate::walkanimate_4 = ":/animates/Dox-walk.gif";
const QString Animate::walkanimate_5 = ":/animates/Dragon-walk.gif";
const QString Animate::walkanimate_6 = ":/animates/Ancient-walk.gif";
const QString Animate::walkanimate_7 = ":/animates/Commander-walkr.gif";
const QString Animate::walkanimate_8 = ":/animates/TallEX-walk.gif";
const QString Animate::walkanimate_9 = ":/animates/Ninetail-walk.gif";
const QString Animate::walkanimate_10 = ":/animates/Catnon-walk.gif";
const QString Animate::walkanimate_1_2 = ":/animates/Doggy-walk-2.gif";
const QString Animate::walkanimate_2_2 = ":/animates/Soldier-walk-2.gif";
const QString Animate::walkanimate_3_2 = ":/animates/Tall-walk-2.gif";
const QString Animate::walkanimate_4_2 = ":/animates/Dox-walk-2.gif";
const QString Animate::walkanimate_5_2 = ":/animates/Dragon-walk-2.gif";
const QString Animate::walkanimate_6_2 = ":/animates/Ancient-walk-2.gif";
const QString Animate::walkanimate_7_2 = ":/animates/Commander-walk-2.gif";
const QString Animate::walkanimate_8_2 = ":/animates/TallEX-walk-2.gif";
const QString Animate::walkanimate_9_2 = ":/animates/Ninetail-walk-2.gif";
const QString Animate::walkanimate_10_2 = ":/animates/Catnon-walk-2.gif";

// set the card attacking animation file path
const QString Animate::attackanimate_1 = ":/animates/Doggy-attack.gif";
const QString Animate::attackanimate_2 = ":/animates/Soldier-attack.gif";
const QString Animate::attackanimate_3 = ":/animates/Tall-attack.gif";
const QString Animate::attackanimate_4 = ":/animates/Dox-attack.gif";
const QString Animate::attackanimate_5 = ":/animates/Dragon-attack.gif";
const QString Animate::attackanimate_6 = ":/animates/Ancient-attack.gif";
const QString Animate::attackanimate_7 = ":/animates/Commander-attack.gif";
const QString Animate::attackanimate_8 = ":/animates/TallEX-attack.gif";
const QString Animate::attackanimate_9 = ":/animates/Ninetail-attack.gif";
const QString Animate::attackanimate_10 = ":/animates/Catnon-attack.gif";
const QString Animate::attackanimate_1_2 = ":/animates/Doggy-attack-2.gif";
const QString Animate::attackanimate_2_2 = ":/animates/Soldier-attack-2.gif";
const QString Animate::attackanimate_3_2 = ":/animates/Tall-attack-2.gif";
const QString Animate::attackanimate_4_2 = ":/animates/Dox-attack-2.gif";
const QString Animate::attackanimate_5_2 = ":/animates/Dragon-attack-2.gif";
const QString Animate::attackanimate_6_2 = ":/animates/Ancient-attack-2.gif";
const QString Animate::attackanimate_7_2 = ":/animates/Commander-attack-2.gif";
const QString Animate::attackanimate_8_2 = ":/animates/TallEX-attack-2.gif";
const QString Animate::attackanimate_9_2 = ":/animates/Ninetail-attack-2.gif";
const QString Animate::attackanimate_10_2 = ":/animates/Catnon-attack-2.gif";
