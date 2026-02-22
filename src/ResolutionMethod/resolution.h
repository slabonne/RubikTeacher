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

#ifndef __RESOLUTION__
#define __RESOLUTION__

#include "../variables.h"

class MainWindow;
class QProgressBar;


class CubeAlreadySolved : public std::exception
{
public:
    CubeAlreadySolved() {};
};



class Resolution
{
  public:
        Resolution(MainWindow * fenprincipale);

        virtual QString getTitle() const = 0;

        virtual bool solve(const unsigned char[CUBE_SIZE], QProgressBar *  = NULL) {return true;};
        virtual void fill_map() = 0;

        static void Copie_Cube(const unsigned char cube[CUBE_SIZE], unsigned char cube_result[CUBE_SIZE]);
        static void Superpose(const unsigned char cube1[CUBE_SIZE], const unsigned char cube2[CUBE_SIZE], unsigned char cube_res[CUBE_SIZE]);

        bool areCubesMatching(const unsigned char iCubeInit[CUBE_SIZE], const unsigned char iTargetCube[CUBE_SIZE], unsigned char iOrientationMvt, std::list<unsigned char> & oAlgo);

        bool Resolution_Match(const unsigned char cube[CUBE_SIZE], const unsigned char target_cube[CUBE_SIZE]);

       static void Mouvement(unsigned char cube[CUBE_SIZE], unsigned char mvt);
        static void Permutation(const unsigned char cube[CUBE_SIZE], unsigned char mvt, unsigned char cube_result[CUBE_SIZE]);

        bool Update_Cube_Colors(const unsigned char cube_init[CUBE_SIZE], const unsigned char cube_algo[CUBE_SIZE], unsigned char cube_result[CUBE_SIZE]);
        static void getColorMap(const unsigned char cube[CUBE_SIZE], unsigned char colors[7]);

        void complete_map(std::map<QString, Algorithm * > & _map);
        void progressStep(int progression);

        bool Resolution_Directe(const unsigned char init_cube[CUBE_SIZE], std::list<unsigned char*>& liste_cubes, unsigned char target_cube[CUBE_SIZE], const std::vector<unsigned char>& Mouvements, std::list<unsigned char>& algo, const int depth_max);
        bool Resolution_Algo(unsigned char init_cube[CUBE_SIZE], std::map<QString, Algorithm* > map_algorithms, unsigned char target_cube[CUBE_SIZE], unsigned char new_cube[CUBE_SIZE], std::list<unsigned char>& algo, const std::vector<unsigned char>& Mouvements, std::list<unsigned char> & iSequenceOrientation);

        bool Resolution_Algo(unsigned char init_cube[CUBE_SIZE], std::map<QString, Algorithm* > map_algorithms, unsigned char target_cube[CUBE_SIZE], unsigned char new_cube[CUBE_SIZE], std::list<unsigned char>& algo, const std::vector<unsigned char>& Mouvements, QString &oText);
        static void Sequence(const unsigned char cube[CUBE_SIZE], const std::list<unsigned char> algo, unsigned char cube_result[CUBE_SIZE]);
        static void Sequence(const unsigned char cube[CUBE_SIZE], const std::vector<unsigned char> algo, unsigned char cube_result[CUBE_SIZE]);
        bool unblockCube(unsigned char cube[CUBE_SIZE], unsigned char iNoMatchCube[CUBE_SIZE], std::vector<unsigned char> & iMouvementsAllowed, std::list<unsigned char> & iUnblockingSequence, std::list<unsigned char> & oAlgo, unsigned char oNewCube[CUBE_SIZE]);
        bool unblockCube(unsigned char cube[CUBE_SIZE], unsigned char iNoMatchCube[CUBE_SIZE], std::list<unsigned char> & iSequenceOrientation, std::list<unsigned char> & iUnblockingSequence, std::list<unsigned char> & oAlgo, unsigned char oNewCube[CUBE_SIZE]);


        static void SimplifyAlgo(std::vector<unsigned char> &algo);
        void addAlgo(QString iText, std::list<unsigned char> & iAlgo, unsigned char ioCube[CUBE_SIZE], unsigned char iTargetCube[CUBE_SIZE], Step & ioStep);

