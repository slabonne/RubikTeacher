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

#include "cube.h"
#include "../variables.h"

int Face_U[9] = {20,19,18,21,24,25,26,23,22};
int Face_B[9] = {24,25,26,17,8,7,6,15,16};
int Face_L[9] = {18,21,24,15,6,3,0,9,12};
int Face_D[9] = {2,1,0,3,6,7,8,5,4};
int Face_F[9] = {18,19,20,11,2,1,0,9,10};
int Face_R[9] = {20,23,26,17,8,5,2,11,14};
int Face_MX[9] = {7,4,1,10,19,22,25,16,13};
int Face_MY[9] = {21,22,23,14,5,4,3,12,13};
int Face_MZ[9] = {15,16,17,14,11,10,9,12,13};

int mapping_textures_table[54][2] = {{24, 0},{25, 0},{26, 0}, {21, 0},{22, 0},{23, 0},{18, 0},{19, 0},{20, 0},{6, 1},{7, 1},{8, 1},{15, 1},{16, 1},{17, 1},{24, 1},{25, 1},{26, 1},{6, 2},{15, 2},{24, 2},{3, 2},{12, 2}, {21, 2},{ 0, 2},{ 9, 2},{ 18, 2},{0, 3},{ 1, 3},{ 2, 3},{3, 3},{4, 3},{5, 3},{6, 3},{7, 3},{8, 3},{ 18, 4}, {19, 4}, {20, 4}, {9, 4},{10, 4}, {11, 4},{0, 4},{1, 4},{2, 4},{26, 5},{17, 5},{8, 5},{23, 5},{14, 5}, {5, 5},{20, 5},{11, 5},{2, 5}};

Cube::Cube(double x, double y, double z, double size)
{
    Ox = x;
    Oy = y;
    Oz = z;
    Size = size;

    for (int i=0;i<3;i++)
    {
        for (int j=0;j<3;j++) 
        {
            for (int k=0;k<3;k++) 
            {
                coins[k+3*j+9*i].p[0] = Ox-size+k*size;
                coins[k+3*j+9*i].p[1] = Oy-size+j*size;
                coins[k+3*j+9*i].p[2] = Oz-size+i*size;  
                coins[k+3*j+9*i].r[0] = 0;
                coins[k+3*j+9*i].r[1] = 0;
                coins[k+3*j+9*i].r[2] = 0;   
                coins[k+3*j+9*i].l = sqrt(pow(Ox-size+i*size,2)+pow(Ox-size+j*size,2)+pow(Ox-size+k*size,2)); 
                for (int m=0; m<6; m++) 
                {  
                    coins[k+3*j+9*i].index_textures[m] = 7;//m+1;
                }
                pieces_cube[k+3*j+9*i] = k+3*j+9*i;
            }
        }
    }

    mapping_Textures(Variables::Rubik_Cube_Resolu);
}



void Cube::mapping_Textures(unsigned char cube[54])
{
    for (int i=0; i<54; i++)
    {
        coins[pieces_cube[mapping_textures_table[i][0]]].index_textures[mapping_textures_table[i][1]] = cube[i];
    }   
}

