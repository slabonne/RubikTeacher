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
#include <QProgressBar>
#include <algorithm>

using namespace std;

///////////////////////////////////
// First Croix
////////////////////////////////////

unsigned char FirstCroix_01[CUBE_SIZE] = {0,0,0,0,1,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,3,0,0,0,0,0,1,0,0,4,0,0,0,0,0,0,0,0,5,0,0,5,0,0,0,0,0,6,0,0,0,0};
unsigned char FirstCroix_01_alg[] = {F, F};
std::vector<unsigned char> FirstCroix_01_algo(FirstCroix_01_alg, FirstCroix_01_alg + sizeof(FirstCroix_01_alg) / sizeof(unsigned char));


unsigned char FirstCroix_02[CUBE_SIZE] = {0,0,0,0,1,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,4,0,0,0,0,0,0,0,0,5,1,0,0,0,0,0,0,0,6,0,0,5,0};
unsigned char FirstCroix_02_alg[] = {U_, R, U};
std::vector<unsigned char> FirstCroix_02_algo(FirstCroix_02_alg, FirstCroix_02_alg + sizeof(FirstCroix_02_alg) / sizeof(unsigned char));


///////////////////////////////////
// First Layer
////////////////////////////////////

unsigned char FirstLayer_00[CUBE_SIZE] = {0,1,0,1,1,1,0,1,1,0,0,0,0,2,0,0,2,0,0,0,0,0,3,3,0,0,0,0,0,0,0,4,0,0,0,0,0,5,5,0,5,0,0,0,0,0,0,0,6,6,0,6,0,0};
unsigned char FirstLayer_00_alg[] = {};
std::vector<unsigned char> FirstLayer_00_algo(FirstLayer_00_alg, FirstLayer_00_alg + sizeof(FirstLayer_00_alg) / sizeof(unsigned char));

unsigned char FirstLayer_01[CUBE_SIZE] = {0,1,0,1,1,1,0,1,0,0,0,1,0,2,0,0,2,0,0,0,0,0,3,3,0,0,0,0,0,0,0,4,0,0,0,6,0,5,0,0,5,0,0,0,0,0,0,5,6,6,0,0,0,0};
unsigned char FirstLayer_01_alg[] = {F,D_,F_};
std::vector<unsigned char> FirstLayer_01_algo(FirstLayer_01_alg, FirstLayer_01_alg + sizeof(FirstLayer_01_alg) / sizeof(unsigned char));

unsigned char FirstLayer_02[CUBE_SIZE] = {0,1,0,1,1,1,0,1,0,0,0,0,0,2,0,0,2,0,0,0,0,0,3,3,1,0,0,5,0,0,0,4,0,0,0,0,0,5,0,0,5,0,6,0,0,0,0,0,6,6,0,0,0,0};
unsigned char FirstLayer_02_alg[] = {R_,D,R};
std::vector<unsigned char> FirstLayer_02_algo(FirstLayer_02_alg, FirstLayer_02_alg + sizeof(FirstLayer_02_alg) / sizeof(unsigned char));

unsigned char FirstLayer_03[CUBE_SIZE] = {0,1,0,1,1,1,0,1,0,6,0,0,0,2,0,0,2,0,5,0,0,0,3,3,0,0,0,0,0,0,0,4,0,1,0,0,0,5,0,0,5,0,0,0,0,0,0,0,6,6,0,0,0,0};
unsigned char FirstLayer_03_alg[] = {R_,D_,R,D_,R_,D,R};
std::vector<unsigned char> FirstLayer_03_algo(FirstLayer_03_alg, FirstLayer_03_alg + sizeof(FirstLayer_03_alg) / sizeof(unsigned char));

unsigned char FirstLayer_04[CUBE_SIZE] = {0,1,0,1,1,1,0,1,6,0,0,0,0,2,0,0,2,0,0,0,0,0,3,3,0,0,0,0,0,0,0,4,0,0,0,0,0,5,1,0,5,0,0,0,0,0,0,0,6,6,0,5,0,0};
unsigned char FirstLayer_04_alg[] = {R_,D,R,D_,R_,D,R};
std::vector<unsigned char> FirstLayer_04_algo(FirstLayer_04_alg, FirstLayer_04_alg + sizeof(FirstLayer_04_alg) / sizeof(unsigned char));

unsigned char FirstLayer_05[CUBE_SIZE] = {0,1,0,1,1,1,0,1,5,0,0,0,0,2,0,0,2,0,0,0,0,0,3,3,0,0,0,0,0,0,0,4,0,0,0,0,0,5,6,0,5,0,0,0,0,0,0,0,6,6,0,1,0,0};
unsigned char FirstLayer_05_alg[] = {F,D_,F_,D,F,D_,F_};
std::vector<unsigned char> FirstLayer_05_algo(FirstLayer_05_alg, FirstLayer_05_alg + sizeof(FirstLayer_05_alg) / sizeof(unsigned char));


///////////////////////////////////
// F2L
////////////////////////////////////

unsigned char Layer_F2L_00[CUBE_SIZE] = {1,1,1,1,1,1,1,1,0,0,0,0,0,2,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,4,0,0,0,0,0,0,0,0,5,5,0,0,0,0,0,0,0,6,0,0,6,0};
unsigned char Layer_F2L_00_alg[] = {};
std::vector<unsigned char> Layer_F2L_00_algo(Layer_F2L_00_alg, Layer_F2L_00_alg + sizeof(Layer_F2L_00_alg) / sizeof(unsigned char));

unsigned char Layer_F2L_01[CUBE_SIZE] = {1,1,1,1,1,1,1,1,0,0,0,0,0,2,0,0,0,0,0,0,0,0,3,0,0,0,0,0,5,0,0,4,0,0,0,0,0,0,0,0,5,0,0,6,0,0,0,0,0,6,0,0,0,0};
unsigned char Layer_F2L_01_alg[] = {R_,D,R};
std::vector<unsigned char> Layer_F2L_01_algo(Layer_F2L_01_alg, Layer_F2L_01_alg + sizeof(Layer_F2L_01_alg) / sizeof(unsigned char));

