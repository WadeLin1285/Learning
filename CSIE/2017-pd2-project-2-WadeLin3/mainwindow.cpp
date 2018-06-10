#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "card.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);    
    reset();
    setButtomEnable(false);
    scene = new MainScene();
    setBackgroundScene(":/images/background.jpg");
    scene->initMinionCard();
    ui->card_1->setCheckable(true);
    ui->card_2->setCheckable(true);
    ui->card_3->setCheckable(true);
    ui->card_4->setCheckable(true);
    ui->card_5->setCheckable(true);
    ui->card_6->setCheckable(true);
    ui->card_7->setCheckable(true);
    ui->card_8->setCheckable(true);
    //ui->card_9->setCheckable(true);
    ui->card_10->setCheckable(true);

    ui->playButton->setEnabled(false);
    connect(ui->card_1,SIGNAL(toggled(bool)) ,this,SLOT (PressButton1(bool)));
    connect(ui->card_2,SIGNAL(toggled(bool)) ,this,SLOT (PressButton2(bool)));
    connect(ui->card_3,SIGNAL(toggled(bool)) ,this,SLOT (PressButton3(bool)));
    connect(ui->card_4,SIGNAL(toggled(bool)) ,this,SLOT (PressButton4(bool)));
    connect(ui->card_5,SIGNAL(toggled(bool)) ,this,SLOT (PressButton5(bool)));
    connect(ui->card_6,SIGNAL(toggled(bool)) ,this,SLOT (PressButton6(bool)));
    connect(ui->card_7,SIGNAL(toggled(bool)) ,this,SLOT (PressButton7(bool)));
    connect(ui->card_8,SIGNAL(toggled(bool)) ,this,SLOT (PressButton8(bool)));
    //connect(ui->card_9,SIGNAL(toggled(bool)) ,this,SLOT (PressButton9(bool)));
    connect(ui->card_10,SIGNAL(toggled(bool)) ,this,SLOT (PressButton10(bool)));

    ui->card_display_1->setText("Unknown");
    ui->card_display_2->setText("Unknown");
    ui->card_display_3->setText("Unknown");
    ui->card_display_4->setText("Unknown");
    ui->card_display_5->setText("Unknown");
    ui->card_display_6->setText("Unknown");
    ui->card_display_7->setText("Unknown");
    ui->card_display_1->setAlignment(Qt::AlignCenter);
    ui->card_display_2->setAlignment(Qt::AlignCenter);
    ui->card_display_3->setAlignment(Qt::AlignCenter);
    ui->card_display_4->setAlignment(Qt::AlignCenter);
    ui->card_display_5->setAlignment(Qt::AlignCenter);
    ui->card_display_6->setAlignment(Qt::AlignCenter);
    ui->card_display_7->setAlignment(Qt::AlignCenter);
    connect(ui->playButton,SIGNAL(pressed()) ,this,SLOT (OpenGameWindow()));
    connect(ui->lineEdit,SIGNAL(textChanged(const QString &)),this,SLOT(setName(const QString &)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setName(const QString &name)
{
    setButtomEnable(true);
    ui->player->setText(name);
    playername = name;
}

QString MainWindow::name() const
{
    return ui->lineEdit->text();
}

void MainWindow::PressButton1(bool state)
{
    if (state == true) ;//ui->card_1->setText("Seleted");
    else{ui->card_1->setIcon(QIcon(Card::cardpath_1));ui->card_1->setIconSize(QSize(150,150));}
    SelectedCard(1);
}
void MainWindow::PressButton2(bool state)
{
    if (state == true) ;//ui->card_2->setText("Seleted");
    else{ui->card_2->setIcon(QIcon(Card::cardpath_2));ui->card_2->setIconSize(QSize(150,150));}
    SelectedCard(2);
}
void MainWindow::PressButton3(bool state)
{
    if (state == true) ;//ui->card_3->setText("Seleted");
    else {ui->card_3->setIcon(QIcon(Card::cardpath_3));ui->card_3->setIconSize(QSize(150,150));}
    SelectedCard(3);
}
void MainWindow::PressButton4(bool state)
{
    if (state == true) ;//ui->card_4->setText("Seleted");
    else {ui->card_4->setIcon(QIcon(Card::cardpath_4));ui->card_4->setIconSize(QSize(150,150));}
    SelectedCard(4);
}
void MainWindow::PressButton5(bool state)
{
    if (state == true) ;//ui->card_5->setText("Seleted");
    else {ui->card_5->setIcon(QIcon(Card::cardpath_5));ui->card_5->setIconSize(QSize(150,150));}
    SelectedCard(5);
}
void MainWindow::PressButton6(bool state)
{
    if (state == true) ;//ui->card_6->setText("Seleted");
    else {ui->card_6->setIcon(QIcon(Card::cardpath_6));ui->card_6->setIconSize(QSize(150,150));}
    SelectedCard(6);
}
void MainWindow::PressButton7(bool state)
{
    if (state == true) ;//ui->card_7->setText("Seleted");
    else {ui->card_7->setIcon(QIcon(Card::cardpath_7));ui->card_7->setIconSize(QSize(150,150));}
    SelectedCard(7);
}
void MainWindow::PressButton8(bool state)
{
    if (state == true) ;//ui->card_8->setText("Seleted");
    else {ui->card_8->setIcon(QIcon(Card::cardpath_8));ui->card_8->setIconSize(QSize(150,150));};
    SelectedCard(8);
}
/*
void MainWindow::PressButton9(bool state)
{
    if (state == true) ;//ui->card_9->setText("Seleted");
    else {ui->card_9->setIcon(QIcon(Card::cardpath_9));ui->card_9->setIconSize(QSize(150,150));}
    SelectedCard(9);
}
*/
void MainWindow::PressButton10(bool state)
{
    if (state == true) ;//ui->card_10->setText("Seleted");
    else {ui->card_10->setIcon(QIcon(Card::cardpath_10));ui->card_10->setIconSize(QSize(150,150));}
    SelectedCard(10);
}


int  MainWindow::SelectedC[7]={0,0,0,0,0,0,0};
void MainWindow::SelectedCard(int card)
{
    int position = 0;
    // find the input card exists or not
    if (SelectedC[0] == card) position = 1;
    if (SelectedC[1] == card) position = 2;
    if (SelectedC[2] == card) position = 3;
    if (SelectedC[3] == card) position = 4;
    if (SelectedC[4] == card) position = 5;
    if (SelectedC[5] == card) position = 6;
    if (SelectedC[6] == card) position = 7;

    // set the selected card
    if (position == 0){
        for (int i = 0; i<7 ; ++i)
            if (SelectedC[i] == 0){
                SelectedC[i] = card;
                scene->addMinionCard(card,i+1);
                break;
            }
    }
    else {
        if (position == 1){
            SelectedC[0] = 0;
            scene->deleteMinionCard(1);
        }
        if (position == 2){
            SelectedC[1] = 0;
            scene->deleteMinionCard(2);
        }
        if (position == 3){
            SelectedC[2] = 0;
            scene->deleteMinionCard(3);
        }
        if (position == 4){
            SelectedC[3] = 0;
            scene->deleteMinionCard(4);
        }
        if (position == 5){
            SelectedC[4] = 0;
            scene->deleteMinionCard(5);
        }
        if (position == 6){
            SelectedC[5] = 0;
            scene->deleteMinionCard(6);
        }
        if (position == 7) {
            SelectedC[6] = 0;
            scene->deleteMinionCard(7);
        }
    }
    // display the card
    displayCards();
    // checked the number of selected card
    int n = 0,Check[20]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    for (int i = 0; i < 7 ; ++i)
        if (SelectedC[i] != 0){
            n++;
            Check[SelectedC[i]-1] = 1;
        }
    if (n >= 7){
        if (Check[0] == 0) ui->card_1->setEnabled(false);
        if (Check[1] == 0) ui->card_2->setEnabled(false);
        if (Check[2] == 0) ui->card_3->setEnabled(false);
        if (Check[3] == 0) ui->card_4->setEnabled(false);
        if (Check[4] == 0) ui->card_5->setEnabled(false);
        if (Check[5] == 0) ui->card_6->setEnabled(false);
        if (Check[6] == 0) ui->card_7->setEnabled(false);
        if (Check[7] == 0) ui->card_8->setEnabled(false);
        //if (Check[8] == 0) ui->card_9->setEnabled(false);
        if (Check[9] == 0) ui->card_10->setEnabled(false);

        ui->playButton->setEnabled(true);
    }
    else {
        setButtomEnable(true);
        ui->playButton->setEnabled(false);
    }
}

void MainWindow::setButtomEnable(bool b)
{
    ui->card_1->setEnabled(b);
    ui->card_2->setEnabled(b);
    ui->card_3->setEnabled(b);
    ui->card_4->setEnabled(b);
    ui->card_5->setEnabled(b);
    ui->card_6->setEnabled(b);
    ui->card_7->setEnabled(b);
    ui->card_8->setEnabled(b);
    //ui->card_9->setEnabled(b);
    ui->card_10->setEnabled(b);

}

void MainWindow::displayCards()
{
    ui->card_display_1->setText(card_name(SelectedC[0]));
    ui->card_display_2->setText(card_name(SelectedC[1]));
    ui->card_display_3->setText(card_name(SelectedC[2]));
    ui->card_display_4->setText(card_name(SelectedC[3]));
    ui->card_display_5->setText(card_name(SelectedC[4]));
    ui->card_display_6->setText(card_name(SelectedC[5]));
    ui->card_display_7->setText(card_name(SelectedC[6]));
    ui->card_display_1->setAlignment(Qt::AlignCenter);
    ui->card_display_2->setAlignment(Qt::AlignCenter);
    ui->card_display_3->setAlignment(Qt::AlignCenter);
    ui->card_display_4->setAlignment(Qt::AlignCenter);
    ui->card_display_5->setAlignment(Qt::AlignCenter);
    ui->card_display_6->setAlignment(Qt::AlignCenter);
    ui->card_display_7->setAlignment(Qt::AlignCenter);
}
int MainWindow::n = 0;
void MainWindow::OpenGameWindow()
{
    this->close();
    if (n == 0){
        Game = new GameWindow();
        Game->playerName(playername);
        Game->setCard(SelectedC[0],SelectedC[1],SelectedC[2],SelectedC[3],SelectedC[4],SelectedC[5],SelectedC[6]);
        Game->displayCard();
        Game->reset();
        Game->show();
        connect(Game,SIGNAL(quit()),this,SLOT(openMainWindow()));
        n++;
    }
    else {}
}

void MainWindow::openMainWindow()
{
    Game->close();
    delete Game;
    this->reset();
    this->show();
    n = 0;
}

void MainWindow::setBackgroundScene(const QString &imagepath)
{
    scene->addPixmap(scene->initBackground(imagepath));
    ui->background->setScene(scene);
    ui->background->show();
}

void MainWindow::reset()
{
    ui->card_1->setIcon(QIcon(Card::cardpath_1));
    ui->card_1->setIconSize(QSize(150,150));
    ui->card_2->setIcon(QIcon(Card::cardpath_2));
    ui->card_2->setIconSize(QSize(150,150));
    ui->card_3->setIcon(QIcon(Card::cardpath_3));
    ui->card_3->setIconSize(QSize(150,150));
    ui->card_4->setIcon(QIcon(Card::cardpath_4));
    ui->card_4->setIconSize(QSize(150,150));
    ui->card_5->setIcon(QIcon(Card::cardpath_5));
    ui->card_5->setIconSize(QSize(150,150));
    ui->card_6->setIcon(QIcon(Card::cardpath_6));
    ui->card_6->setIconSize(QSize(150,150));
    ui->card_7->setIcon(QIcon(Card::cardpath_7));
    ui->card_7->setIconSize(QSize(150,150));
    ui->card_8->setIcon(QIcon(Card::cardpath_8));
    ui->card_8->setIconSize(QSize(150,150));
    //ui->card_9->setIcon(QIcon(Card::cardpath_9));
    //ui->card_9->setIconSize(QSize(150,150));
    ui->card_10->setIcon(QIcon(Card::cardpath_10));
    ui->card_10->setIconSize(QSize(150,150));

    ui->card_1->setChecked(false);
    ui->card_2->setChecked(false);
    ui->card_3->setChecked(false);
    ui->card_4->setChecked(false);
    ui->card_5->setChecked(false);
    ui->card_6->setChecked(false);
    ui->card_7->setChecked(false);
    ui->card_8->setChecked(false);
    //ui->card_9->setChecked(false);
    ui->card_10->setChecked(false);
}

QString MainWindow::card_name(int num)
{
    switch (num) {
    case 1:
        return "Doggy";
        break;
    case 2:
        return "Soldier";
        break;
    case 3:
        return "Tall";
        break;
    case 4:
        return "Dox";
        break;
    case 5:
        return "Dragon";
        break;
    case 6:
        return "Ancient";
        break;
    case 7:
        return "Commander";
        break;
    case 8:
        return "TallEX";
        break;
    case 9:
        return "Ninetail";
        break;
    case 10:
        return "Catnon";
        break;
    default:
        return "Unknown";
    }
}
