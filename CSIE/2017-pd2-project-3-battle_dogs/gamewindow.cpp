#include "gamewindow.h"
#include "ui_gamewindow.h"

#include <iostream>

GameWindow::GameWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GameWindow)
{
    // set UIs
    ui->setupUi(this);
    setNoticeVisible(false);
    setButtonEnable(false);
    ui->AITowerHP->setMaximum(MAXTOWERHP);
    ui->AITowerHP->setMinimum(0);
    ui->AITowerHP->setValue(MAXTOWERHP);
    ui->AITowerHP->setFormat("%v");
    ui->AITowerHP->setStyleSheet("QProgressBar::chunk { background-color: #FF2D2D;}"
                                 "QProgressBar { text-align: center; color: white;}"
                                 "QProgressBar { border: 3px solid #750000; border-radius: 1px;}");
    ui->PlayerTowerHP->setMaximum(MAXTOWERHP);
    ui->PlayerTowerHP->setMinimum(0);
    ui->PlayerTowerHP->setValue(MAXTOWERHP);
    ui->PlayerTowerHP->setFormat("%v");
    ui->PlayerTowerHP->setStyleSheet("QProgressBar::chunk { background-color: #0066CC;}"
                                     "QProgressBar { text-align: center; color: white;}"
                                     "QProgressBar { border: 3px solid #000079; border-radius: 1px;}");
    ui->fire_button->hide();
    ui->fire_button->setStyleSheet("QPushButton {background-color: #AE0000; color: #FF8000}");
    ui->fire_time->setText("60");
    ui->fire_time->setStyleSheet("QLabel {color: #003D79}");
    ui->fire_count->setStyleSheet("QLabel {color: #003D79}");
    ui->fire_bg->setStyleSheet("QGraphicsView {background-color: #97CBFF;}");
    ui->moneyLabel->setStyleSheet("QLabel {color: #642100;}");
    ui->money->setStyleSheet("QLabel {color: #FFD306}");
    ui->quitButton->setStyleSheet("QPushButton {border: 5px solid #642100; border-radius: 10px;}"
                                  "QPushButton {color: #BB5E00}");
    ui->pauseButton->setStyleSheet(ui->quitButton->styleSheet());
    ui->noticeButtonLeft->setStyleSheet("QPushButton {border: 5px solid black; border-radius: 10px;}"
                                        "QPushButton {color: black;}");
    ui->noticeButtonRight->setStyleSheet(ui->noticeButtonLeft->styleSheet());
    ui->card_1->setStyleSheet("QPushButton {border: 0px solid black; border-radius: 20px;}");
    ui->card_2->setStyleSheet(ui->card_1->styleSheet());
    ui->card_3->setStyleSheet(ui->card_1->styleSheet());
    ui->card_4->setStyleSheet(ui->card_1->styleSheet());
    ui->card_5->setStyleSheet(ui->card_1->styleSheet());
    ui->card_6->setStyleSheet(ui->card_1->styleSheet());
    ui->card_7->setStyleSheet(ui->card_1->styleSheet());
    ui->card_cost_1->setStyleSheet("QLabel {background-color: #FFF8D7; color: #EAC100;}"
                                   "QLabel {border: 0px solid #FF9224; border-radius: 15px}");
    ui->card_cost_2->setStyleSheet(ui->card_cost_1->styleSheet());
    ui->card_cost_3->setStyleSheet(ui->card_cost_1->styleSheet());
    ui->card_cost_4->setStyleSheet(ui->card_cost_1->styleSheet());
    ui->card_cost_5->setStyleSheet(ui->card_cost_1->styleSheet());
    ui->card_cost_6->setStyleSheet(ui->card_cost_1->styleSheet());
    ui->card_cost_7->setStyleSheet(ui->card_cost_1->styleSheet());

    //set scene
    scene = new BattleScene();
    scene->initBackground();
    ui->background->setScene(scene);
    ui->background->show();
    scene->initPlayerTower();
    scene->initAITower();
    scene->initMagic();
    scene->towerStop();
    scene->setSceneRect(0,0,1300,850);

    // create the battle object for game start
    battle = new Battle(scene);

    // connect the actions
    connect(battle,SIGNAL(battlingEnd()),this,SLOT(updating()));
    connect(battle,SIGNAL(countDown(int)),this,SLOT(countDown(int)));
    connect(battle,SIGNAL(newMinion(int,int)),this,SLOT(displayNewMinion(int,int)));
    connect(battle,SIGNAL(end(int)),this,SLOT(result(int)));
    connect(battle,SIGNAL(playerTowerModeChange(int)),this,SLOT(playerTowerMode(int)));
    connect(battle,SIGNAL(AITowerModeChange(int)),this,SLOT(AITowermode(int)));
    connect(ui->card_1,SIGNAL(clicked(bool)),this,SLOT(addMinion_1(bool)));
    connect(ui->card_2,SIGNAL(clicked(bool)),this,SLOT(addMinion_2(bool)));
    connect(ui->card_3,SIGNAL(clicked(bool)),this,SLOT(addMinion_3(bool)));
    connect(ui->card_4,SIGNAL(clicked(bool)),this,SLOT(addMinion_4(bool)));
    connect(ui->card_5,SIGNAL(clicked(bool)),this,SLOT(addMinion_5(bool)));
    connect(ui->card_6,SIGNAL(clicked(bool)),this,SLOT(addMinion_6(bool)));
    connect(ui->card_7,SIGNAL(clicked(bool)),this,SLOT(addMinion_7(bool)));
    connect(ui->quitButton,SIGNAL(clicked(bool)),this,SLOT(closeSlot(bool)));
    connect(ui->pauseButton,SIGNAL(clicked(bool)),this,SLOT(pauseSlot(bool)));
    connect(ui->noticeButtonLeft,SIGNAL(clicked(bool)),this,SLOT(LeftButtonAction()));
    connect(ui->noticeButtonRight,SIGNAL(clicked(bool)),this,SLOT(RightButtonAction()));
    connect(ui->fire_button,SIGNAL(clicked(bool)),this,SLOT(fire(bool)));
}