unsigned char Layer_F2L_02[CUBE_SIZE] = {1,1,1,1,1,1,1,1,0,0,0,0,0,2,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,4,6,0,0,0,0,0,0,0,5,0,0,0,0,0,0,0,0,6,5,0,0,0};
unsigned char Layer_F2L_02_alg[] = {F,D_,F_};
std::vector<unsigned char> Layer_F2L_02_algo(Layer_F2L_02_alg, Layer_F2L_02_alg + sizeof(Layer_F2L_02_alg) / sizeof(unsigned char));


///////////////////////////////////
// End F2L
////////////////////////////////////
unsigned char Layer_EndF2L_01[CUBE_SIZE] = {1,1,1,1,1,1,1,1,0,0,0,0,2,2,2,2,2,2,0,3,3,0,3,3,5,3,3,6,0,0,0,4,0,0,0,0,5,5,0,5,5,5,1,0,0,6,6,0,6,6,0,0,6,0};
unsigned char Layer_EndF2L_01_alg[] = {R_,D,D,B_,D,D,B,R};
std::vector<unsigned char> Layer_EndF2L_01_algo(Layer_EndF2L_01_alg, Layer_EndF2L_01_alg + sizeof(Layer_EndF2L_01_alg) / sizeof(unsigned char));

unsigned char Layer_EndF2L_02[CUBE_SIZE] = {1,1,1,1,1,1,1,1,0,0,0,6,2,2,2,2,2,2,0,3,3,0,3,3,0,3,3,0,0,0,0,4,0,0,0,5,5,5,0,5,5,5,0,0,0,6,6,1,6,6,0,0,6,0};
unsigned char Layer_EndF2L_02_alg[] = {F,D,D,L,D,D,L_,F_};
std::vector<unsigned char> Layer_EndF2L_02_algo(Layer_EndF2L_02_alg, Layer_EndF2L_02_alg + sizeof(Layer_EndF2L_02_alg) / sizeof(unsigned char));


///////////////////////////////////
// Croix 2
////////////////////////////////////
unsigned char Layer_Croix2_01[CUBE_SIZE] = {0,0,0,0,1,1,0,1,0,2,2,2,2,2,2,0,1,0,3,3,0,3,3,1,3,3,0,4,4,4,4,4,4,4,4,4,0,0,0,5,5,5,5,5,5,0,6,6,0,6,6,0,6,6};
unsigned char Layer_Croix2_01_alg[] = {B,U,L,U_,L_,B_};
std::vector<unsigned char> Layer_Croix2_01_algo(Layer_Croix2_01_alg, Layer_Croix2_01_alg + sizeof(Layer_Croix2_01_alg) / sizeof(unsigned char));

unsigned char Layer_Croix2_02[CUBE_SIZE] = {0,0,0,1,1,1,0,0,0,2,2,2,2,2,2,0,1,0,3,3,0,3,3,0,3,3,0,4,4,4,4,4,4,4,4,4,0,1,0,5,5,5,5,5,5,0,6,6,0,6,6,0,6,6};
unsigned char Layer_Croix2_02_alg[] = {B,L,U,L_,U_,B_};
std::vector<unsigned char> Layer_Croix2_02_algo(Layer_Croix2_02_alg, Layer_Croix2_02_alg + sizeof(Layer_Croix2_02_alg) / sizeof(unsigned char));


///////////////////////////////////
// Orientation Croix 2
////////////////////////////////////
unsigned char Layer_OrientationCroix2_01[CUBE_SIZE] = {0,1,0,1,1,1,0,1,0,2,2,2,2,2,2,0,3,0,3,3,0,3,3,6,3,3,0,4,4,4,4,4,4,4,4,4,0,5,0,5,5,5,5,5,5,0,6,6,2,6,6,0,6,6};
unsigned char Layer_OrientationCroix2_01_alg[] = {L_,U_,U_,L,U,L_,U,L};
std::vector<unsigned char> Layer_OrientationCroix2_01_algo(Layer_OrientationCroix2_01_alg, Layer_OrientationCroix2_01_alg + sizeof(Layer_OrientationCroix2_01_alg) / sizeof(unsigned char));

unsigned char Layer_OrientationCroix2_02[CUBE_SIZE] = {0,1,0,1,1,1,0,1,0,2,2,2,2,2,2,0,6,0,3,3,0,3,3,2,3,3,0,4,4,4,4,4,4,4,4,4,0,5,0,5,5,5,5,5,5,0,6,6,3,6,6,0,6,6};
unsigned char Layer_OrientationCroix2_02_alg[] = {R,U,U,R_,U_,R,U_,R_};
std::vector<unsigned char> Layer_OrientationCroix2_02_algo(Layer_OrientationCroix2_02_alg, Layer_OrientationCroix2_02_alg + sizeof(Layer_OrientationCroix2_02_alg) / sizeof(unsigned char));


///////////////////////////////////
// Placament Coins 3
////////////////////////////////////
unsigned char Layer_PlacementCoin_01[CUBE_SIZE] = {0};
unsigned char Layer_PlacementCoin_01_alg[] = {RZ,R,U_,L,U,R_,U_,L_,U};
list<unsigned char> Layer_PlacementCoin_01_algo(Layer_PlacementCoin_01_alg, Layer_PlacementCoin_01_alg+sizeof(Layer_PlacementCoin_01_alg)/sizeof(unsigned char));

unsigned char Layer_PlacementCoin_02[CUBE_SIZE] = {0};
unsigned char Layer_PlacementCoin_02_alg[] = {RZ_,L_,U,R_,U_,L,U,R,U_};
list<unsigned char> Layer_PlacementCoin_02_algo(Layer_PlacementCoin_02_alg, Layer_PlacementCoin_02_alg+sizeof(Layer_PlacementCoin_02_alg)/sizeof(unsigned char));


///////////////////////////////////
// Orientation Coins 3
////////////////////////////////////
unsigned char OrienteCoin_01[CUBE_SIZE] = {0,1,0,1,1,1,0,1,5,0,0,0,0,2,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,4,0,0,0,0,0,0,6,0,5,0,0,0,0,0,0,0,0,6,0,1,0,0};
unsigned char OrienteCoin_01_alg[] = {F,D_,F_,D,F,D_,F_,D};
std::vector<unsigned char> OrienteCoin_01_algo(OrienteCoin_01_alg, OrienteCoin_01_alg + sizeof(OrienteCoin_01_alg) / sizeof(unsigned char));

