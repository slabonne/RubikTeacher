//#include "fenprincipale.h"
#include "mainwindow.h"
#include "qpushbuttonmovecube.h"
#include <QBitmap>

QPushButtonMoveCube::QPushButtonMoveCube(const QString &title, MainWindow *frame, unsigned char mvt, const QString &icone)
    : QPushButton(title, frame), _mvt(mvt)
{
    setFixedSize(60,40);
    QPixmap * myPixmap = new QPixmap(icone);
    myPixmap->setMask(myPixmap->createHeuristicMask());
    setIcon(QIcon(*myPixmap));
    setIconSize(QSize(32,32));
    setToolTip(title);

    setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);

    QObject::connect(this, SIGNAL(pressed()), this, SLOT(Tourner_Face()));
}



void QPushButtonMoveCube::Tourner_Face()
{
    MainWindow::getInstance()->queueMovement(_mvt);
}
