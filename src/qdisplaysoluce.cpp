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

#include "mainwindow.h"
#include "mystandarditem.h"
#include "qdisplaysoluce.h"
#include "Cube3D/qthreadmvtface.h"
#include "ResolutionMethod/resolution.h"

#include <QStandardItem>
#include <algorithm>
#include "Cube2D/rubikplat.h"
#include "Cube3D/glrubik.h"

#include <QLabel>


QDisplaySoluce::QDisplaySoluce(QWidget *fenprincipale) : QTreeView(fenprincipale)
{
    setRootIsDecorated(false);
    setSelectionMode(QAbstractItemView::SingleSelection);
    setSelectionBehavior(QAbstractItemView::SelectRows);

    model = new QStandardItemModel(0, 3);

   connect(this, SIGNAL(clicked(QModelIndex)), this, SLOT(displayAlgo(QModelIndex)));
}


void QDisplaySoluce::resizeEvent (QResizeEvent *)
{
    setColumnWidth(0, (width()-60)*2/5);
    setColumnWidth(1, (width()-60)*3/5);
    setColumnWidth(2, 40);
}

void QDisplaySoluce::ClearLog()
{
    model->clear();
    model->setColumnCount(3);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Etape"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Algorithme"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Mvts"));
    setModel(model);

    MainWindow::getInstance()->clearPlayer();
}

int QDisplaySoluce::addAlgo(Algorithm algo, bool soluce)
{
    int n = 0;
    algo.format(_ALGO_UNITAIRE);

    int row = model->rowCount();

    MyStandardItem * aAlgoItem = new MyStandardItem(algo, soluce);
    model->setItem(row, 1, aAlgoItem);

    QStandardItem * title = new QStandardItem(algo._title);
    title->setEditable(false);

    model->setItem(row, 0, title);

    if (algo.isAlgo())
    {
        algo._n_mvts = getNumberMvts(algo._mvts);
    }
    QStandardItem * n_mvts = new QStandardItem(QString::number(algo._n_mvts));
    n_mvts->setEditable(false);

    n = algo._n_mvts;
    if (n >=0 )
        model->setItem(row, 2, n_mvts);

    setFocus();

    return n;
}



void QDisplaySoluce::displayAlgo(const QModelIndex & modelindex)
{
    MainWindow::getInstance()->on_stop_clicked();

    if (!modelindex.isValid())
        return;

    int row = modelindex.row();

    MyStandardItem* item = static_cast<MyStandardItem*>(model->item(row, 1));
    if (!item)
        return;
    Algorithm *algo = item->getAlgo();
    item->indexAlgoDisplayed = 0;
    item->_algo.indexNextToQueue = 0;

     updatePlayer();

     if (item->getType() == END)
         return;

    MainWindow::getInstance()->Rubik1->fill_Cube(algo->_init_cube);
    MainWindow::getInstance()->glRubik->rubik_cube->mapping_Textures(algo->_init_cube);
    MainWindow::getInstance()->Rubik2->fill_Cube(algo->_target_cube);
}

MyStandardItem *QDisplaySoluce::getCurrentAlgo()
{
    int row = getCurrentRow();
    if (row <0 ||  !model || row >= model->rowCount() || !model->item(row,1))
            return NULL;

    MyStandardItem* item =  static_cast<MyStandardItem*>(model->item(row,1));
    return item;
}




int QDisplaySoluce::NextMvt()
{
    MyStandardItem* algo = getCurrentAlgo();
    if (!algo)
        return -1;

    int mvt = algo->getCurrentMvt();
    return mvt;
}

int QDisplaySoluce::PrevMvt()
{
    MyStandardItem* algo = getCurrentAlgo();
    if (!algo)
        return -1;

    int mvt = algo->getPrevMvt();
    if (mvt != _VOID_)
    {
        algo->move(-1);
        updatePlayer();
        return (mvt+18)%36;
    }
    else
        return mvt;
}

bool QDisplaySoluce::Begin(unsigned char cube[CUBE_SIZE])
{
    MyStandardItem* algo = getCurrentAlgo();
    if (!algo)
        return false;

    algo->goToBegin();

    updatePlayer();
    Resolution::Copie_Cube(algo->_algo._init_cube, cube);
    return true;
}

bool QDisplaySoluce::End(unsigned char cube[CUBE_SIZE])
{
    MyStandardItem* algo = getCurrentAlgo();
    if (!algo)
        return false;

    algo->goToEnd();
    updatePlayer();
    Resolution::Copie_Cube(algo->_algo._new_cube, cube);
    return true;
}


QList<int> QDisplaySoluce::getNextMvts()
{
    QList<int> mvts;
    MyStandardItem* algo = getCurrentAlgo();
    if (!algo)
        return mvts;

    mvts = algo->getNextMoves();

    return mvts;
}