unsigned char OrienteCoin_02[CUBE_SIZE] = {0,1,0,1,1,1,0,1,6,0,0,0,0,2,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,4,0,0,0,0,0,0,1,0,5,0,0,0,0,0,0,0,0,6,0,5,0,0};
unsigned char OrienteCoin_02_alg[] = {D_,F,D,F_,D_,F,D,F_};
std::vector<unsigned char> OrienteCoin_02_algo(OrienteCoin_02_alg, OrienteCoin_02_alg + sizeof(OrienteCoin_02_alg) / sizeof(unsigned char));




Resolution_Layer::Resolution_Layer(MainWindow * fenprincipale)
    : Resolution(fenprincipale)
{
    fill_map();
}


void Resolution_Layer::fill_map()
{
    map_algorithms_Croix1["Arete_01"] = new Algorithm(FirstCroix_01, FirstCroix_01_algo, ":/methods/Images/Methods/Layer/Arete_01.png");
    map_algorithms_Croix1["Arete_02"] = new Algorithm(FirstCroix_02, FirstCroix_02_algo, ":/methods/Images/Methods/Layer/Arete_02.png");

    map_algorithms_FirstLayer["FirstLayer_00"] = new Algorithm(FirstLayer_00, FirstLayer_00_algo, ":/methods/Images/Methods/Layer/FirstLayer_00.png");
    map_algorithms_FirstLayer["FirstLayer_01"] = new Algorithm(FirstLayer_01, FirstLayer_01_algo, ":/methods/Images/Methods/Layer/FirstLayer_01.png");
    map_algorithms_FirstLayer["FirstLayer_02"] = new Algorithm(FirstLayer_02, FirstLayer_02_algo, ":/methods/Images/Methods/Layer/FirstLayer_02.png");
    map_algorithms_FirstLayer["FirstLayer_03"] = new Algorithm(FirstLayer_03, FirstLayer_03_algo, ":/methods/Images/Methods/Layer/FirstLayer_03.png");
    map_algorithms_FirstLayer["FirstLayer_04"] = new Algorithm(FirstLayer_04, FirstLayer_04_algo, ":/methods/Images/Methods/Layer/FirstLayer_04.png");
    map_algorithms_FirstLayer["FirstLayer_05"] = new Algorithm(FirstLayer_05, FirstLayer_05_algo, ":/methods/Images/Methods/Layer/FirstLayer_05.png");

    map_algorithms_F2L["F2L_00"] = new Algorithm(Layer_F2L_00, Layer_F2L_00_algo, ":/methods/Images/Methods/Layer/F2L_00.png");
    map_algorithms_F2L["F2L_01"] = new Algorithm(Layer_F2L_01, Layer_F2L_01_algo, ":/methods/Images/Methods/Layer/F2L_01.png");
    map_algorithms_F2L["F2L_02"] = new Algorithm(Layer_F2L_02, Layer_F2L_02_algo, ":/methods/Images/Methods/Layer/F2L_02.png");

    map_algorithms_EndF2L["EndF2L_01"] = new Algorithm(Layer_EndF2L_01, Layer_EndF2L_01_algo, ":/methods/Images/Methods/Layer/EndF2L_01.png");
    map_algorithms_EndF2L["EndF2L_02"] = new Algorithm(Layer_EndF2L_02, Layer_EndF2L_02_algo, ":/methods/Images/Methods/Layer/EndF2L_02.png");


    map_algorithms_Croix2["Croix2_01"] = new Algorithm(Layer_Croix2_01, Layer_Croix2_01_algo, ":/methods/Images/Methods/Layer/Croix2_01.png");
    map_algorithms_Croix2["Croix2_02"] = new Algorithm(Layer_Croix2_02, Layer_Croix2_02_algo, ":/methods/Images/Methods/Layer/Croix2_02.png");

    map_algorithms_OrientationCroix2["OrientationCroix2_01"] = new Algorithm(Layer_OrientationCroix2_01, Layer_OrientationCroix2_01_algo, ":/methods/Images/Methods/Layer/OrientationCroix2_01.png");
    map_algorithms_OrientationCroix2["OrientationCroix2_02"] = new Algorithm(Layer_OrientationCroix2_02, Layer_OrientationCroix2_02_algo, ":/methods/Images/Methods/Layer/OrientationCroix2_02.png");

    map_algorithms_OrientationCoins2["OrienteCoin_01"] = new Algorithm(OrienteCoin_01, OrienteCoin_01_algo, ":/methods/Images/Methods/Layer/OrienteCoin_01.png");
    map_algorithms_OrientationCoins2["OrienteCoin_02"] = new Algorithm(OrienteCoin_02, OrienteCoin_02_algo, ":/methods/Images/Methods/Layer/OrienteCoin_02.png");



    complete_map(map_algorithms_Croix1);
    complete_map(map_algorithms_FirstLayer);
    complete_map(map_algorithms_F2L);
    complete_map(map_algorithms_EndF2L);
    complete_map(map_algorithms_Croix2);
    complete_map(map_algorithms_OrientationCroix2);
    complete_map(map_algorithms_PlacementCoinsFace2);
    complete_map(map_algorithms_OrientationCoins2);



   // QMap<QString, Algorithm* > map_void;
    map_steps.insert(std::pair<QString, std::map<QString, Algorithm* > >("", std::map<QString, Algorithm* >()));
    map_steps.insert(std::pair<QString, std::map<QString, Algorithm* > >(QObject::tr("1) Croix Face 1"), map_algorithms_Croix1));
    map_steps.insert(std::pair<QString, std::map<QString, Algorithm* > >(QObject::tr("2) Face 1"), map_algorithms_FirstLayer));
    map_steps.insert(std::pair<QString, std::map<QString, Algorithm* > >(QObject::tr("3.1) Couronne centrale"), map_algorithms_F2L));
    map_steps.insert(std::pair<QString, std::map<QString, Algorithm* > >(QObject::tr("3.2) Dernier coin Face 1"), map_algorithms_EndF2L));
    map_steps.insert(std::pair<QString, std::map<QString, Algorithm* > >(QObject::tr("4.1) Croix Face 2"), map_algorithms_Croix2));
    map_steps.insert(std::pair<QString, std::map<QString, Algorithm* > >(QObject::tr("4.2) Orientation Croix 2"), map_algorithms_OrientationCroix2));
  //   map_steps.insert(std::pair<QString, map<QString, Algorithm* > >("5.1) Placement Coins", map_algorithms_PlacementCoinsFace2));
    map_steps.insert(std::pair<QString, std::map<QString, Algorithm* > >(QObject::tr("5.2) Orientation Coins"), map_algorithms_OrientationCoins2));


}