GameWindow::~GameWindow()
{
    delete ui;
    delete battle;
    delete scene;
}
void GameWindow::reset()
{
    battle->battleReset();
    ui->AITowerHP->setValue(MAXTOWERHP);
    ui->PlayerTowerHP->setValue(MAXTOWERHP);
}

int  GameWindow::disk[7]={0,0,0,0,0,0,0};
int  GameWindow::money[20] = {30,60,60,80,120,100,200,250,500,300,60,80,100,200,120,200,200,300,400,500};
void GameWindow::setCard(int card_1,int card_2,int card_3,int card_4,int card_5,int card_6,int card_7)
{
    disk[0] = card_1;
    disk[1] = card_2;
    disk[2] = card_3;
    disk[3] = card_4;
    disk[4] = card_5;
    disk[5] = card_6;
    disk[6] = card_7;
}

void GameWindow::displayCard()
{
    ui->card_1->setIcon(QIcon(selectPath(disk[0])));
    ui->card_1->setIconSize(QSize(100,100));
    ui->card_cost_1->setText((QString("$ %1").arg(money[disk[0]-1])));
    ui->card_2->setIcon(QIcon(selectPath(disk[1])));
    ui->card_2->setIconSize(QSize(100,100));
    ui->card_cost_2->setText((QString("$ %1").arg(money[disk[1]-1])));
    ui->card_3->setIcon(QIcon(selectPath(disk[2])));
    ui->card_3->setIconSize(QSize(100,100));
    ui->card_cost_3->setText((QString("$ %1").arg(money[disk[2]-1])));
    ui->card_4->setIcon(QIcon(selectPath(disk[3])));
    ui->card_4->setIconSize(QSize(100,100));
    ui->card_cost_4->setText((QString("$ %1").arg(money[disk[3]-1])));
    ui->card_5->setIcon(QIcon(selectPath(disk[4])));
    ui->card_5->setIconSize(QSize(100,100));
    ui->card_cost_5->setText((QString("$ %1").arg(money[disk[4]-1])));
    ui->card_6->setIcon(QIcon(selectPath(disk[5])));
    ui->card_6->setIconSize(QSize(100,100));
    ui->card_cost_6->setText((QString("$ %1").arg(money[disk[5]-1])));
    ui->card_7->setIcon(QIcon(selectPath(disk[6])));
    ui->card_7->setIconSize(QSize(100,100));
    ui->card_cost_7->setText((QString("$ %1").arg(money[disk[6]-1])));
}

