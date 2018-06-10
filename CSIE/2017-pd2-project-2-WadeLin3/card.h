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
                         cardpath_6, cardpath_7, cardpath_8, cardpath_9, cardpath_10;

private:

};

#endif // CARD_H
