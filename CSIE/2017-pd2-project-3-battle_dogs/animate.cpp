#include "animate.h"

Animate::Animate()
{
    size = QSize(50,50);
}

Animate::Animate(int cls)
{
    switch (cls) {
    case 1:
        walkfile   = walkanimate_1;
        w = 170;
        h = 170;
        x = 500;
        y = 250;
        break;
    case 2:
        walkfile   = walkanimate_2;
        w = QPixmap(walkfile).width()*0.3;
        h = QPixmap(walkfile).height()*0.3;
        x = 500;
        y = 160;
        break;
    case 3:
        walkfile   = walkanimate_3;
        w = QPixmap(walkfile).width()*0.28;
        h = QPixmap(walkfile).height()*0.28;
        x = 500;
        y = 20;
        break;
    case 4:
        walkfile   = walkanimate_4;
        w = QPixmap(walkfile).width()*0.3;
        h = QPixmap(walkfile).height()*0.3;
        x = 450;
        y = 160;
        break;
    case 5:
        walkfile   = walkanimate_5;
        w = QPixmap(walkfile).width()*0.3;
        h = QPixmap(walkfile).height()*0.3;
        x = 400;
        y = 250;
        break;
    case 6:
        walkfile   = walkanimate_6;
        w = QPixmap(walkfile).width()*0.3;
        h = QPixmap(walkfile).height()*0.3;
        x = 500;
        y = 250;
        break;
    case 7:
        walkfile   = walkanimate_7;
        w = QPixmap(walkfile).width()*0.3;
        h = QPixmap(walkfile).height()*0.3;
        x = 470;
        y = 165;
        break;
    case 8:
        walkfile   = walkanimate_8;
        w = QPixmap(walkfile).width()*0.28;
        h = QPixmap(walkfile).height()*0.28;
        x = 500;
        y = 30;
        break;
    case 9:
        walkfile   = walkanimate_9;
        w = QPixmap(walkfile).width()*0.28;
        h = QPixmap(walkfile).height()*0.28;
        x = 400;
        y = 30;
        break;
    case 10:
        walkfile   = walkanimate_10;
        w = QPixmap(walkfile).width()*0.3;
        h = QPixmap(walkfile).height()*0.3;
        x = 430;
        y = 80;
        break;
    case 11:
        walkfile   = walkanimate_11;
        w = QPixmap(walkfile).width()*0.32;
        h = QPixmap(walkfile).height()*0.32;
        x = 425;
        y = 55;
        break;
    case 12:
        walkfile   = walkanimate_12;
        w = QPixmap(walkfile).width()*0.3;
        h = QPixmap(walkfile).height()*0.3;
        x = 500;
        y = 190;
        break;
    case 13:
        walkfile   = walkanimate_13;
        w = QPixmap(walkfile).width()*0.3;
        h = QPixmap(walkfile).height()*0.3;
        x = 510;
        y = 250;
        break;
    case 14:
        walkfile   = walkanimate_14;
        w = QPixmap(walkfile).width()*0.3;
        h = QPixmap(walkfile).height()*0.3;
        x = 450;
        y = 190;
        break;
    case 15:
        walkfile   = walkanimate_15;
        w = QPixmap(walkfile).width()*0.3;
        h = QPixmap(walkfile).height()*0.3;
        x = 490;
        y = 165;
        break;
    case 16:
        walkfile   = walkanimate_16;
        w = QPixmap(walkfile).width()*0.3;
        h = QPixmap(walkfile).height()*0.3;
        x = 500;
        y = 195;
        break;
    case 17:
        walkfile   = walkanimate_17;
        w = QPixmap(walkfile).width()*0.25;
        h = QPixmap(walkfile).height()*0.25;
        x = 330;
        y = -70;
        break;
    case 18:
        walkfile   = walkanimate_18;
        w = QPixmap(walkfile).width()*0.3;
        h = QPixmap(walkfile).height()*0.3;
        x = 480;
        y = 170;
        break;
    case 19:
        walkfile   = walkanimate_19;
        w = QPixmap(walkfile).width()*0.3;
        h = QPixmap(walkfile).height()*0.3;
        x = 490;
        y = 170;
        break;
    case 20:
        walkfile   = walkanimate_20;
        w = QPixmap(walkfile).width()*0.3;
        h = QPixmap(walkfile).height()*0.3;
        x = 390;
        y = 170;
        break;
    default:
        break;
    }
    size = QSize(w,h);
    // define the QLabel object
    walkLabel = new QLabel();
    walkLabel->setAttribute(Qt::WA_NoSystemBackground);

    // define the QMovie object
    walkMovie  = new QMovie(walkfile);
    walkMovie->setScaledSize(size);

    // set the widget object
    walkLabel->setMovie(walkMovie);

    HPBar = NULL;
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
            barx = -10;
            bary = 130;
            break;
        case 2:
            walkfile   = walkanimate_2;
            attackfile = attackanimate_2;
            barx = -10;
            bary = 130;
            break;
        case 3:
            walkfile   = walkanimate_3;
            attackfile = attackanimate_3;
            barx = -5;
            bary = 70;
            break;
        case 4:
            walkfile   = walkanimate_4;
            attackfile = attackanimate_4;
            barx = 10;
            bary = 130;
            break;
        case 5:
            walkfile   = walkanimate_5;
            attackfile = attackanimate_5;
            barx = 50;
            bary = 130;
            break;
        case 6:
            walkfile   = walkanimate_6;
            attackfile = attackanimate_6;
            barx = -10;
            bary = 130;
            break;
        case 7:
            walkfile   = walkanimate_7;
            attackfile = attackanimate_7;
            barx = 10;
            bary = 130;
            break;
        case 8:
            walkfile   = walkanimate_8;
            attackfile = attackanimate_8;
            barx = -5;
            bary = 40;
            break;
        case 9:
            walkfile   = walkanimate_9;
            attackfile = attackanimate_9;
            barx = 50;
            bary = 50;
            break;
        case 10:
            walkfile   = walkanimate_10;
            attackfile = attackanimate_10;
            barx = 30;
            bary = 130;
            break;
        case 11:
            walkfile   = walkanimate_11;
            attackfile = attackanimate_11;
            barx = 20;
            bary = 100;
            break;
        case 12:
            walkfile   = walkanimate_12;
            attackfile = attackanimate_12;
            barx = 0;
            bary = 130;
            break;
        case 13:
            walkfile   = walkanimate_13;
            attackfile = attackanimate_13;
            barx = -10;
            bary = 130;
            break;
        case 14:
            walkfile   = walkanimate_14;
            attackfile = attackanimate_14;
            barx = 10;
            bary = 100;
            break;
        case 15:
            walkfile   = walkanimate_15;
            attackfile = attackanimate_15;
            barx = -10;
            bary = 110;
            break;
        case 16:
            walkfile   = walkanimate_16;
            attackfile = attackanimate_16;
            barx = -10;
            bary = 110;
            break;
        case 17:
            walkfile   = walkanimate_17;
            attackfile = attackanimate_17;
            barx = 100;
            bary = 50;
            break;
        case 18:
            walkfile   = walkanimate_18;
            attackfile = attackanimate_18;
            barx = 0;
            bary = 70;
            break;
        case 19:
            walkfile   = walkanimate_19;
            attackfile = attackanimate_19;
            barx = 0;
            bary = 70;
            break;
        case 20:
            walkfile   = walkanimate_20;
            attackfile = attackanimate_20;
            barx = 50;
            bary = 70;
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
            barx = -10;
            bary = 130;
            break;
        case 2:
            walkfile   = walkanimate_2_2;
            attackfile = attackanimate_2_2;
            barx = 30;
            bary = 130;
            break;
        case 3:
            walkfile   = walkanimate_3_2;
            attackfile = attackanimate_3_2;
            barx = 150;
            bary = 70;
            break;
        case 4:
            walkfile   = walkanimate_4_2;
            attackfile = attackanimate_4_2;
            barx = 50;
            bary = 130;
            break;
        case 5:
            walkfile   = walkanimate_5_2;
            attackfile = attackanimate_5_2;
            barx = 200;
            bary = 130;
            break;
        case 6:
            walkfile   = walkanimate_6_2;
            attackfile = attackanimate_6_2;
            barx = 30;
            bary = 130;
            break;
        case 7:
            walkfile   = walkanimate_7_2;
            attackfile = attackanimate_7_2;
            barx = 50;
            bary = 130;
            break;
        case 8:
            walkfile   = walkanimate_8_2;
            attackfile = attackanimate_8_2;
            barx = 110;
            bary = 40;
            break;
        case 9:
            walkfile   = walkanimate_9_2;
            attackfile = attackanimate_9_2;
            barx = 270;
            bary = 50;
            break;
        case 10:
            walkfile   = walkanimate_10_2;
            attackfile = attackanimate_10_2;
            barx = 270;
            bary = 130;
            break;
        case 11:
            walkfile   = walkanimate_11_2;
            attackfile = attackanimate_11_2;
            barx = 110;
            bary = 100;
            break;
        case 12:
            walkfile   = walkanimate_12_2;
            attackfile = attackanimate_12_2;
            barx = 70;
            bary = 130;
            break;
        case 13:
            walkfile   = walkanimate_13_2;
            attackfile = attackanimate_13_2;
            barx = 30;
            bary = 130;
            break;
        case 14:
            walkfile   = walkanimate_14_2;
            attackfile = attackanimate_14_2;
            barx = 50;
            bary = 100;
            break;
        case 15:
            walkfile   = walkanimate_15_2;
            attackfile = attackanimate_15_2;
            barx = 60;
            bary = 110;
            break;
        case 16:
            walkfile   = walkanimate_16_2;
            attackfile = attackanimate_16_2;
            barx = 100;
            bary = 110;
            break;
        case 17:
            walkfile   = walkanimate_17_2;
            attackfile = attackanimate_17_2;
            barx = 80;
            bary = 50;
            break;
        case 18:
            walkfile   = walkanimate_18_2;
            attackfile = attackanimate_18_2;
            barx = 230;
            bary = 70;
            break;
        case 19:
            walkfile   = walkanimate_19_2;
            attackfile = attackanimate_19_2;
            barx = 240;
            bary = 70;
            break;
        case 20:
            walkfile   = walkanimate_20_2;
            attackfile = attackanimate_20_2;
            barx = 190;
            bary = 70;
            break;
        default:
            break;
        }
    }
    yy = 0;
    if (cls == 1)
    {
        size = QSize(85,85);
        w = 85;
        h = 85;
        ww = 600-w;
        hh = 500-h;
    }
    else
    {
        w = QPixmap(walkfile).width()*0.15;
        h = QPixmap(walkfile).height()*0.15;
        size = QSize(w,h);

        if (cls == 9) {
            ww = w;
            hh = h;
            yy = 20;
        }
        else if (cls == 5) {
            ww = w;
            hh = h;
            yy = 170;
        }
        else if (cls == 10) {
            ww = w;
            hh = h;
            yy = 70;
        }
        else if (cls == 17) {
            ww = w;
            hh = h;
            yy = -40;
        }
        else if (cls == 18) {
            ww = w;
            hh = h;
            yy = 100;
        }
        else if (cls == 19) {
            ww = w;
            hh = h;
            yy = 100;
        }
        else if (cls == 20) {
            ww = w;
            hh = h;
            yy = 100;
        }
        else {
            ww = 600-w;
            hh = 500-h;
        }
    }
    setAnimate();
    // set HPBar
    HPBar = new QProgressBar();
    HPBar->setBaseSize(100,20);
    HPBar->setAttribute(Qt::WA_NoSystemBackground);
    scene->addWidget(HPBar);
    HPBar->setTextVisible(false);
    HPBar->show();
    if (group == 2) {
        HPBar->setStyleSheet("QProgressBar::chunk { background-color: #930000 ; width: 10px;}"
                             "QProgressBar { border: 2px solid white; border-radius: 5px; }");
    }
    else {
        HPBar->setStyleSheet("QProgressBar::chunk { background-color: #0066CC ; width: 10px;}"
                             "QProgressBar { border: 2px solid white; border-radius: 5px; }");
    }
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
    delete HPBar;
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
    walkLabel->setGeometry(x,y+yy,ww,hh);
    attackLabel->setGeometry(x,y+yy,ww,hh);
    HPBar->setGeometry(x+barx,y+bary,100,20);
    position_y = y;
}

