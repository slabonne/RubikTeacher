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
#include "kociemba/algo.h"

#include <QProgressBar>

struct Piece
{
   QVector<char> v;

    Piece() {};

    Piece(std::initializer_list<char> list)
        : v(list) {}

    QString toString() const
    {
        QString result;
        result.reserve(v.size() * 3);

        for (int i = 0; i < v.size(); ++i) {
            if (i)
                result += ',';
            result += QString::number(static_cast<unsigned char>(v[i]));
        }

        return result;
    }


    bool isSame(const Piece& p) const
    {
        QVector<char> v1 = v;
        QVector<char> v2 = p.v;

        if (v1.size() != v2.size())
            return false;

        std::sort(v1.begin(), v1.end());
        std::sort(v2.begin(), v2.end());

        return (v1 == v2);
    }
};



struct Corner : public Piece
{
 using Piece::Piece;
};

const QList<Corner> CORNERS = {
    {33,18,9}, {35,11,47}, {29,53,44}, {27,42,24},      // bottom face
    {0,15,20}, {2,45,17}, {8,38,51}, {6,26,36},         // top face
 };




struct Edge : public Piece
{
 using Piece::Piece;
};

const QList<Edge> EDGES = {
    {19,12}, {46,14}, {52,41}, {25,39},
    {1,16}, {5,48}, {7,37}, {3,23},
    {34,10}, {32,50}, {28,43}, {30,21}
  };




Resolution_Kociemba::Resolution_Kociemba(MainWindow * fenprincipale) : Resolution(fenprincipale)
{

}


template<typename T>
bool findPiece(const unsigned char cube[],
               const QList<T>& pieces,
               int p,
               int8_t& pos,
               int8_t& orientation,
               bool orientationCorner = false)
{
    int dim = pieces[p].v.count();

    Piece piece_looked;
    for (int i = 0; i < dim; ++i)
    {
        piece_looked.v.push_back(cube[pieces[p].v[i]]);
    }

    int position = 0;
    for (const T& piece : pieces)
    {
        Piece piece_0;
        for (int i = 0; i < dim; ++i)
        {
            piece_0.v.push_back(Variables::Rubik_Cube_Resolu[piece.v[i]]);
        }

        if (piece_looked.isSame(piece_0))
        {
            pos = position;

            if (orientationCorner)
            {
                for (int o = 0; o < dim; ++o)
                {
                    if (piece_looked.v[o] %3 == 1)
                    {
                        orientation = o;
                        return true;
                    }
                }
                return false;
            }
            else
            {
                orientation = (piece_looked.v == piece_0.v) ? 0 : 1;
            }

            return true;
        }
        ++position;
    }

    return false;
}


rubik_cube::cube_t transformCube(const unsigned char cube[])
{
    rubik_cube::cube_t cubeT;

    // corners' position and orientation
    for (int i = 0 ; i < 8; ++i)
    {
        if (!findPiece(cube, CORNERS, i, cubeT.cp[i], cubeT.co[i], true))
            break;
    }
   /* qDebug() << "==== CORNERS";
    for (int i = 0 ; i < 8; ++i)
    {
        qDebug() << cubeT.cp[i] << "   " << cubeT.co[i];
    }*/

    // edges' position and orientation
    for (int i = 0 ; i < 12; ++i)
    {
        if (!findPiece(cube, EDGES, i, cubeT.ep[i], cubeT.eo[i]))
            break;
    }
   /* qDebug() << "==== EDGES";
    for (int i = 0 ; i < 12; ++i)
    {
        qDebug() << cubeT.ep[i] << "   " << cubeT.eo[i];
    }*/

    return cubeT;
}

QString moveSeqToQString(const rubik_cube::move_seq_t& seq)
{
    QString result;

    for (const auto& step : seq)
    {
        const rubik_cube::face_t::face_type face = step.first;
        const int turns = step.second;

        QString faceStr;
        switch (face)
        {
        case rubik_cube::face_t::top:    faceStr = "U"; break;
        case rubik_cube::face_t::bottom: faceStr = "D"; break;
        case rubik_cube::face_t::front:  faceStr = "F"; break;
        case rubik_cube::face_t::back:   faceStr = "B"; break;
        case rubik_cube::face_t::left:   faceStr = "L"; break;
        case rubik_cube::face_t::right:  faceStr = "R"; break;
        default:             faceStr = "?"; break;
        }

        // Convention classique du cube
        if (turns == 1)
            result += faceStr + " ";
        else if (turns == 2)
            result += faceStr + "2 ";
        else if (turns == -1)
            result += faceStr + "' ";
        else
            result += faceStr + QString("(%1) ").arg(turns);
    }

    return result.trimmed();
}



std::vector<unsigned char> transformAlgo(const rubik_cube::move_seq_t& seq)
{
    std::vector<unsigned char> algo;


    for (const auto& step : seq)
    {
        const rubik_cube::face_t::face_type face = step.first;
        int turns = step.second;

        int move;

        QString faceStr;
        switch (face)
        {
            case rubik_cube::face_t::top:    move = U; break;
            case rubik_cube::face_t::bottom: move = D; break;
            case rubik_cube::face_t::front:  move = F; break;
            case rubik_cube::face_t::back:   move = B; break;
            case rubik_cube::face_t::left:   move = L; break;
            case rubik_cube::face_t::right:  move = R; break;
            default: {
                qDebug() << "inconnu";
                break;
            }
        }

        if (turns == -1)
        {
            move += 18;
            turns = 1;
        }

        for (int i=0; i < turns; i++)
            algo.push_back(move);
    }

    return algo;
}


bool Resolution_Kociemba::solve(const unsigned char cube[], QProgressBar *progressbar)
{
    if (!check_ColorsCube(cube))
        return false;

    _progressbar = progressbar;
    if (_progressbar != NULL)
    {
        _progressbar->setValue(0);
        _progression = 0;
    }

    _progressionMax = 1;
    solution._list_steps.clear();
    solution._title = QObject::tr("Méthode Kociemba");

    Step step(QObject::tr("Resolution optimale"));
    unsigned char new_cube[CUBE_SIZE] = {0};
    unsigned char new_cube2[CUBE_SIZE] = {0};
    std::vector<unsigned char> aAlgo;

    Copie_Cube(cube, new_cube2);
    Update_Colors(new_cube2, new_cube);

    std::shared_ptr<rubik_cube::algo_t> alg = rubik_cube::create_kociemba_algo(4);
    alg->init();

    rubik_cube::cube_t cubeT = transformCube(new_cube);
    rubik_cube::move_seq_t seq = alg->solve(cubeT);

    aAlgo = transformAlgo(seq);

    Algorithm Algo(QString("aaa"), new_cube2, new_cube, Variables::Rubik_Cube_Resolu, aAlgo);
    step._list_algos.push_back(Algo);

    solution._list_steps.push_back(step);

    progressStep(_progression++);
    return true;
}


