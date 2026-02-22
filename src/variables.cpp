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

#include "variables.h"
#include "ResolutionMethod/resolution.h"

#include <QDebug>

QString Variables::Liste_Mouvements[37] = {"U","L","F","D","R","B","MX","MY","MZ","u","l","f","d","r","b","RX","RY","RZ","U'","L'","F'","D'","R'","B'","MX'","MY'","MZ'","u'","l'","f'","d'","r'","b'","RX'","RY'","RZ'",""};

// Gris, Bleu, Orange, Blanc, Vert, Rouge, Jaune, Noir
QStringList Variables::COLORS = {"180,180,180", "0,0,255", "255,112,40", "255,255,255",  "0,255,0", "255,0,0", "255,255,0", "0,0,0"};
QStringList Variables::Colors_Cube3D = {
        ":/colors/grey",
        ":/colors/blue",
        ":/colors/orange",
        ":/colors/white",
        ":/colors/green",
        ":/colors/red",
        ":/colors/yellow",
        ":/colors/black"
    };



bool Variables::_UNBLOCKED = true;
bool Variables::_ALLOW_LOGS_ = false;
bool Variables::_ALLOW_FILLCOLORS_ = true;
bool Variables::_ALLOW_CUBECODE_ = true;
bool Variables::_ALLOW_DISPLAY_SOLUCE_ = true;
bool Variables::_ALLOW_REGRESSION_ = true;
bool Variables::_ALLOW_LEARNING_MODE_ = true;
bool Variables::_ALLOW_DISPLAY_DESCRIPTIONS_ = true;


unsigned char Variables::Rubik_Cube_Resolu[CUBE_SIZE] =  	{1,1,1,1,1,1,1,1,1,
                                                            2,2,2,2,2,2,2,2,2,
                                                            3,3,3,3,3,3,3,3,3,
                                                            4,4,4,4,4,4,4,4,4,
                                                            5,5,5,5,5,5,5,5,5,
                                                            6,6,6,6,6,6,6,6,6};
							 
unsigned char Variables::Rubik_Cube_Vide[CUBE_SIZE] =   	{0};

Variables::Variables()
{
}

void Variables::Update_Colors(unsigned char colors[7])
{
    QStringList COLORS2 = COLORS;
    QStringList Colors_Cube3D_2 = Colors_Cube3D;

    for (unsigned int i=0; i<7; i++)
    {
        COLORS[i] = COLORS2[colors[i]];
        Colors_Cube3D[i] = Colors_Cube3D_2[colors[i]];
    }
}

Algorithm::Algorithm(QString title, unsigned char init_cube[CUBE_SIZE], unsigned char new_cube[CUBE_SIZE], unsigned char target_cube[CUBE_SIZE], std::vector<unsigned char> mvts, bool bold)
{
    _title = title;
    Resolution::Copie_Cube(init_cube, _init_cube);
    Resolution::Copie_Cube(new_cube, _new_cube);
    Resolution::Copie_Cube(target_cube, _target_cube);
    _mvts = mvts;
    _display = bold;
     _n_mvts = 0;
     _beginStep = false;
}

Algorithm::Algorithm(QString title, unsigned char init_cube[CUBE_SIZE], unsigned char new_cube[CUBE_SIZE], unsigned char target_cube[CUBE_SIZE], std::list<unsigned char> mvts, bool bold)
{
    _title = title;
    Resolution::Copie_Cube(init_cube, _init_cube);
    Resolution::Copie_Cube(new_cube, _new_cube);
    Resolution::Copie_Cube(target_cube, _target_cube);
    _mvts.assign(mvts.begin(), mvts.end());
    _display = bold;
     _n_mvts = 0;
     _beginStep = false;
}


Algorithm::Algorithm(unsigned char init_cube[CUBE_SIZE], std::vector<unsigned char> mvts, QString icon)
{
    Resolution::Copie_Cube(init_cube, _init_cube);
    _mvts = mvts;
    _display = true;
     _n_mvts = 0;
          _beginStep = false;

    _icon = QIcon(icon);
}

Algorithm::Algorithm(QString title)
{
    _title = title;
    _n_mvts = 0;
    _display = false;
    _beginStep = false;
}

Algorithm::Algorithm(const Algorithm &s)
{
    _title = s._title;
    Resolution::Copie_Cube(s._init_cube, _init_cube);
    Resolution::Copie_Cube(s._new_cube, _new_cube);
    Resolution::Copie_Cube(s._target_cube, _target_cube);
    _mvts =s._mvts;
    _n_mvts = s._n_mvts;
    _format = s._format;
}

Algorithm Algorithm::operator=(const Algorithm &s)
{
    _title = s._title;
    Resolution::Copie_Cube(s._init_cube, _init_cube);
    Resolution::Copie_Cube(s._new_cube, _new_cube);
   Resolution::Copie_Cube(s._target_cube, _target_cube);
    _mvts =s._mvts;
    _n_mvts = s._n_mvts;
   _format = s._format;

   return *this;
}

Step::Step(QString title)
{
    _title = title;
    _n_mvts = 0;
}

Solution::Solution(QString title)
{
    _title = title;
    _n_mvts = 0;
}

std::vector<unsigned char> Solution::getMvts()
{
    std::vector<unsigned char> mvts;
    foreach(Step step, _list_steps)
    {
        foreach(Algorithm algo, step._list_algos)
        {
            foreach(int mvt, algo._mvts)
            {
                mvts.push_back(mvt);
            }
        }

    }
    return mvts;
}


void Algorithm::formatTitleSoluce()
{
    _beginStep = false;
    _beginSoluce = true;
    _endSoluce = false;
    _display = true;
    _bold = true;
}

void Algorithm::formatTitleStep()
{
    _beginStep = true;
    _beginSoluce = false;
    _endSoluce = false;
    _display = true;
    _bold = true;
}

void Algorithm::formatAlgo()
{
    _beginStep = false;
    _beginSoluce = false;
    _endSoluce = false;
    _display = true;
    _bold = false;
}

void Algorithm::formatAlgoUnitaire()
{
    _beginStep = false;
    _beginSoluce = false;
    _endSoluce = false;
    _display = true;
    _bold = false;
}

void Algorithm::formatEndSoluce()
{
    _beginStep = false;
    _beginSoluce = false;
    _endSoluce = true;
    _display = true;
    _bold = false;
}

void Algorithm::format(int format)
{
    _format = format;
    switch(format)
    {
        case _ALGO :            formatAlgo();
                                break;
        case _ALGO_UNITAIRE :   formatAlgoUnitaire();
                                break;
        case _ALGO_STEP :       formatTitleStep();
                                break;
        case _ALGO_SOLUCE :     formatTitleSoluce();
                                break;
        case _END_SOLUCE :      formatEndSoluce();
                                break;
        default:                break;
    }
}

std::vector<unsigned char> Algorithm::getMvts(bool updatePlayer)
{
    if (!updatePlayer)
        return _mvts;

    std::vector<unsigned char> mvts;
    foreach(unsigned char mvt, _mvts)
    {
        mvts.push_back(mvt);
        mvts.push_back(UPDATE_PLAYER_NEXT);
    }
    return mvts;
}

bool Algorithm::isAlgo()
{
    return (_format == _ALGO || _format == _ALGO_UNITAIRE);
}
