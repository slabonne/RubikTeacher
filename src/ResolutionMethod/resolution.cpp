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

#include "resolution.h"

#include "math.h"
#include <QProgressBar>

using namespace std;

////////////////////////////////////////////////////////
// CONSTRUCTEURS
////////////////////////////////////////////////////////

Resolution::Resolution(MainWindow * fenprincipale)
{

     _mainFrame = fenprincipale;
}

void Resolution::fill_map()
{

}



////////////////////////////////////////////////////////
// STATIC METHODS
////////////////////////////////////////////////////////

void Resolution::Copie_Cube(const unsigned char cube[CUBE_SIZE], unsigned char cube_result[CUBE_SIZE])
{
     for (unsigned char i=0; i<CUBE_SIZE; i++)
     {
         cube_result[i] = cube[i];
     }
}

void Resolution::Superpose(const unsigned char cube1[CUBE_SIZE], const unsigned char cube2[CUBE_SIZE], unsigned char cube_res[CUBE_SIZE])
{
    for (unsigned char i=0; i<CUBE_SIZE; i++)
    {
        if (cube1[i]!=0)
        {
            cube_res[i] = cube1[i];
        } else {
            cube_res[i] = cube2[i];
        }
    }
}



////////////////////////////////////////////////////////
// COMPARAISON DE CUBES
////////////////////////////////////////////////////////

bool Resolution::areCubesMatching(const unsigned char iCubeInit[CUBE_SIZE], const unsigned char iTargetCube[CUBE_SIZE], unsigned char iOrientationMvt, std::list<unsigned char> & oAlgo)
{
    unsigned char aTargetCubeEqu[CUBE_SIZE] = {0}, aCubeInit2[CUBE_SIZE] = {0};

    for (int i=0; i<4; i++)
    {
        oAlgo.clear();
        for (int j=0; j<i; j++)
        {
            oAlgo.push_back(iOrientationMvt);
        }

        Sequence(iCubeInit, oAlgo, aCubeInit2);
        Update_Cube_Colors(aCubeInit2, iTargetCube, aTargetCubeEqu);

        if (Resolution_Match(aCubeInit2, aTargetCubeEqu))
        {
            return true;
        }
    }
    oAlgo.clear();
    return false;
}


bool Resolution::Resolution_Match(const unsigned char cube[CUBE_SIZE], const unsigned char target_cube[CUBE_SIZE])
{
    for (int i=0; i<CUBE_SIZE; i++)
    {
        if (target_cube[i]!=0 && cube[i]!=target_cube[i]) 
        {
            return false;
    	}
    }

    return true;
}

////////////////////////////////////////////////////////
// MOUVEMENTS DE CUBE
////////////////////////////////////////////////////////

void Resolution::Permutation(const unsigned char cube[CUBE_SIZE], unsigned char mvt, unsigned char cube_result[CUBE_SIZE])
{
    const unsigned char * perm = NULL;
    bool face_tournee = true;
    int sens = HORAIRE;

    switch(mvt)
    {
       case U:
          perm = perm_U_;
          break;
       case L:
          perm = perm_L_;
          sens = ANTI_HORAIRE;
          break;
       case F:
          perm = perm_F_;
          break;
       case D:
          perm = perm_D_;
          sens = ANTI_HORAIRE;
          break;
       case R:
          perm = perm_R_;
          break;
       case B:
          perm = perm_B_;
          sens = ANTI_HORAIRE;
          break;
       case MX:
          perm = perm_Mx_;
          face_tournee = false;
          break;
       case MY:
          perm = perm_My_;
          face_tournee = false;
          break;
       case MZ:
          perm = perm_Mz_;
          face_tournee = false;
          break;
       case U_:
          perm = perm_U_;
          sens = ANTI_HORAIRE;
          break;
       case L_:
          perm = perm_L_;
          break;
       case F_:
          perm = perm_F_;
          sens = ANTI_HORAIRE;
          break;
       case D_:
          perm = perm_D_;
          break;
       case R_:
          perm = perm_R_;
          sens = ANTI_HORAIRE;
          break;
       case B_:
          perm = perm_B_;
          break;
       case MX_:
          perm = perm_Mx_;
          sens = ANTI_HORAIRE;
          face_tournee = false;
          break;
       case MY_:
          perm = perm_My_;
          sens = ANTI_HORAIRE;
          face_tournee = false;
          break;
       case MZ_:
          perm = perm_Mz_;
          sens = ANTI_HORAIRE;
          face_tournee = false;
          break;
    }

    Copie_Cube(cube, cube_result);

    for (int i=0; i<12; i++)
    {
        cube_result[perm[i]] = cube[perm[(i+3*sens+12)%12]];
    }

    if (face_tournee)
    {
        for (int i=0; i<8; i++)
        {
            cube_result[perm[12+i]] = cube[perm[((i+2*sens+8)%8)+12]];
        }
    }
}



