#include "rubik_plat.h"

#include "resolution.h"
#include "rubik_croix_carres.h"

#include <QButtonGroup>
#include <QToolButton>
#include <QVBoxLayout>
#include <QBitmap>
#include <QMessageBox>
#include "glrubik.h"



Rubik_Plat::Rubik_Plat(QWidget *parent) : Rubik_Plat(NULL, "", parent, false)
{

}

Rubik_Plat::Rubik_Plat(FenPrincipale *frame, QString title, QWidget *parent, bool edit)
{
   // Tracer::Tracer_Log("Rubik_Plat","Rubik_Plat");

    Frame = frame;
    _edit = edit;


    QVBoxLayout *l1 = new QVBoxLayout;
    l1->setAlignment(Qt::AlignTop | Qt::AlignHCenter);

     //   Rubik = new Rubik_Croix_Carres(this, 25);
    l1->addWidget(Rubik);
        

    if (_edit)
    {
        QButtonGroup *palette_colors = new QButtonGroup(this);
        for (int i=0; i<6; i++)
        {
            Liste_ButtonsColors[i] = new Push_Color(Rubik, this, i+1);
            Liste_ButtonsColors[i]->setAutoExclusive(true);
            Liste_ButtonsColors[i]->setCheckable(true);
            Liste_ButtonsColors[i]->setStyleSheet("QPushButton {\ncolor : rgb(0,0,0);\nbackground-color : rgb(" + Variables::COLORS[i+1] + ");\n""}""\n");

            palette_colors->addButton(Liste_ButtonsColors[i], i);
        }
        palette_colors->setExclusive(true);

        for (int i=0; i<2; i++)
            for (int j=0; j<3; j++)
                 Liste_ButtonsColors[3*i+j]->setGeometry(180+20*i,240+20*j,20,20);

        Initialiser_Cube = new QToolButton(Rubik);
        QPixmap * myPixmap13 = new QPixmap(QString(":/Cube2D/Images/Cube_Resolu.bmp"));
        myPixmap13->setMask(myPixmap13->createHeuristicMask());
        Initialiser_Cube->setIcon(QIcon(*myPixmap13));
        Initialiser_Cube->setIconSize(QSize(55,32));
        Initialiser_Cube->setToolTip("Initialisation");
        Initialiser_Cube->setGeometry(10,180,60,40);

        Vider_Cube = new QToolButton(Rubik);
        QPixmap * myPixmap14 = new QPixmap(QString(":/Cube2D/Images/Cube_Vide.bmp"));
        myPixmap14->setMask(myPixmap14->createHeuristicMask());
        Vider_Cube->setIcon(QIcon(*myPixmap14));
        Vider_Cube->setIconSize(QSize(55,32));
        Vider_Cube->setToolTip("Vider le cube");
        Vider_Cube->setGeometry(10,220,60,40);

        Verifier_Cube = new QToolButton(Rubik);
        QPixmap * myPixmap15 = new QPixmap(QString(":/Cube2D/Images/Cube_Check.bmp"));
        myPixmap15->setMask(myPixmap15->createHeuristicMask());
        Verifier_Cube->setIcon(QIcon(*myPixmap15));
        Verifier_Cube->setIconSize(QSize(55,32));
        Verifier_Cube->setToolTip("Vérifier le cube");
        Verifier_Cube->setGeometry(10,260,60,40);

        change_Current_Color(1, 1);
        change_Current_Color(2, 0);


       // Generer_Cube = new QPushButton("");
       // l1->addWidget(Generer_Cube);

        QObject::connect(Initialiser_Cube, SIGNAL(pressed()), this, SLOT(initialiser()));
        QObject::connect(Vider_Cube, SIGNAL(pressed()), this, SLOT(vider()));
    //    QObject::connect(Generer_Cube, SIGNAL(pressed()), this, SLOT(generer()));
        QObject::connect(Verifier_Cube, SIGNAL(pressed()), this, SLOT(verifier()));
    }


    setLayout(l1);
}

Rubik_Plat::~Rubik_Plat()
{
}

// Tourner une face du cube
void Rubik_Plat::Tourner_Face(unsigned char mvt)
{
 //   Tracer::Tracer_Log("Rubik_Plat","Tourner_Face");

    unsigned char cube[CUBE_SIZE] = {0};
    Resolution::Copie_Cube(Rubik->getCube(), cube);

    Mouvement(cube, mvt);
   Rubik->fill_Cube(cube);
}

// Initialisation du cube
void Rubik_Plat::initialiser()
{
  //  Tracer::Tracer_Log("Rubik_Plat","initialiser");

   // Frame->SaveStep();
    Update_Colors();
    Rubik->initialiser();
    Frame->glRubik->rubik_cube->mapping_Textures(Rubik->getCube());
}

// Vidage du cube
void Rubik_Plat::vider()
{
   // Tracer::Tracer_Log("Rubik_Plat","vider");

    //Frame->SaveStep();
    Update_Colors();
    Rubik->vider();
     Frame->glRubik->rubik_cube->mapping_Textures(Rubik->getCube());
}

// V�rification et validation du cube
bool Rubik_Plat::verifier()
{
   // Tracer::Tracer_Log("Rubik_Plat","verifier");

    Update_Colors();

     unsigned char * Cube = getCube();

     if (!check_ColorsFace(Cube))
     {
         QMessageBox::critical(this, "V�rification Couleurs Face", "Erreur : V�rifier les couleurs des centres des faces");
         return false;
     }

     if (!check_ColorsCube(Cube))
     {
         QMessageBox::critical(this, "V�rification Couleurs Cube", "Erreur : V�rifier les couleurs du cube");
         return false;
     }

     if (!check_SolutionCube(Cube))
     {
        QMessageBox::critical(this, "V�rification R�solution", "Erreur : R�solution impossible");
        return false;
     }

     QMessageBox::information(this, "V�rification du cube", "Cube OK : R�solution possible");
     return true;
}








