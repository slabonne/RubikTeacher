#include "mainwindow.h"
#include "palette.h"
#include "resolution.h"
#include "rubik_croix_carres.h"
#include "rubikplat.h"
#include "ui_rubikplat.h"

#include <QBoxLayout>
#include <QToolButton>
#include <QMessageBox>
#include "glrubik.h"

RubikPlat::RubikPlat(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RubikPlat)
{
    ui->setupUi(this);

    QVBoxLayout *l1 = new QVBoxLayout;
        l1->setAlignment(Qt::AlignTop | Qt::AlignHCenter);
        Rubik = new Rubik_Croix_Carres(this, 25);
        l1->addWidget(Rubik);
     setLayout(l1);
}

RubikPlat::~RubikPlat()
{
    delete ui;
}

void RubikPlat::setEditable()
{
    change_Current_Color(1, 1);
    change_Current_Color(2, 0);
    _edit = true;
}

MainWindow *RubikPlat::getMainWindow()
{
    return MainWindow::getInstance();
}



// Tourner une face du cube
void RubikPlat::Tourner_Face(unsigned char mvt)
{
    unsigned char cube[CUBE_SIZE] = {0};
    Resolution::Copie_Cube(Rubik->getCube(), cube);

     Mouvement(cube, mvt);
    Rubik->fill_Cube(cube);
}

// Initialisation du cube
void RubikPlat::initialiser()
{
    Update_Colors();
    Rubik->initialiser();
    getMainWindow()->glRubik->rubik_cube->mapping_Textures(Rubik->getCube());
}

// Vidage du cube
void RubikPlat::vider()
{
    Rubik->vider();
     getMainWindow()->glRubik->rubik_cube->mapping_Textures(Rubik->getCube());
}

// Vï¿½rification et validation du cube
bool RubikPlat::verifier()
{
    Update_Colors();

     unsigned char * Cube = getCube();

     if (!check_ColorsFace(Cube))
     {
         QMessageBox::critical(this, tr("Résolution impossible"), tr("Résolution impossible!\nIndice: Les centres des faces du cube définissent la couleur de la face.\nLes 6 centres doivent donc être de couleur différente!"));
         return false;
     }

     if (!check_ColorsCube(Cube))
     {
         QMessageBox::critical(this, tr("Résolution impossible"), tr("Résolution impossible!\nVérifiez les couleurs du cube!\nChacune des 6 couleurs doit apparaitre 9 fois"));
         return false;
     }

     try
     {
         if (!check_SolutionCube(Cube))
         {
            QMessageBox::critical(this, tr("Résolution impossible!"), tr("Erreur : Résolution impossible!\nVérifiez les couleurs du cube!"));
            return false;
         }
     }
     catch (CubeAlreadySolved)
     {
         QMessageBox::information(this, tr("Cube résolu..."), tr("Le cube est déjà résolu... non?!"));
         return true;
     }

     QMessageBox::information(this, tr("Résolution possible"), tr("Cube OK: Le cube est résolvable!"));
     return true;
}






/*
 * Determine code couleurs en fonction des couleurs des centres des faces
 * */
void RubikPlat::Update_Colors()
{
    unsigned char colors[7] = {0};
    unsigned char * cube = nullptr;
    cube = Rubik->getCube();

    for (int i=1; i<=6; i++)
        colors[cube[9*(i-1)+4]]++;

   bool error = false;
    for (int i=1; i<=6; i++)
        if (colors[i] != 1)
            error = true;

    if (!error)
    {
        unsigned char colors2[7] = {0};
        for (int i=1; i<=6; i++)
            colors2[i] = cube[9*(i-1)+4];

        Variables::Update_Colors(colors2);                  //re-map couleurs cube plat & textures 3D

        // re-map couleurs palette
        getMainWindow()->getPalette()->retrieveColors();
        change_Current_Color(1, colors2[getCurrentColor(1)]);

        // re-compute cube colors
        update_Cube(colors2);

        //re-map textures 3D
        if (getMainWindow()->glRubik)
        {
            getMainWindow()->glRubik->updateColors();       // BUG
            getMainWindow()->glRubik->rubik_cube->mapping_Textures(Rubik->getCube());
        }

    }
}

void RubikPlat::update_Cube(unsigned char colors2[7])
{
    unsigned char *cube = NULL;
    cube = Rubik->getCube();

    unsigned char cube2[CUBE_SIZE] = {0};
    for (int i=0; i<CUBE_SIZE; i++)
    {
        unsigned char ind = 0;
        while (cube[i] != colors2[ind])
            ind++;
        cube2[i] = ind;
    }
    Rubik->fill_Cube(cube2);
}


QString RubikPlat::generer()
{
     unsigned char *Cube = NULL;
     Cube = Rubik->getCube();

     QString aStringCube;

     aStringCube += "{";
     for (int i=0; i<(CUBE_SIZE-1); i++)
     {
         aStringCube += QString::number(Cube[i]);
         aStringCube += ",";
     }
     aStringCube += QString::number(Cube[CUBE_SIZE-1]);
    aStringCube += "};";

    return aStringCube;
}





