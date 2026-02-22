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

#include "QDisplaySoluce.h"
#include "Regression.h"

#include <QBoxLayout>
#include <QFile>
#include <QLabel>
#include <QProgressBar>
#include <QPushButton>
#include <QStandardItem>
#include <QTableView>


Regression::Regression(std::map<QString, Resolution * > map_methodes)
{
    // Construction fenêtre
     setWindowTitle("Validation des méthodes de résolution");

     QVBoxLayout * v1 = new QVBoxLayout;
	 
        QHBoxLayout * h1 = new QHBoxLayout;
            _progressBar = new QProgressBar(this);
            _progressBar->setTextVisible(false);
        h1->addWidget(_progressBar);

            _startRegression = new QPushButton("START");
            _startRegression->setFixedWidth(100);
            h1->addWidget(_startRegression);
    v1->addLayout(h1);

        _statistiques = new QLabel;
        v1->addWidget(_statistiques);

            _nbreMvts = new QLabel;
        v1 ->addWidget(_nbreMvts);
            _displayResultats = new QTableView;
        v1->addWidget(_displayResultats);

    setLayout(v1);
	

    // Initialisation
    _map_methodes = map_methodes;


    int colums = 1+_map_methodes.size();
    _model = new QStandardItemModel(0, colums);

    cleanDisplay();

    setFixedSize(800,600);
	setModal(false);

    QObject::connect(_startRegression, SIGNAL(pressed()), this, SLOT(startRegression()));
    QObject::connect(this, SIGNAL(startStop()), this, SLOT(startStopRegression()));

    
}

Regression::~Regression()
{

}

void Regression::cleanDisplay()
{
	_nTest = 1;
	
    _model->setHeaderData(0, Qt::Horizontal, "Cube");


    _successMap.clear();
    _map_mouvements.clear();

    int i = 0;
    for (std::map<QString, Resolution * >::iterator it = _map_methodes.begin(); it != _map_methodes.end(); it++)
    {
        _successMap[it->first] = 0;
        _model->setHeaderData(1+i, Qt::Horizontal, it->first);
        i++;

        QFile * file = new QFile(QString(it->first)+".txt");
        file->open(QIODevice::WriteOnly | QIODevice::Text);
        file->close();
        delete file;

    }

    _displayResultats->setModel(_model);
    _displayResultats->setColumnWidth(0, 400);
    _displayResultats->setColumnWidth(1, 150);
    _displayResultats->setColumnWidth(2, 150);
}

void Regression::startRegression()
{
	emit startStop();
}
	
void Regression::startStopRegression()
{
    if (_startRegression->text() == "START")
    {
        _startRegression->setText("STOP");
		_thread_regression = new Thread_Regression(this);
        _thread_regression->start();
    }
    else
    {
        _thread_regression->_continue = false;
        _startRegression->setText("START");
    }
}


void Regression::UpdateStats()
{
	QString aResult = "% SUCCESS :                  ";
	for (std::map<QString, int >::iterator it = _successMap.begin(); it != _successMap.end(); it++)
	{
            aResult += "     ";
            aResult += it->first;
            aResult += " : ";
            double pourc = (double)((it->second*100) / _nTest);
            aResult += QString::number(pourc);
            aResult += " %";
	}
        _statistiques->setText(aResult);


	aResult = "Nombre de mouvements : ";
	for (std::map<QString, std::list<int> >::iterator it = _map_mouvements.begin(); it != _map_mouvements.end(); it++)
	{
		aResult += "     ";
		aResult += it->first;
		aResult += " : ";

		int n = 0;
		if (!it->second.empty())
		{
			for (std::list<int>::const_iterator it2 = it->second.begin(); it2 != it->second.end(); it2++)
				n += *it2;
			aResult += QString::number(n/it->second.size());
		}
		else
		{
			aResult += "0";
		}
		aResult += " mvts";
	}
	_nbreMvts->setText(aResult);
	
	update();
}

void Regression::generateRandomCube(unsigned char ioCube[CUBE_SIZE])
{
    unsigned int nMvts = 10+rand()%50;
    _melange = generateRandomSequence(nMvts);

    Resolution::Sequence(Variables::Rubik_Cube_Resolu, _melange, ioCube);
}