bool Resolution_Layer::solve(const unsigned char cube[CUBE_SIZE], QProgressBar * progressbar)
{
     if (!check_ColorsCube(cube))
         return false;

    // Initialisation variables
     _progressbar = progressbar;
     if (_progressbar)
     {
         _progressbar->setValue(0);

     }
     _progression = 0;
     _progressionMax = 15;
    solution._list_steps.clear();
    solution._title = QObject::tr("Méthode ""Couche par Couche"" ");

	
	unsigned char new_cube[CUBE_SIZE] = {0}, new_cube2[CUBE_SIZE] = {0};
    Copie_Cube(cube, new_cube2);
    Update_Colors(new_cube2, new_cube);

    if (Resolution_Match(new_cube, Variables::Rubik_Cube_Resolu))
    {
        throw CubeAlreadySolved();
    }

    // Résolution croix première face
    if (!Solve_Croix(new_cube))
       return false;

    // Résolution première face
    if (!Solve_FirstLayer(new_cube))
       return false;

    // Résolution F2L
    if (!Solve_F2L(new_cube))
       return false;

    // Résolution Croix Derniere Face
    if (!Solve_SecondCroix(new_cube))
       return false;

    // Resolution des derniers coins
    if (!Solve_LastCorners(new_cube))
        return false;
           
    return true;
}



bool Resolution_Layer::Solve_Croix(unsigned char init_cube[CUBE_SIZE])
{
    // Initialisation variables
    Step step(QObject::tr("(1) Croix"));
    unsigned char cube[CUBE_SIZE] = {0}, new_cube[CUBE_SIZE] = {0};
    Copie_Cube(init_cube, cube);
    unsigned char target_cube[CUBE_SIZE] = {0,0,0,0,1,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,4,0,0,0,0,0,0,0,0,5,0,0,0,0,0,0,0,0,6,0,0,0,0};
    std::list<unsigned char> algo2;

    // Remplissage map
    ///////////////////////////////////
    // Croix
    ////////////////////////////////////
    const unsigned char cube10[CUBE_SIZE] = {0,0,0,0,1,0,0,1,0,0,0,0,0,2,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,4,0,0,0,0,0,5,0,0,5,0,0,0,0,0,0,0,0,6,0,0,0,0};
    const unsigned char cube11[CUBE_SIZE] = {0,0,0,0,1,1,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,4,0,0,0,0,0,0,0,0,5,0,0,0,0,0,0,0,6,6,0,0,0,0};
    const unsigned char cube12[CUBE_SIZE] = {0,1,0,0,1,0,0,0,0,0,0,0,0,2,0,0,2,0,0,0,0,0,3,0,0,0,0,0,0,0,0,4,0,0,0,0,0,0,0,0,5,0,0,0,0,0,0,0,0,6,0,0,0,0};
    const unsigned char cube13[CUBE_SIZE] = {0,0,0,1,1,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,3,3,0,0,0,0,0,0,0,4,0,0,0,0,0,0,0,0,5,0,0,0,0,0,0,0,0,6,0,0,0,0};

    std::list<unsigned char*> liste_cubes;
    unsigned char _cube10[CUBE_SIZE] = {0}, _cube11[CUBE_SIZE] = {0}, _cube12[CUBE_SIZE] = {0}, _cube13[CUBE_SIZE] = {0};
    Copie_Cube(cube10, _cube10);
    Copie_Cube(cube11, _cube11);
    Copie_Cube(cube12, _cube12);
    Copie_Cube(cube13, _cube13);
    liste_cubes.push_back(_cube10);
    liste_cubes.push_back(_cube11);
    liste_cubes.push_back(_cube12);
    liste_cubes.push_back(_cube13);

    // Mouvements
    std::vector<unsigned char> Mouvements;
    Mouvements.push_back(U);    Mouvements.push_back(U_);
    Mouvements.push_back(L);    Mouvements.push_back(L_);
    Mouvements.push_back(F);    Mouvements.push_back(F_);
    Mouvements.push_back(D);    Mouvements.push_back(D_);
    Mouvements.push_back(R);    Mouvements.push_back(R_);
    Mouvements.push_back(B);    Mouvements.push_back(B_);

    unsigned char i = 1;
    while (!liste_cubes.empty())
    {
       if (Resolution_Directe(cube, liste_cubes, target_cube, Mouvements, algo2, 6))
       {
           Sequence(cube, algo2, new_cube);

           Algorithm Algo(QString("Arête "+QString::number(i)), cube, new_cube, target_cube, algo2);
           step._list_algos.push_back(Algo);

           Copie_Cube(new_cube, cube);

           progressStep(_progression++);
        }
       else
       {
           return false;
       }
       i++;
    }

    Copie_Cube(cube, init_cube);
    solution._list_steps.push_back(step);
    unsigned char target_cube_Croix1[CUBE_SIZE] = {0,1,0,1,1,1,0,1,0,0,0,0,0,2,0,0,2,0,0,0,0,0,3,3,0,0,0,0,0,0,0,4,0,0,0,0,0,5,0,0,5,0,0,0,0,0,0,0,6,6,0,0,0,0};
    return areCubesMatching(init_cube, target_cube_Croix1, RZ, algo2);
}