void RubikPlat::Mouvement(unsigned char cube[CUBE_SIZE], unsigned char mvt)
{
    switch(mvt)
    {
        case U : Permutations(cube, perm_U_, HORAIRE, true);
                break;
        case L : Permutations(cube, perm_L_, ANTI_HORAIRE, true);
                break;
        case F : Permutations(cube, perm_F_, HORAIRE, true);
                break;
        case D : Permutations(cube, perm_D_, ANTI_HORAIRE, true);
                break;
        case R : Permutations(cube, perm_R_, HORAIRE, true);
                break;
        case B : Permutations(cube, perm_B_, ANTI_HORAIRE, true);
                break;
        case U_ : Permutations(cube, perm_U_, ANTI_HORAIRE, true);
                break;
        case L_ : Permutations(cube, perm_L_, HORAIRE, true);
                break;
        case F_ : Permutations(cube, perm_F_, ANTI_HORAIRE, true);
                break;
        case D_ : Permutations(cube, perm_D_, HORAIRE, true);
                break;
        case R_ : Permutations(cube, perm_R_, ANTI_HORAIRE, true);
                break;
        case B_ : Permutations(cube, perm_B_, HORAIRE, true);
                break;

        case MX : Permutations(cube, perm_Mx_, HORAIRE, false);
             break;
        case MY : Permutations(cube, perm_My_, HORAIRE, false);
             break;
        case MZ : Permutations(cube, perm_Mz_, HORAIRE, false);
             break;
        case MX_ : Permutations(cube, perm_Mx_, ANTI_HORAIRE, false);
             break;
        case MY_ : Permutations(cube, perm_My_, ANTI_HORAIRE, false);
             break;
        case MZ_ : Permutations(cube, perm_Mz_, ANTI_HORAIRE, false);
             break;

        case u :
             Mouvement(cube, U);
             Mouvement(cube, MZ);
             break;
        case l :
             Mouvement(cube, L);
             Mouvement(cube, MX_);
             break;
        case f :
             Mouvement(cube, F);
             Mouvement(cube, MY);
             break;
        case d :
             Mouvement(cube, D);
             Mouvement(cube, MZ_);
             break;
        case r :
             Mouvement(cube, R);
             Mouvement(cube, MX);
             break;
        case b :
             Mouvement(cube, B);
             Mouvement(cube, MY_);
             break;
        case u_ :
             Mouvement(cube, U_);
             Mouvement(cube, MZ_);
             break;
        case l_ :
             Mouvement(cube, L_);
             Mouvement(cube, MX);
             break;
        case f_ :
             Mouvement(cube, F_);
             Mouvement(cube, MY_);
             break;
        case d_ :
             Mouvement(cube, D_);
             Mouvement(cube, MZ);
             break;
        case r_ :
             Mouvement(cube, R_);
             Mouvement(cube, MX_);
            break;
        case b_ :
             Mouvement(cube, B_);
             Mouvement(cube, MY);
            break;

        case RX :
            Mouvement(cube, L_);
            Mouvement(cube, MX);
            Mouvement(cube, R);
            break;
        case RY :
            Mouvement(cube, F);
            Mouvement(cube, MY);
            Mouvement(cube, B_);
            break;
        case RZ :
            Mouvement(cube, U);
            Mouvement(cube, MZ);
            Mouvement(cube, D_);
            break;
        case RX_ :
            Mouvement(cube, L);
            Mouvement(cube, MX_);
            Mouvement(cube, R_);
            break;
        case RY_ :
            Mouvement(cube, F_);
            Mouvement(cube, MY_);
            Mouvement(cube, B);
            break;
        case RZ_ :
            Mouvement(cube, U_);
            Mouvement(cube, MZ_);
            Mouvement(cube, D);
            break;

        default :
            break;
    }
}


void RubikPlat::Permutations( unsigned char cube[CUBE_SIZE], const unsigned char *perm, int sens, bool face_tournee )
{
    unsigned char copie_cube[CUBE_SIZE] = {0};

    for (int i=0; i<CUBE_SIZE; i++)
    {
        copie_cube[i] = cube[i];
    }

    for (int i=0; i<12; i++)
    {
        cube[perm[i]] = copie_cube[perm[(i+3*sens+12)%12]];
    }

    if (face_tournee)
    {
        for (int i=0; i<8; i++)
        {
            cube[perm[12+i]] = copie_cube[perm[((i+2*sens+8)%8)+12]];
        }
    }
}



unsigned char* RubikPlat::getCube()
{
     return Rubik->getCube();
}

void RubikPlat::change_Color(int i, unsigned char color)
{
     Rubik->change_Color(i, color);
     getMainWindow()->glRubik->rubik_cube->mapping_Textures(Rubik->getCube());
}

void RubikPlat::fill_Cube(unsigned char cube[CUBE_SIZE])
{
    QString s;
    for (int i =0; i< 54; ++i)
    {
        s += QString::number(cube[i]);
        s += " ";
    }


    if (Rubik)
         Rubik->fill_Cube(cube);
}


bool RubikPlat::check_Cube()
{
     Update_Colors();
     unsigned char *Cube = getCube();

     if (!check_ColorsFace(Cube))
     {
         return false;
     }

     if (!check_ColorsCube(Cube))
     {
         return false;
     }

     if (!check_SolutionCube(Cube))
     {
        return false;
     }

     return true;
}

bool RubikPlat::check_ColorsFace(unsigned char cube[CUBE_SIZE])
{
    int count[7] = {0};

    for (int i=0; i<6; i++)
    {
        count[cube[9*i+4]]++;
    }

    for (int i=1; i<=6; i++)
    {
        if (count[i]!=1)
            return false;
    }

    return true;
}

bool RubikPlat::check_ColorsCube(unsigned char cube[CUBE_SIZE])
{
    int count[7] = {0};

    for (int i=0; i<54; i++)
    {
        count[cube[i]]++;
    }

    for (int i=1; i<=6; i++)
    {
        if (count[i]!=9)
            return false;
    }

    return true;
}

bool RubikPlat::check_SolutionCube(unsigned char cube[CUBE_SIZE])
{
    Resolution *resolution = getMainWindow()->_listMethodes[1];
    return resolution->solve(cube);
}


unsigned char RubikPlat::getCurrentColor(int i)
{
     return CurrentColors[i-1];
}

void RubikPlat::change_Current_Color(int i, unsigned char color)
{
    CurrentColors[i-1] = color;
}
