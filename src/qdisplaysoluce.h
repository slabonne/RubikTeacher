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

#ifndef QDISPLAYSOLUCE_H
#define QDISPLAYSOLUCE_H

#include <QTreeView>
#include "variables.h"
#include "mystandarditem.h"


class QStandardItemModel;
class MainWindow;
class MyStandardItem;
class QSemaphore;


class QDisplaySoluce : public QTreeView
{
    Q_OBJECT

public:
    explicit QDisplaySoluce(QWidget *parent = nullptr);

    AlgoType _autoPlayTo = END;

    void setCurrentLine(int row);
    int getCurrentRow() const;


    void play();
    void autoNext();
    void next();

    void moveFinished();

    int    addAlgo(Algorithm algo, bool isSoluce = false);
    void    addStep(Step step);
    void    addSolution(Solution soluce);
    void    addBreakLine();


    int     PrevMvt();
    int     NextMvt();
    bool    Begin(unsigned char cube[CUBE_SIZE]);
    bool    End(unsigned char cube[CUBE_SIZE]);
    bool    isEndStep();

    void    Play_Next_Algo();
    void    updatePlayer();

    static int getNumberMvts(const std::vector<unsigned char> &algo);
    static int getNumberMvts(const Step &step);
    static int getNumberMvts(const Solution &soluce);

    QList<int> getNextMvts();

    void displaySoluce(Solution* solution);

    void addLine(QString text, AlgoType type,  unsigned char cube[CUBE_SIZE]= {0}, unsigned char target[CUBE_SIZE] = {0});

public slots :
    void displayAlgo(const QModelIndex & modelindex);
    void nextLine();
    void ClearLog();

private:
    QStandardItemModel  *model = nullptr;
    MyStandardItem* getCurrentAlgo();

protected:
    void resizeEvent ( QResizeEvent * event );
};

#endif // QDISPLAYSOLUCE_H
