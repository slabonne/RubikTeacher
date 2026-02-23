/*
 * Rubik Teacher
 * Copyright (C) 2026 Sébastien LABONNE
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <https://www.gnu.org/licenses/>.
 */

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
    if (indexAlgoDisplayed >= _algo._mvts.size())
        return _VOID_;
    return _algo._mvts[indexAlgoDisplayed];
}

int MyStandardItem::getNextMvt()
{
    qDebug() << "getNextMvt()";
    if (indexAlgoDisplayed+1 >= _algo._mvts.size())
        return _VOID_;
    return _algo._mvts[indexAlgoDisplayed+1];
}

int MyStandardItem::getPrevMvt()
{
    if (indexAlgoDisplayed-1 < 0 || indexAlgoDisplayed-1 >= _algo._mvts.size())
        return _VOID_;
    return _algo._mvts[indexAlgoDisplayed-1];
}



void MyStandardItem::move(int p)
{
    indexAlgoDisplayed += p;
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
    return indexAlgoDisplayed == 0;
}

bool MyStandardItem::isEnd()
{
    return(indexAlgoDisplayed == _algo._mvts.size());
}

void MyStandardItem::goToBegin()
{
    indexAlgoDisplayed = 0;
    _algo.indexNextToQueue = 0;
}

void MyStandardItem::goToEnd()
{
    indexAlgoDisplayed = _algo._mvts.size();
}

QList<int> MyStandardItem::getNextMoves()
{
    QList<int> mvts;
    for (int i=indexAlgoDisplayed; i< _algo._mvts.size(); ++i)
        mvts << _algo._mvts[i];

    return mvts;
}

bool MyStandardItem::isSoluce()
{
    return _isSoluce;
}


