#include "battlescene.h"
#include<iostream>

BattleScene::BattleScene()
{
    size = QSize(300,300);
    size2 = QSize(1200,850);
    playermode = 0;
    AImode = 0;

    // set Label
    //playerTower = new QLabel();
    playerTowerAttack = new QLabel();
    //AITower = new QLabel();
    AITowerAttack = new QLabel();
    fire = new QLabel();
    //playerTower->setAttribute(Qt::WA_NoSystemBackground);
    playerTowerAttack->setAttribute(Qt::WA_NoSystemBackground);
    //AITower->setAttribute(Qt::WA_NoSystemBackground);
    AITowerAttack->setAttribute(Qt::WA_NoSystemBackground);
    fire->setAttribute(Qt::WA_NoSystemBackground);
    // set Movie
    //playerTowerAnimation = new QMovie(PlayerTowerAnimationPath);
    playerTowerAttackAnimation = new QMovie(PlayerTowerAttackAnimationPath);
    //AITowerAnimation = new QMovie(AITowerAnimationPath);
    AITowerAttackAnimation = new QMovie(AITowerAttackAnimationPath);
    fireAnimation = new QMovie(FireAnimationPath);
    //playerTowerAnimation->setScaledSize(size);
    playerTowerAttackAnimation->setScaledSize(size);
    //AITowerAnimation->setScaledSize(size);
    AITowerAttackAnimation->setScaledSize(size);
    fireAnimation->setScaledSize(size2);
    // set widget
    //playerTower->setMovie(playerTowerAnimation);
    playerTowerAttack->setMovie(playerTowerAttackAnimation);
    //AITower->setMovie(AITowerAnimation);
    AITowerAttack->setMovie(AITowerAttackAnimation);
    fire->setMovie(fireAnimation);

    //playerTower->setGeometry(20,250,300,300);
    playerTowerAttack->setGeometry(20,250,300,300);
    //AITower->setGeometry(MAXPOSITION-220,250,300,300);
    AITowerAttack->setGeometry(MAXPOSITION-220,250,300,300);
    fire->setGeometry(50,0,1000,800);

    playerTower = NULL;
    AITower = NULL;
    playerTowerAnimation = NULL;
    AITowerAnimation = NULL;
}

BattleScene::~BattleScene()
{
    delete playerTowerAnimation;
    delete playerTowerAttackAnimation;
    delete AITowerAnimation;
    delete AITowerAttackAnimation;
    delete fireAnimation;
    delete playerTower;
    delete playerTowerAttack;
    delete AITower;
    delete AITowerAttack;
    delete fire;
}

const QString BattleScene::PlayerTowerImagePath = ":/images/defaultcard.png";
const QString BattleScene::AITowerImagePath     = ":/images/20.png";
const QString BattleScene::bgImagePath = ":/images/background.jpg";
const QString BattleScene::PlayerTowerAnimationPath = ":/animates/tower-normal.gif";
const QString BattleScene::PlayerTowerAttackAnimationPath = ":/animates/tower-attack.gif";
const QString BattleScene::AITowerAnimationPath = ":/animates/tower-normal-2.gif";
const QString BattleScene::AITowerAttackAnimationPath = ":/animates/tower-attack-2.gif";
const QString BattleScene::bgAnimationPath = "";
const QString BattleScene::FireAnimationPath = ":/animates/fire.gif";

QPixmap BattleScene::initBackground()
{
    bgImage.load(bgImagePath);
    bgImage = bgImage.scaled(1300,850);
    this->addPixmap(bgImage);
    return bgImage;
}

void BattleScene::initPlayerTower()
{

    //this->addWidget(playerTower);
    this->addWidget(playerTowerAttack);
    //playerTowerAnimation->start();
    playerTowerAttackAnimation->start();
    //playerTowerAnimation->stop();
    playerTowerAttackAnimation->stop();
    //playerTower->show();
    //playerTowerAttack->hide();
    playerTowerAttack->show();
}

void BattleScene::initAITower()
{
    //this->addWidget(AITower);
    this->addWidget(AITowerAttack);
    //AITowerAnimation->start();
    AITowerAttackAnimation->start();
    //AITowerAnimation->stop();
    AITowerAttackAnimation->stop();
    //AITower->show();
    //AITowerAttack->hide();
    AITowerAttack->show();
}

void BattleScene::initMagic()
{
    this->addWidget(fire);
    fireAnimation->start();
    fireAnimation->stop();
    fire->hide();
}

void BattleScene::towerStop()
{
    //playerTowerAnimation->setPaused(true);
    if (playermode == 1) playerTowerAttackAnimation->setPaused(true);
    //AITowerAnimation->setPaused(true);
    if (AImode == 1) AITowerAttackAnimation->setPaused(true);
}

void BattleScene::towerStart()
{
    //playerTowerAnimation->setPaused(false);
    if (playermode == 1) playerTowerAttackAnimation->setPaused(false);
    //AITowerAnimation->setPaused(false);
    if (AImode == 1) AITowerAttackAnimation->setPaused(false);
}

void BattleScene::fireAnimate()
{
    fireAnimation->start();
    fire->show();
}

void BattleScene::fireEnd()
{
    fireAnimation->stop();
    fire->hide();
}

void BattleScene::playerTowerMode(int mode)
{
    if (mode == 0) // normal tower
    {
        //playerTowerAnimation->start();
        playerTowerAttackAnimation->stop();
        playerTowerAttackAnimation->start();
        playerTowerAttackAnimation->stop();
        //playerTower->show();
        //playerTowerAttack->hide();
        playermode = 0;
    }
    if (mode == 1) // attack tower
    {
        //playerTowerAnimation->stop();
        playerTowerAttackAnimation->start();
        //playerTower->hide();
        //playerTowerAttack->show();
        playermode = 1;
    }
}

void BattleScene::AITowermode(int mode)
{
    if (mode == 0) // normal tower
    {
        //AITowerAnimation->start();
        AITowerAttackAnimation->stop();
        AITowerAttackAnimation->start();
        AITowerAttackAnimation->stop();
        //AITower->show();
        //AITowerAttack->hide();
        AImode = 0;
    }
    if (mode == 1) // attack tower
    {
        //AITowerAnimation->stop();
        AITowerAttackAnimation->start();
        //AITower->hide();
        //AITowerAttack->show();
        AImode = 1;
    }
}

void BattleScene::destroyTower(QString tower)
{
    //playerTowerAnimation->stop();
    playerTowerAttackAnimation->stop();
    //AITowerAnimation->stop();
    AITowerAttackAnimation->stop();
    if (tower == "AI")
    {
        AITowerAttack->hide();
        //if (!AITower->isHidden())       AITower->hide();
        //if (!AITowerAttack->isHidden()) AITowerAttack->hide();
    }
    if (tower == "Player")
    {
        playerTowerAttack->hide();
        //if (!playerTower->isHidden())       playerTower->hide();
        //if (!playerTowerAttack->isHidden()) playerTowerAttack->hide();
    }
}

void BattleScene::showTower()
{
    AITowerAttack->show();
    playerTowerAttack->show();
}
