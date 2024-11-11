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