QString GameWindow::selectPath(int num)
{
    switch (num) {
    case  1: return  Card::cardpath_1;
    case  2: return  Card::cardpath_2;
    case  3: return  Card::cardpath_3;
    case  4: return  Card::cardpath_4;
    case  5: return  Card::cardpath_5;
    case  6: return  Card::cardpath_6;
    case  7: return  Card::cardpath_7;
    case  8: return  Card::cardpath_8;
    case  9: return  Card::cardpath_9;
    case 10: return  Card::cardpath_10;
    case 11: return  Card::cardpath_11;
    case 12: return  Card::cardpath_12;
    case 13: return  Card::cardpath_13;
    case 14: return  Card::cardpath_14;
    case 15: return  Card::cardpath_15;
    case 16: return  Card::cardpath_16;
    case 17: return  Card::cardpath_17;
    case 18: return  Card::cardpath_18;
    case 19: return  Card::cardpath_19;
    case 20: return  Card::cardpath_20;

    default:
        return " ";
    }
}

/***************************************** UPDATE the minions' action *****************************************************/
int  GameWindow::battleTime = 0;
int  GameWindow::fireTime = 600;
int  GameWindow::position_y = 300;
void GameWindow::updating()
{
    // update UIs
    battleTime = (battle->time)/10;
    if (fireTime > 0) {
        fireTime--;
        ui->fire_time->setText((QString("%1").arg(fireTime/10)));
    }
    else if (fireTime == -1) ui->fire_button->hide();
    else {
        fireTime = 0;
        ui->fire_button->show();
        ui->fire_time->setText("-Ready-");
    }
    ui->money->setNum(battle->money);
    ui->time->setText((QString("%1:%2").arg(battleTime/60).arg(battleTime%60)));

    ui->AITowerHP->setValue(battle->AI_HP);
    ui->PlayerTowerHP->setValue(battle->P1_HP);
    checkMoney();
    // set Minion positions
    for (int mini_pos = 0; mini_pos <MAXPOSITION; mini_pos++) // MINIONLIST
    {
        for (int mini_order = 0; mini_order < battle->minionList[mini_pos].size() ; mini_order++) // QVector<Minion>
        {
            // minion action
            if (battle->minionList[mini_pos][mini_order].getState() == 0) // walk
            {
                // minion picture
                battle->minionList[mini_pos][mini_order].minionAnimate->setPos(mini_pos,battle->minionList[mini_pos][mini_order].minionAnimate->getY());
                battle->minionList[mini_pos][mini_order].walk();
            }
            else // attack
                battle->minionList[mini_pos][mini_order].attack();
        }
    }
    // update minions
    battle->updateMinion();
}
/****************************************************************************************************************************/

void GameWindow::displayNewMinion(int pos,int order)
{
    int random = (qrand()%3-1)*2;
    // minion gif
    battle->minionList[pos][order].minionAnimate->setPos(pos,position_y + random);
    scene->addItem(battle->minionList[pos][order].minionAnimate->proxy);
}

void GameWindow::countDown(int cd)
{
    battleTime = (battle->time)/10;
    ui->money->setNum(battle->money);
    ui->time->setText((QString("%1:00").arg(battleTime/60)));
    if (cd/10 == 5) ui->noticeText->setVisible(true);
    else if (cd/10 == 4) ui->noticeText->setText("3");
    else if (cd/10 == 3) ui->noticeText->setText("2");
    else if (cd/10 == 2) ui->noticeText->setText("1");
    else if (cd/10 == 1) ui->noticeText->setText("! START !");
    else if (cd/10 == 0){
        ui->noticeText->setVisible(false);
        ui->quitButton->setEnabled(true);
        ui->pauseButton->setEnabled(true);
        //scene->towerStart();
    }
}

