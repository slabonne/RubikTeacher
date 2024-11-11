#ifndef __RUBIK_PLAT__
#define __RUBIK_PLAT__

//#include <QtGui>
#include "variables.h"
//#include "rubik_croix_carres.h"
//#include "fenprincipale.h"
#include <QFrame>
#include <QPushButton>

class Rubik_Plat;
class Rubik_Croix_Carres;
class FenPrincipale;
class QToolButton;

// Palette 6 couleurs
/*
class Rubik_Color : public QFrame
{
      Q_OBJECT
      
      public:
         Rubik_Color(QWidget *parent, Rubik_Plat *rubik_plat, unsigned char c);
         ~Rubik_Color();
         
         unsigned char color;
         
         
      private:
          Rubik_Plat *Rubik_plat;
         
      protected:
         void mousePressEvent(QMouseEvent *event);
         
};*/

// Palette 6 couleurs
class Push_Color : public QPushButton
{
      Q_OBJECT

      public:
         Push_Color(QWidget *parent, Rubik_Plat *rubik_plat, unsigned char c);
         ~Push_Color();

         unsigned char color;
         QString color_string;

        void Retrieve_Color();
      private:
          Rubik_Plat *Rubik_plat;


      public slots :
          void PressEvent();

};

class Rubik_Plat : public QWidget
{
      Q_OBJECT
      
      public:
        Rubik_Plat(QWidget*);
        Rubik_Plat(FenPrincipale *frame, QString title, QWidget *parent = 0, bool edit = true);
        ~Rubik_Plat();

        bool _edit;


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
         FenPrincipale         *Frame;
         Rubik_Croix_Carres    *Rubik;
         Push_Color            *Liste_ButtonsColors[6];
         QFrame                *Rubik_Colors_Mouse[2];  
         unsigned char         CurrentColors[2];   
         QToolButton           *Initialiser_Cube;
         QToolButton           *Vider_Cube;
         QToolButton           *Verifier_Cube;
         QPushButton           *Generer_Cube;


         void Mouvement(unsigned char cube[CUBE_SIZE], unsigned char mvt);
         void Permutations(unsigned char cube[CUBE_SIZE], const unsigned char *perm, int sens, bool face_tournee);
         bool check_ColorsFace(unsigned char cube[CUBE_SIZE]);
         bool check_ColorsCube(unsigned char cube[CUBE_SIZE]);
         bool check_SolutionCube(unsigned char cube[CUBE_SIZE]);
};

#endif
