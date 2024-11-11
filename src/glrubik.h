#ifndef __GLRUBIK__
#define __GLRUBIK__

#include "cube.h"
#include <QOpenGLWidget>
#include <QtGui>
#include <QtOpenGL>
#include <math.h>


struct Coin;
class FenPrincipale;
class MainWindow;
class QPushButton;

class QThreadMvtFace;

class GLRubik : public QOpenGLWidget, protected QOpenGLFunctions
{
     Q_OBJECT

 public:
    GLRubik(QWidget *parent);
     ~GLRubik();

     QThreadMvtFace * _qThreadMvtFace = nullptr;			// Face Moves QThreadMvtFace * _qThreadMvtFace = NULL;			// Face Moves

    bool _animation;

    void queueMovement(unsigned char mvt, bool updatePlayer = false);

    bool isInitialized() const;

     QTimer *timerMvt = nullptr;

     MainWindow* getMainWindow();

     void updateColors();
     void reset();

     void init();

 public slots:
     void setXRotation(int angle);
     void setYRotation(int angle);
     void setZRotation(int angle);
     void resetCube();
     void AnimationOnOff();
     void Tourner_Face_Increment();

 signals:
     void xRotationChanged(int angle);
     void yRotationChanged(int angle);
     void zRotationChanged(int angle);

 protected:
     void initializeGL();
     void paintGL();
     void resizeGL(int width, int height);
     void mousePressEvent(QMouseEvent *event);
     void mouseMoveEvent(QMouseEvent *event);
     void resetPosition();

 private slots:
     void advanceGears();

 private:
     GLuint makeGear(const GLfloat *reflectance, GLdouble innerRadius,
                     GLdouble outerRadius, GLdouble thickness,
                     GLdouble toothSize, GLint toothCount);
     void drawGear(GLuint gear, GLdouble dx, GLdouble dy, GLdouble dz,
                   GLdouble angle);

     void normalizeAngle(int *angle);

     int xRot;
     int yRot;
     int zRot;
     QPoint lastPos;

     QPushButton *cleanLogs = nullptr;
     
 private:
     void drawRepere(unsigned int echelle=1);
     void drawCube(Cube *cube);
     void drawCoin(Coin coin);

     int face_cube;
     double _theta;
     unsigned char _mvt;
     double _speed;

     GLuint		textures[8];

 public:
     Cube *rubik_cube = nullptr;
     void Tourner_Face(const unsigned char mvt, double speed);

     bool _GLRubikReady;
     QPushButton * _AnimationOnOff = nullptr;

    void loadTexture (const char *filename, GLuint &textureID);
};

#endif

