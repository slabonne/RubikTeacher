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

#ifndef RUBIKPLAT_H
#define RUBIKPLAT_H

#include <QWidget>
#include "../variables.h"

namespace Ui {
    class RubikPlat;
}

class QFrame;
class QToolButton;
class QPushButton;
class MainWindow;
class Rubik_Croix_Carres;
class Push_Color;

class RubikPlat : public QWidget
{
    Q_OBJECT

public:
    explicit RubikPlat(QWidget *parent = nullptr);
    ~RubikPlat();

    void setEditable();
    Rubik_Croix_Carres    *Rubik = nullptr;

    MainWindow* getMainWindow();


     bool _edit = false;

   unsigned char* getCube();
   unsigned char getCurrentColor(int i);
   void fill_Cube(unsigned char cube[CUBE_SIZE]);
   void change_Color(int i, unsigned char color);
   void change_Current_Color(int i, unsigned char color);
   void Tourner_Face(unsigned char mvt);
   bool check_Cube();
   void Update_Colors();
   void update_Cube(unsigned char colors2[7]);
   QString generer();

public slots :
    void initialiser();
    void vider();
    bool verifier();

 private:
    unsigned char         CurrentColors[2];

    void Mouvement(unsigned char cube[CUBE_SIZE], unsigned char mvt);
    void Permutations(unsigned char cube[CUBE_SIZE], const unsigned char *perm, int sens, bool face_tournee);
    bool check_ColorsFace(unsigned char cube[CUBE_SIZE]);
    bool check_ColorsCube(unsigned char cube[CUBE_SIZE]);
    bool check_SolutionCube(unsigned char cube[CUBE_SIZE]);

private:
    Ui::RubikPlat *ui;
};





#endif // RUBIKPLAT_H
