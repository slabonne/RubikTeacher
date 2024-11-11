#include "glrubik.h"

#include "mainwindow.h"
#include "qdisplaysoluce.h"
#include "qthreadmvtface.h"

#include <QLCDNumber>
#include <QOpenGLContext>
#include <QPushButton>

GLRubik::GLRubik(QWidget *parent) : QOpenGLWidget(parent)
{
    resetCube();

    rubik_cube = new Cube();

    QPushButton *Origine = new QPushButton(this);
    QPixmap myPixmap6(QString(":/Cube2D/Images/GL/origin.png"));
    Origine->setIcon(QIcon(myPixmap6));
    Origine->setGeometry(10,10,52,52);
    Origine->setIconSize(QSize(48,48));
    Origine->setToolTip("Recentrer le cube");

    _AnimationOnOff = new QPushButton(this);
    QPixmap myPixmap7(QString(":/GL/Images/GL/animation.png"));

    _AnimationOnOff->setIcon(QIcon(myPixmap7));
    _AnimationOnOff->setGeometry(65,10,52,52);
    _AnimationOnOff->setIconSize(QSize(48,48));
    _AnimationOnOff->setToolTip("Animation On/Off");
    _AnimationOnOff->setCheckable(true);
    _AnimationOnOff->setFocusPolicy(Qt::NoFocus);
    _animation = false;


    cleanLogs = new QPushButton(this);
    cleanLogs->setIcon(QIcon(":/Cube2D/Images/GL/clean.png"));
    cleanLogs->setGeometry(width() -60,height()-60,52,52);
    cleanLogs->setIconSize(QSize(48,48));
    cleanLogs->setToolTip("Nettoyer les algorithmes ci-dessous");


    _animation = false;

    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(advanceGears()));
    timer->start(40);

    connect(Origine, SIGNAL(pressed()), this, SLOT(resetCube()));
    connect(_AnimationOnOff, SIGNAL(toggled(bool)), this, SLOT(AnimationOnOff()));


    _GLRubikReady = false;
    timerMvt = new QTimer(this);
    QObject::connect(timerMvt, SIGNAL(timeout()), this, SLOT(Tourner_Face_Increment()));
    timerMvt->start(40);

    _qThreadMvtFace = new QThreadMvtFace(MainWindow::getInstance());
    _qThreadMvtFace->start();
}

void GLRubik::reset()
{
    makeCurrent();
    resizeGL(width(), height());
}

void GLRubik::init()
{
    connect(cleanLogs, SIGNAL(clicked()), MainWindow::getInstance()->log, SLOT(ClearLog()));

}


void GLRubik::AnimationOnOff()
{
    _animation = !_animation;
    _AnimationOnOff->setStyleSheet(_AnimationOnOff->isChecked() ? "background-color: #6ad597" : "");
}

void GLRubik::resetCube()
{
     xRot = -60;
     yRot = 0;
     zRot = -40;
}


GLRubik::~GLRubik()
{
     glDeleteLists(face_cube, 1);
     delete rubik_cube;
}

void GLRubik::queueMovement(unsigned char mvt, bool updatePlayer)
{
    if (mvt != UPDATE_PLAYER_NEXT && mvt != _VOID_)
         _qThreadMvtFace->addMvt(mvt);

    if (updatePlayer)
        _qThreadMvtFace->addMvt(UPDATE_PLAYER_NEXT);

}

MainWindow *GLRubik::getMainWindow()
{
    return MainWindow::getInstance();
}

void GLRubik::setXRotation(int angle)
{
     normalizeAngle(&angle);
     if (angle != xRot)
     {
         xRot = angle;
         emit xRotationChanged(angle);
         update();
     }
}

void GLRubik::setYRotation(int angle)
{
     normalizeAngle(&angle);
     if (angle != yRot)
     {
         yRot = angle;
         emit yRotationChanged(angle);
         update();
     }
}

void GLRubik::setZRotation(int angle)
{
     normalizeAngle(&angle);
     if (angle != zRot)
     {
         zRot = angle;
         emit zRotationChanged(angle);
          update();
     }
}

void GLRubik::initializeGL()
{
    initializeOpenGLFunctions();
    static const GLfloat reflectance1[4] = { 1.0f, 1.0f, 0.0f, 1.0f };
    glEnable(GL_TEXTURE_2D);
    updateColors();
    makeGear(reflectance1, 1.0, 4.0, 1.0, 0.7, 20);
    glEnable(GL_DEPTH_TEST);
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}


void GLRubik::loadTexture (const char *filename, GLuint &textureID)
{
    QImage im(filename);
    QOpenGLTexture* tex = new QOpenGLTexture(im);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, tex->width(), tex->height(), 0, GL_RGBA, GL_UNSIGNED_BYTE, im.constBits());
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);

    textureID = tex->textureId();
    glBindTexture(GL_TEXTURE_2D, textureID);
}


bool GLRubik::isInitialized() const
{
    return QOpenGLFunctions::isInitialized(QOpenGLFunctions::d_ptr);
}

