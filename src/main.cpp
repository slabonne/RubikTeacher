#include <QApplication>
#include <QtGui>

#include "mainwindow.h"


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    // Initialisation des ressources
    Q_INIT_RESOURCE(ressources);

    // Création de la fenêtre principale
    MainWindow fenetre;
    fenetre.show();
    fenetre.init();
    
    return app.exec();
}