void Animate::walk()
{
    if (state == 1)
    {
        proxy->setWidget(walkLabel);
        walking();
        state = 0;
    }
    //walkMovie->start();
}

void Animate::attack()
{
    if (state == 0)
    {
        proxy->setWidget(attackLabel);
        attacking();
        state = 1;
    }
    //attackMovie->start();
}

void Animate::display()
{
    walkLabel->setGeometry(x,y,w,h);
    walkMovie->start();
    walkMovie->stop();
    walkLabel->hide();
}

int Animate::getY() { return position_y; }

// set the card walking animation file path
const QString Animate::walkanimate_1  = ":/animates/Doggy-walk.gif";
const QString Animate::walkanimate_2  = ":/animates/Soldier-walk.gif";
const QString Animate::walkanimate_3  = ":/animates/Tall-walk.gif";
const QString Animate::walkanimate_4  = ":/animates/Dox-walk.gif";
const QString Animate::walkanimate_5  = ":/animates/Dragon-walk.gif";
const QString Animate::walkanimate_6  = ":/animates/Ancient-walk.gif";
const QString Animate::walkanimate_7  = ":/animates/Commander-walk.gif";
const QString Animate::walkanimate_8  = ":/animates/TallEX-walk.gif";
const QString Animate::walkanimate_9  = ":/animates/Ninetail-walk.gif";
const QString Animate::walkanimate_10 = ":/animates/Catnon-walk.gif";
const QString Animate::walkanimate_11 = ":/animates/Saber-walk.gif";
const QString Animate::walkanimate_12 = ":/animates/Nija-walk.gif";
const QString Animate::walkanimate_13 = ":/animates/Robort-walk.gif";
const QString Animate::walkanimate_14 = ":/animates/Shield-walk.gif";
const QString Animate::walkanimate_15 = ":/animates/Ditch-walk.gif";
const QString Animate::walkanimate_16 = ":/animates/Spartan-walk.gif";
const QString Animate::walkanimate_17 = ":/animates/Bigdog-walk.gif";
const QString Animate::walkanimate_18 = ":/animates/Superdog-walk.gif";
const QString Animate::walkanimate_19 = ":/animates/Jesus-walk.gif";
const QString Animate::walkanimate_20 = ":/animates/King-walk.gif";

