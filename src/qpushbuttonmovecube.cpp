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