void QDisplaySoluce::displaySoluce(Solution *solution)
{
    addLine("*************************", SOLUCE, solution->_list_steps.front()._list_algos.front()._init_cube, Variables::Rubik_Cube_Resolu);
    addLine(solution->_title, SOLUCE, solution->_list_steps.front()._list_algos.front()._init_cube, Variables::Rubik_Cube_Resolu);
    addLine("*************************", SOLUCE, solution->_list_steps.front()._list_algos.front()._init_cube, Variables::Rubik_Cube_Resolu);

    int n_mvts = 0;

    for (std::list<Step>::iterator s = solution->_list_steps.begin(); s != solution->_list_steps.end(); ++s)
    {
        addLine(s->_title, STEP, s->_list_algos.front()._init_cube, s->_list_algos.back()._target_cube);
        for (std::list<Algorithm>::const_iterator a = s->_list_algos.begin(); a != s->_list_algos.end(); ++a)
        {
            n_mvts += addAlgo(*a, true);
        }
    }
    addLine(QString::number(n_mvts), END);


    setCurrentLine(0);
    _autoPlayTo = END;
    next();
}

void QDisplaySoluce::setCurrentLine(int row)
{
     if (row <0)
        row = model->rowCount()-1;

    if (row < model->rowCount())
        selectionModel()->select(QModelIndex(model->index(row, 0)) , QItemSelectionModel::Rows | QItemSelectionModel::ClearAndSelect);

    displayAlgo(QModelIndex(model->index(row, 0)));
}

int QDisplaySoluce::getCurrentRow() const
{
    if (selectionModel()->selectedRows().count() <= 0)
        return -1;
    return  selectionModel()->selectedRows()[0].row();
}










void QDisplaySoluce::play()
{
    MyStandardItem* algo = getCurrentAlgo();
    if (!algo)
        return;

    if (algo->getType() == END)
        return;

    _autoPlayTo = ALGO;

    if (algo->getType() == SOLUCE)
    {
        _autoPlayTo = SOLUCE;
        nextLine();
    }
    else if (algo->getType() == STEP)
    {
        _autoPlayTo = STEP;
        nextLine();
    }
    else
        next();
}

void QDisplaySoluce::next()
{
    MainWindow::getInstance()->disablePlayer();

    MyStandardItem* algo = getCurrentAlgo();
    if (!algo)
        return;

    int nextMvt = algo->_algo.queueNextMove(MainWindow::getInstance()->glRubik, true);

     if (nextMvt == _VOID_ && algo->isSoluce())
       nextLine();
}

void QDisplaySoluce::moveFinished()
{
    MyStandardItem* algo = getCurrentAlgo();
    if (!algo)
        return;

    algo->move(+1);
    updatePlayer();

    if (_autoPlayTo == SINGLE_MOVE )
        return;

    AlgoType type = algo->_type;
    int nextMvt = NextMvt();


    if (nextMvt == _VOID_)
    {
        if (_autoPlayTo == END_LINE)
            return;
        else if (algo->_type == ALGO && _autoPlayTo == ALGO)
            return;
        else if (algo->_type == STEP && _autoPlayTo == STEP)
           return;

        nextLine();
    }
    else
        next();
}

void QDisplaySoluce::nextLine()
{
    int row = getCurrentRow() + 1;

    if (row >= model->rowCount())
        return;
    setCurrentLine(row);

    MyStandardItem* item = static_cast<MyStandardItem*>(model->item(row, 1));
    if (!item)
        return;

    item->indexAlgoDisplayed = 0;
     item->_algo.indexNextToQueue = 0;

    updatePlayer();

    if (item->getType() == END || _autoPlayTo == SINGLE_MOVE)
        return;

    if (item->isSoluce())
    {
        if (_autoPlayTo == STEP && item->getType() == STEP)
            return;

        else if (_autoPlayTo == ALGO && item->getType() == STEP)
            return;

        else
            next();
    }
}



void QDisplaySoluce::updatePlayer()
{
    for (int i=0; i<3; ++i)
        MainWindow::getInstance()->_LabelsMvt[i]->setText("");

    MyStandardItem* algo = getCurrentAlgo();
    if (!algo)
        return;

    if (algo->_type == END)
    {
        MainWindow::getInstance()->disablePlayer();
        for (int i=0; i<3; ++i)
            MainWindow::getInstance()->_LabelsMvt[0]->setText("");
        return;
    }

    int mvt = algo->getPrevMvt();
    MainWindow::getInstance()->_LabelsMvt[0]->setText(Variables::Liste_Mouvements[mvt]);
    MainWindow::getInstance()->enablePrev(mvt != _VOID_);

    int current_mvt = algo->getCurrentMvt();

    MainWindow::getInstance()->_LabelsMvt[1]->setText(Variables::Liste_Mouvements[current_mvt]);

    mvt = algo->getNextMvt();

    MainWindow::getInstance()->_LabelsMvt[2]->setText(Variables::Liste_Mouvements[mvt]);
   MainWindow::getInstance()->enableNext(current_mvt != _VOID_ || (algo->isSoluce() && algo->getType() != END));
}