bool Resolution_Layer::Solve_FirstLayer(unsigned char init_cube[CUBE_SIZE])
{
    Step step(QObject::tr("(2) Première Face (3/4 coins)"));
    unsigned char cube[CUBE_SIZE] = {0}, target_cube[CUBE_SIZE]= {0}, new_cube[CUBE_SIZE] = {0}, init_cube2[CUBE_SIZE] = {0};

    Copie_Cube(init_cube, cube);
    Copie_Cube(cube, init_cube2);

    unsigned char target_cube_Croixf1[CUBE_SIZE] = {0,0,0,0,1,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,4,0,0,0,0,0,0,0,0,5,0,0,0,0,0,0,0,0,6,0,0,0,0};
    Copie_Cube(target_cube_Croixf1, target_cube);

    unsigned char target_cube_f1l[CUBE_SIZE] = {1,1,1,1,1,1,1,1,0,0,0,0,0,2,0,2,2,2,0,0,3,0,3,3,0,0,3,0,0,0,0,4,0,0,0,0,5,5,0,0,5,0,0,0,0,6,0,0,6,6,0,0,0,0};

    // Mouvements
    std::vector<unsigned char> Mouvements;
    Mouvements.push_back(RZ);
    Mouvements.push_back(D);

    std::list<unsigned char> aAlgo, aNewAlgo;

    unsigned char c = 1;
    unsigned char gf = 0;
    while (!areCubesMatching(target_cube, target_cube_f1l, RZ, aNewAlgo) && gf<20)
    {
        QString aAlgoText;
        if (Resolution_Algo(cube, map_algorithms_FirstLayer, target_cube, new_cube, aNewAlgo, Mouvements, aAlgoText))
        {
            aAlgo.insert(aAlgo.end(), aNewAlgo.begin(), aNewAlgo.end());
            addAlgo(QString("Coin "+QString::number(c++)), aAlgo, init_cube2, target_cube, step);
            aAlgo.clear();
            Copie_Cube(init_cube2, cube);
        }
        else
        {        
            vector<unsigned char> aMouvementsAllowed;
            aMouvementsAllowed.push_back(RZ);

            unsigned char aNoMatchCube[CUBE_SIZE] = {0,1,0,1,1,1,0,1,1,0,0,0,0,2,0,0,2,0,0,0,0,0,3,3,0,0,0,0,0,0,0,4,0,0,0,0,0,5,5,0,5,0,0,0,0,0,0,0,6,6,0,6,0,0};

            unsigned char aUnblockingSequenceInt[] = {R_, D_, R};
            std::list<unsigned char> aUnblockingSequence;
            aUnblockingSequence.assign(aUnblockingSequenceInt, aUnblockingSequenceInt+sizeof(aUnblockingSequenceInt)/sizeof(unsigned char));

            std::list<unsigned char> aUnblockingAlgo;
            bool res = unblockCube(cube, aNoMatchCube, aMouvementsAllowed, aUnblockingSequence, aUnblockingAlgo, new_cube);
            if (res)
            {
                aAlgo.insert(aAlgo.end(), aUnblockingAlgo.begin(), aUnblockingAlgo.end());
                Sequence(cube, aUnblockingAlgo, new_cube);
                Sequence(target_cube, aUnblockingAlgo, target_cube);

                Copie_Cube(new_cube, cube);
            }
            else
                return false;
        }

        progressStep(_progression++);
        gf++;
    }

    Copie_Cube(cube, init_cube);
    solution._list_steps.push_back(step);

    return areCubesMatching(cube, target_cube_f1l, RZ, aNewAlgo);
}



