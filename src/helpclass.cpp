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

#include "helpclass.h"
#include "constants.h"
#include "mainwindow.h"

#include <QPushButton>

HelpClass::HelpClass()
{
    setMinimumSize(250,100);
    setWindowTitle("A propos...");

    QVBoxLayout * vert_layout1 = new QVBoxLayout;
    QLabel * aLabel = new QLabel("<strong style=""color:red"">"+___APP_NAME___+"</strong>");
    aLabel->setAlignment(Qt::AlignHCenter);
    QFont aFont;
    aFont.setBold(true);
    aFont.setPixelSize(18);
    aLabel->setFont(aFont);
    vert_layout1->addWidget(aLabel);

    QLabel * aLabel3 = new QLabel("v"+___VERSION___);
    aLabel3->setAlignment(Qt::AlignHCenter);
    vert_layout1->addWidget(aLabel3);

    QPushButton* checkNewVersion = new QPushButton(tr("Vérifier les mises à jour"), this);
    vert_layout1->addWidget(checkNewVersion);
    connect(checkNewVersion, SIGNAL(clicked()), MainWindow::getInstance(), SLOT(checkLatestVersion()));

    QLabel * aLabel2 = new QLabel(QString("<em>par %1</em>").arg(___AUTHOR___));
    aLabel2->setAlignment(Qt::AlignHCenter);
    vert_layout1->addWidget(aLabel2);

    QLabel * aLabel4 = new QLabel(QString("<a href=""%1"">%1</a>").arg(___WEBPAGE_URL___));
    aLabel4->setAlignment(Qt::AlignHCenter);
    aLabel4->setOpenExternalLinks(true);
    vert_layout1->addWidget(aLabel4);

     setLayout(vert_layout1);
     setModal(true);
}

