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

    int indexAlgoDisplayed = 0;

    AlgoType _type = ALGO;

    bool isSoluce();
    bool _isSoluce = false;
};

#endif // MYSTANDARDITEM_H
