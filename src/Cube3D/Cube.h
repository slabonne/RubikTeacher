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

# ifndef __CUBE__
# define __CUBE__

#include <QOpenGLWidget>
#include <math.h>
#include <QtGui>

struct Coin
{
  double p[3];
  double r[3];
  GLuint *texture[6];
  int index_textures[6];
  double l;
};

class Cube
{
public:
    Cube(double x=0, double y=0, double z=0, double size=1);

    Coin    coins[27];

    void Mouvement(int mvt, double speed, bool mvt_fini);
    void mapping_Textures(unsigned char cube[54]);

private:
    double Ox,Oy,Oz;	// Origine du cube
    double Size;
    GLuint *textures[7];
    int pieces_cube[27];
    int coin_cube;

    void Tourner_Face(int *Face, int sens, double speed, bool mvt_fini);
    void Rotation_Coins(int *Face, double *Rot, int axe, double theta);
    void Permutations_Pieces(int *perm, int sens, int axe, int r[4]);
};

#endif