void Resolution::Mouvement(unsigned char cube[CUBE_SIZE], unsigned char mvt)
{
     std::list<unsigned char> liste_mvt;

     switch (mvt)
     {
       case U:
          liste_mvt.push_back(U);
          break;
       case L:
          liste_mvt.push_back(L);
          break;
       case F:
          liste_mvt.push_back(F);
          break;
       case D:
          liste_mvt.push_back(D);
          break;
       case R:
          liste_mvt.push_back(R);
          break;
       case B:
          liste_mvt.push_back(B);
          break;
       case MX:
          liste_mvt.push_back(MX);
          break;
       case MY:
          liste_mvt.push_back(MY);
          break;
       case MZ:
          liste_mvt.push_back(MZ);
          break;
       case u:
          liste_mvt.push_back(U);
          liste_mvt.push_back(MZ);
          break;
       case l:
          liste_mvt.push_back(L);
          liste_mvt.push_back(MX_);
          break;
       case f:
          liste_mvt.push_back(F);
          liste_mvt.push_back(MY);
          break;
       case d:
          liste_mvt.push_back(D);
          liste_mvt.push_back(MZ_);
          break;
       case r:
          liste_mvt.push_back(R);
          liste_mvt.push_back(MX);
          break;
       case b:
          liste_mvt.push_back(B);
          liste_mvt.push_back(MY_);
          break;
       case U_:
          liste_mvt.push_back(U_);
          break;
       case L_:
          liste_mvt.push_back(L_);
          break;
       case F_:
          liste_mvt.push_back(F_);
          break;
       case D_:
          liste_mvt.push_back(D_);
          break;
       case R_:
          liste_mvt.push_back(R_);
          break;
       case B_:
          liste_mvt.push_back(B_);
          break;
       case MX_:
          liste_mvt.push_back(MX_);
          break;
       case MY_:
          liste_mvt.push_back(MY_);
          break;
       case MZ_:
          liste_mvt.push_back(MZ_);
          break;
       case u_:
          liste_mvt.push_back(U_);
          liste_mvt.push_back(MZ_);
          break;
       case l_:
          liste_mvt.push_back(L_);
          liste_mvt.push_back(MX);
          break;
       case f_:
          liste_mvt.push_back(F_);
          liste_mvt.push_back(MY_);
          break;
       case d_:
          liste_mvt.push_back(D_);
          liste_mvt.push_back(MZ);
          break;
       case r_:
          liste_mvt.push_back(R_);
          liste_mvt.push_back(MX_);
          break;
       case b_:
          liste_mvt.push_back(B_);
          liste_mvt.push_back(MY);
          break;
       case RX:
          liste_mvt.push_back(L_);
          liste_mvt.push_back(MX);
          liste_mvt.push_back(R);
          break;
       case RY:
          liste_mvt.push_back(F);
          liste_mvt.push_back(MY);
          liste_mvt.push_back(B_);
          break;
       case RZ:
          liste_mvt.push_back(U);
          liste_mvt.push_back(MZ);
          liste_mvt.push_back(D_);
          break;
       case RX_:
          liste_mvt.push_back(L);
          liste_mvt.push_back(MX_);
          liste_mvt.push_back(R_);
          break;
       case RY_:
          liste_mvt.push_back(F_);
          liste_mvt.push_back(MY_);
          liste_mvt.push_back(B);
          break;
       case RZ_:
          liste_mvt.push_back(U_);
          liste_mvt.push_back(MZ_);
          liste_mvt.push_back(D);
          break;
     }

     unsigned char cube_tmp[CUBE_SIZE] = {0};
     Copie_Cube(cube, cube_tmp);

     for (std::list<unsigned char>::const_iterator it_mvt = liste_mvt.begin();  it_mvt != liste_mvt.end(); it_mvt++)
     {
         Permutation(cube, *it_mvt, cube_tmp);
         Copie_Cube(cube_tmp, cube);
     }
}