void GameWindow::checkMoney()
{
    if (battle->getMoney() < (money[disk[0]-1])) ui->card_1->setEnabled(false);
    else ui->card_1->setEnabled(true);
    if (battle->getMoney() < (money[disk[1]-1])) ui->card_2->setEnabled(false);
    else ui->card_2->setEnabled(true);
    if (battle->getMoney() < (money[disk[2]-1])) ui->card_3->setEnabled(false);
    else ui->card_3->setEnabled(true);
    if (battle->getMoney() < (money[disk[3]-1])) ui->card_4->setEnabled(false);
    else ui->card_4->setEnabled(true);
    if (battle->getMoney() < (money[disk[4]-1])) ui->card_5->setEnabled(false);
    else ui->card_5->setEnabled(true);
    if (battle->getMoney() < (money[disk[5]-1])) ui->card_6->setEnabled(false);
    else ui->card_6->setEnabled(true);
    if (battle->getMoney() < (money[disk[6]-1])) ui->card_7->setEnabled(false);
    else ui->card_7->setEnabled(true);
}

int  GameWindow::position_x_min = 170;
int  GameWindow::position_x_max = 1200;
void GameWindow::addMinion_1(bool press){ if(!press) battle->addMinion(disk[0],1,position_x_min); }
void GameWindow::addMinion_2(bool press){ if(!press) battle->addMinion(disk[1],1,position_x_min); }
void GameWindow::addMinion_3(bool press){ if(!press) battle->addMinion(disk[2],1,position_x_min); }
void GameWindow::addMinion_4(bool press){ if(!press) battle->addMinion(disk[3],1,position_x_min); }
void GameWindow::addMinion_5(bool press){ if(!press) battle->addMinion(disk[4],1,position_x_min); }
void GameWindow::addMinion_6(bool press){ if(!press) battle->addMinion(disk[5],1,position_x_min); }
void GameWindow::addMinion_7(bool press){ if(!press) battle->addMinion(disk[6],1,position_x_min); }

void GameWindow::closeSlot(bool press)
{
    if(!press)
    {
        ui->noticeText->setText("Are you SURE ? QAQ");
        ui->noticeButtonLeft->setText("QUIT");
        ui->noticeButtonRight->setText("NO");
        setNoticeEnable(true);
        setNoticeVisible(true);
        battle->battleTimer->stop();
        battle->pause();
        scene->towerStop();
    }
}

void GameWindow::pauseSlot(bool press)
{
    if(!press)
    {
        ui->noticeText->setText("PAUSE");
        ui->noticeButtonLeft->setText("QUIT");
        ui->noticeButtonRight->setText("Resume");
        setNoticeEnable(true);
        setNoticeVisible(true);
        battle->battleTimer->stop();
        battle->pause();
        scene->towerStop();
    }
}

void GameWindow::LeftButtonAction()
{
    // quit option & pause option
    if (ui->noticeButtonLeft->text() == "QUIT")
    {
        setNoticeVisible(false);
        setNoticeEnable(false);
        emit quit();
    }
}

void GameWindow::RightButtonAction()
{
    // quit option
    if (ui->noticeButtonRight->text() == "NO")
    {
        setNoticeVisible(false);
        setNoticeEnable(false);
        battle->battleTimer->start(100);
        battle->resume();
        scene->towerStart();
    }
    // pause option
    if (ui->noticeButtonRight->text() == "Resume")
    {
        setNoticeVisible(false);
        setNoticeEnable(false);
        battle->battleTimer->start(100);
        battle->resume();
        scene->towerStart();
    }
    // time out option
    if (ui->noticeButtonRight->text() == "Again")
    {
        ui->AITowerHP->setValue(MAXTOWERHP);
        ui->PlayerTowerHP->setValue(MAXTOWERHP);
        battle->reset();
        fireTime = 600;
        scene->playerTowerMode(0);
        scene->AITowermode(0);
        scene->showTower();
        setNoticeVisible(false);
        setNoticeEnable(false);
        battle->battleTimer->start(100);
    }
}

