#include"battle.h"
#include<iostream>

#define GAMETIME 5*60*10
#define TOWERRANGE 300
#define TOWERATTACK 10

Battle::Battle(BattleScene *battlescene) : scene(battlescene)
{
    // set Timer
    battleTimer = new QTimer;
    battleTimer->setTimerType(Qt::PreciseTimer);
    // set AI
    Ai = new AI();
    // connect the battle loop singal to function
    connect(battleTimer,SIGNAL(timeout()),this,SLOT(battling()));
    connect(this,SIGNAL(b()),this,SLOT(battling()));

    battleStart();
}

void Battle::addMinion(const int minionNum,int minionGroup,int minionPosition)
{
    //std::cout << "add Minion " << minionNum <<std::endl;
    Minion *m;
    int n = minionList[minionPosition].size();

    // add minion
    if (minionNum == 1) m = new Doggy(scene,minionGroup,minionPosition);
    else if (minionNum == 2)      m = new Soldier(scene,minionGroup,minionPosition);
    else if (minionNum == 3)      m = new Tall(scene,minionGroup,minionPosition);
    else if (minionNum == 4)      m = new Dox(scene,minionGroup,minionPosition);
    else if (minionNum == 5)      m = new Dragon(scene,minionGroup,minionPosition);
    else if (minionNum == 6)      m = new Ancient(scene,minionGroup,minionPosition);
    else if (minionNum == 7)      m = new Commander(scene,minionGroup,minionPosition);
    else if (minionNum == 8)      m = new TallEX(scene,minionGroup,minionPosition);
    else if (minionNum == 9)      m = new Ninetail(scene,minionGroup,minionPosition);
    else if (minionNum == 10)     m = new Catnon(scene,minionGroup,minionPosition);

    minionList[minionPosition].push_back(*m);
    // check for the addition of minion
    if (n < minionList[minionPosition].size())
    {
        if (minionGroup == 1) money -= m->getCost(); // money consumed
        emit newMinion(minionPosition,minionList[minionPosition].size()-1);
    }
}

void Battle::printList()
{
    for (int i = 0; i <MAXPOSITION; ++i)
    {
        //std::cout << "Position " << i << " : ";
        QVector <Minion> mini_list = minionList[i];
            for (int j = 0; j < mini_list.size() ; j++)
            {
                std::cout << mini_list.at(j).getHP();
            }
            std::cout<<".";
        //std::cout << std::endl;
    }
    std::cout << std::endl;
}

int  Battle::time = GAMETIME+50; // initial 5 minute (unit:0.1s)
void Battle::setTime(int t){ time = t; }
int  Battle::getTime()const{ return time;}
int  Battle::getMoney()const{ return money;}

void Battle::battleStart()
{
    std::cout<<"Battle Start!!"<<std::endl;
    battleTimer->start(100);
}

void Battle::battleReset()
{
    time = GAMETIME+50;
    money = 0;
    P1_HP = 2000;
    AI_HP = 2000;
    battleTimer->start();
}