bool Resolution_Layer::Solve_F2L(unsigned char init_cube[CUBE_SIZE])
{
    Step step(QObject::tr("(3) Couronne centrale"));
    unsigned char cube[CUBE_SIZE] = {0}, target_cube[CUBE_SIZE]= {0}, new_cube[CUBE_SIZE] = {0}, init_cube2[CUBE_SIZE] = {0};

    Copie_Cube(init_cube, cube);
    Copie_Cube(cube, init_cube2);


    // Orientation du cube
    std::list<unsigned char> aAlgo, aNewAlgo;
    unsigned char target_cube_f1l[CUBE_SIZE] = {1,1,1,1,1,1,1,1,0,0,0,0,0,2,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,4,0,0,0,0,0,0,0,0,5,0,0,0,0,0,0,0,0,6,0,0,0,0}; //{1,1,1,1,1,1,1,1,0,0,0,0,0,2,0,2,2,2,0,0,3,0,3,3,0,0,3,0,0,0,0,4,0,0,0,0,5,5,0,0,5,0,0,0,0,6,0,0,6,6,0,0,0,0};
    areCubesMatching(cube, target_cube_f1l, RZ, aAlgo);
    Sequence(target_cube_f1l, aAlgo, target_cube);
    Sequence(cube, aAlgo, cube);
    Update_Cube_Colors(cube, target_cube, new_cube);
    Copie_Cube(new_cube, target_cube);


   unsigned char target_cube_f1l_2[CUBE_SIZE] = {0,1,0,1,1,1,0,1,0,0,0,0,0,2,0,0,2,0,0,0,0,0,3,3,0,0,0,0,0,0,0,4,0,0,0,0,0,5,0,0,5,0,0,0,0,0,0,0,6,6,0,0,0,0};
   Copie_Cube(target_cube_f1l_2, new_cube);
   Update_Cube_Colors(cube, new_cube, target_cube);

    unsigned char target_cube_f2l[CUBE_SIZE] = {0,1,0,1,1,1,0,1,0,0,0,0,2,2,2,0,2,0,0,3,0,0,3,3,0,3,0,0,0,0,0,4,0,0,0,0,0,5,0,5,5,5,0,0,0,0,6,0,6,6,0,0,6,0};

    // Mouvements
    std::vector<unsigned char> Mouvements;
    Mouvements.push_back(D);

    std::list<unsigned char> aSequenceOrientation;
    unsigned char aSequenceOrientationInt[] = {RZ, U_};
    aSequenceOrientation.assign(aSequenceOrientationInt, aSequenceOrientationInt+sizeof(aSequenceOrientationInt)/sizeof(unsigned char));


    unsigned char gf = 1;
    unsigned char c = 1;
    while (!areCubesMatching(cube, target_cube_f2l, U, aNewAlgo))// && gf<10)
    {
        if (Resolution_Algo(cube, map_algorithms_F2L, target_cube, new_cube, aNewAlgo, Mouvements, aSequenceOrientation))
        {
            aAlgo.insert(aAlgo.end(), aNewAlgo.begin(), aNewAlgo.end());
            addAlgo(QString("Arête "+QString::number(c++)), aAlgo, init_cube2, target_cube, step);
            aAlgo.clear();
            Copie_Cube(init_cube2, cube);
        }
        else
        {
            unsigned char aNoMatchCube[CUBE_SIZE];
            Copie_Cube(Layer_F2L_00, aNoMatchCube);

            unsigned char aUnblockingSequenceInt[] = {R_, D_, R};
            std::list<unsigned char> aUnblockingSequence;
            aUnblockingSequence.assign(aUnblockingSequenceInt, aUnblockingSequenceInt+sizeof(aUnblockingSequenceInt)/sizeof(unsigned char));

            std::list<unsigned char> aUnblockingAlgo;
            if (unblockCube(cube, aNoMatchCube, aSequenceOrientation, aUnblockingSequence, aUnblockingAlgo, new_cube))
            {
                aAlgo.insert(aAlgo.end(), aUnblockingAlgo.begin(), aUnblockingAlgo.end());
                Sequence(cube, aUnblockingAlgo, cube);
                Sequence(target_cube, aUnblockingAlgo, target_cube);
            }
        }

        progressStep(_progression++);
        gf++;
    }


    // Dernier coin
    Sequence(target_cube, aNewAlgo, target_cube);
    addAlgo("Fin couronne centrale", aNewAlgo, cube, target_cube, step);

    Mouvements.clear();
    Mouvements.push_back(RZ);
    Mouvements.push_back(D);

    unsigned char target_cube_f2l_full[CUBE_SIZE] = {1,1,1,1,1,1,1,1,1,0,0,0,2,2,2,2,2,2,0,3,3,0,3,3,0,3,3,0,0,0,0,4,0,0,0,0,5,5,5,5,5,5,0,0,0,6,6,0,6,6,0,6,6,0};
    gf=0;
    while (!areCubesMatching(cube, target_cube_f2l_full, U, aNewAlgo) && gf < 4)
    {
        QString aAlgoText;
        if (Resolution_Algo(cube, map_algorithms_EndF2L, target_cube, new_cube, aNewAlgo, Mouvements, aAlgoText))
        {
            aAlgo.insert(aAlgo.end(), aNewAlgo.begin(), aNewAlgo.end());
            addAlgo("Dernier coin", aAlgo, cube, target_cube, step);
            aAlgo.clear();
        }
        else
        {
            unsigned char aInitCube2[CUBE_SIZE] = {0};
            Copie_Cube(cube, aInitCube2);

            unsigned char target_cube_f2l_bloquedLastCorner1[CUBE_SIZE] = {1,1,1,1,1,1,1,1,0,0,0,0,2,2,2,2,2,2,0,3,3,0,3,3,0,3,3,0,0,0,0,4,0,0,0,0,5,5,0,5,5,5,0,0,0,6,6,0,6,6,0,0,6,0};
            areCubesMatching(cube, target_cube_f2l_bloquedLastCorner1, RZ, aNewAlgo);
            Sequence(cube, aNewAlgo, cube);
            aAlgo.insert(aAlgo.end(), aNewAlgo.begin(), aNewAlgo.end());

            unsigned char target_cube_f2l_bloquedLastCorner[CUBE_SIZE] = {1,1,1,1,1,1,1,1,0,0,0,0,2,2,2,2,2,2,0,3,3,0,3,3,0,3,3,0,0,0,0,4,0,0,0,1,5,5,0,5,5,5,0,0,0,6,6,0,6,6,0,0,6,0};
            if (areCubesMatching(cube, target_cube_f2l_bloquedLastCorner, D, aNewAlgo))
            {
                aAlgo.insert(aAlgo.end(), aNewAlgo.begin(), aNewAlgo.end());
            }

            aAlgo.insert(aAlgo.end(), map_algorithms_EndF2L.begin()->second->_mvts.begin(), map_algorithms_EndF2L.begin()->second->_mvts.end());
            Sequence(target_cube, aAlgo, target_cube);
            addAlgo("Deblocage dernier coin", aAlgo, aInitCube2, target_cube, step);

            Copie_Cube(aInitCube2, cube);
            aAlgo.clear();
        }

        gf++;
        progressStep(_progression++);
    }


    Copie_Cube(cube, init_cube);
    solution._list_steps.push_back(step);
    return true;
}