void GLRubik::updateColors()
{
    if (!isInitialized())
        return;

    makeCurrent();

    for (int i=0; i<8; i++)
    {
        GLuint textureID;
        loadTexture((Variables::Colors_Cube3D[i]).toStdString().c_str(), textureID);
        textures[i] =  textureID;
    }
}

void GLRubik::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

     glPushMatrix();
     glRotated(xRot, 1.0, 0.0, 0.0);
     glRotated(yRot, 0.0, 1.0, 0.0);
     glRotated(zRot, 0.0, 0.0, 1.0);

     drawCube(rubik_cube);
     glPopMatrix();
}

void GLRubik::resizeGL(int width, int height)
{
     int side = qMin(width, height);

     glViewport((width - side) / 2, (height - side) / 2, side, side);

     glMatrixMode(GL_PROJECTION);
     glLoadIdentity();
     glFrustum(-1.0, +1.0, -1.0, 1.0, 5.0, 60.0);
     glMatrixMode(GL_MODELVIEW);
     glLoadIdentity();
     glTranslated(0.0, 0.0, -20.0);

     if (cleanLogs)
        cleanLogs->setGeometry(width -60,height-60,52,52);
}

void GLRubik::mousePressEvent(QMouseEvent *event)
{
     lastPos = event->pos();
}

void GLRubik::mouseMoveEvent(QMouseEvent *event)
{
     int dx = event->x() - lastPos.x();
     int dy = event->y() - lastPos.y();

     if (event->buttons() & Qt::LeftButton)
     {
         setXRotation(xRot +  dy);
         setZRotation(zRot +  dx);
     }
     else if (event->buttons() & Qt::RightButton)
     {
         setXRotation(xRot +  dy);
         setYRotation(yRot +  dx);
     }
     lastPos = event->pos();
}

void GLRubik::advanceGears()
{
    if (_animation)
    {
        xRot += 1;
        yRot += 2;
        zRot += 3;
    }
    update();
}

GLuint GLRubik::makeGear(const GLfloat *reflectance, GLdouble innerRadius,
                           GLdouble outerRadius, GLdouble thickness,
                           GLdouble toothSize, GLint toothCount)
{
     GLuint list = glGenLists(1);
      glNewList(list, GL_COMPILE);
     glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, reflectance);

     GLdouble r0 = innerRadius;
     GLdouble r1 = outerRadius - toothSize / 2.0;
     GLdouble r2 = outerRadius + toothSize / 2.0;
     GLdouble delta = (2.0 * Pi / toothCount) / 4.0;
     GLdouble z = thickness / 2.0;
     int i, j;

     glShadeModel(GL_FLAT);

     for (i = 0; i < 2; ++i)
     {
         GLdouble sign = (i == 0) ? +1.0 : -1.0;

         glNormal3d(0.0, 0.0, sign);

         glBegin(GL_QUAD_STRIP);
         for (j = 0; j <= toothCount; ++j)
         {
             GLdouble angle = 2.0 * Pi * j / toothCount;
             glVertex3d(r0 * cos(angle), r0 * sin(angle), sign * z);
             glVertex3d(r1 * cos(angle), r1 * sin(angle), sign * z);
             glVertex3d(r0 * cos(angle), r0 * sin(angle), sign * z);
             glVertex3d(r1 * cos(angle + 3 * delta), r1 * sin(angle + 3 * delta),
                        sign * z);
         }
         glEnd();

         glBegin(GL_QUADS);
         for (j = 0; j < toothCount; ++j)
         {
             GLdouble angle = 2.0 * Pi * j / toothCount;
             glVertex3d(r1 * cos(angle), r1 * sin(angle), sign * z);
             glVertex3d(r2 * cos(angle + delta), r2 * sin(angle + delta),
                        sign * z);
             glVertex3d(r2 * cos(angle + 2 * delta), r2 * sin(angle + 2 * delta),
                        sign * z);
             glVertex3d(r1 * cos(angle + 3 * delta), r1 * sin(angle + 3 * delta),
                        sign * z);
         }
         glEnd();
     }

     glBegin(GL_QUAD_STRIP);
     for (i = 0; i < toothCount; ++i)
     {
         for (j = 0; j < 2; ++j) {
             GLdouble angle = 2.0 * Pi * (i + (j / 2.0)) / toothCount;
             GLdouble s1 = r1;
             GLdouble s2 = r2;
             if (j == 1)
                 qSwap(s1, s2);

             glNormal3d(cos(angle), sin(angle), 0.0);
             glVertex3d(s1 * cos(angle), s1 * sin(angle), +z);
             glVertex3d(s1 * cos(angle), s1 * sin(angle), -z);

             glNormal3d(s2 * sin(angle + delta) - s1 * sin(angle),
                        s1 * cos(angle) - s2 * cos(angle + delta), 0.0);
             glVertex3d(s2 * cos(angle + delta), s2 * sin(angle + delta), +z);
             glVertex3d(s2 * cos(angle + delta), s2 * sin(angle + delta), -z);
         }
     }
     glVertex3d(r1, 0.0, +z);
     glVertex3d(r1, 0.0, -z);
     glEnd();

     glShadeModel(GL_SMOOTH);

     glBegin(GL_QUAD_STRIP);
     for (i = 0; i <= toothCount; ++i)
     {
         GLdouble angle = i * 2.0 * Pi / toothCount;
         glNormal3d(-cos(angle), -sin(angle), 0.0);
         glVertex3d(r0 * cos(angle), r0 * sin(angle), +z);
         glVertex3d(r0 * cos(angle), r0 * sin(angle), -z);
     }
     glEnd();

     glEndList();


     double size = 1.;
     double c = size/2.;
     face_cube = glGenLists(2);
     glNewList(face_cube, GL_COMPILE);
     glBegin(GL_QUADS);
       glTexCoord2d(1,1);     glVertex3d(-c,0,c);
       glTexCoord2d(0,1);     glVertex3d(c,0,c);
       glTexCoord2d(0,0);     glVertex3d(c,0,-c);
       glTexCoord2d(1,0);     glVertex3d(-c,0,-c);

     glEnd();
     glEndList();

     return list;
}

