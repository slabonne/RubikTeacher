#include "glrubik.h"
#include "mainwindow.h"
#include "qdisplaysoluce.h"
#include "qthreadmvtface.h"
#include "rubikplat.h"

#include <QSemaphore>
#include <QDebug>
#include "variables.h"


QThreadMvtFace::QThreadMvtFace(MainWindow * fenprincipale)
{
    _mainFrame = fenprincipale;
    _mvts.clear();
    _semMvtDispo = new QSemaphore(0);
    _semMvtFace = new QSemaphore(1);
}

void QThreadMvtFace::run()
{
    forever
    {
        _semMvtFace->acquire();
        _semMvtDispo->acquire();

        unsigned char mvt = _mvts.front();
        _mvts.erase(_mvts.begin());

        if (mvt == UPDATE_PLAYER_NEXT)
        {
            _mainFrame->log->moveFinished();
            _semMvtFace->release();
        }
        else
        {
            // Update GL_Rubik
            _mainFrame->glRubik->Tourner_Face(mvt, _mainFrame->_speed);

            // Update Rubik plat
            _mainFrame->Rubik1->Tourner_Face(mvt);
        }
    }

}

void QThreadMvtFace::addMvt(unsigned char mvt)
{
    _mvts.push_back(mvt);
    _semMvtDispo->release();
}

void QThreadMvtFace::addMvts(const std::vector<unsigned char> &mvts)
{
    foreach(unsigned char mvt, mvts)
        addMvt(mvt);
}

void QThreadMvtFace::stopThread()
{
    _semMvtDispo->acquire(_mvts.size());
    _mvts.clear();
}
