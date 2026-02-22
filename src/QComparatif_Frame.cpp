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

#include "QComparatif_Frame.h"
#include "qdisplaysoluce.h"
#include "ResolutionMethod/resolution.h"

#include <QBoxLayout>
#include <QLabel>
#include <QProgressBar>
#include <QPushButton>
#include <QMessageBox>

using namespace std;

QComparatif_Frame::QComparatif_Frame(QList<Resolution *> aMapMethodes, unsigned char cube[CUBE_SIZE])
{
    setWindowTitle(tr("Comparatif des Méthodes de résolution"));

    QGridLayout* layout = new QGridLayout;

    layout->setSpacing(20);

    QFont font;
    font.setBold(true);

    QLabel* l1 = new QLabel(tr("Méthode de résolution"), this);
    l1->setFont(font);
    layout->addWidget(l1, 0,0);

    QLabel* l2 = new QLabel(tr("Résolution possible en:"), this);
    l2->setFont(font);
    layout->addWidget(l2, 0,1);

    setLayout(layout);


    int row = 1;
    try
    {
        for (QList<Resolution*>::iterator it = aMapMethodes.begin(); it != aMapMethodes.end(); it++)
        {
            layout->addWidget(new QLabel((*it)->getTitle(), this), row,0);
            if ((*it)->solve(cube))
            {
                QString aText = QString::number(QDisplaySoluce::getNumberMvts((*it)->solution));
                aText += tr(" mouvements");
                layout->addWidget(new QLabel(aText, this), row,1);
            }
            else
            {
                layout->addWidget(new QLabel(tr("Résolution impossible!"), this), row,1);
            }
            row++;
        }
    }
    catch (CubeAlreadySolved)
    {
        QMessageBox::information(this, tr("Cube résolu..."), tr("Le cube est déjà résolu... non?!"));
    }
}