const QString Animate::walkanimate_1_2  = ":/animates/Doggy-walk-2.gif";
const QString Animate::walkanimate_2_2  = ":/animates/Soldier-walk-2.gif";
const QString Animate::walkanimate_3_2  = ":/animates/Tall-walk-2.gif";
const QString Animate::walkanimate_4_2  = ":/animates/Dox-walk-2.gif";
const QString Animate::walkanimate_5_2  = ":/animates/Dragon-walk-2.gif";
const QString Animate::walkanimate_6_2  = ":/animates/Ancient-walk-2.gif";
const QString Animate::walkanimate_7_2  = ":/animates/Commander-walk-2.gif";
const QString Animate::walkanimate_8_2  = ":/animates/TallEX-walk-2.gif";
const QString Animate::walkanimate_9_2  = ":/animates/Ninetail-walk-2.gif";
const QString Animate::walkanimate_10_2 = ":/animates/Catnon-walk-2.gif";
const QString Animate::walkanimate_11_2 = ":/animates/Saber-walk-2.gif";
const QString Animate::walkanimate_12_2 = ":/animates/Nija-walk-2.gif";
const QString Animate::walkanimate_13_2 = ":/animates/Robort-walk-2.gif";
const QString Animate::walkanimate_14_2 = ":/animates/Shield-walk-2.gif";
const QString Animate::walkanimate_15_2 = ":/animates/Ditch-walk-2.gif";
const QString Animate::walkanimate_16_2 = ":/animates/Spartan-walk-2.gif";
const QString Animate::walkanimate_17_2 = ":/animates/Bigdog-walk-2.gif";
const QString Animate::walkanimate_18_2 = ":/animates/Superdog-walk-2.gif";
const QString Animate::walkanimate_19_2 = ":/animates/Jesus-walk-2.gif";
const QString Animate::walkanimate_20_2 = ":/animates/King-walk-2.gif";