void Resolution::Sequence(const unsigned char cube[CUBE_SIZE], const std::vector<unsigned char> algo, unsigned char cube_result[CUBE_SIZE])
{
    Copie_Cube(cube, cube_result);
    for (std::vector<unsigned char>::const_iterator mvt = algo.begin(); mvt != algo.end(); mvt++)
    {
         Mouvement(cube_result, *mvt);
    }
}



void Resolution::Sequence(const unsigned char cube[CUBE_SIZE], const std::list<unsigned char> algo, unsigned char cube_result[CUBE_SIZE])
{
    Copie_Cube(cube, cube_result);
    for (std::list<unsigned char>::const_iterator mvt = algo.begin(); mvt != algo.end(); mvt++)
    {
        Mouvement(cube_result, *mvt);
    }
}






////////////////////////////////////////////////////////
// METHODES DE RESOLUTION
////////////////////////////////////////////////////////

bool Resolution::Resolution_Directe(const unsigned char init_cube[CUBE_SIZE], std::list<unsigned char*>& liste_cubes, unsigned char target_cube[CUBE_SIZE], const std::vector<unsigned char>& Mouvements, std::list<unsigned char>& algo, const int depth_max)
{
    int n = 0;
    double nbre_seq_max = pow(Mouvements.size(),depth_max);
    unsigned char cube[CUBE_SIZE] = {0}, cube_result[CUBE_SIZE] = {0};
    const int n_mvts = Mouvements.size();

    for (std::list<unsigned char*>::iterator it = liste_cubes.begin(); it != liste_cubes.end(); it++)
    {
        Superpose(target_cube, *it, *it);
    }

    while (n<nbre_seq_max)
    {
        Copie_Cube(init_cube, cube);
        algo.clear();

        int seq = n;
        while (seq > 0)
        {
            algo.push_front(Mouvements[(seq-1)%n_mvts]);
            seq -= seq%n_mvts;
            seq /= n_mvts;
        }

        Sequence(cube, algo, cube_result);

        for (std::list<unsigned char*>::iterator it = liste_cubes.begin(); it != liste_cubes.end(); it++)
        {
            if (Resolution_Match(cube_result, *it))
            {
                Copie_Cube(*it, target_cube);
                liste_cubes.erase(it);
                return true;
            }
        }


        n++;
    }

    return false;
}






bool Resolution::Resolution_Algo(unsigned char init_cube[CUBE_SIZE], std::map<QString, Algorithm* > map_algorithms, unsigned char target_cube[CUBE_SIZE], unsigned char new_cube[CUBE_SIZE], std::list<unsigned char>& algo, const std::vector<unsigned char>& Mouvements, QString &oText)
{
    unsigned char cube[CUBE_SIZE] = {0}, cube_result[CUBE_SIZE] = {0}, cube_equ[CUBE_SIZE] = {0};
    Copie_Cube(init_cube, cube_init2);
    Copie_Cube(init_cube, new_cube);


     std::map<int, Algorithm* > sorted_algo_map;
     int i = 0;
     for (std::map<QString, Algorithm* >::const_iterator it = map_algorithms.begin(); it != map_algorithms.end(); it++)
     {
        sorted_algo_map.insert(pair<int, Algorithm*>(i++, it->second));
     }

     std::list<unsigned char> algo_orientation;
     int n=0;
     double nbre_seq_max = pow(4,Mouvements.size());

     while (n<nbre_seq_max)
     {
        Copie_Cube(cube_init2, cube);

        algo_orientation.clear();

        int seq = n++;

        for (int i=1; i<=(seq%4); i++)
        {
            algo_orientation.push_back(Mouvements[0]);
        }
        seq -= seq%4;
        seq /= 4;
        for (int i=1; i<=seq; i++)
        {
            algo_orientation.push_back(Mouvements[1]);
        }

        Copie_Cube(cube_init2, cube);

        Sequence(cube, algo_orientation, cube_result);

        for (std::map<int, Algorithm* >::const_iterator it_algo = sorted_algo_map.begin(); it_algo != sorted_algo_map.end(); it_algo++)
        {
            Update_Cube_Colors(cube_result, it_algo->second->_init_cube, cube_equ);

            if (Resolution_Match(cube_result, cube_equ))
            {
                // Check it has not been solved before
                unsigned char target_cube_equ[CUBE_SIZE] = {0}, target_cube2[CUBE_SIZE] = {0};
                Copie_Cube(target_cube, target_cube2);
                Sequence(target_cube2, algo_orientation, target_cube_equ);

                unsigned char target_cube_final[CUBE_SIZE] = {0}, target_cube_final_equ[CUBE_SIZE] = {0};
                Copie_Cube(it_algo->second->_target_cube, target_cube_final);
                Update_Cube_Colors(target_cube_equ, target_cube_final, target_cube_final_equ);

                if (!Resolution_Match(target_cube_equ, target_cube_final_equ))
                {
                    Copie_Cube(cube_result, new_cube);

                    Sequence(target_cube, algo_orientation, target_cube);

                    std::vector<unsigned char> algo2 = it_algo->second->_mvts;

                    Update_Cube_Colors(cube_result, it_algo->second->_target_cube, cube_equ);

                    unsigned char target_cube2[CUBE_SIZE] = {0};
                    Superpose(target_cube, cube_equ, target_cube2);
                    Copie_Cube(target_cube2, target_cube);

                    algo.clear();
                    algo.assign(algo_orientation.begin(), algo_orientation.end());
                    algo.insert(algo.end(), algo2.begin(), algo2.end());


                    oText = it_algo->second->_title;
                    return true;
                }
            }
         }
     }
     return false;
}





