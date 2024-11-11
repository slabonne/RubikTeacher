#ifndef __RUBIK_CROIX_CARRES__
#define __RUBIK_CROIX_CARRES__

#include "rubik_croix.h"
#include "variables.h"


class Rubik_Croix_Carres;
class RubikPlat;
class Rubik_Carre;

class Rubik_Carre : public QFrame
{
    Q_OBJECT

public:
    Rubik_Carre(QWidget *parent, RubikPlat *rubik,  int n);
    Rubik_Carre(int s, int c);

private:
     int     color;
     int N;
     RubikPlat         *Rubik_plat = nullptr;

protected:
    void mousePressEvent(QMouseEvent *event);
};


class Rubik_Croix_Carres : public Rubik_Croix
{
    Q_OBJECT

public:
    Rubik_Croix_Carres(RubikPlat *rubik);
    Rubik_Croix_Carres(RubikPlat *rubik, int s);
    ~Rubik_Croix_Carres();

    unsigned char * getCube() {return Cube; }

    void change_Color(int i, int color);
    void fill_Cube(unsigned char cube[CUBE_SIZE]);
    void initialiser();
    void vider();

signals:
    void needsRepaint();

public slots:
    void RepaintCube();

private:
    RubikPlat      *Rubik_plat = nullptr;;
    Rubik_Carre     *carre[CUBE_SIZE];
    unsigned char  *Cube = nullptr;

private:
    void Build_Rubik_Carres(RubikPlat *rubik);
};

#endif