// set the card attacking animation file path
const QString Animate::attackanimate_1  = ":/animates/Doggy-attack.gif";
const QString Animate::attackanimate_2  = ":/animates/Soldier-attack.gif";
const QString Animate::attackanimate_3  = ":/animates/Tall-attack.gif";
const QString Animate::attackanimate_4  = ":/animates/Dox-attack.gif";
const QString Animate::attackanimate_5  = ":/animates/Dragon-attack.gif";
const QString Animate::attackanimate_6  = ":/animates/Ancient-attack.gif";
const QString Animate::attackanimate_7  = ":/animates/Commander-attack.gif";
const QString Animate::attackanimate_8  = ":/animates/TallEX-attack.gif";
const QString Animate::attackanimate_9  = ":/animates/Ninetail-attack.gif";
const QString Animate::attackanimate_10 = ":/animates/Catnon-attack.gif";
const QString Animate::attackanimate_11 = ":/animates/Saber-attack.gif";
const QString Animate::attackanimate_12 = ":/animates/Nija-attack.gif";
const QString Animate::attackanimate_13 = ":/animates/Robort-attack.gif";
const QString Animate::attackanimate_14 = ":/animates/Shield-attack.gif";
const QString Animate::attackanimate_15 = ":/animates/Ditch-attack.gif";
const QString Animate::attackanimate_16 = ":/animates/Spartan-attack.gif";
const QString Animate::attackanimate_17 = ":/animates/Bigdog-attack.gif";
const QString Animate::attackanimate_18 = ":/animates/Superdog-attack.gif";
const QString Animate::attackanimate_19 = ":/animates/Jesus-attack.gif";
const QString Animate::attackanimate_20 = ":/animates/King-attack.gif";