int Battle::money = 0; // initial 100 coins
int Battle::moneyAdd = 20; // gererate 10 coins per second
int Battle::P1_HP = 6000; // player initial healthpoint
int Battle::AI_HP = 6000; // AI computer intial healthpoint
int Battle::playerTowerMode = 0;
int Battle::AITowerMode = 0;
void Battle::battling()
{
    // count down for 4 sec
    if (time > GAMETIME)
    {
        emit countDown(time-GAMETIME);
        time--;
        return;
    }
    else if (time == GAMETIME) emit countDown(0);
    // check the time remain
    if (time  == 0) emit end(0);
    // check AI's HP
    if (AI_HP <= 0) emit end(1);
    // check the player's HP
    if (P1_HP <= 0) emit end(2);
    // time elapse
    time -= 1;
    // momey generate
    if ((time%10) == 0) money += moneyAdd;
    /************************************* MINION ACTION START ***********************************************/
    for (int mini_pos = 0; mini_pos <MAXPOSITION; mini_pos++) // MINIONLIST
    { 
        for (int mini_order = 0; mini_order < minionList[mini_pos].size() ; mini_order++) // QVector<Minion>
        {
            // check if minion have already modified
            if (minionList[mini_pos][mini_order].getRecord()) continue;
            // check the minion's hp
            if (minionList[mini_pos][mini_order].getHP() <= 0)
            {
                minionList[mini_pos][mini_order].dead();
                minionList[mini_pos].remove(mini_order);
                mini_order--; // after delete the element, the list re-arrange
                continue;
            }
            // store minion's data
            int mini_atkr = minionList[mini_pos][mini_order].getAttackRange();
            int mini_atk  = minionList[mini_pos][mini_order].getAP();
            int mini_gp   = minionList[mini_pos][mini_order].getGP();
            int mini_ws   = minionList[mini_pos][mini_order].getWalkingSpeed();
            bool enemy = false;  // enemy exists or not
            int enemy_pos = 0;   // enemy's position in Array
            int enemy_order = 0; // enemy's order in QVector list
             /*********** PLAYER **************/
            if (mini_gp == 1)
            {
                // find enemy and set target
                for (int k = mini_pos; k <= (mini_pos+mini_atkr) ; ++k) // MINIONLIST
                {
                    //search each minion in mini_list with position k
                    for (int g = 0; g < minionList[k].size() ; ++g) // QVector<Minion>
                    {
                        if (minionList[k][g].getGP() == 2 &&
                                (!enemy || minionList[k][g].getHP() < minionList[k][enemy_order].getHP()))
                            // if find the 1st enemy or new enemy has lower HP, update the enemy data
                        {
                            enemy_pos = k;
                            enemy_order = g;
                            enemy = true;
                        }
                    }
                    if (enemy) break;
                }
                // minion action
                if (enemy) // attack
                {
                    minionList[enemy_pos][enemy_order].injury(mini_atk);
                    minionList[mini_pos][mini_order].setState(1);
                }
                else // no enemy
                {
                    // minion arrive at enemy's castle
                    if (mini_pos >= (MAXPOSITION-200-mini_atkr))
                    {
                        AI_HP -= mini_atk;
                        minionList[mini_pos][mini_order].setState(1);
                    }
                    // walk
                    else
                    {
                        //minionList[mini_pos][mini_order].setPosition(mini_pos+mini_ws);
                        minionList[mini_pos][mini_order].setRecord(true);
                        minionList[mini_pos][mini_order].setState(0);
                        minionList[mini_pos+mini_ws].push_back(minionList[mini_pos][mini_order]);
                        minionList[mini_pos].remove(mini_order);
                        mini_order--; // one item moved
                    }
                }
            }
            /************   AI   **************/
            else if (mini_gp == 2)
                {
                // find enemy and set target
                for (int k = mini_pos; k >= (mini_pos-mini_atkr) ; --k) // MINIONLIST
                {
                    //search each minion in mini_list with position k
                    for (int g = 0; g < minionList[k].size() ; ++g) // QVector<Minion>
                    {
                        if (minionList[k][g].getGP() == 1 &&
                                (!enemy || minionList[k][g].getHP() < minionList[k][enemy_order].getHP()))
                            // if find the 1st enemy or new enemy has lower HP, update the enemy data
                        {
                            enemy_pos = k;
                            enemy_order = g;
                            enemy = true;
                        }
                    }
                    if (enemy) break;
                }
                // minion action
                if (enemy) // attack
                {
                    minionList[enemy_pos][enemy_order].injury(mini_atk);
                    minionList[mini_pos][mini_order].setState(1);
                }
                else // no enemy
                {
                    // minion arrive at enemy's castle
                    if (mini_pos <= (200+mini_atkr))
                    {
                        P1_HP -= mini_atk;
                        minionList[mini_pos][mini_order].setState(1);
                    }
                    // walk
                    else
                    {
                        //minionList[mini_pos][mini_order].setPosition(mini_pos-mini_ws);
                        minionList[mini_pos][mini_order].setRecord(true);
                        minionList[mini_pos][mini_order].setState(0);
                        minionList[mini_pos-mini_ws].push_back(minionList[mini_pos][mini_order]);
                        minionList[mini_pos].remove(mini_order);
                        mini_order--;
                    }
                }
            }
        }
    }
    /*************************************** TOWER ATTCK START *********************************************/
    bool tower_enemy = false;  // enemy exists or not
    int tower_enemy_pos = 0;   // enemy's position in Array
    int tower_enemy_order = 0; // enemy's order in QVector list

    /************** Player's tower ************/
    for (int mini_pos = 0; mini_pos <TOWERRANGE; mini_pos++) // MINIONLIST
    {
        for (int mini_order = 0; mini_order < minionList[mini_pos].size() ; mini_order++) // QVector<Minion>
        {
            if (minionList[mini_pos][mini_order].getGP() == 2 &&
                    (!tower_enemy || minionList[mini_pos][mini_order].getHP() < minionList[mini_pos][tower_enemy_order].getHP()))
                // if find the 1st enemy or new enemy has lower HP, update the enemy data
            {
                tower_enemy_pos = mini_pos;
                tower_enemy_order = mini_order;
                tower_enemy = true;
            }
        }
        if (tower_enemy) break;
    }
    if (tower_enemy)
    {
        minionList[tower_enemy_pos][tower_enemy_order].injury(TOWERATTACK); // tower attack
        if (playerTowerMode == 0) emit playerTowerModeChange(1);
        playerTowerMode = 1;   // attack mode
    }
    else
    {
        if (playerTowerMode == 1) emit playerTowerModeChange(0);
        playerTowerMode = 0;  // normal mode
    }

    // reset the variables
    tower_enemy = false;
    tower_enemy_pos = 0;
    tower_enemy_order = 0;
    /*********** AI's tower ***********/
    for (int mini_pos = MAXPOSITION; mini_pos > (MAXPOSITION-TOWERRANGE); mini_pos--) // MINIONLIST
    {
        for (int mini_order = 0; mini_order < minionList[mini_pos].size() ; mini_order++) // QVector<Minion>
        {
            if (minionList[mini_pos][mini_order].getGP() == 1 &&
                    (!tower_enemy || minionList[mini_pos][mini_order].getHP() < minionList[mini_pos][tower_enemy_order].getHP()))
                // if find the 1st enemy or new enemy has lower HP, update the enemy data
            {
                tower_enemy_pos = mini_pos;
                tower_enemy_order = mini_order;
                tower_enemy = true;
            }
        }
        if (tower_enemy) break;
    }
    if (tower_enemy)
    {
        minionList[tower_enemy_pos][tower_enemy_order].injury(TOWERATTACK); // tower attack
        if (AITowerMode == 0) emit AITowerModeChange(1);
        AITowerMode = 1;   // attack mode
    }
    else
    {
        if (AITowerMode == 1) emit AITowerModeChange(0);
        AITowerMode = 0;  // normal mode
    }
    /******************************************* ACTION DONE ***********************************************/
    if(Ai->action(time) != 0) addMinion(Ai->action(time),2,MAXPOSITION-150);
    emit battlingEnd();
}

