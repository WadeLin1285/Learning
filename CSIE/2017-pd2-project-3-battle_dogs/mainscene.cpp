#include "mainscene.h"

MainScene::MainScene()
{
    initMinionCard();
}
QPixmap MainScene::initBackground(const QString &imagepath)
{
    bgimage.load(imagepath);
    bgimage = bgimage.scaled(1200,880);
    return bgimage;
}

void MainScene::initShadow()
{
    shadow_1 = new Card();
    shadow_2 = new Card();
    shadow_3 = new Card();
    shadow_4 = new Card();
    shadowimage.load(":/images/shadow.png");
    shadowimage = shadowimage.scaled(200,200,Qt::KeepAspectRatio);
    shadow_1->setPixmap(shadowimage);
    shadow_1->setPos(490,350);
    shadowimage = shadowimage.scaled(250,250,Qt::KeepAspectRatio);
    shadow_2->setPixmap(shadowimage);
    shadow_2->setPos(460,350);
    shadowimage = shadowimage.scaled(400,120);
    shadow_3->setPixmap(shadowimage);
    shadow_3->setPos(400,340);
    shadowimage = shadowimage.scaled(150,150,Qt::KeepAspectRatio);
    shadow_4->setPixmap(shadowimage);
    shadow_4->setPos(510,400);
    addItem(shadow_1);
    addItem(shadow_2);
    addItem(shadow_3);
    addItem(shadow_4);
    shadow_1->hide();
    shadow_2->hide();
    shadow_3->hide();
    shadow_4->hide();
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
    case 11:mimage.load(Card::cardpath_11);break;
    case 12:mimage.load(Card::cardpath_12);break;
    case 13:mimage.load(Card::cardpath_13);break;
    case 14:mimage.load(Card::cardpath_14);break;
    case 15:mimage.load(Card::cardpath_15);break;
    case 16:mimage.load(Card::cardpath_16);break;
    case 17:mimage.load(Card::cardpath_17);break;
    case 18:mimage.load(Card::cardpath_18);break;
    case 19:mimage.load(Card::cardpath_19);break;
    case 20:mimage.load(Card::cardpath_20);break;

    default :mimage.load(Card::defaultpath);break;
    }
    mimage = mimage.scaled(150,150,Qt::KeepAspectRatio);
    switch(cardpos){
    case 1:
        displaycard_1->setPixmap(mimage);
        displaycard_1->setPos(pos_x[cardpos],pos_y[cardpos]);
        break;
    case 2:
        displaycard_2->setPixmap(mimage);
        displaycard_2->setPos(pos_x[cardpos],pos_y[cardpos]);
        break;
    case 3:
        displaycard_3->setPixmap(mimage);
        displaycard_3->setPos(pos_x[cardpos],pos_y[cardpos]);
        break;
    case 4:
        displaycard_4->setPixmap(mimage);
        displaycard_4->setPos(pos_x[cardpos],pos_y[cardpos]);
        break;
    case 5:
        displaycard_5->setPixmap(mimage);
        displaycard_5->setPos(pos_x[cardpos],pos_y[cardpos]);
        break;
    case 6:
        displaycard_6->setPixmap(mimage);
        displaycard_6->setPos(pos_x[cardpos],pos_y[cardpos]);
        break;
    case 7:
        displaycard_7->setPixmap(mimage);
        displaycard_7->setPos(pos_x[cardpos],pos_y[cardpos]);
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