bool Resolution::Resolution_Algo(unsigned char init_cube[CUBE_SIZE], std::map<QString, Algorithm* > map_algorithms, unsigned char target_cube[CUBE_SIZE], unsigned char new_cube[CUBE_SIZE], std::list<unsigned char>& algo, const std::vector<unsigned char>& Mouvements, std::list<unsigned char> & iSequenceOrientation)
{
     unsigned char cube[CUBE_SIZE] = {0}, cube_result[CUBE_SIZE] = {0}, cube_equ[CUBE_SIZE] = {0};
     Copie_Cube(init_cube, new_cube);

     std::multimap<int, Algorithm* > sorted_algo_map;
     for (std::map<QString, Algorithm* >::const_iterator it = map_algorithms.begin(); it != map_algorithms.end(); it++)
     {
         sorted_algo_map.insert(std::pair<int, Algorithm* >(it->second->_mvts.size(), it->second));
     }


     std::list<unsigned char> algo_orientation;
     int n=0;
      int nbre_seq_max = 16;

     while (n<nbre_seq_max)
     {
        Copie_Cube(init_cube, cube);
        algo_orientation.clear();

        int seq = n++;

        std::list<unsigned char>::iterator it_SeqOr = iSequenceOrientation.begin();
        for (int i=1; i<=(seq%4); i++)
        {
            algo_orientation.push_back(*it_SeqOr);
        }
        it_SeqOr++;
        for (int i=1; i<=(seq%4); i++)
        {
            algo_orientation.push_back(*it_SeqOr);
        }

        seq -= seq%4;
        seq /= 4;
        for (int i=1; i<=seq; i++)
        {
            algo_orientation.push_back(Mouvements[0]);
        }

        Copie_Cube(init_cube, cube);

        Sequence(cube, algo_orientation, cube_result);

        for (std::multimap<int, Algorithm* >::const_iterator it_algo = sorted_algo_map.begin(); it_algo != sorted_algo_map.end(); it_algo++)
         {
             Update_Cube_Colors(cube_result, it_algo->second->_init_cube, cube_equ);

             if (Resolution_Match(cube_result, cube_equ))
             {
                // Check it has not been solved before
                unsigned char target_cube_equ[CUBE_SIZE];
                Sequence(target_cube, algo_orientation, target_cube_equ);

                unsigned char target_cube_final[CUBE_SIZE] = {0}, target_cube_final_equ[CUBE_SIZE] = {0};
                Copie_Cube(it_algo->second->_target_cube, target_cube_final);
                Update_Cube_Colors(target_cube_equ, target_cube_final, target_cube_final_equ);

                 if (!Resolution_Match(target_cube_equ, target_cube_final_equ))
                 {
                    Copie_Cube(cube_result, new_cube);

                    Sequence(target_cube, algo_orientation, target_cube);

                    std::vector<unsigned char> algo2 = it_algo->second->_mvts;

                    Update_Cube_Colors(cube_result, it_algo->second->_target_cube, cube_equ);

                    unsigned char target_cube2[CUBE_SIZE];
                    Superpose(target_cube, cube_equ, target_cube2);
                    Copie_Cube(target_cube2, target_cube);

                    algo.clear();
                    algo.assign(algo_orientation.begin(), algo_orientation.end());
                    algo.insert(algo.end(), algo2.begin(), algo2.end());
                    return true;
                 }
             }
         }
     }
     return false;
}