void Rubik_Plat::Update_Colors()
{
    Tracer::Tracer_Log("Rubik_Plat","Update_Colors");



    unsigned char colors[7] = {0};
    unsigned char * cube;
    cube = Rubik->getCube();

    Tracer::Tracer_Log("Cube avant :");
    Tracer::Tracer_Log_Cube(cube);

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

        Variables::Update_Colors(colors2);

        for (int i=0; i<6; i++)
        {
            Liste_ButtonsColors[i]->Retrieve_Color();
        }

        change_Current_Color(1, colors2[getCurrentColor(1)]);
        update_Cube(colors2);

        Frame->glRubik->updateColors();

        Tracer::Tracer_Log("Cube apr�s :");
        Tracer::Tracer_Log_Cube(Rubik->getCube());

        Frame->glRubik->rubik_cube->mapping_Textures(Rubik->getCube());
    }
}

void Rubik_Plat::update_Cube(unsigned char colors2[7])
{
 //   Tracer::Tracer_Log("Rubik_Plat","update_Cube");


    unsigned char *cube = NULL;
    cube = Rubik->getCube();

  //  Tracer::Tracer_Log_Cube(cube);

    unsigned char cube2[CUBE_SIZE] = {0};
    for (int i=0; i<CUBE_SIZE; i++)
    {
        unsigned char ind = 0;
        while (cube[i] != colors2[ind])
            ind++;
        cube2[i] = ind;
    }
    Rubik->fill_Cube(cube2);


 //   Tracer::Tracer_Log_Cube(cube2);
}


QString Rubik_Plat::generer()
{
   // Tracer::Tracer_Log("Rubik_Plat","generer");

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
	 
 //   QTextStream out(&file);
  //   out <<  aStringCube << endl;

    return aStringCube;
}





void Rubik_Plat::Mouvement(unsigned char cube[CUBE_SIZE], unsigned char mvt)
{
   // Tracer::Tracer_Log("Rubik_Plat","Mouvement");

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


void Rubik_Plat::Permutations( unsigned char cube[CUBE_SIZE], const unsigned char *perm, int sens, bool face_tournee )
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



unsigned char* Rubik_Plat::getCube() 
{
     return Rubik->getCube(); 
} 

void Rubik_Plat::change_Color(int i, unsigned char color)
{
     Rubik->change_Color(i, color);
     Frame->glRubik->rubik_cube->mapping_Textures(Rubik->getCube());
}

void Rubik_Plat::fill_Cube(unsigned char cube[CUBE_SIZE])
{
 //   Tracer::Tracer_Log("Rubik_Plat","fill_Cube");

     Rubik->fill_Cube(cube);
}


bool Rubik_Plat::check_Cube()
{
   // Tracer::Tracer_Log("Rubik_Plat","check_Cube");

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

   /*  if (!check_SolutionCube(Cube))
     {
        return false;
     }
*/
     return true;
}

bool Rubik_Plat::check_ColorsFace(unsigned char cube[CUBE_SIZE])
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

bool Rubik_Plat::check_ColorsCube(unsigned char cube[CUBE_SIZE])
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

bool Rubik_Plat::check_SolutionCube(unsigned char cube[CUBE_SIZE])
{
   // Tracer::Tracer_Log("Rubik_Plat","check_SolutionCube�");

    Resolution *resolution = Frame->_map_methodes[_FRIDRICH_];
    return resolution->solve(cube, Frame->progressBar);

  //  return false;
}


unsigned char Rubik_Plat::getCurrentColor(int i)
{
  //  Tracer::Tracer_Log("Rubik_Plat","getCurrentColor");

     return CurrentColors[i-1];
}


void Rubik_Plat::change_Current_Color(int i, unsigned char color)
{
  //  Tracer::Tracer_Log("Rubik_Plat","change_Current_Color");

    CurrentColors[i-1] = color;
}




/*
////////////////////////////////////////////////////////////////////////////////////////
Rubik_Color::Rubik_Color(QWidget *parent, Rubik_Plat *rubik_plat, unsigned char c) : QFrame(parent)
{
  //  Tracer::Tracer_Log("Rubik_Color","Rubik_Color");

     Rubik_plat = rubik_plat;
     color = c;
}

Rubik_Color::~Rubik_Color()
{
  //  Tracer::Tracer_Log("Rubik_Color","~Rubik_Color");
}

void Rubik_Color::mousePressEvent(QMouseEvent *event)
{   
    //Tracer::Tracer_Log("Rubik_Color","mousePressEvent");

     if (event->buttons() & Qt::LeftButton)   
     {
        Rubik_plat->change_Current_Color(1, color);
     }
}*/
/////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////
Push_Color::Push_Color(QWidget *parent, Rubik_Plat *rubik_plat, unsigned char c) : QPushButton(parent)
{
     Rubik_plat = rubik_plat;
     color = c;
     color_string = Variables::COLORS[c];

     QObject::connect(this, SIGNAL(pressed()), this, SLOT(PressEvent()));
}

Push_Color::~Push_Color()
{
}

void Push_Color::PressEvent()
{
    Rubik_plat->change_Current_Color(1, color);
}

void Push_Color::Retrieve_Color()
{
    int ind = 0;
    while (Variables::COLORS[ind] != color_string)
        ind++;
    color = ind;
}

/////////////////////////////////////////////////////////////////////////////////////////////
