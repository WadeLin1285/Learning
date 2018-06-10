#include "battlescene.h"
#include<iostream>

BattleScene::BattleScene()
{
    size = QSize(300,300);
    playermode = 0;
    AImode = 0;

    // set Label
    playerTower = new QLabel();
    playerTowerAttack = new QLabel();
    AITower = new QLabel();
    AITowerAttack = new QLabel();
    playerTower->setAttribute(Qt::WA_NoSystemBackground);
    playerTowerAttack->setAttribute(Qt::WA_NoSystemBackground);
    AITower->setAttribute(Qt::WA_NoSystemBackground);
    AITowerAttack->setAttribute(Qt::WA_NoSystemBackground);
    // set Movie
    playerTowerAnimation = new QMovie(PlayerTowerAnimationPath);
    playerTowerAttackAnimation = new QMovie(PlayerTowerAttackAnimationPath);
    AITowerAnimation = new QMovie(AITowerAnimationPath);
    AITowerAttackAnimation = new QMovie(AITowerAttackAnimationPath);
    playerTowerAnimation->setScaledSize(size);
    playerTowerAttackAnimation->setScaledSize(size);
    AITowerAnimation->setScaledSize(size);
    AITowerAttackAnimation->setScaledSize(size);
    // set widget
    playerTower->setMovie(playerTowerAnimation);
    playerTowerAttack->setMovie(playerTowerAttackAnimation);
    AITower->setMovie(AITowerAnimation);
    AITowerAttack->setMovie(AITowerAttackAnimation);

    playerTower->setGeometry(20,300,300,300);
    playerTowerAttack->setGeometry(20,300,300,300);
    AITower->setGeometry(MAXPOSITION-220,300,300,300);
    AITowerAttack->setGeometry(MAXPOSITION-220,300,300,300);
}

BattleScene::~BattleScene()
{
    delete playerTowerAnimation;
    delete playerTowerAttackAnimation;
    delete AITowerAnimation;
    delete AITowerAttackAnimation;
    delete playerTower;
    delete playerTowerAttack;
    delete AITower;
    delete AITowerAttack;
}

const QString BattleScene::PlayerTowerImagePath = ":/images/defaultcard.png";
const QString BattleScene::AITowerImagePath     = ":/images/20.png";
const QString BattleScene::bgImagePath = ":/images/background.jpg";
const QString BattleScene::PlayerTowerAnimationPath = ":/animates/tower-normal.gif";
const QString BattleScene::PlayerTowerAttackAnimationPath = ":/animates/tower-attack.gif";
const QString BattleScene::AITowerAnimationPath = ":/animates/tower-normal-2.gif";
const QString BattleScene::AITowerAttackAnimationPath = ":/animates/tower-attack-2.gif";
const QString BattleScene::bgAnimationPath = "";

QPixmap BattleScene::initBackground()
{
    bgImage.load(bgImagePath);
    bgImage = bgImage.scaled(1300,900);
    this->addPixmap(bgImage);
    return bgImage;
}

void BattleScene::initPlayerTower()
{

    this->addWidget(playerTower);
    this->addWidget(playerTowerAttack);
    playerTowerAnimation->start();
    playerTowerAttackAnimation->start();
    playerTower->show();
    playerTowerAttack->hide();
    /*
    playerTower = new Card();
    PlayerTowerImage.load(PlayerTowerImagePath);
    PlayerTowerImage = PlayerTowerImage.scaled(200,200,Qt::KeepAspectRatio);
    playerTower->setPixmap(PlayerTowerImage);
    playerTower->setPos(0,YPOSITION-200);
    this->addItem(playerTower);
    */
}

void BattleScene::initAITower()
{
    this->addWidget(AITower);
    this->addWidget(AITowerAttack);
    AITowerAnimation->start();
    AITowerAttackAnimation->start();
    AITower->show();
    AITowerAttack->hide();
    /*
    AITower = new Card();
    AITowerImage.load(AITowerImagePath);
    AITowerImage = AITowerImage.scaled(200,200,Qt::KeepAspectRatio);
    AITower->setPixmap(AITowerImage);
    AITower->setPos(MAXPOSITION-200,YPOSITION-200);
    this->addItem(AITower);
    */
}

void BattleScene::towerStop()
{
    playerTowerAnimation->setPaused(true);
    playerTowerAttackAnimation->setPaused(true);
    AITowerAnimation->setPaused(true);
    AITowerAttackAnimation->setPaused(true);
}

void BattleScene::towerStart()
{
    playerTowerAnimation->setPaused(false);
    playerTowerAttackAnimation->setPaused(false);
    AITowerAnimation->setPaused(false);
    AITowerAttackAnimation->setPaused(false);
}

void BattleScene::conti()
{
    if (playermode == 0) playerTowerAnimation->start();
    else if (playermode == 1) playerTowerAttackAnimation->start();
    if (AImode == 0) AITowerAnimation->start();
    else if (AImode == 1) AITowerAttackAnimation->start();
}

void BattleScene::playerTowerMode(int mode)
{
    if (mode == 0) // normal tower
    {
        playerTowerAnimation->start();
        playerTowerAttackAnimation->stop();
        playerTower->show();
        playerTowerAttack->hide();
        playermode = 0;
    }
    if (mode == 1) // attack tower
    {
        playerTowerAnimation->stop();
        playerTowerAttackAnimation->start();
        playerTower->hide();
        playerTowerAttack->show();
        playermode = 1;
    }
}

void BattleScene::AITowermode(int mode)
{
    if (mode == 0) // normal tower
    {
        AITowerAnimation->start();
        AITowerAttackAnimation->stop();
        AITower->show();
        AITowerAttack->hide();
        AImode = 0;
    }
    if (mode == 1) // attack tower
    {
        AITowerAnimation->stop();
        AITowerAttackAnimation->start();
        AITower->hide();
        AITowerAttack->show();
        AImode = 1;
    }
}

void BattleScene::destroyTower(QString tower)
{
    playerTowerAnimation->stop();
    playerTowerAttackAnimation->stop();
    AITowerAnimation->stop();
    AITowerAttackAnimation->stop();
    if (tower == "AI")
    {
        if (!AITower->isHidden())       AITower->hide();
        if (!AITowerAttack->isHidden()) AITowerAttack->hide();
    }
    if (tower == "Player")
    {
        if (!playerTower->isHidden())       playerTower->hide();
        if (!playerTowerAttack->isHidden()) playerTowerAttack->hide();
    }
}
