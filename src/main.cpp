/*
 * Rubik Teacher
 * Copyright (C) 2026 Sébastien LABONNE
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <https://www.gnu.org/licenses/>.
 */

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