void GameWindow::setNoticeVisible(bool visible)
{
    ui->noticeText->setVisible(visible);
    ui->noticeButtonLeft->setVisible(visible);
    ui->noticeButtonRight->setVisible(visible);
}

void GameWindow::setNoticeEnable(bool able)
{
    ui->noticeButtonLeft->setEnabled(able);
    ui->noticeButtonRight->setEnabled(able);
    setButtonEnable(!able);
    if (!able) checkMoney();
}

void GameWindow::setButtonEnable(bool able)
{
    ui->card_1->setEnabled(able);
    ui->card_2->setEnabled(able);
    ui->card_3->setEnabled(able);
    ui->card_4->setEnabled(able);
    ui->card_5->setEnabled(able);
    ui->card_6->setEnabled(able);
    ui->card_7->setEnabled(able);
    ui->pauseButton->setEnabled(able);
    ui->quitButton->setEnabled(able);
}

void GameWindow::result(int battleResult)
{
    if (battleResult == 0) ui->noticeText->setText("! TIME OUT !");

    else if (battleResult == 1)
    {
        ui->noticeText->setText("!!! You WIN !!!");
        scene->destroyTower("AI");

        // check score and update the rank file
        int time = battle->getTime()/10;
        int score[7];
        QString player[7];

        QFile file("/home/pd2vm/2017-pd2-project-3-battle_dogs/rank.txt");
        if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
            std::cout << "Can't read the file !" << std::endl;
        QTextStream in(&file);
        int number = 0;
        while (!in.atEnd()) {
            QString line = in.readLine();
            if (number % 2 == 1) score[number/2] = line.toInt();
            else player[number/2] = line;
            number++;
            if (number == 15) break;
        }
        file.close();
        number = (number-1)/2;

        for (int i = 0; i <= number ; i++) {
            if (score[i] > time) continue;
            if (i >= 7) break;
            else {
                for (int j = number-1; j > i ; j--) {
                    score[j] = score[j-1];
                    player[j] = player[j-1];
                }
                score[i] = time;
                player[i] = playername;
                break;
            }
        }

        file.setFileName("/home/pd2vm/2017-pd2-project-3-battle_dogs/rank.txt");
        if (!file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Truncate))
            std::cout<< "Can't write the file !" << std::endl;
        QTextStream out(&file);
        if (number < 7) number++;
        for (int i = 0; i < number ; i++) {
            out << player[i] << "\n";
            out << score[i]  << "\n";
        }
        file.close();
    }
    else if (battleResult == 2)
    {
        ui->noticeText->setText("... You LOSE ...");
        scene->destroyTower("Player");
    }

    ui->noticeButtonLeft->setText("QUIT");
    ui->noticeButtonRight->setText("Again");
    setNoticeEnable(true);
    setNoticeVisible(true);
    battle->battleTimer->stop();
    battle->pause();
}

void GameWindow::playerTowerMode(int mode)
{
    scene->playerTowerMode(mode);
}

void GameWindow::AITowermode(int mode)
{
    scene->AITowermode(mode);
}

void GameWindow::fire(bool press)
{
    if (!press) {
        std::cout<<"fire!"<<std::endl;
        ui->fire_button->hide();
        fireTime = -1;
        scene->fireAnimate();
        connect(scene->fireAnimation,SIGNAL(finished()),this,SLOT(fireEnd()));
    }
}

void GameWindow::fireEnd()
{
    scene->fireEnd();
    battle->totalAttack();
    ui->fire_time->setText("60");
    ui->fire_button->setEnabled(true);
    ui->fire_button->hide();
    fireTime = 600;
}

void GameWindow::playerName(QString name)
{
    ui->name->setText(name);
    playername = name;
}