void Battle::updateMinion(){
    // update the minion's position
    for (int mini_pos = 0; mini_pos <MAXPOSITION; mini_pos++) // MINIONLIS
        for (int mini_order = 0; mini_order < minionList[mini_pos].size() ; mini_order++) // QVector<Minion>
            if (minionList[mini_pos][mini_order].getPosition() != mini_pos)
                minionList[mini_pos][mini_order].setPosition(mini_pos);
    // set the record of all minions to false
    for (int mini_pos = 0; mini_pos <MAXPOSITION; mini_pos++) // MINIONLIST
    {
        for (int mini_order = 0; mini_order < minionList[mini_pos].size() ; mini_order++) // QVector<Minion>
            minionList[mini_pos][mini_order].recordErase();
        minionList[mini_pos].squeeze();
    }
}

void Battle::pause()
{
    for (int mini_pos = 0; mini_pos <MAXPOSITION; mini_pos++) // MINIONLIS
        for (int mini_order = 0; mini_order < minionList[mini_pos].size() ; mini_order++) // QVector<Minion>
                minionList[mini_pos][mini_order].minionAnimate->pause();
}

void Battle::resume()
{
    for (int mini_pos = 0; mini_pos <MAXPOSITION; mini_pos++) // MINIONLIS
        for (int mini_order = 0; mini_order < minionList[mini_pos].size() ; mini_order++) // QVector<Minion>
                minionList[mini_pos][mini_order].minionAnimate->resume();
}

void Battle::reset()
{
    for (int mini_pos = 0; mini_pos <MAXPOSITION; mini_pos++) // MINIONLIST
    {
        for (int mini_order = 0; mini_order < minionList[mini_pos].size() ; mini_order++) // QVector<Minion>
        {
            minionList[mini_pos][mini_order].dead();
            minionList[mini_pos].remove(mini_order);
            mini_order--; // after delete the element, the list re-arrange
        }
    }
    battleReset();
}

// mode 0 for normal state ; mode 1 for attack state
int  Battle::getPlayerTowerMode()const{ return playerTowerMode; }
int  Battle::getAITowerMode()    const{ return AITowerMode;     }