////////////////////////////////////////////////////////
// UPDATE COULEURS CUBE
////////////////////////////////////////////////////////

bool Resolution::Update_Cube_Colors(const unsigned char cube_init[CUBE_SIZE], const unsigned char cube_algo[CUBE_SIZE], unsigned char cube_result[CUBE_SIZE])
{
    unsigned char colors[7] = {0};
    getColorMap(cube_init, colors);

    unsigned char colors_algo[7] = {0};
    getColorMap(cube_algo, colors_algo);

    Copie_Cube(cube_algo, cube_result);
    for (int j=1; j<=6; j++)
    {
        for (int i=0; i<CUBE_SIZE; i++)
        {
            if (cube_algo[i] == colors_algo[j])
            {
                cube_result[i] = colors[j];
            }
        }
    }

    return true;
}


void Resolution::getColorMap(const unsigned char cube[CUBE_SIZE], unsigned char colors[7])
{
    for (int i=1; i<7; i++)
    {
        colors[i] = cube[9*(i-1)+4];
    }
}








bool Resolution::unblockCube(unsigned char cube[CUBE_SIZE], unsigned char iNoMatchCube[CUBE_SIZE], std::vector<unsigned char> & iMouvementsAllowed, std::list<unsigned char> & iUnblockingSequence, std::list<unsigned char> & oAlgo, unsigned char oNewCube[CUBE_SIZE])
{
    unsigned char aNoMatchCubeEqu[CUBE_SIZE] = {0};

    unsigned char aMvt = iMouvementsAllowed.front();

    for (int i = 0; i<4; i++)
    {
        // orientation du cube
        oAlgo.clear();
        for (int j = 0; j<i; j++)
        {
            oAlgo.push_back(aMvt);
        }
        Sequence(cube, oAlgo, oNewCube);

        // calcul du target_cube equivalent à cube
        Update_Cube_Colors(oNewCube, iNoMatchCube, aNoMatchCubeEqu);

        // si cube & target_cube ne correspondent pas...
        if (!Resolution_Match(oNewCube, aNoMatchCubeEqu))
        {
            oAlgo.insert(oAlgo.end(), iUnblockingSequence.begin(), iUnblockingSequence.end());
            return true;
        }
    }
    return false;
}


bool Resolution::unblockCube(unsigned char cube[CUBE_SIZE], unsigned char iNoMatchCube[CUBE_SIZE], std::list<unsigned char> & iSequenceOrientation, std::list<unsigned char> & iUnblockingSequence, std::list<unsigned char> & oAlgo, unsigned char oNewCube[CUBE_SIZE])
{
    unsigned char aNoMatchCubeEqu[CUBE_SIZE] = {0};

    for (int i = 0; i<4; i++)
    {
        // orientation du cube
        oAlgo.clear();
        for (std::list<unsigned char>::const_iterator it = iSequenceOrientation.begin(); it != iSequenceOrientation.end(); it++)
        {
            for (int j = 0; j<i; j++)
            {
                oAlgo.push_back(*it);
            }
        }

        Sequence(cube, oAlgo, oNewCube);

        // calcul du target_cube equivalent à cube
        Update_Cube_Colors(oNewCube, iNoMatchCube, aNoMatchCubeEqu);

        // si cube & target_cube ne correspondent pas...
        if (!Resolution_Match(oNewCube, aNoMatchCubeEqu))
        {
            oAlgo.insert(oAlgo.end(), iUnblockingSequence.begin(), iUnblockingSequence.end());
            return true;
        }
    }
    return false;
}




////////////////////////////////////////////////////////
// OPERATIONS SUR LES ALGORITHMES
////////////////////////////////////////////////////////