bool Resolution_Layer::Solve_SecondCroix(unsigned char init_cube[CUBE_SIZE])
{
    Step step(QObject::tr("(4) Seconde Croix"));
    unsigned char cube[CUBE_SIZE] = {0}, target_cube[CUBE_SIZE]= {0}, new_cube[CUBE_SIZE] = {0};
    Copie_Cube(init_cube, cube);

    std::list<unsigned char> algo2, aAlgo, aNewAlgo;

    unsigned char aOrientationSequenceInt[] = {RY,RY};
    aAlgo.assign(aOrientationSequenceInt, aOrientationSequenceInt+sizeof(aOrientationSequenceInt)/sizeof(unsigned char));

    unsigned char target_cube_f2l_full[CUBE_SIZE] = {1,1,1,1,1,1,1,1,1,0,0,0,2,2,2,2,2,2,0,3,3,0,3,3,0,3,3,0,0,0,0,4,0,0,0,0,5,5,5,5,5,5,0,0,0,6,6,0,6,6,0,6,6,0};
    Copie_Cube(target_cube_f2l_full, target_cube);
    Sequence(target_cube, aAlgo, target_cube);
    addAlgo("Retournement du cube", aAlgo, cube, target_cube, step);
    aAlgo.clear();


    // Mouvements
    std::vector<unsigned char> Mouvements;
    Mouvements.push_back(RZ);
    Mouvements.push_back(U);

    unsigned char init_cube2[CUBE_SIZE] = {0};
    Copie_Cube(cube, init_cube2);
    unsigned char target_cube_croix2[CUBE_SIZE] = {0,1,0,1,1,1,0,1,0,2,2,2,2,2,2,0,0,0,3,3,0,3,3,0,3,3,0,4,4,4,4,4,4,4,4,4,0,0,0,5,5,5,5,5,5,0,6,6,0,6,6,0,6,6};
    unsigned char gf = 0;
    while (!areCubesMatching(cube, target_cube_croix2, RZ, aNewAlgo) && gf < 2)
    {
        QString aAlgoText;
        if (Resolution_Algo(cube, map_algorithms_Croix2, target_cube, new_cube, aNewAlgo, Mouvements, aAlgoText))
        {
            aAlgo.insert(aAlgo.end(), aNewAlgo.begin(), aNewAlgo.end());
            addAlgo("Seconde Croix", aAlgo, init_cube2, target_cube, step);
            aAlgo.clear();
        }
        else
        {
            aNewAlgo.assign(map_algorithms_Croix2.begin()->second->_mvts.begin(), map_algorithms_Croix2.begin()->second->_mvts.end());

            Sequence(cube, aNewAlgo, cube);
            Sequence(target_cube, aNewAlgo, target_cube);

            aAlgo.insert(aAlgo.end(), aNewAlgo.begin(), aNewAlgo.end());
        }
        gf++;
    }

    progressStep(_progression++);progressStep(_progression++);



    Copie_Cube(init_cube2, cube);

    unsigned char target_cube_croix2b[CUBE_SIZE] = {0,1,0,1,1,1,0,1,0,2,2,2,2,2,2,0,0,0,3,3,0,3,3,0,3,3,0,4,4,4,4,4,4,4,4,4,0,0,0,5,5,5,5,5,5,0,6,6,0,6,6,0,6,6};
    Update_Cube_Colors(cube, target_cube_croix2b, target_cube);

    unsigned char target_cube_OrientedCroix2[CUBE_SIZE] = {0,1,0,1,1,1,0,1,0,2,2,2,2,2,2,0,2,0,3,3,0,3,3,3,3,3,0,4,4,4,4,4,4,4,4,4,0,5,0,5,5,5,5,5,5,0,6,6,6,6,6,0,6,6};
    unsigned char target_cube_OrientedCroix2_Equ[CUBE_SIZE];
    Update_Cube_Colors(cube, target_cube_OrientedCroix2, target_cube_OrientedCroix2_Equ);

    gf = 0;
    while (!areCubesMatching(cube, target_cube_OrientedCroix2_Equ, U, aNewAlgo) && gf < 4)
    {
        QString aAlgoText;
        if (Resolution_Algo(cube, map_algorithms_OrientationCroix2, target_cube, new_cube, aNewAlgo, Mouvements, aAlgoText))
        {
            addAlgo("Orientation Seconde Croix", aNewAlgo, cube, target_cube, step);
        }
        else
        {
            aNewAlgo.assign(map_algorithms_OrientationCroix2.begin()->second->_mvts.begin(), map_algorithms_OrientationCroix2.begin()->second->_mvts.end());
            addAlgo("Orientation Croix 2", aNewAlgo, cube, target_cube, step);
        }
        gf++;
    }

    addAlgo("Fin", aNewAlgo, cube, target_cube_OrientedCroix2_Equ, step);

    progressStep(_progression++);

    Copie_Cube(cube, init_cube);
    solution._list_steps.push_back(step);
    return true;
}




