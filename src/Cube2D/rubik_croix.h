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

#ifndef __RUBIK_CROIX__
#define __RUBIK_CROIX__

#include <QFrame>

class Rubik_Croix : public QFrame
{
public:
    Rubik_Croix();
    Rubik_Croix(int s);
    ~Rubik_Croix();

protected:
    QFrame *face[6];
    int s;
    int s2;
    int gap;

private:
    void Build_Rubik_Croix();
};

#endif


