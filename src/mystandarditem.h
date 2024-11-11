#ifndef MYSTANDARDITEM_H
#define MYSTANDARDITEM_H

#include <QStandardItem>

#include "variables.h"

enum AlgoType {ALGO = 0, STEP, SOLUCE, END, SINGLE_MOVE, END_LINE};

class MyStandardItem : public QStandardItem
{
public:
    MyStandardItem(Algorithm algo, bool soluce = false);
    MyStandardItem(AlgoType);

    Algorithm _algo;
    void setAlgo(Algorithm algo);
    Algorithm* getAlgo();

    int getNextMvt();
    int getCurrentMvt();
    int getPrevMvt();

    void move(int);

    QString getStringAlgo();

    bool isBegin();
    bool isEnd();
    void goToBegin();
    void goToEnd();

    QList<int> getNextMoves();

    AlgoType getType() const {return _type; }

    int position = 0;
    AlgoType _type = ALGO;

    bool isSoluce();
    bool _isSoluce = false;
};

#endif // MYSTANDARDITEM_H