bool Resolution_Layer::Solve_LastCorners(unsigned char init_cube[CUBE_SIZE])
{
    Step step(QObject::tr("(5) Resolution des derniers coins"));
    unsigned char cube[CUBE_SIZE] = {0}, init_cube2[CUBE_SIZE] = {0}, target_cube[CUBE_SIZE] = {0};
    Copie_Cube(init_cube, cube);

    unsigned char target_cube_OrientedCroix2[CUBE_SIZE] = {0,1,0,1,1,1,0,1,0,2,2,2,2,2,2,0,2,0,3,3,0,3,3,3,3,3,0,4,4,4,4,4,4,4,4,4,0,5,0,5,5,5,5,5,5,0,6,6,6,6,6,0,6,6};
    Update_Cube_Colors(cube, target_cube_OrientedCroix2, target_cube);


    unsigned char p1[] = {1,4,2,3};
    std::vector<unsigned char> Vp1(p1, p1+4);
    unsigned char algo1[] = {RZ ,R,U_,L_,U,R_,U_,L,U,RZ_};
    std::list<unsigned char> Lalgo1(algo1, algo1+sizeof(algo1)/sizeof(unsigned char));

    unsigned char p2[] = {1,3,4,2};
    std::vector<unsigned char> Vp2(p2, p2+4);
    unsigned char algo2[] = {L_,U,R,U_,L,U,R_,U_};
    std::list<unsigned char> Lalgo2(algo2, algo2+sizeof(algo2)/sizeof(unsigned char));


    std::map< vector<unsigned char>, std::list<unsigned char> > aMapAlgo;
    aMapAlgo[Vp1] = Lalgo1;
    aMapAlgo[Vp2] = Lalgo2;

    std::list<unsigned char> aAlgo, aNewAlgo, aTmpAlgo;
    std::vector<unsigned char> aPlaceCorners;
    aAlgo.push_back(RZ);

    Copie_Cube(init_cube, init_cube2);
    unsigned char gf = 0;
    bool fini = false;
    while (countNomberOfPlacedCorners(cube, aPlaceCorners) != 4 && gf < 3)
    {
        aNewAlgo.clear();
        for (unsigned char i=0; i<4 && countNomberOfPlacedCorners(cube, aPlaceCorners)<4; i++)
        {
            countNomberOfPlacedCorners(cube, aPlaceCorners);

            for (map< vector<unsigned char>, list<unsigned char> >::iterator it = aMapAlgo.begin(); it != aMapAlgo.end(); it++)
            {
                if (aPlaceCorners == it->first)
                {
                    addAlgo("Permutation des coins", it->second, cube, target_cube, step);
                    fini = true;
                    break;
                }
            }

            if (!fini)
            {
                aNewAlgo.clear();
                aNewAlgo.push_back(RZ);
                Sequence(target_cube, aNewAlgo, target_cube);
                addAlgo("Rotation", aNewAlgo, cube, target_cube, step);
            }
        }

        if (countNomberOfPlacedCorners(cube, aPlaceCorners) != 4)
        {
            addAlgo("Déblocage", aMapAlgo.begin()->second, cube, target_cube, step);
            Copie_Cube(cube, init_cube2);
        }

        gf++;
    }
    progressStep(_progression++);



    //////////////////////////////////////
    // Centres
    unsigned char coin1[3] = {4, 49, 40};
    unsigned char coin2[3] = {4, 40, 22};
    unsigned char coin3[3] = {4, 22, 13};
    unsigned char coin4[3] = {4, 13, 49};
    unsigned char *coins[] = {coin1, coin2, coin3, coin4};


     // Coins
    unsigned char place1[] = {8, 51, 38};
    unsigned char place2[] = {6, 36, 26};
    unsigned char place3[] = {0, 20,15};
    unsigned char place4[] = {2, 17, 45};
    unsigned char * places[] = {place1, place2, place3, place4};

    std::map<unsigned char, std::vector<unsigned char> > aMapPlaceCoin;
    std::map<unsigned char, std::vector<unsigned char> > aMapCornerCoin;

    for (unsigned char p=1; p<=4; p++)
    {
        for (unsigned char i=0; i<3; i++)
        {
             aMapPlaceCoin[p].push_back(cube[coins[p-1][i]]);
             aMapCornerCoin[p].push_back(cube[places[p-1][i]]);
        }
    }

    aAlgo.clear();
    for (unsigned char m= 0; m<4; m++)
    {

        unsigned char n = orientationCoin(aMapCornerCoin[m+1], aMapPlaceCoin[m+1]);

        QString aText = "Coin "+QString::number(m+1);
        if (n == 1)
        {
            aAlgo.assign(OrienteCoin_01_algo.begin(), OrienteCoin_01_algo.end());
            aAlgo.push_back(U_);
            QString aText2 = (Variables::_ALLOW_LEARNING_MODE_) ? " sens anti-horaire" : "";
            addAlgo(aText+aText2, aAlgo, cube, target_cube, step);
        }
        else if (n == 2)
        {
            aAlgo.assign(OrienteCoin_02_algo.begin(), OrienteCoin_02_algo.end());
            aAlgo.push_back(U_);
            QString aText2 = (Variables::_ALLOW_LEARNING_MODE_) ? " sens horaire" : "";
            addAlgo(aText+aText2, aAlgo, cube, target_cube, step);
        }
        else
        {
            aAlgo.push_back(U_);
            QString aText2 = (Variables::_ALLOW_LEARNING_MODE_) ? " resolu" : "";
            addAlgo(aText+aText2, aAlgo, cube, target_cube, step);

        }

        aAlgo.clear();
        progressStep(_progression++);
    }

    progressStep(_progression++);

    Copie_Cube(cube, init_cube);
    solution._list_steps.push_back(step);
    return true;

}





unsigned char Resolution_Layer::countNomberOfPlacedCorners(unsigned char init_cube[CUBE_SIZE], std::vector<unsigned char> & aPlaceCorners)
{
    unsigned char n = 0;

    // Centres
    unsigned char coin1[3] = {4, 49, 40};
    unsigned char coin2[3] = {4, 40, 22};
    unsigned char coin3[3] = {4, 22, 13};
    unsigned char coin4[3] = {4, 13, 49};
    unsigned char *coins[] = {coin1, coin2, coin3, coin4};

    std::map<unsigned char, std::vector<unsigned char> > aMapPlaceCoin;
    for (unsigned char p=1; p<=4; p++)
    {
        for (unsigned char i=0; i<3; i++)
        {
             aMapPlaceCoin[p].push_back(init_cube[coins[p-1][i]]);
        }
        progressStep(_progression++);
    }


    // Coins
    unsigned char place1[] = {8, 51, 38};
    unsigned char place2[] = {6, 36, 26};
    unsigned char place3[] = {0, 20,15};
    unsigned char place4[] = {2, 17, 45};
    unsigned char * places[] = {place1, place2, place3, place4};

    aPlaceCorners.clear();
    for (unsigned char p=1; p<=4; p++)
    {
        std::vector<unsigned char> aCorner;
        for (unsigned char i=0; i<3; i++)
        {
             aCorner.push_back(init_cube[places[p-1][i]]);
        }
        if (isCornerInPlace(aCorner, aMapPlaceCoin[p]))
            n++;

        aPlaceCorners.push_back(placeCorner(aCorner, aMapPlaceCoin));
    }

    QString aString;
    for (std::vector<unsigned char>::const_iterator it = aPlaceCorners.begin(); it != aPlaceCorners.end(); it++)
    {
        aString += QString::number(*it);
        aString += "  ";
    }

    return n;
}


bool Resolution_Layer::isCornerInPlace(std::vector<unsigned char> & iCorner, std::vector<unsigned char> & iPlace)
{
    for (unsigned char i=0; i<iCorner.size(); i++)
    {
        if (iCorner == iPlace)
            return true;
        rotate(iCorner.begin(), iCorner.begin()+1, iCorner.end());
    }

    return false;
}

unsigned char Resolution_Layer::placeCorner(std::vector<unsigned char> & iCorner, std::map<unsigned char, std::vector<unsigned char> > & iMapPlaceCoin)
{
    for (std::map<unsigned char, std::vector<unsigned char> >::iterator it = iMapPlaceCoin.begin(); it != iMapPlaceCoin.end(); it++)
    {
        if (isCornerInPlace(iCorner, it->second))
            return it->first;
    }
    return -1;
}

unsigned char Resolution_Layer::orientationCoin(std::vector<unsigned char> & iCorner, std::vector<unsigned char> & iPlace)
{
    for (unsigned char i=1; i<=2; i++)
    {
        rotate(iCorner.begin(), iCorner.begin()+1, iCorner.end());
        if (iCorner == iPlace)
            return i;
    }

    return 0;
}