void Cube::Mouvement(int mvt, double speed, bool mvt_fini)
{
     switch(mvt)
     {
          case U : Tourner_Face(Face_U, HORAIRE, speed, mvt_fini);
               break;;     
          case B : Tourner_Face(Face_B, ANTI_HORAIRE, speed, mvt_fini);
               break;
          case L : Tourner_Face(Face_L, ANTI_HORAIRE, speed, mvt_fini);
               break;
          case D : Tourner_Face(Face_D, ANTI_HORAIRE, speed, mvt_fini);
               break;
          case F : Tourner_Face(Face_F, HORAIRE, speed, mvt_fini);
               break;
          case R : Tourner_Face(Face_R, HORAIRE, speed, mvt_fini);
               break;
          case U_ : Tourner_Face(Face_U, ANTI_HORAIRE, speed, mvt_fini);
               break;
          case B_ : Tourner_Face(Face_B, HORAIRE, speed, mvt_fini);
               break;
          case L_ : Tourner_Face(Face_L, HORAIRE, speed, mvt_fini);
               break;
          case D_ : Tourner_Face(Face_D, HORAIRE, speed, mvt_fini);
               break;
          case F_ : Tourner_Face(Face_F, ANTI_HORAIRE, speed, mvt_fini);
               break;
          case R_ : Tourner_Face(Face_R, ANTI_HORAIRE, speed, mvt_fini);
               break;     
          
          case MX : Tourner_Face(Face_MX, HORAIRE, speed, mvt_fini);
               break;
          case MY : Tourner_Face(Face_MY, HORAIRE, speed, mvt_fini);
               break;
          case MZ : Tourner_Face(Face_MZ, HORAIRE, speed, mvt_fini);
               break;    
          case MX_ : Tourner_Face(Face_MX, ANTI_HORAIRE, speed, mvt_fini);
               break;
          case MY_ : Tourner_Face(Face_MY, ANTI_HORAIRE, speed, mvt_fini);
               break;
          case MZ_ : Tourner_Face(Face_MZ, ANTI_HORAIRE, speed, mvt_fini);
               break;    
               
          case u :
               Tourner_Face(Face_U, HORAIRE, speed, mvt_fini);
               Tourner_Face(Face_MZ, HORAIRE, speed, mvt_fini);
               break;;     
          case b :
               Tourner_Face(Face_B, ANTI_HORAIRE, speed, mvt_fini);
               Tourner_Face(Face_MY, ANTI_HORAIRE, speed, mvt_fini);
               break;
          case l :
               Tourner_Face(Face_L, ANTI_HORAIRE, speed, mvt_fini);
               Tourner_Face(Face_MX, ANTI_HORAIRE, speed, mvt_fini);
               break;
          case d :
               Tourner_Face(Face_D, ANTI_HORAIRE, speed, mvt_fini);
               Tourner_Face(Face_MZ, ANTI_HORAIRE, speed, mvt_fini);
               break;
          case f :
               Tourner_Face(Face_F, HORAIRE, speed, mvt_fini);
               Tourner_Face(Face_MY, HORAIRE, speed, mvt_fini);
               break;
          case r :
               Tourner_Face(Face_R, HORAIRE, speed, mvt_fini);
               Tourner_Face(Face_MX, HORAIRE, speed, mvt_fini);
               break;
          case u_ :
               Tourner_Face(Face_U, ANTI_HORAIRE, speed, mvt_fini);
               Tourner_Face(Face_MZ, ANTI_HORAIRE, speed, mvt_fini);
               break;;     
          case b_ :
               Tourner_Face(Face_B, HORAIRE, speed, mvt_fini);
               Tourner_Face(Face_MY, HORAIRE, speed, mvt_fini);
               break;
          case l_ :
               Tourner_Face(Face_L, HORAIRE, speed, mvt_fini);
               Tourner_Face(Face_MX, HORAIRE, speed, mvt_fini);
               break;
          case d_ :
               Tourner_Face(Face_D, HORAIRE, speed, mvt_fini);
               Tourner_Face(Face_MZ, HORAIRE, speed, mvt_fini);
               break;
          case f_ :
               Tourner_Face(Face_F, ANTI_HORAIRE, speed, mvt_fini);
               Tourner_Face(Face_MY, ANTI_HORAIRE, speed, mvt_fini);
               break;
          case r_ :
               Tourner_Face(Face_R, ANTI_HORAIRE, speed, mvt_fini);
               Tourner_Face(Face_MX, ANTI_HORAIRE, speed, mvt_fini);
               break;
           
           case RX :
                Tourner_Face(Face_L, HORAIRE, speed, mvt_fini);
                Tourner_Face(Face_MX, HORAIRE, speed, mvt_fini);
                Tourner_Face(Face_R, HORAIRE, speed, mvt_fini);
                break;
           case RY :
                Tourner_Face(Face_F, HORAIRE, speed, mvt_fini);
                Tourner_Face(Face_MY, HORAIRE, speed, mvt_fini);
                Tourner_Face(Face_B, HORAIRE, speed, mvt_fini);
                break;
           case RZ :
                Tourner_Face(Face_U, HORAIRE, speed, mvt_fini);
                Tourner_Face(Face_MZ, HORAIRE, speed, mvt_fini);
                Tourner_Face(Face_D, HORAIRE, speed, mvt_fini);
                break;         
          
          case RX_ :
                Tourner_Face(Face_L, ANTI_HORAIRE, speed, mvt_fini);
                Tourner_Face(Face_MX, ANTI_HORAIRE, speed, mvt_fini);
                Tourner_Face(Face_R, ANTI_HORAIRE, speed, mvt_fini);
                break;
           case RY_ :
                Tourner_Face(Face_F, ANTI_HORAIRE, speed, mvt_fini);
                Tourner_Face(Face_MY, ANTI_HORAIRE, speed, mvt_fini);
                Tourner_Face(Face_B, ANTI_HORAIRE, speed, mvt_fini);
                break;
           case RZ_ :
                Tourner_Face(Face_U, ANTI_HORAIRE, speed, mvt_fini);
                Tourner_Face(Face_MZ, ANTI_HORAIRE, speed, mvt_fini);
                Tourner_Face(Face_D, ANTI_HORAIRE, speed, mvt_fini);
                break;         
          default :
               Tourner_Face(Face_U, ANTI_HORAIRE, speed, mvt_fini);
    }
    
}     
     
