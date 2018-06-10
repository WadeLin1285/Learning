#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "card.h"

#include <iostream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // set the scene
    scene = new MainScene();
    setBackgroundScene(":/images/background-2.png");
    scene->initMinionCard();
    scene->setSceneRect(0,0,1300,880);
    scene->initShadow();
    // setup the card picking page
    setup();
    // set card selected button
    ui->card_1->setCheckable(true);
    ui->card_2->setCheckable(true);
    ui->card_3->setCheckable(true);
    ui->card_4->setCheckable(true);
    ui->card_5->setCheckable(true);
    ui->card_6->setCheckable(true);
    ui->card_7->setCheckable(true);
    ui->card_8->setCheckable(true);
    ui->card_9->setCheckable(true);
    ui->card_10->setCheckable(true);
    ui->card_11->setCheckable(true);
    ui->card_12->setCheckable(true);
    ui->card_13->setCheckable(true);
    ui->card_14->setCheckable(true);
    ui->card_15->setCheckable(true);
    ui->card_16->setCheckable(true);
    ui->card_17->setCheckable(true);
    ui->card_18->setCheckable(true);
    ui->card_19->setCheckable(true);
    ui->card_20->setCheckable(true);
    // set the color of labels
    ui->miniondata->setStyleSheet("QLabel {color: #003E3E;border: 7px solid #00CACA;}");
    ui->miniondata_bg->setStyleSheet("QGraphicsView {background-color: #D9FFFF}");
    ui->miniondata_bg_1->setStyleSheet("QGraphicsView {background-color: #CEFFCE}");
    ui->miniondata_bg_2->setStyleSheet(ui->miniondata_bg_1->styleSheet());
    ui->miniondata_bg_3->setStyleSheet(ui->miniondata_bg_1->styleSheet());
    ui->miniondata_label_1->setStyleSheet("QLabel {color: #006000; border: 5px solid #00DB00;}");
    ui->miniondata_label_2->setStyleSheet(ui->miniondata_label_1->styleSheet());
    ui->miniondata_label_3->setStyleSheet(ui->miniondata_label_1->styleSheet());
    ui->miniondata_1->setStyleSheet("QLabel {color: #006000;}");
    ui->miniondata_2->setStyleSheet(ui->miniondata_1->styleSheet());
    ui->miniondata_3->setStyleSheet(ui->miniondata_1->styleSheet());
    ui->card_display_1->setStyleSheet("QTextBrowser {color: #003D79;}"
                                      "QTextBrowser {border: 3px solid #003D79; border-radius: 5px;}");
    ui->card_display_2->setStyleSheet(ui->card_display_1->styleSheet());
    ui->card_display_3->setStyleSheet(ui->card_display_1->styleSheet());
    ui->card_display_4->setStyleSheet(ui->card_display_1->styleSheet());
    ui->card_display_5->setStyleSheet(ui->card_display_1->styleSheet());
    ui->card_display_6->setStyleSheet(ui->card_display_1->styleSheet());
    ui->card_display_7->setStyleSheet(ui->card_display_1->styleSheet());
    ui->playButton->setStyleSheet("QPushButton {border: 5px solid black; border-radius: 20px;}"
                                  "QPushButton {background-color: #A3D1D1;}");
    ui->card_1->setStyleSheet("QPushButton {border: 0px solid black; border-radius: 20px;}");
    ui->card_2->setStyleSheet(ui->card_1->styleSheet());
    ui->card_3->setStyleSheet(ui->card_1->styleSheet());
    ui->card_4->setStyleSheet(ui->card_1->styleSheet());
    ui->card_5->setStyleSheet(ui->card_1->styleSheet());
    ui->card_6->setStyleSheet(ui->card_1->styleSheet());
    ui->card_7->setStyleSheet(ui->card_1->styleSheet());
    ui->card_8->setStyleSheet(ui->card_1->styleSheet());
    ui->card_9->setStyleSheet(ui->card_1->styleSheet());
    ui->card_10->setStyleSheet(ui->card_1->styleSheet());
    ui->card_11->setStyleSheet(ui->card_1->styleSheet());
    ui->card_12->setStyleSheet(ui->card_1->styleSheet());
    ui->card_13->setStyleSheet(ui->card_1->styleSheet());
    ui->card_14->setStyleSheet(ui->card_1->styleSheet());
    ui->card_15->setStyleSheet(ui->card_1->styleSheet());
    ui->card_16->setStyleSheet(ui->card_1->styleSheet());
    ui->card_17->setStyleSheet(ui->card_1->styleSheet());
    ui->card_18->setStyleSheet(ui->card_1->styleSheet());
    ui->card_19->setStyleSheet(ui->card_1->styleSheet());
    ui->card_20->setStyleSheet(ui->card_1->styleSheet());

    // set function buttons
    ui->playButton->setEnabled(false);
    ui->playButton->hide();
    ui->rankbox->hide();
    ui->rankbox->setAutoFillBackground(true);
    // set ranking
    setRankFile();
    // card connections
    connect(ui->card_1,SIGNAL(toggled(bool)) ,this,SLOT (PressButton1(bool)));
    connect(ui->card_1,SIGNAL(mouseTouch())  ,this,SLOT (Information1()));
    connect(ui->card_1,SIGNAL(mouseLeft())   ,this,SLOT (DefaultInformation()));
    connect(ui->card_2,SIGNAL(toggled(bool)) ,this,SLOT (PressButton2(bool)));
    connect(ui->card_2,SIGNAL(mouseTouch())  ,this,SLOT (Information2()));
    connect(ui->card_2,SIGNAL(mouseLeft())   ,this,SLOT (DefaultInformation()));
    connect(ui->card_3,SIGNAL(toggled(bool)) ,this,SLOT (PressButton3(bool)));
    connect(ui->card_3,SIGNAL(mouseTouch())  ,this,SLOT (Information3()));
    connect(ui->card_3,SIGNAL(mouseLeft())   ,this,SLOT (DefaultInformation()));
    connect(ui->card_4,SIGNAL(toggled(bool)) ,this,SLOT (PressButton4(bool)));
    connect(ui->card_4,SIGNAL(mouseTouch())  ,this,SLOT (Information4()));
    connect(ui->card_4,SIGNAL(mouseLeft())   ,this,SLOT (DefaultInformation()));
    connect(ui->card_5,SIGNAL(toggled(bool)) ,this,SLOT (PressButton5(bool)));
    connect(ui->card_5,SIGNAL(mouseTouch())  ,this,SLOT (Information5()));
    connect(ui->card_5,SIGNAL(mouseLeft())   ,this,SLOT (DefaultInformation()));
    connect(ui->card_6,SIGNAL(toggled(bool)) ,this,SLOT (PressButton6(bool)));
    connect(ui->card_6,SIGNAL(mouseTouch())  ,this,SLOT (Information6()));
    connect(ui->card_6,SIGNAL(mouseLeft())   ,this,SLOT (DefaultInformation()));
    connect(ui->card_7,SIGNAL(toggled(bool)) ,this,SLOT (PressButton7(bool)));
    connect(ui->card_7,SIGNAL(mouseTouch())  ,this,SLOT (Information7()));
    connect(ui->card_7,SIGNAL(mouseLeft())   ,this,SLOT (DefaultInformation()));
    connect(ui->card_8,SIGNAL(toggled(bool)) ,this,SLOT (PressButton8(bool)));
    connect(ui->card_8,SIGNAL(mouseTouch())  ,this,SLOT (Information8()));
    connect(ui->card_8,SIGNAL(mouseLeft())   ,this,SLOT (DefaultInformation()));
    connect(ui->card_9,SIGNAL(toggled(bool)) ,this,SLOT (PressButton9(bool)));
    connect(ui->card_9,SIGNAL(mouseTouch())  ,this,SLOT (Information9()));
    connect(ui->card_9,SIGNAL(mouseLeft())   ,this,SLOT (DefaultInformation()));
    connect(ui->card_10,SIGNAL(toggled(bool)),this,SLOT (PressButton10(bool)));
    connect(ui->card_10,SIGNAL(mouseTouch()) ,this,SLOT (Information10()));
    connect(ui->card_10,SIGNAL(mouseLeft())  ,this,SLOT (DefaultInformation()));
    connect(ui->card_11,SIGNAL(toggled(bool)) ,this,SLOT (PressButton11(bool)));
    connect(ui->card_11,SIGNAL(mouseTouch())  ,this,SLOT (Information11()));
    connect(ui->card_11,SIGNAL(mouseLeft())   ,this,SLOT (DefaultInformation()));
    connect(ui->card_12,SIGNAL(toggled(bool)) ,this,SLOT (PressButton12(bool)));
    connect(ui->card_12,SIGNAL(mouseTouch())  ,this,SLOT (Information12()));
    connect(ui->card_12,SIGNAL(mouseLeft())   ,this,SLOT (DefaultInformation()));
    connect(ui->card_13,SIGNAL(toggled(bool)) ,this,SLOT (PressButton13(bool)));
    connect(ui->card_13,SIGNAL(mouseTouch())  ,this,SLOT (Information13()));
    connect(ui->card_13,SIGNAL(mouseLeft())   ,this,SLOT (DefaultInformation()));
    connect(ui->card_14,SIGNAL(toggled(bool)) ,this,SLOT (PressButton14(bool)));
    connect(ui->card_14,SIGNAL(mouseTouch())  ,this,SLOT (Information14()));
    connect(ui->card_14,SIGNAL(mouseLeft())   ,this,SLOT (DefaultInformation()));
    connect(ui->card_15,SIGNAL(toggled(bool)) ,this,SLOT (PressButton15(bool)));
    connect(ui->card_15,SIGNAL(mouseTouch())  ,this,SLOT (Information15()));
    connect(ui->card_15,SIGNAL(mouseLeft())   ,this,SLOT (DefaultInformation()));
    connect(ui->card_16,SIGNAL(toggled(bool)) ,this,SLOT (PressButton16(bool)));
    connect(ui->card_16,SIGNAL(mouseTouch())  ,this,SLOT (Information16()));
    connect(ui->card_16,SIGNAL(mouseLeft())   ,this,SLOT (DefaultInformation()));
    connect(ui->card_17,SIGNAL(toggled(bool)) ,this,SLOT (PressButton17(bool)));
    connect(ui->card_17,SIGNAL(mouseTouch())  ,this,SLOT (Information17()));
    connect(ui->card_17,SIGNAL(mouseLeft())   ,this,SLOT (DefaultInformation()));
    connect(ui->card_18,SIGNAL(toggled(bool)) ,this,SLOT (PressButton18(bool)));
    connect(ui->card_18,SIGNAL(mouseTouch())  ,this,SLOT (Information18()));
    connect(ui->card_18,SIGNAL(mouseLeft())   ,this,SLOT (DefaultInformation()));
    connect(ui->card_19,SIGNAL(toggled(bool)) ,this,SLOT (PressButton19(bool)));
    connect(ui->card_19,SIGNAL(mouseTouch())  ,this,SLOT (Information19()));
    connect(ui->card_19,SIGNAL(mouseLeft())   ,this,SLOT (DefaultInformation()));
    connect(ui->card_20,SIGNAL(toggled(bool)),this,SLOT (PressButton20(bool)));
    connect(ui->card_20,SIGNAL(mouseTouch()) ,this,SLOT (Information20()));
    connect(ui->card_20,SIGNAL(mouseLeft())  ,this,SLOT (DefaultInformation()));

    // set the card displays
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

    // connect the functional buttons
    connect(ui->playButton,SIGNAL(pressed()) ,this,SLOT (OpenGameWindow()));
    connect(ui->rank,SIGNAL(toggled(bool)),this,SLOT(ranking(bool)));
    connect(ui->rank,SIGNAL(pressed()),this,SLOT(DefaultInformation()));
    connect(ui->name_lineEdit,SIGNAL(textChanged(const QString &)),this,SLOT(setName(const QString &)));
    setButtomEnable(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setup()
{
    buttomSize = QSize(131,131);
    setButtomEnable(false);
    ui->rank->setEnabled(false);
    reset();

    minion1 = new Animate(1);
    scene->addWidget(minion1->walkLabel);
    minion1->display();
    minion2 = new Animate(2);
    scene->addWidget(minion2->walkLabel);
    minion2->display();
    minion3 = new Animate(3);
    scene->addWidget(minion3->walkLabel);
    minion3->display();
    minion4 = new Animate(4);
    scene->addWidget(minion4->walkLabel);
    minion4->display();
    minion5 = new Animate(5);
    scene->addWidget(minion5->walkLabel);
    minion5->display();
    minion6 = new Animate(6);
    scene->addWidget(minion6->walkLabel);
    minion6->display();
    minion7 = new Animate(7);
    scene->addWidget(minion7->walkLabel);
    minion7->display();
    minion8 = new Animate(8);
    scene->addWidget(minion8->walkLabel);
    minion8->display();
    minion9 = new Animate(9);
    scene->addWidget(minion9->walkLabel);
    minion9->display();
    minion10 = new Animate(10);
    scene->addWidget(minion10->walkLabel);
    minion10->display();
    minion11 = new Animate(11);
    scene->addWidget(minion11->walkLabel);
    minion11->display();
    minion12 = new Animate(12);
    scene->addWidget(minion12->walkLabel);
    minion12->display();
    minion13 = new Animate(13);
    scene->addWidget(minion13->walkLabel);
    minion13->display();
    minion14 = new Animate(14);
    scene->addWidget(minion14->walkLabel);
    minion14->display();
    minion15 = new Animate(15);
    scene->addWidget(minion15->walkLabel);
    minion15->display();
    minion16 = new Animate(16);
    scene->addWidget(minion16->walkLabel);
    minion16->display();
    minion17 = new Animate(17);
    scene->addWidget(minion17->walkLabel);
    minion17->display();
    minion18 = new Animate(18);
    scene->addWidget(minion18->walkLabel);
    minion18->display();
    minion19 = new Animate(19);
    scene->addWidget(minion19->walkLabel);
    minion19->display();
    minion20 = new Animate(20);
    scene->addWidget(minion20->walkLabel);
    minion20->display();
}

void MainWindow::setRankFile()
{
    QFile file("/home/pd2vm/2017-pd2-project-3-battle_dogs/rank.txt");
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream in(&file);
    int number = 0;
    while (!in.atEnd()) {
        QString line = in.readLine();
        rank[number] = line;
        number++;
    }
    file.close();
    for (int i = number;i < 14;i++) { rank[i] = "---"; }
    ui->player_1->setText(rank[0]);
    ui->time_1->setText(rank[1]);
    ui->player_2->setText(rank[2]);
    ui->time_2->setText(rank[3]);
    ui->player_3->setText(rank[4]);
    ui->time_3->setText(rank[5]);
    ui->player_4->setText(rank[6]);
    ui->time_4->setText(rank[7]);
    ui->player_5->setText(rank[8]);
    ui->time_5->setText(rank[9]);
    ui->player_6->setText(rank[10]);
    ui->time_6->setText(rank[11]);
    ui->player_7->setText(rank[12]);
    ui->time_7->setText(rank[13]);
}

void MainWindow::setName(const QString &name)
{
    setButtomEnable(true);
    ui->rank->setEnabled(true);
    playername = name;
}

QString MainWindow::name() const
{
    return ui->name_lineEdit->text();
}

void MainWindow::PressButton1(bool state)
{
    if (state == true) {
        ui->card_1->setIcon(QIcon(Card::cardpath_1_2));
        ui->card_1->setIconSize(buttomSize);
    }
    else {
        ui->card_1->setIcon(QIcon(Card::cardpath_1));
        ui->card_1->setIconSize(buttomSize);
    }
    SelectedCard(1);
}
void MainWindow::PressButton2(bool state)
{
    if (state == true) {
        ui->card_2->setIcon(QIcon(Card::cardpath_2_2));
        ui->card_2->setIconSize(buttomSize);
    }
    else {
        ui->card_2->setIcon(QIcon(Card::cardpath_2));
        ui->card_2->setIconSize(buttomSize);
    }
    SelectedCard(2);
}
void MainWindow::PressButton3(bool state)
{
    if (state == true) {
        ui->card_3->setIcon(QIcon(Card::cardpath_3_2));
        ui->card_3->setIconSize(buttomSize);
    }
    else {
        ui->card_3->setIcon(QIcon(Card::cardpath_3));
        ui->card_3->setIconSize(buttomSize);
    }
    SelectedCard(3);
}
void MainWindow::PressButton4(bool state)
{
    if (state == true) {
        ui->card_4->setIcon(QIcon(Card::cardpath_4_2));
        ui->card_4->setIconSize(buttomSize);
    }
    else {
        ui->card_4->setIcon(QIcon(Card::cardpath_4));
        ui->card_4->setIconSize(buttomSize);
    }
    SelectedCard(4);
}
void MainWindow::PressButton5(bool state)
{
    if (state == true) {
        ui->card_5->setIcon(QIcon(Card::cardpath_5_2));
        ui->card_5->setIconSize(buttomSize);
    }
    else {
        ui->card_5->setIcon(QIcon(Card::cardpath_5));
        ui->card_5->setIconSize(buttomSize);
    }
    SelectedCard(5);
}
void MainWindow::PressButton6(bool state)
{
    if (state == true) {
        ui->card_6->setIcon(QIcon(Card::cardpath_6_2));
        ui->card_6->setIconSize(buttomSize);
    }
    else {
        ui->card_6->setIcon(QIcon(Card::cardpath_6));
        ui->card_6->setIconSize(buttomSize);
    }
    SelectedCard(6);
}
void MainWindow::PressButton7(bool state)
{
    if (state == true) {
        ui->card_7->setIcon(QIcon(Card::cardpath_7_2));
        ui->card_7->setIconSize(buttomSize);
    }
    else {
        ui->card_7->setIcon(QIcon(Card::cardpath_7));
        ui->card_7->setIconSize(buttomSize);
    }
    SelectedCard(7);
}
void MainWindow::PressButton8(bool state)
{
    if (state == true) {
        ui->card_8->setIcon(QIcon(Card::cardpath_8_2));
        ui->card_8->setIconSize(buttomSize);
    }
    else {
        ui->card_8->setIcon(QIcon(Card::cardpath_8));
        ui->card_8->setIconSize(buttomSize);
    }
    SelectedCard(8);
}
void MainWindow::PressButton9(bool state)
{
    if (state == true) {
        ui->card_9->setIcon(QIcon(Card::cardpath_9_2));
        ui->card_9->setIconSize(buttomSize);
    }
    else {
        ui->card_9->setIcon(QIcon(Card::cardpath_9));
        ui->card_9->setIconSize(buttomSize);
    }
    SelectedCard(9);
}
void MainWindow::PressButton10(bool state)
{
    if (state == true) {
        ui->card_10->setIcon(QIcon(Card::cardpath_10_2));
        ui->card_10->setIconSize(buttomSize);
    }
    else {
        ui->card_10->setIcon(QIcon(Card::cardpath_10));
        ui->card_10->setIconSize(buttomSize);
    }
    SelectedCard(10);
}
void MainWindow::PressButton11(bool state)
{
    if (state == true) {
        ui->card_11->setIcon(QIcon(Card::cardpath_11_2));
        ui->card_11->setIconSize(buttomSize);
    }
    else {
        ui->card_11->setIcon(QIcon(Card::cardpath_11));
        ui->card_11->setIconSize(buttomSize);
    }
    SelectedCard(11);
}
void MainWindow::PressButton12(bool state)
{
    if (state == true) {
        ui->card_12->setIcon(QIcon(Card::cardpath_12_2));
        ui->card_12->setIconSize(buttomSize);
    }
    else {
        ui->card_12->setIcon(QIcon(Card::cardpath_12));
        ui->card_12->setIconSize(buttomSize);
    }
    SelectedCard(12);
}
void MainWindow::PressButton13(bool state)
{
    if (state == true) {
        ui->card_13->setIcon(QIcon(Card::cardpath_13_2));
        ui->card_13->setIconSize(buttomSize);
    }
    else {
        ui->card_13->setIcon(QIcon(Card::cardpath_13));
        ui->card_13->setIconSize(buttomSize);
    }
    SelectedCard(13);
}
void MainWindow::PressButton14(bool state)
{
    if (state == true) {
        ui->card_14->setIcon(QIcon(Card::cardpath_14_2));
        ui->card_14->setIconSize(buttomSize);
    }
    else {
        ui->card_14->setIcon(QIcon(Card::cardpath_14));
        ui->card_14->setIconSize(buttomSize);
    }
    SelectedCard(14);
}
void MainWindow::PressButton15(bool state)
{
    if (state == true) {
        ui->card_15->setIcon(QIcon(Card::cardpath_15_2));
        ui->card_15->setIconSize(buttomSize);
    }
    else {
        ui->card_15->setIcon(QIcon(Card::cardpath_15));
        ui->card_15->setIconSize(buttomSize);
    }
    SelectedCard(15);
}
void MainWindow::PressButton16(bool state)
{
    if (state == true) {
        ui->card_16->setIcon(QIcon(Card::cardpath_16_2));
        ui->card_16->setIconSize(buttomSize);
    }
    else {
        ui->card_16->setIcon(QIcon(Card::cardpath_16));
        ui->card_16->setIconSize(buttomSize);
    }
    SelectedCard(16);
}
void MainWindow::PressButton17(bool state)
{
    if (state == true) {
        ui->card_17->setIcon(QIcon(Card::cardpath_17_2));
        ui->card_17->setIconSize(buttomSize);
    }
    else {
        ui->card_17->setIcon(QIcon(Card::cardpath_17));
        ui->card_17->setIconSize(buttomSize);
    }
    SelectedCard(17);
}
void MainWindow::PressButton18(bool state)
{
    if (state == true) {
        ui->card_18->setIcon(QIcon(Card::cardpath_18_2));
        ui->card_18->setIconSize(buttomSize);
    }
    else {
        ui->card_18->setIcon(QIcon(Card::cardpath_18));
        ui->card_18->setIconSize(buttomSize);
    }
    SelectedCard(18);
}
void MainWindow::PressButton19(bool state)
{
    if (state == true) {
        ui->card_19->setIcon(QIcon(Card::cardpath_19_2));
        ui->card_19->setIconSize(buttomSize);
    }
    else {
        ui->card_19->setIcon(QIcon(Card::cardpath_19));
        ui->card_19->setIconSize(buttomSize);
    }
    SelectedCard(19);
}
void MainWindow::PressButton20(bool state)
{
    if (state == true) {
        ui->card_20->setIcon(QIcon(Card::cardpath_20_2));
        ui->card_20->setIconSize(buttomSize);
    }
    else {
        ui->card_20->setIcon(QIcon(Card::cardpath_20));
        ui->card_20->setIconSize(buttomSize);
    }
    SelectedCard(20);
}

void MainWindow::Information1()
{
    ui->miniondata_1->setText("50");
    ui->miniondata_2->setText("500");
    ui->miniondata_3->setText("30");
    ui->miniondata_1->setStyleSheet("QLabel {color: #006000;}");
    ui->miniondata_2->setStyleSheet("QLabel {color: #006000;}");
    ui->miniondata_3->setStyleSheet("QLabel {color: #006000;}");
    ui->miniondata->setText("<<<   Doggy   >>>\n\nNormal dog with\nNORMAL ability.\n");
    minion1->walkLabel->show();
    minion1->walkMovie->start();
    scene->shadow_1->show();
    scene->shadow_2->hide();
    scene->shadow_3->hide();
    scene->shadow_4->hide();
}
void MainWindow::Information2()
{
    ui->miniondata_1->setText("60");
    ui->miniondata_2->setText("500");
    ui->miniondata_3->setText("60");
    ui->miniondata_1->setStyleSheet("QLabel {color: #006000;}");
    ui->miniondata_2->setStyleSheet("QLabel {color: #006000;}");
    ui->miniondata_3->setStyleSheet("QLabel {color: #006000;}");
    ui->miniondata->setText("<<< Soldier >>>\n\nSoldier from DOGGY\nkingdom.\nHave high minion CP.");
    minion2->walkLabel->show();
    minion2->walkMovie->start();
    scene->shadow_1->show();
    scene->shadow_2->hide();
    scene->shadow_3->hide();
    scene->shadow_4->hide();
}
void MainWindow::Information3()
{
    ui->miniondata_1->setText("30");
    ui->miniondata_2->setText("1500");
    ui->miniondata_3->setText("60");
    ui->miniondata_1->setStyleSheet("QLabel {color: #006000;}");
    ui->miniondata_2->setStyleSheet("QLabel {color: #EA0000;}");
    ui->miniondata_3->setStyleSheet("QLabel {color: #006000;}");
    ui->miniondata->setText("<<<  Tall  >>>\n\nTallest dog in the\ndoggy wrold.\nHave high HP.");
    minion3->walkLabel->show();
    minion3->walkMovie->start();
    scene->shadow_1->show();
    scene->shadow_2->hide();
    scene->shadow_3->hide();
    scene->shadow_4->hide();
}
void MainWindow::Information4()
{
    ui->miniondata_1->setText("70");
    ui->miniondata_2->setText("300");
    ui->miniondata_3->setText("80");
    ui->miniondata_1->setStyleSheet("QLabel {color: #006000;}");
    ui->miniondata_2->setStyleSheet("QLabel {color: #006000;}");
    ui->miniondata_3->setStyleSheet("QLabel {color: #006000;}");
    ui->miniondata->setText("<<<  Dox  >>>\n\nThe new species.\n Have long tail.\n");
    minion4->walkLabel->show();
    minion4->walkMovie->start();
    scene->shadow_1->show();
    scene->shadow_2->hide();
    scene->shadow_3->hide();
    scene->shadow_4->hide();
}
void MainWindow::Information5()
{
    ui->miniondata_1->setText("10");
    ui->miniondata_2->setText("4000");
    ui->miniondata_3->setText("120");
    ui->miniondata_1->setStyleSheet("QLabel {color: #006000;}");
    ui->miniondata_2->setStyleSheet("QLabel {color: #EA0000;}");
    ui->miniondata_3->setStyleSheet("QLabel {color: #006000;}");
    ui->miniondata->setText("<<< Dragon >>>\n\nHide in the deep\n mountain.BUT one day,\nit was angry...");
    minion5->walkLabel->show();
    minion5->walkMovie->start();
    scene->shadow_1->hide();
    scene->shadow_2->hide();
    scene->shadow_3->show();
    scene->shadow_4->hide();
}
void MainWindow::Information6()
{
    ui->miniondata_1->setText("30");
    ui->miniondata_2->setText("1000");
    ui->miniondata_3->setText("100");
    ui->miniondata_1->setStyleSheet("QLabel {color: #006000;}");
    ui->miniondata_2->setStyleSheet("QLabel {color: #006000;}");
    ui->miniondata_3->setStyleSheet("QLabel {color: #006000;}");
    ui->miniondata->setText("<<< Ancient >>>\n\nAnicient dog from time\nmachine. Using stone\nweapon to attack.");
    minion6->walkLabel->show();
    minion6->walkMovie->start();
    scene->shadow_1->show();
    scene->shadow_2->hide();
    scene->shadow_3->hide();
    scene->shadow_4->hide();
}
void MainWindow::Information7()
{
    ui->miniondata_1->setText("120");
    ui->miniondata_2->setText("1200");
    ui->miniondata_3->setText("200");
    ui->miniondata_1->setStyleSheet("QLabel {color: #006000;}");
    ui->miniondata_2->setStyleSheet("QLabel {color: #006000;}");
    ui->miniondata_3->setStyleSheet("QLabel {color: #006000;}");
    ui->miniondata->setText("<<<Commander>>>\n\nThe leader of Soldiers.\nUsing RPG to attack.\n");
    minion7->walkLabel->show();
    minion7->walkMovie->start();
    scene->shadow_1->show();
    scene->shadow_2->hide();
    scene->shadow_3->hide();
    scene->shadow_4->hide();
}
void MainWindow::Information8()
{
    ui->miniondata_1->setText("100");
    ui->miniondata_2->setText("2000");
    ui->miniondata_3->setText("250");
    ui->miniondata_1->setStyleSheet("QLabel {color: #006000;}");
    ui->miniondata_2->setStyleSheet("QLabel {color: #EA0000;}");
    ui->miniondata_3->setStyleSheet("QLabel {color: #006000;}");
    ui->miniondata->setText("<<< TallEX >>>\n\nThe secret modified\nweapon. Base on Tall,\nbut powerful than it...");
    minion8->walkLabel->show();
    minion8->walkMovie->start();
    scene->shadow_1->show();
    scene->shadow_2->hide();
    scene->shadow_3->hide();
    scene->shadow_4->hide();
}
void MainWindow::Information9()
{
    ui->miniondata_1->setText("250");
    ui->miniondata_2->setText("500");
    ui->miniondata_3->setText("500");
    ui->miniondata_1->setStyleSheet("QLabel {color: #EA0000;}");
    ui->miniondata_2->setStyleSheet("QLabel {color: #006000;}");
    ui->miniondata_3->setStyleSheet("QLabel {color: #EA0000;}");
    ui->miniondata->setText("<<< NineTail >>>\n\nLengendary monster.\nHave high ability than\nother doggys.");
    minion9->walkLabel->show();
    minion9->walkMovie->start();
    scene->shadow_1->hide();
    scene->shadow_2->hide();
    scene->shadow_3->hide();
    scene->shadow_4->show();
}
void MainWindow::Information10()
{
    ui->miniondata_1->setText("170");
    ui->miniondata_2->setText("200");
    ui->miniondata_3->setText("300");
    ui->miniondata_1->setStyleSheet("QLabel {color: #EA0000;}");
    ui->miniondata_2->setStyleSheet("QLabel {color: #006000;}");
    ui->miniondata_3->setStyleSheet("QLabel {color: #006000;}");
    ui->miniondata->setText("<<< Catnon >>>\n\nSlave dog of kingdom.\nCarry the canon to\nsupport commander.");
    minion10->walkLabel->show();
    minion10->walkMovie->start();
    scene->shadow_1->hide();
    scene->shadow_2->hide();
    scene->shadow_3->show();
    scene->shadow_4->hide();
}
void MainWindow::Information11()
{
    ui->miniondata_1->setText("70");
    ui->miniondata_2->setText("500");
    ui->miniondata_3->setText("60");
    ui->miniondata_1->setStyleSheet("QLabel {color: #006000;}");
    ui->miniondata_2->setStyleSheet("QLabel {color: #006000;}");
    ui->miniondata_3->setStyleSheet("QLabel {color: #006000;}");
    ui->miniondata->setText("<<<  Saber  >>>\n\nThe royalest soilder\nin doggy kingdom.\nUsing giant sword.");
    minion11->walkLabel->show();
    minion11->walkMovie->start();
    scene->shadow_1->show();
    scene->shadow_2->hide();
    scene->shadow_3->hide();
    scene->shadow_4->hide();
}
void MainWindow::Information12()
{
    ui->miniondata_1->setText("120");
    ui->miniondata_2->setText("200");
    ui->miniondata_3->setText("80");
    ui->miniondata_1->setStyleSheet("QLabel {color: #006000;}");
    ui->miniondata_2->setStyleSheet("QLabel {color: #006000;}");
    ui->miniondata_3->setStyleSheet("QLabel {color: #006000;}");
    ui->miniondata->setText("<<<  Nija  >>>\n\nSecert minion.\nAlways hide in the\nshadow.");
    minion12->walkLabel->show();
    minion12->walkMovie->start();
    scene->shadow_1->show();
    scene->shadow_2->hide();
    scene->shadow_3->hide();
    scene->shadow_4->hide();
}
void MainWindow::Information13()
{
    ui->miniondata_1->setText("50");
    ui->miniondata_2->setText("1000");
    ui->miniondata_3->setText("100");
    ui->miniondata_1->setStyleSheet("QLabel {color: #006000;}");
    ui->miniondata_2->setStyleSheet("QLabel {color: #006000;}");
    ui->miniondata_3->setStyleSheet("QLabel {color: #006000;}");
    ui->miniondata->setText("<<<  Robort  >>>\n\nModified doggy,\nbut FAILED.\nOnly have a little ablity.");
    minion13->walkLabel->show();
    minion13->walkMovie->start();
    scene->shadow_1->show();
    scene->shadow_2->hide();
    scene->shadow_3->hide();
    scene->shadow_4->hide();
}
void MainWindow::Information14()
{
    ui->miniondata_1->setText("0");
    ui->miniondata_2->setText("5000");
    ui->miniondata_3->setText("200");
    ui->miniondata_1->setStyleSheet("QLabel {color: #006000;}");
    ui->miniondata_2->setStyleSheet("QLabel {color: #EA0000;}");
    ui->miniondata_3->setStyleSheet("QLabel {color: #006000;}");
    ui->miniondata->setText("<<<  Shield  >>>\n\nExtremely HIGH HP.\nCarry giant shield\nwith it.");
    minion14->walkLabel->show();
    minion14->walkMovie->start();
    scene->shadow_1->hide();
    scene->shadow_2->show();
    scene->shadow_3->hide();
    scene->shadow_4->hide();
}
void MainWindow::Information15()
{
    ui->miniondata_1->setText("100");
    ui->miniondata_2->setText("300");
    ui->miniondata_3->setText("120");
    ui->miniondata_1->setStyleSheet("QLabel {color: #006000;}");
    ui->miniondata_2->setStyleSheet("QLabel {color: #006000;}");
    ui->miniondata_3->setStyleSheet("QLabel {color: #006000;}");
    ui->miniondata->setText("<<<  Ditch  >>>\n\nKnowing all magic.\nUse lighting to\nattack enemy.");
    minion15->walkLabel->show();
    minion15->walkMovie->start();
    scene->shadow_1->show();
    scene->shadow_2->hide();
    scene->shadow_3->hide();
    scene->shadow_4->hide();
}
void MainWindow::Information16()
{
    ui->miniondata_1->setText("70");
    ui->miniondata_2->setText("2000");
    ui->miniondata_3->setText("200");
    ui->miniondata_1->setStyleSheet("QLabel {color: #006000;}");
    ui->miniondata_2->setStyleSheet("QLabel {color: #EA0000;}");
    ui->miniondata_3->setStyleSheet("QLabel {color: #006000;}");
    ui->miniondata->setText("<<< Spartan >>>\n\nPowerful Soldier.\nBest than Saber and\nhave lots muscles.");
    minion16->walkLabel->show();
    minion16->walkMovie->start();
    scene->shadow_1->show();
    scene->shadow_2->hide();
    scene->shadow_3->hide();
    scene->shadow_4->hide();
}
void MainWindow::Information17()
{
    ui->miniondata_1->setText("10");
    ui->miniondata_2->setText("3000");
    ui->miniondata_3->setText("200");
    ui->miniondata_1->setStyleSheet("QLabel {color: #006000;}");
    ui->miniondata_2->setStyleSheet("QLabel {color: #EA0000;}");
    ui->miniondata_3->setStyleSheet("QLabel {color: #006000;}");
    ui->miniondata->setText("<<< Bigdog >>>\n\nMutation dog.\nBigger than other dogs.\nBut very stupid...");
    minion17->walkLabel->show();
    minion17->walkMovie->start();
    scene->shadow_1->hide();
    scene->shadow_2->show();
    scene->shadow_3->hide();
    scene->shadow_4->hide();
}
void MainWindow::Information18()
{
    ui->miniondata_1->setText("170");
    ui->miniondata_2->setText("800");
    ui->miniondata_3->setText("300");
    ui->miniondata_1->setStyleSheet("QLabel {color: #EA0000;}");
    ui->miniondata_2->setStyleSheet("QLabel {color: #006000;}");
    ui->miniondata_3->setStyleSheet("QLabel {color: #006000;}");
    ui->miniondata->setText("<<< Superdog >>>\n\nAlien from other planet.\nHave unbelievable\nsuper power.");
    minion18->walkLabel->show();
    minion18->walkMovie->start();
    scene->shadow_1->hide();
    scene->shadow_2->hide();
    scene->shadow_3->hide();
    scene->shadow_4->show();
}
void MainWindow::Information19()
{
    ui->miniondata_1->setText("200");
    ui->miniondata_2->setText("800");
    ui->miniondata_3->setText("400");
    ui->miniondata_1->setStyleSheet("QLabel {color: #EA0000;}");
    ui->miniondata_2->setStyleSheet("QLabel {color: #006000;}");
    ui->miniondata_3->setStyleSheet("QLabel {color: #EA0000;}");
    ui->miniondata->setText("<<<  Jesus  >>>\n\nThe god of doggy.\nAlways pray for peace.\nAmen");
    minion19->walkLabel->show();
    minion19->walkMovie->start();
    scene->shadow_1->hide();
    scene->shadow_2->hide();
    scene->shadow_3->hide();
    scene->shadow_4->show();
}
void MainWindow::Information20()
{
    ui->miniondata_1->setText("250");
    ui->miniondata_2->setText("1000");
    ui->miniondata_3->setText("500");
    ui->miniondata_1->setStyleSheet("QLabel {color: #EA0000;}");
    ui->miniondata_2->setStyleSheet("QLabel {color: #006000;}");
    ui->miniondata_3->setStyleSheet("QLabel {color: #EA0000;}");
    ui->miniondata->setText("<<<  King  >>>\n\nThe greatest KING\nin doggy kingdom.\nHave infinity swords.");
    minion20->walkLabel->show();
    minion20->walkMovie->start();
    scene->shadow_1->hide();
    scene->shadow_2->hide();
    scene->shadow_3->hide();
    scene->shadow_4->show();
}

void MainWindow::DefaultInformation()
{
    ui->miniondata_1->setText("????");
    ui->miniondata_2->setText("????");
    ui->miniondata_3->setText("????");
    ui->miniondata_1->setStyleSheet("QLabel {color: #006000;}");
    ui->miniondata_2->setStyleSheet("QLabel {color: #006000;}");
    ui->miniondata_3->setStyleSheet("QLabel {color: #006000;}");
    ui->miniondata->setText("Choosing a DOG...");
    minion1->walkLabel->hide();
    minion2->walkLabel->hide();
    minion3->walkLabel->hide();
    minion4->walkLabel->hide();
    minion5->walkLabel->hide();
    minion6->walkLabel->hide();
    minion7->walkLabel->hide();
    minion8->walkLabel->hide();
    minion9->walkLabel->hide();
    minion10->walkLabel->hide();
    minion11->walkLabel->hide();
    minion12->walkLabel->hide();
    minion13->walkLabel->hide();
    minion14->walkLabel->hide();
    minion15->walkLabel->hide();
    minion16->walkLabel->hide();
    minion17->walkLabel->hide();
    minion18->walkLabel->hide();
    minion19->walkLabel->hide();
    minion20->walkLabel->hide();
    minion1->walkMovie->stop();
    minion2->walkMovie->stop();
    minion3->walkMovie->stop();
    minion4->walkMovie->stop();
    minion5->walkMovie->stop();
    minion6->walkMovie->stop();
    minion7->walkMovie->stop();
    minion8->walkMovie->stop();
    minion9->walkMovie->stop();
    minion10->walkMovie->stop();
    minion11->walkMovie->stop();
    minion12->walkMovie->stop();
    minion13->walkMovie->stop();
    minion14->walkMovie->stop();
    minion15->walkMovie->stop();
    minion16->walkMovie->stop();
    minion17->walkMovie->stop();
    minion18->walkMovie->stop();
    minion19->walkMovie->stop();
    minion20->walkMovie->stop();
    scene->shadow_1->hide();
    scene->shadow_2->hide();
    scene->shadow_3->hide();
    scene->shadow_4->hide();
}

void MainWindow::ranking(bool button)
{
    if (button) {
        setButtomEnable(false);
        ui->miniondata->hide();
        ui->miniondata_1->hide();
        ui->miniondata_2->hide();
        ui->miniondata_3->hide();
        ui->miniondata_label_1->hide();
        ui->miniondata_label_2->hide();
        ui->miniondata_label_3->hide();
        ui->rankbox->show();
        ui->rank->setText("Back");
    }
    else {
        setButtomEnable(true);
        ui->miniondata->show();
        ui->miniondata_1->show();
        ui->miniondata_2->show();
        ui->miniondata_3->show();
        ui->miniondata_label_1->show();
        ui->miniondata_label_2->show();
        ui->miniondata_label_3->show();
        ui->rankbox->hide();
        ui->rank->setText("Rank");
    }

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
        if (Check[0]  == 0) ui->card_1->setEnabled(false);
        if (Check[1]  == 0) ui->card_2->setEnabled(false);
        if (Check[2]  == 0) ui->card_3->setEnabled(false);
        if (Check[3]  == 0) ui->card_4->setEnabled(false);
        if (Check[4]  == 0) ui->card_5->setEnabled(false);
        if (Check[5]  == 0) ui->card_6->setEnabled(false);
        if (Check[6]  == 0) ui->card_7->setEnabled(false);
        if (Check[7]  == 0) ui->card_8->setEnabled(false);
        if (Check[8]  == 0) ui->card_9->setEnabled(false);
        if (Check[9]  == 0) ui->card_10->setEnabled(false);
        if (Check[10] == 0) ui->card_11->setEnabled(false);
        if (Check[11] == 0) ui->card_12->setEnabled(false);
        if (Check[12] == 0) ui->card_13->setEnabled(false);
        if (Check[13] == 0) ui->card_14->setEnabled(false);
        if (Check[14] == 0) ui->card_15->setEnabled(false);
        if (Check[15] == 0) ui->card_16->setEnabled(false);
        if (Check[16] == 0) ui->card_17->setEnabled(false);
        if (Check[17] == 0) ui->card_18->setEnabled(false);
        if (Check[18] == 0) ui->card_19->setEnabled(false);
        if (Check[19] == 0) ui->card_20->setEnabled(false);
        ui->playButton->show();
        ui->playButton->setEnabled(true);
        ui->rank->setEnabled(false);
    }
    else {
        setButtomEnable(true);
        ui->playButton->hide();
        ui->playButton->setEnabled(false);
        ui->rank->setEnabled(true);
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
    ui->card_9->setEnabled(b);
    ui->card_10->setEnabled(b);
    ui->card_11->setEnabled(b);
    ui->card_12->setEnabled(b);
    ui->card_13->setEnabled(b);
    ui->card_14->setEnabled(b);
    ui->card_15->setEnabled(b);
    ui->card_16->setEnabled(b);
    ui->card_17->setEnabled(b);
    ui->card_18->setEnabled(b);
    ui->card_19->setEnabled(b);
    ui->card_20->setEnabled(b);
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
    setRankFile();
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
    ui->card_1->setIconSize(buttomSize);
    ui->card_2->setIcon(QIcon(Card::cardpath_2));
    ui->card_2->setIconSize(buttomSize);
    ui->card_3->setIcon(QIcon(Card::cardpath_3));
    ui->card_3->setIconSize(buttomSize);
    ui->card_4->setIcon(QIcon(Card::cardpath_4));
    ui->card_4->setIconSize(buttomSize);
    ui->card_5->setIcon(QIcon(Card::cardpath_5));
    ui->card_5->setIconSize(buttomSize);
    ui->card_6->setIcon(QIcon(Card::cardpath_6));
    ui->card_6->setIconSize(buttomSize);
    ui->card_7->setIcon(QIcon(Card::cardpath_7));
    ui->card_7->setIconSize(buttomSize);
    ui->card_8->setIcon(QIcon(Card::cardpath_8));
    ui->card_8->setIconSize(buttomSize);
    ui->card_9->setIcon(QIcon(Card::cardpath_9));
    ui->card_9->setIconSize(buttomSize);
    ui->card_10->setIcon(QIcon(Card::cardpath_10));
    ui->card_10->setIconSize(buttomSize);
    ui->card_11->setIcon(QIcon(Card::cardpath_11));
    ui->card_11->setIconSize(buttomSize);
    ui->card_12->setIcon(QIcon(Card::cardpath_12));
    ui->card_12->setIconSize(buttomSize);
    ui->card_13->setIcon(QIcon(Card::cardpath_13));
    ui->card_13->setIconSize(buttomSize);
    ui->card_14->setIcon(QIcon(Card::cardpath_14));
    ui->card_14->setIconSize(buttomSize);
    ui->card_15->setIcon(QIcon(Card::cardpath_15));
    ui->card_15->setIconSize(buttomSize);
    ui->card_16->setIcon(QIcon(Card::cardpath_16));
    ui->card_16->setIconSize(buttomSize);
    ui->card_17->setIcon(QIcon(Card::cardpath_17));
    ui->card_17->setIconSize(buttomSize);
    ui->card_18->setIcon(QIcon(Card::cardpath_18));
    ui->card_18->setIconSize(buttomSize);
    ui->card_19->setIcon(QIcon(Card::cardpath_19));
    ui->card_19->setIconSize(buttomSize);
    ui->card_20->setIcon(QIcon(Card::cardpath_20));
    ui->card_20->setIconSize(buttomSize);

    ui->card_1->setChecked(false);
    ui->card_2->setChecked(false);
    ui->card_3->setChecked(false);
    ui->card_4->setChecked(false);
    ui->card_5->setChecked(false);
    ui->card_6->setChecked(false);
    ui->card_7->setChecked(false);
    ui->card_8->setChecked(false);
    ui->card_9->setChecked(false);
    ui->card_10->setChecked(false);
    ui->card_11->setChecked(false);
    ui->card_12->setChecked(false);
    ui->card_13->setChecked(false);
    ui->card_14->setChecked(false);
    ui->card_15->setChecked(false);
    ui->card_16->setChecked(false);
    ui->card_17->setChecked(false);
    ui->card_18->setChecked(false);
    ui->card_19->setChecked(false);
    ui->card_20->setChecked(false);

    ui->playButton->hide();
    setButtomEnable(true);
    for (int i = 0; i < 7; i++) {
        SelectedC[i] = 0;
    }
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
    case 11:
        return "Saber";
        break;
    case 12:
        return "Nija";
        break;
    case 13:
        return "Robort";
        break;
    case 14:
        return "Shield";
        break;
    case 15:
        return "Ditch";
        break;
    case 16:
        return "Spartan";
        break;
    case 17:
        return "Bigdog";
        break;
    case 18:
        return "Superdog";
        break;
    case 19:
        return "Jesus";
        break;
    case 20:
        return "King";
        break;
    default:
        return "Unknown";
    }
}
