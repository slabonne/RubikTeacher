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

#ifndef VARIABLES_H
#define VARIABLES_H

#include <QAbstractItemModel>
#include <QIcon>


#define	_CUBE_ROWS_   	3
#define	_CUBE_FACES_ 	6
#define	CUBE_SIZE (_CUBE_ROWS_ * _CUBE_ROWS_ * _CUBE_FACES_)


const double Pi = 3.14159265358979323846;

enum {HORAIRE=-1, ANTI_HORAIRE=1};

enum {U=0, L, F, D, R, B, MX, MY, MZ, u, l ,f, d, r, b, RX, RY, RZ, U_, L_, F_, D_, R_, B_, MX_, MY_, MZ_, u_, l_ ,f_, d_, r_, b_, RX_, RY_, RZ_, _VOID_,  UPDATE_PLAYER_NEXT}; //START_CHRONO, STOP_CHRONO,

enum { _ALGO, _ALGO_UNITAIRE, _ALGO_STEP, _ALGO_SOLUCE, _END_SOLUCE };

enum Color { GREY = 0, BLUE, ORANGE, WHITE, GREEN, RED, YELLOW, BLACK };



// Cube 2D
const unsigned char perm_U_[20] = {15,16,17,45,48,51,38,37,36,26,23,20,0,1,2,5,8,7,6,3};
const unsigned char perm_B_[20] = {0,1,2,45,46,47,35,34,33,18,19,20,15,16,17,14,11,10,9,12};
const unsigned char perm_L_[20] = {33,30,27,42,39,36,6,3,0,15,12,9,18,21,24,25,26,23,20,19};
const unsigned char perm_F_[20] = {6,7,8,51,52,53,29,28,27,24,25,26,36,37,38,41,44,43,42,39};
const unsigned char perm_R_[20] = {35,32,29,44,41,38,8,5,2,17,14,11,47,50,53,52,51,48,45,46};
const unsigned char perm_D_[20] = {9,10,11,47,50,53,44,43,42,24,21,18,33,34,35,32,29,28,27,30};
const unsigned char perm_Mx_[12] = {34,31,28,43,40,37,7,4,1,16,13,10};
const unsigned char perm_My_[12] = {21,22,23,3,4,5,48,49,50,32,31,30};
const unsigned char perm_Mz_[12] = {12,13,14,46,49,52,41,40,39,25,22,19};



class GLRubik;

class Variables
{
public:
    Variables();

    static QString Liste_Mouvements[37];
    static QStringList COLORS;
    static QStringList Colors_Cube3D;

    static unsigned char Rubik_Cube_Resolu[CUBE_SIZE];
    static unsigned char Rubik_Cube_Vide[CUBE_SIZE];

    static void Update_Colors(unsigned char colors[7]);

    static bool _UNBLOCKED;
    static bool _ALLOW_LOGS_;
    static bool _ALLOW_FILLCOLORS_;
    static bool _ALLOW_CUBECODE_;
    static bool _ALLOW_DISPLAY_SOLUCE_;
    static bool _ALLOW_REGRESSION_;
    static bool _ALLOW_LEARNING_MODE_;
    static bool _ALLOW_DISPLAY_DESCRIPTIONS_;
};


struct Algorithm
{
	QString          		_title;
    unsigned char    		_init_cube[CUBE_SIZE] = {0};
    unsigned char   			_new_cube[CUBE_SIZE] = {0};
    unsigned char  			_target_cube[CUBE_SIZE] = {0};
    std::vector<unsigned char> 	_mvts;

    int              		_n_mvts = 0;
	QModelIndex      		_qmodelIndex;
	QIcon            		_icon;

    bool             		_beginStep = false;
    bool             		_beginSoluce = false;
    bool             		_endSoluce = false;
    bool             		_display = false;
    bool             		_bold = false;
    int              		_format = 0;

	Algorithm() {};
    Algorithm(QString title, unsigned char init_cube[CUBE_SIZE], unsigned char new_cube[CUBE_SIZE], unsigned char target_cube[CUBE_SIZE], std::vector<unsigned char> mvts, bool bold = true);
    Algorithm(QString title, unsigned char init_cube[CUBE_SIZE], unsigned char new_cube[CUBE_SIZE], unsigned char target_cube[CUBE_SIZE], std::list<unsigned char> mvts, bool bold = true);
    Algorithm(unsigned char init_cube[CUBE_SIZE], std::vector<unsigned char> mvts, QString icon = "");
	Algorithm(QString title);

    Algorithm(const Algorithm&);
     Algorithm operator=(const Algorithm&);

	void formatTitleSoluce();
	void formatTitleStep();
	void formatAlgo();
	void formatAlgoUnitaire();
	void formatEndSoluce();
	void format(int format);

    std::vector<unsigned char>getMvts(bool updatePlayer = false);

	bool isAlgo();

    int queueNextMove(GLRubik* glRubik, bool updatePlayer);
    int indexNextToQueue = 0;
};

struct Step
{
   QString         	_title;
   std::list<Algorithm>	_list_algos;
   int            	_n_mvts = 0;

   Step() {};
   Step(QString title);
};

struct Solution
{
   QString 		_title;
   std::list<Step> 	_list_steps;
   int     		_n_mvts = 0;

   Solution() {};
   Solution(QString title);

    std::vector<unsigned char> 	getMvts();
};


#endif // VARIABLES_H
