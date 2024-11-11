#include "mystandarditem.h"

MyStandardItem::MyStandardItem(Algorithm algo, bool isSoluce)
{
    setEditable(false);
    setAlgo(algo);
    setText(getStringAlgo());
    _type = ALGO;
    _isSoluce = isSoluce;
}

MyStandardItem::MyStandardItem(AlgoType type)
{
    _type = type;
    _isSoluce = true;
    if (type == END)
        _isSoluce = false;
}

void MyStandardItem::setAlgo(Algorithm algo)
{
    _algo = algo;
}


Algorithm *MyStandardItem::getAlgo()
{
    return &_algo;
}

int MyStandardItem::getCurrentMvt()
{
    if (position >= _algo._mvts.size())
        return _VOID_;
    return _algo._mvts[position];
}

int MyStandardItem::getNextMvt()
{
    if (position+1 >= _algo._mvts.size())
        return _VOID_;
    return _algo._mvts[position+1];
}

int MyStandardItem::getPrevMvt()
{
    if (position-1 < 0 || position-1 >= _algo._mvts.size())
        return _VOID_;
    return _algo._mvts[position-1];
}

void MyStandardItem::move(int p)
{
    position += p;
}

QString MyStandardItem::getStringAlgo()
{
    QString s = "";
    unsigned char prev_mvt = -100;
    int n = 1;

    for (std::vector<unsigned char>::const_iterator aIter = _algo._mvts.begin(); aIter != _algo._mvts.end(); aIter++)
    {
        if (*aIter == prev_mvt)
            n++;
        else
        {
            if (n>1)
                s.append(QString::number(n));
            s.append("  "+Variables::Liste_Mouvements[*aIter]);
            n = 1;
        }
        prev_mvt = *aIter;
    }

    if (n>1)
        s.append(QString::number(n));

    return s;
}

bool MyStandardItem::isBegin()
{
    return position == 0;
}

bool MyStandardItem::isEnd()
{
    return(position == _algo._mvts.size());
}

void MyStandardItem::goToBegin()
{
    position = 0;
}

void MyStandardItem::goToEnd()
{
    position = _algo._mvts.size();
}

QList<int> MyStandardItem::getNextMoves()
{
    QList<int> mvts;
    for (int i=position; i< _algo._mvts.size(); ++i)
        mvts << _algo._mvts[i];

    return mvts;
}

bool MyStandardItem::isSoluce()
{
    return _isSoluce;
}


