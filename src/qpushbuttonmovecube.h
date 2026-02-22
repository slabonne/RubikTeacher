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

#ifndef QPUSHBUTTONMOVECUBE_H
#define QPUSHBUTTONMOVECUBE_H

#include <QPushButton>

class MainWindow;

class QPushButtonMoveCube : public QPushButton
{
    Q_OBJECT

public:
    QPushButtonMoveCube(const QString& title, MainWindow *frame, unsigned char mvt, const QString& icone);

private:
    unsigned char _mvt = 0;

private slots :
    void Tourner_Face();
};


#endif // QPUSHBUTTONMOVECUBE_H
