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

#ifndef __RUBIK_CROIX_CARRES__
#define __RUBIK_CROIX_CARRES__

#include "rubik_croix.h"
#include "../variables.h"


class Rubik_Croix_Carres;
class RubikPlat;
class Rubik_Carre;

class Rubik_Carre : public QFrame
{
    Q_OBJECT

public:
    Rubik_Carre(QWidget *parent, RubikPlat *rubik,  int n);
    Rubik_Carre(int s, int c);

private:
     int     color;
     int N;
     RubikPlat         *Rubik_plat = nullptr;

protected:
    void mousePressEvent(QMouseEvent *event);
};


class Rubik_Croix_Carres : public Rubik_Croix
{
    Q_OBJECT

public:
    Rubik_Croix_Carres(RubikPlat *rubik);
    Rubik_Croix_Carres(RubikPlat *rubik, int s);
    ~Rubik_Croix_Carres();

    unsigned char * getCube() {return Cube; }

    void change_Color(int i, int color);
    void fill_Cube(unsigned char cube[CUBE_SIZE]);
    void initialiser();
    void vider();

signals:
    void needsRepaint();

public slots:
    void RepaintCube();

private:
    RubikPlat      *Rubik_plat = nullptr;;
    Rubik_Carre     *carre[CUBE_SIZE];
    unsigned char  *Cube = nullptr;

private:
    void Build_Rubik_Carres(RubikPlat *rubik);
};

#endif
