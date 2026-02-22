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

#include "palette.h"
#include "rubik_croix_carres.h"
#include "rubikplat.h"

#include <QMessageBox>
#include <QMouseEvent>
#include <QDebug>
#include <QMessageBox>

Rubik_Croix_Carres::Rubik_Croix_Carres(RubikPlat *rubik)
{
	Build_Rubik_Carres(rubik);
}

Rubik_Croix_Carres::Rubik_Croix_Carres(RubikPlat *rubik, int s) : Rubik_Croix(s)
{
	Build_Rubik_Carres(rubik);
}

void Rubik_Croix_Carres::Build_Rubik_Carres(RubikPlat *rubik)
{
    Rubik_plat = rubik;
    Cube = new unsigned char[54];
    
	for (int f=0; f<6; f++)
	{
		for (int i=0; i<3; i++)
		{
			for (int j=0; j<3; j++)
			{
				int ind = 9*f+3*i+j;
				int y = s*i + gap*(i+1);
				int x = s*j + gap*(j+1);
				carre[ind] = new Rubik_Carre(face[f], Rubik_plat, ind);
				carre[ind]->setFrameStyle(QFrame::StyledPanel | QFrame::Plain);
				carre[ind]->setGeometry(x, y, s, s);
			}
		}
	}


    QObject::connect(this, SIGNAL(needsRepaint()), this, SLOT(RepaintCube()));

    fill_Cube(Variables::Rubik_Cube_Resolu);
}

Rubik_Croix_Carres::~Rubik_Croix_Carres()
{
}



/////////////////////////////////////
// INTERFACE
////////////////////////////////////

void Rubik_Croix_Carres::initialiser()
{
     fill_Cube(Variables::Rubik_Cube_Resolu);
}

void Rubik_Croix_Carres::vider()
{
     fill_Cube(Variables::Rubik_Cube_Vide);
}





void Rubik_Croix_Carres::change_Color(int i, int color)
{
    Cube[i] = color;
    carre[i]->setStyleSheet("QFrame {\nbackground-color : rgb(" + Variables::COLORS[color] + ")\n""}");
}

void Rubik_Croix_Carres::fill_Cube(unsigned char cube[CUBE_SIZE])
{
    for (int i =0; i< 54; ++i)
    {
        Cube[i] = cube[i];
    }
    emit needsRepaint();
}

void Rubik_Croix_Carres::RepaintCube()
{
    for (int f=0; f<6; f++)
    {
         for (int c=0; c<9; c++)
         {
             unsigned char color = Cube[9*f+c];
             carre[9*f+c]->setStyleSheet("QFrame {\nbackground-color : rgb(" + Variables::COLORS[color] + ")\n""}");
         }
    }

    repaint();
}


////////////////////////////////////////////////////////
Rubik_Carre::Rubik_Carre(QWidget *parent, RubikPlat *rubik, int n) : QFrame(parent)
{
     Rubik_plat = rubik;
     N = n;
}

Rubik_Carre::Rubik_Carre(int s, int c) 
{
    color = c;
}


void Rubik_Carre::mousePressEvent(QMouseEvent *event)
{
    if (!Rubik_plat->_edit)
        return;

    int color = Palette::getCurrentColor();
    if (event->buttons() & Qt::LeftButton && color >= 0)
        Rubik_plat->change_Color(N, color);

    else if (event->buttons() & Qt::RightButton)
        Rubik_plat->change_Color(N, 0);

    else
        QMessageBox::warning(NULL, tr("Attention"), tr("Veuillez choisir une couleur dans la palette avant de peindre!"));
}