void GLRubik::drawGear(GLuint , GLdouble dx, GLdouble dy, GLdouble dz, GLdouble angle)
{
     glPushMatrix();
        glTranslated(dx, dy, dz);
        glRotated(angle, 0.0, 0.0, 1.0);
        glCallList(face_cube);
     glPopMatrix();
}

void GLRubik::normalizeAngle(int *angle)
{
     while (*angle < 0)
         *angle += 360 * 16;
     while (*angle > 360 * 16)
         *angle -= 360 * 16;
}



void GLRubik::drawRepere(unsigned int echelle)
{
    glPushMatrix();
    glScalef(echelle,echelle,echelle);
    glBegin(GL_LINES);
    glColor3ub(0,0,255);
    glVertex3i(0,0,0);
    glVertex3i(1,0,0);
    glColor3ub(0,255,0);
    glVertex3i(0,0,0);
    glVertex3i(0,1,0);
    glColor3ub(255,0,0);
    glVertex3i(0,0,0);
    glVertex3i(0,0,1);
    glEnd();
    glPopMatrix();
}

void GLRubik::drawCube(Cube *cube)
{
    glColor3ub(255,0,0);

   for (int i=0; i<27; i++)
   {
       drawCoin(cube->coins[i]);
   }
}


void GLRubik::drawCoin(Coin coin)
{
     double Size = 1.;
     double c = (double)Size/2.;

     glColor3ub(255,255,255);

     glPushMatrix();
     glTranslatef(coin.p[0], coin.p[1], coin.p[2]);
     glRotated(coin.r[0], 1, 0, 0);
     glRotated(coin.r[1], 0, 1, 0);
     glRotated(coin.r[2], 0, 0, 1);

     glPushMatrix();
     glTranslatef(0, 0, c);
     glRotated(90, 1, 0, 0);
     glBindTexture(GL_TEXTURE_2D, textures[coin.index_textures[0]]);
     glCallList(face_cube);
     glPopMatrix();

     glPushMatrix();
     glTranslatef(0, 0, -c);
     glRotated(90, 1, 0, 0);
     glBindTexture(GL_TEXTURE_2D, textures[coin.index_textures[3]]);
     glCallList(face_cube);
     glPopMatrix();

     glPushMatrix();
     glTranslatef(0, c, 0);
     glBindTexture(GL_TEXTURE_2D, textures[coin.index_textures[1]]);
     glCallList(face_cube);
     glPopMatrix();

     glPushMatrix();
     glTranslatef(0, -c, 0);
     glBindTexture(GL_TEXTURE_2D, textures[coin.index_textures[4]]);
     glCallList(face_cube);
     glPopMatrix();

     glPushMatrix();
     glTranslatef(-c, 0, 0);
     glRotated(90, 0, 0, 1);
     glBindTexture(GL_TEXTURE_2D, textures[coin.index_textures[2]]);
     glCallList(face_cube);
     glPopMatrix();

     glPushMatrix();
     glTranslatef(c, 0, 0);
     glRotated(90, 0, 0, 1);
     glBindTexture(GL_TEXTURE_2D, textures[coin.index_textures[5]]);
     glCallList(face_cube);
     glPopMatrix();
     glPopMatrix();
}




void GLRubik::Tourner_Face(const unsigned char mvt, double )
{
    _theta = 0;
    _mvt = mvt;
    _GLRubikReady = true;
}

void GLRubik::Tourner_Face_Increment()
{
    if (_GLRubikReady)
    {
        double incr = 0;
        double speed = getMainWindow()->_speed;
        if (_theta+speed<Pi/2)
        {
            incr = speed;
            rubik_cube->Mouvement(_mvt, incr, false);
            _theta += incr;
            update();
        } else {
            incr = Pi/2-_theta;
            rubik_cube->Mouvement(_mvt, incr, true);
            _theta += incr;
            update();
            _GLRubikReady = false;
            _qThreadMvtFace->_semMvtFace->release();
        }
    }
}
