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

#ifndef _QCOMPARATIF_FRAME_
#define _QCOMPARATIF_FRAME_

#include <QDialog>
#include <QWidget>

#include "variables.h"

class QLabel;
class Resolution;
class QProgressBar;
class QPushButton;


class QComparatif_Frame : public QDialog
{
public:
    QComparatif_Frame(QList<Resolution*>, unsigned char  cube[CUBE_SIZE]);
};

#endif