const QString Animate::attackanimate_1_2  = ":/animates/Doggy-attack-2.gif";
const QString Animate::attackanimate_2_2  = ":/animates/Soldier-attack-2.gif";
const QString Animate::attackanimate_3_2  = ":/animates/Tall-attack-2.gif";
const QString Animate::attackanimate_4_2  = ":/animates/Dox-attack-2.gif";
const QString Animate::attackanimate_5_2  = ":/animates/Dragon-attack-2.gif";
const QString Animate::attackanimate_6_2  = ":/animates/Ancient-attack-2.gif";
const QString Animate::attackanimate_7_2  = ":/animates/Commander-attack-2.gif";
const QString Animate::attackanimate_8_2  = ":/animates/TallEX-attack-2.gif";
const QString Animate::attackanimate_9_2  = ":/animates/Ninetail-attack-2.gif";
const QString Animate::attackanimate_10_2 = ":/animates/Catnon-attack-2.gif";
const QString Animate::attackanimate_11_2 = ":/animates/Saber-attack-2.gif";
const QString Animate::attackanimate_12_2 = ":/animates/Nija-attack-2.gif";
const QString Animate::attackanimate_13_2 = ":/animates/Robort-attack-2.gif";
const QString Animate::attackanimate_14_2 = ":/animates/Shield-attack-2.gif";
const QString Animate::attackanimate_15_2 = ":/animates/Ditch-attack-2.gif";
const QString Animate::attackanimate_16_2 = ":/animates/Spartan-attack-2.gif";
const QString Animate::attackanimate_17_2 = ":/animates/Bigdog-attack-2.gif";
const QString Animate::attackanimate_18_2 = ":/animates/Superdog-attack-2.gif";
const QString Animate::attackanimate_19_2 = ":/animates/Jesus-attack-2.gif";
const QString Animate::attackanimate_20_2 = ":/animates/King-attack-2.gif";