void QDisplaySoluce::addLine(QString text, AlgoType type, unsigned char cube[], unsigned char target[])
{
    int row = model->rowCount();

    QStandardItem * title = new QStandardItem(text);
    title->setEditable(false);

    MyStandardItem * aAlgoItem = new MyStandardItem(type);
    model->setItem(row, 1, aAlgoItem);

    if (type == SOLUCE || type == STEP)
    {
        QFont * qFont = new QFont();
        qFont->setBold(true);
        title->setFont(*qFont);

        Resolution::Copie_Cube(cube, aAlgoItem->_algo._init_cube);
        Resolution::Copie_Cube(target, aAlgoItem->_algo._target_cube);
    }

    int col = (type == END ? 2 : 0);
    model->setItem(row, col, title);
}






void QDisplaySoluce::addStep(Step step)
{
    std::list<unsigned char> mvts;
    Algorithm algo2(step._title, step._list_algos.front()._init_cube,
                    step._list_algos.back()._new_cube,
                    step._list_algos.back()._target_cube,
                    mvts, false);

    step._n_mvts = getNumberMvts(step);
    algo2._n_mvts =  step._n_mvts;
    addAlgo(algo2, _ALGO_STEP);

    std::list<Algorithm>::iterator it = step._list_algos.begin();
    for (; it != step._list_algos.end(); it++)
    {
        addAlgo(*it, _ALGO);
    }

}

void QDisplaySoluce::addSolution(Solution soluce)
{
    Algorithm algo1;
    std::list<unsigned char> mvts;
    Algorithm algo2(soluce._title, soluce._list_steps.front()._list_algos.front()._init_cube,
                                   soluce._list_steps.back()._list_algos.back()._new_cube,
                                   soluce._list_steps.back()._list_algos.back()._target_cube,
                                   mvts, false);
    algo1 = algo2;
    algo1._title = "****************";
    algo1._n_mvts = -1;

    soluce._n_mvts = getNumberMvts(soluce);
    algo2._n_mvts = soluce._n_mvts;

    addAlgo(algo1, _ALGO_SOLUCE);
    addAlgo(algo2, _ALGO_SOLUCE);
    addAlgo(algo1, _ALGO_SOLUCE);

    for (std::list<Step>::const_iterator it = soluce._list_steps.begin(); it != soluce._list_steps.end(); it++)
    {
        addStep(*it);
    }
    addBreakLine();
}

void QDisplaySoluce::addBreakLine()
{
    Algorithm algo("");
    addAlgo(algo, _END_SOLUCE);
}



void QDisplaySoluce::Play_Next_Algo()
{
   int i = currentIndex().row()+1;
 
    QModelIndex qmodelindex0 = model->index(i,0);

    setCurrentIndex(qmodelindex0);

    setSelectionMode(QAbstractItemView::SingleSelection);
}


int QDisplaySoluce::getNumberMvts(const std::vector<unsigned char> &algo)
{
    int n = 0;
    unsigned char prev_mvt = -1;

    unsigned char mvts[] = {U, L, F, D, R, B, MX, MY, MZ, u, l ,f, d, r, b, U_, L_, F_, D_, R_, B_, MX_, MY_, MZ_, u_, l_ ,f_, d_, r_, b_};
    std::list<unsigned char> liste_mvts(mvts, mvts + sizeof(mvts) / sizeof(unsigned char));

    for (std::vector<unsigned char>::const_iterator it = algo.begin(); it != algo.end(); it++)
    {
        if ((*it != prev_mvt) && binary_search(liste_mvts.begin(), liste_mvts.end(), *it))
            n++;
        prev_mvt = *it;
    }
    return n;
}

int QDisplaySoluce::getNumberMvts(const Solution &soluce)
{
    int n = 0;
    for (std::list<Step>::const_iterator it = soluce._list_steps.begin(); it != soluce._list_steps.end(); it++)
    {
        n += getNumberMvts(*it);
    }
    return n;
}

int QDisplaySoluce::getNumberMvts(const Step &step)
{
    int n = 0;
    for (std::list<Algorithm>::const_iterator it = step._list_algos.begin(); it != step._list_algos.end(); it++)
    {
        n += getNumberMvts(it->_mvts);
    }
    return n;
}