        bool Update_Colors(unsigned char init_cube[CUBE_SIZE], unsigned char final_cube[CUBE_SIZE]);

        bool check_ColorsCube(const unsigned char cube[CUBE_SIZE]);

        std::map<QString, Algorithm* > map_algorithms;
        std::map<QString, std::map<QString, Algorithm* > > map_steps;

        Solution solution;

        unsigned char cube_init2[CUBE_SIZE];

protected:
    MainWindow *     _mainFrame = nullptr;;
    QProgressBar *   _progressbar = nullptr;;
    int              _progressionMax;
    int              _progression;
    bool             _display;
};




class Resolution_Friedriech : public Resolution
{
public:
    Resolution_Friedriech(MainWindow * fenprincipale);

    virtual QString getTitle() const { return QObject::tr("Fridrich (Méthode expert)"); };

    virtual bool solve(const unsigned char cube[CUBE_SIZE], QProgressBar * progressbar = NULL);
    void fill_map();

    bool Resolution_Directe2(const unsigned char init_cube[CUBE_SIZE], std::list<unsigned char *>& liste_cubes, unsigned char target_cube[CUBE_SIZE], const std::vector<unsigned char>& Mouvements, std::list<unsigned char>& algo, const int depth_max);
    bool areCubesMatching_FaceD(const unsigned char iCubeInit[CUBE_SIZE], const unsigned char iTargetCube[CUBE_SIZE], const unsigned char iOrientationMvt, std::list<unsigned char> & oAlgo);
    bool Resolution_Match_FaceD(const unsigned char cube[CUBE_SIZE], const unsigned char target_cube[CUBE_SIZE]);

private:
      bool Solve_Croix(unsigned char init_cube[CUBE_SIZE]);
      bool Solve_F2L(unsigned char cube[CUBE_SIZE]);
      bool Solve_OLL(unsigned char cube[CUBE_SIZE]);
      bool Solve_PLL(unsigned char cube[CUBE_SIZE]);

      std::map<QString, Algorithm* > map_algorithms_Croix1;;
      std::map<QString, Algorithm* > map_algorithms_F2L;
      std::map<QString, Algorithm* > map_algorithms_F2L_Multislotting;
      std::map<QString, Algorithm* > map_algorithms_OLL;
      std::map<QString, Algorithm* > map_algorithms_PLL;
};

class Resolution_Layer : public Resolution
{
public:
     Resolution_Layer(MainWindow * fenprincipale);

     virtual QString getTitle() const { return QObject::tr("Couche par Couche (Méthode débutant)"); };
     virtual bool solve(const unsigned char cube[CUBE_SIZE], QProgressBar * progressbar = NULL);
     void fill_map();
         

private:
    bool Solve_Croix(unsigned char init_cube[CUBE_SIZE]);
    bool Solve_FirstLayer(unsigned char init_cube[CUBE_SIZE]);
    bool Solve_F2L(unsigned char init_cube[CUBE_SIZE]);
    bool Solve_SecondCroix(unsigned char init_cube[CUBE_SIZE]);
    bool Solve_LastCorners(unsigned char init_cube[CUBE_SIZE]);

    unsigned char countNomberOfPlacedCorners(unsigned char init_cube[CUBE_SIZE], std::vector<unsigned char> & aPlaceCorners);
    bool isCornerInPlace(std::vector<unsigned char> & iCorner, std::vector<unsigned char> & iPlace);
     unsigned char placeCorner(std::vector<unsigned char> & iCorner, std::map<unsigned char, std::vector<unsigned char> > & iMapPlaceCoin);
     unsigned char orientationCoin(std::vector<unsigned char> & iCorner, std::vector<unsigned char> & iPlace);

    std::map<QString, Algorithm* > map_algorithms_Croix1;
    std::map<QString, Algorithm* > map_algorithms_FirstLayer;
    std::map<QString, Algorithm* > map_algorithms_F2L;
    std::map<QString, Algorithm* > map_algorithms_EndF2L;
    std::map<QString, Algorithm* > map_algorithms_Croix2;
    std::map<QString, Algorithm* > map_algorithms_OrientationCroix2;
    std::map<QString, Algorithm* > map_algorithms_PlacementCoinsFace2;
    std::map<QString, Algorithm* > map_algorithms_OrientationCoins2;
};


#endif