void Resolution::addAlgo(QString iText, list<unsigned char> & iAlgo, unsigned char ioCube[CUBE_SIZE], unsigned char iTargetCube[CUBE_SIZE], Step & ioStep)
{
    unsigned char aNewCube[CUBE_SIZE] = {0};

    std::vector<unsigned char> aAlgo;
    aAlgo.assign(iAlgo.begin(), iAlgo.end());
    SimplifyAlgo(aAlgo);
    Sequence(ioCube, aAlgo, aNewCube);
    Algorithm Algo(iText, ioCube, aNewCube, iTargetCube, aAlgo);
    ioStep._list_algos.push_back(Algo);

    Copie_Cube(aNewCube, ioCube);
}

void Resolution::SimplifyAlgo(std::vector<unsigned char> &algo)
{
    if (algo.empty())
        return;

    std::vector<unsigned char> algo2;
    algo2 = algo;

    std::list<std::pair<unsigned char, unsigned char> > list_mvts;

    std::vector<unsigned char>::const_iterator aIter = algo2.begin();
    int prev_mvt = *aIter;
    int n = 0;
    for (; aIter != algo2.end(); aIter++)
    {
        if (*aIter == prev_mvt)
        {
            n++;
           // prev_mvt = *aIter;
        }
        else if (*aIter == (prev_mvt + 18)%36)
        {
           n += 3 ;
        }
        else
        {
            pair<unsigned char, unsigned char> aListItem;
            aListItem.first = prev_mvt;
            aListItem.second = n%4;
            list_mvts.push_back(aListItem);
            n = 1;
            prev_mvt = *aIter;
        }
    }

    pair<unsigned char, unsigned char> aListItem;
    aListItem.first = prev_mvt;
    aListItem.second = n%4;
    list_mvts.push_back(aListItem);

    algo.clear();
    for (std::list<std::pair<unsigned char, unsigned char> >::const_iterator aIter2 = list_mvts.begin(); aIter2 != list_mvts.end(); aIter2++)
    {
        if (aIter2->second == 3)
        {
             algo.push_back((aIter2->first + 18)%36);
        }
        else
        {
            for (int i = 0; i<aIter2->second; i++)
            {
                algo.push_back(aIter2->first);
            }
        }
    }
}



void Resolution::complete_map(std::map<QString, Algorithm*> & _map)
{
     unsigned char cube[CUBE_SIZE] = {0};

     for  (std::map<QString, Algorithm*>::iterator it = _map.begin(); it != _map.end(); it++)
    {
        it->second->_title = it->first;
        Copie_Cube(it->second->_init_cube, cube);
        Sequence(cube, it->second->_mvts, cube);
        Copie_Cube(cube, it->second->_target_cube);
    }
}

void Resolution::progressStep(int progression)
{
    if (_progressbar != NULL)
    {
        _progressbar->setValue((100*progression)/_progressionMax);
    }
}



bool Resolution::Update_Colors(unsigned char init_cube[CUBE_SIZE], unsigned char final_cube[CUBE_SIZE])
{
    unsigned char colors[7] = {0};
	unsigned char cube[CUBE_SIZE] = {0};
	Copie_Cube(init_cube, cube);

    for (int i=1; i<=6; i++)
	{
        colors[cube[9*(i-1)+4]]++;
	}

    bool error = false;
    for (int i=1; i<=6; i++)
	{
        if (colors[i] != 1)
		{
            error = true;
		}
	}

	unsigned char cube2[CUBE_SIZE] = {0};
    if (!error)
    {
        unsigned char colors2[7] = {0};
        for (int i=1; i<=6; i++)
            colors2[i] = cube[9*(i-1)+4];

		for (int i=0; i<CUBE_SIZE; i++)
		{
			unsigned char ind = 0;
			while (cube[i] != colors2[ind])
				ind++;
			cube2[i] = ind;
		}
    }
	else
	{
		return false;
	}
	
	Copie_Cube(cube2, final_cube);

    return true;
}

bool Resolution::check_ColorsCube(const unsigned char cube[])
{
    int count[7] = {0};

    for (int i=0; i<54; i++)
    {
        if (cube[i] <= 0 || cube[i] > 6)
            return false;
        count[cube[i]]++;
    }

    for (int i=1; i<=6; i++)
    {
        if (count[i]!=9)
            return false;
    }

    return true;
}
