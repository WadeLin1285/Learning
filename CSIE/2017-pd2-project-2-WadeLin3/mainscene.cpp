#include "mainscene.h"

MainScene::MainScene()
{
    initMinionCard();
}
QPixmap MainScene::initBackground(const QString &imagepath)
{
    bgimage.load(imagepath);
    bgimage = bgimage.scaled(1200,900);
    return bgimage;
}

void MainScene::initMinionCard()
{
    displaycard_1 = new Card();
    displaycard_2 = new Card();
    displaycard_3 = new Card();
    displaycard_4 = new Card();
    displaycard_5 = new Card();
    displaycard_6 = new Card();
    displaycard_7 = new Card();
    for (int i = 1; i < 8 ; ++i ) addMinionCard(0,i);
    addItem(displaycard_1);
    addItem(displaycard_2);
    addItem(displaycard_3);
    addItem(displaycard_4);
    addItem(displaycard_5);
    addItem(displaycard_6);
    addItem(displaycard_7);
}

void MainScene::addMinionCard(int cardnum,int cardpos)
{
    switch(cardnum){
    case 1: mimage.load(Card::cardpath_1);break;
    case 2: mimage.load(Card::cardpath_2);break;
    case 3: mimage.load(Card::cardpath_3);break;
    case 4: mimage.load(Card::cardpath_4);break;
    case 5: mimage.load(Card::cardpath_5);break;
    case 6: mimage.load(Card::cardpath_6);break;
    case 7: mimage.load(Card::cardpath_7);break;
    case 8: mimage.load(Card::cardpath_8);break;
    case 9: mimage.load(Card::cardpath_9);break;
    case 10:mimage.load(Card::cardpath_10);break;

    default :mimage.load(Card::defaultpath);break;
    }
    mimage = mimage.scaled(150,150,Qt::KeepAspectRatio);
    switch(cardpos){
    case 1:
        displaycard_1->setPixmap(mimage);
        displaycard_1->setPos(pos_x[cardpos],pos_y[cardpos]);
        //addItem(displaycard_1);
        break;
    case 2:
        displaycard_2->setPixmap(mimage);
        displaycard_2->setPos(pos_x[cardpos],pos_y[cardpos]);
        //addItem(displaycard_2);
        break;
    case 3:
        displaycard_3->setPixmap(mimage);
        displaycard_3->setPos(pos_x[cardpos],pos_y[cardpos]);
        //addItem(displaycard_3);
        break;
    case 4:
        displaycard_4->setPixmap(mimage);
        displaycard_4->setPos(pos_x[cardpos],pos_y[cardpos]);
        //addItem(displaycard_4);
        break;
    case 5:
        displaycard_5->setPixmap(mimage);
        displaycard_5->setPos(pos_x[cardpos],pos_y[cardpos]);
        //addItem(displaycard_5);
        break;
    case 6:
        displaycard_6->setPixmap(mimage);
        displaycard_6->setPos(pos_x[cardpos],pos_y[cardpos]);
        //addItem(displaycard_6);
        break;
    case 7:
        displaycard_7->setPixmap(mimage);
        displaycard_7->setPos(pos_x[cardpos],pos_y[cardpos]);
        //addItem(displaycard_7);
        break;
    }
}

void MainScene::deleteMinionCard(int cardpos)
{
    mimage.load(Card::defaultpath);
    mimage = mimage.scaled(150,150,Qt::KeepAspectRatio);
    if (cardpos == 1 && displaycard_1 != NULL) displaycard_1->setPixmap(mimage);
    if (cardpos == 2 && displaycard_1 != NULL) displaycard_2->setPixmap(mimage);
    if (cardpos == 3 && displaycard_1 != NULL) displaycard_3->setPixmap(mimage);
    if (cardpos == 4 && displaycard_1 != NULL) displaycard_4->setPixmap(mimage);
    if (cardpos == 5 && displaycard_1 != NULL) displaycard_5->setPixmap(mimage);
    if (cardpos == 6 && displaycard_1 != NULL) displaycard_6->setPixmap(mimage);
    if (cardpos == 7 && displaycard_1 != NULL) displaycard_7->setPixmap(mimage);
}