void Cube::Tourner_Face(int *Face, int sens, double speed, bool mvt_fini)
{
     double *Rot = nullptr;
     double theta = sens * speed;
     double Rot_X[9] = {1, 0, 0, 0, cos(theta), -sin(theta), 0, sin(theta), cos(theta)};  
     double Rot_Y[9] = {cos(theta), 0, -sin(theta), 0, 1, 0, sin(theta), 0, cos(theta)};
     double Rot_Z[9] = {cos(theta), -sin(theta), 0, sin(theta), cos(theta), 0, 0, 0, 1};
     int axe = 0; 
     
     int rx[4] = {0,1,3,4};
     int ry[4] = {2,0,5,3};
     int rz[4] = {5,4,2,1};
     int *r = NULL;
        
     if (Face==Face_U || Face==Face_D || Face==Face_MZ)
     {
         Rot = Rot_Z; 
         r = rz; 
         axe = 2;        
     }
     else if (Face==Face_L || Face==Face_R || Face==Face_MX)
     {
         Rot = Rot_X;
         r = rx;
         axe = 0;  
     }
     else if (Face==Face_F || Face==Face_B || Face==Face_MY)
     {
         Rot = Rot_Y;  
         r = ry; 
         axe = 1; 
         theta *= -1;
     }       
     
     Rotation_Coins(Face, Rot, axe, theta); 
      
     if (mvt_fini)
     {
        Permutations_Pieces(Face, sens, axe, r);
     }    
}     


void Cube::Rotation_Coins(int *Face, double *Rot, int axe, double theta)
{
    for (int k=0; k<9; k++)
    {
         double *p = coins[pieces_cube[Face[k]]].p;
         double p2[3] = {p[0], p[1], p[2]};
 
         for (int i=0; i<3; i++)
         {
             p[i] = 0;
             for (int j=0; j<3; j++)
             {
                 p[i] += Rot[3*i+j]*p2[j];
             }
         }
         for (int i=0; i<3; i++)
         {
             if (i==axe)
             {
                coins[pieces_cube[Face[k]]].r[axe] += theta*180/Pi;
             } else {
                coins[pieces_cube[Face[k]]].r[i] = 0;
             }    
         }
     }

}



void Cube::Permutations_Pieces(int *perm, int sens, int axe, int r[4])
{
	int pieces_cube_copie[27] = {0};
    for (int i=0; i<27; i++)
    {
		pieces_cube_copie[i] = pieces_cube[i];
    }

    for (int i=0; i<8; i++)
    {
		pieces_cube[perm[i]] = pieces_cube_copie[perm[(i+2*sens+8)%8]];
		
        int Text[6] = {0}; 
        for (int j=0; j<6; j++)
        {
            Text[j] = coins[pieces_cube[perm[i]]].index_textures[j];
        }   
        for (int j=0; j<4; j++)
        {
            coins[pieces_cube[perm[i]]].index_textures[r[j]] = Text[r[(j+sens+4)%4]];
        }
        for (int j=0; j<3; j++)
        {
            coins[pieces_cube[perm[i]]].r[j] = 0; 
        }
    }
}
