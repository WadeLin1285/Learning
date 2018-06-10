#ifndef CARD_H
#define CARD_H

#include<QPainter>
#include<QGraphicsItem>
#include<QGraphicsPixmapItem>

#define MAXPOSITION 1200
#define YPOSITION 0

class Card :public QGraphicsPixmapItem
{
public:
    Card();

    // picture file path of cards
    static const QString defaultpath,
                         cardpath_1, cardpath_2, cardpath_3, cardpath_4, cardpath_5,
                         cardpath_6, cardpath_7, cardpath_8, cardpath_9, cardpath_10,
                         cardpath_11,cardpath_12,cardpath_13,cardpath_14,cardpath_15,
                         cardpath_16,cardpath_17,cardpath_18,cardpath_19,cardpath_20,
                         cardpath_1_2, cardpath_2_2, cardpath_3_2, cardpath_4_2, cardpath_5_2,
                         cardpath_6_2, cardpath_7_2, cardpath_8_2, cardpath_9_2, cardpath_10_2,
                         cardpath_11_2,cardpath_12_2,cardpath_13_2,cardpath_14_2,cardpath_15_2,
                         cardpath_16_2,cardpath_17_2,cardpath_18_2,cardpath_19_2,cardpath_20_2;

private:

};

#endif // CARD_H