std::vector<unsigned char> Regression::generateRandomSequence(unsigned int iMvts)
{
    std::vector<unsigned char> aList;

    unsigned char mvt_prec = 255;
    unsigned char mvt = 0;

    unsigned char mvts[] = {U, L, F, D, R, B, MX, MY, MZ, u, l ,f, d, r, b, U_, L_, F_, D_, R_, B_, MX_, MY_, MZ_, u_, l_ ,f_, d_, r_, b_};
    int n_mvt = sizeof(mvts) / sizeof(unsigned char);

    for (unsigned int i=0; i<iMvts; i++)
    {
        do
        {
            mvt = mvts[rand()%n_mvt];
        } while (mvt_prec==((mvt+18)%36));
        mvt_prec = mvt;

        aList.push_back(mvt);
    }

    return aList;
}


QString Regression::getCube(const unsigned char iCube[CUBE_SIZE])
{
    QString text;
	text += "{";
	for (unsigned int i=0; i<(CUBE_SIZE-1); i++)
	{
                text += QString::number(iCube[i]);
		text += ",";
	}
        text += QString::number(iCube[CUBE_SIZE-1]);
	text += "}";

	return text;
}


void Regression::writeSoluce(QString filename, Solution & soluce, const unsigned char cube[CUBE_SIZE], const int index)
{
    QFile * file = new QFile(filename);
    file->open(QIODevice::Append | QIODevice::WriteOnly | QIODevice::Text);
    QTextStream out(file);

    out << "**********************************************************************************" <<  Qt::endl;
    out << "           CUBE " <<  QString::number(index) << Qt::endl;
    out << "**********************************************************************************" <<  Qt::endl;
    out << "Mélange : " << getStringSequence(_melange) << Qt::endl;
    out << "Cube : " << getCube(cube) << Qt::endl;
    out << "Résolution en : " << QDisplaySoluce::getNumberMvts(soluce) << " mouvements" << Qt::endl << Qt::endl;

    for (std::list<Step>::const_iterator it = soluce._list_steps.begin(); it != soluce._list_steps.end(); it++)
    {
       out << it->_title << Qt::endl;
       for (std::list<Algorithm>::const_iterator it2 = it->_list_algos.begin(); it2 != it->_list_algos.end(); it2++)
       {
           out << "  " <<  it2->_title  <<  "\t" << getStringSequence(it2->_mvts) << Qt::endl;
       }
    }
    out << Qt::endl << Qt::endl << Qt::endl << Qt::endl;

    file->close();
    delete file;
}


QString Regression::getStringSequence(const std::vector<unsigned char> &algo)
{
    QString text;
    for (std::vector<unsigned char>::const_iterator it = algo.begin(); it != algo.end(); it++)
    {
        text += Variables::Liste_Mouvements[*it];
        text += "  ";
    }

    return text;
}
//////////////////////////////////////////////////////////////////////////////////////////

Thread_Regression::Thread_Regression(Regression * regression)
{
	_regression = regression;
	_continue = true;
	srand(time(NULL));
}

void Thread_Regression::run()
{
     _regression->cleanDisplay();

     while (_continue)
    {
        solveNewRandomCube();
    }
}

void Thread_Regression::solveNewRandomCube()
{
    unsigned char cube_init[CUBE_SIZE] = {0};
    _regression->generateRandomCube(cube_init);

    unsigned char cube[CUBE_SIZE] = {0};
    _regression->_model->setItem(_regression->_nTest-1, 0, new QStandardItem(_regression->getCube(cube_init)));
	

    int i = 0;
    for (std::map<QString, Resolution * >::iterator it = _regression->_map_methodes.begin(); it != _regression->_map_methodes.end(); it++)
    {
        Resolution::Copie_Cube(cube_init, cube);

        QString aResult = "Failed";
        if (it->second->solve(cube, _regression->_progressBar))
        {
            aResult = "OK (";
            int n =  QDisplaySoluce::getNumberMvts(it->second->solution);
            aResult += QString::number(n);
            aResult += " mvts)";
            _regression->_successMap[it->first]++;
            _regression->_map_mouvements[it->first].push_back(n);
        }

        _regression->_model->setItem(_regression->_nTest-1, 1+i, new QStandardItem(aResult));

        _regression->writeSoluce(it->first+".txt", it->second->solution, cube_init, _regression->_nTest);

        i++;
    }
	
    _regression->UpdateStats();
    _regression->_nTest++;
}


