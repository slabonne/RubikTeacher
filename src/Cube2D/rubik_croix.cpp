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

#include "rubik_croix.h"

Rubik_Croix::Rubik_Croix()
{
	s = 15;
	Build_Rubik_Croix();
}


Rubik_Croix::Rubik_Croix(int s)
{
	this->s = s;
	Build_Rubik_Croix();
}

void Rubik_Croix::Build_Rubik_Croix()
{
    gap = 0;
    int gap2 = 4;

    s2 = 3*s + 4*gap;
    int w3 = 3*s2 + 4*gap2;
    int h3 = 4*s2 + 5*gap2;

    setFrameShape(QFrame::StyledPanel);
    setFixedSize(w3,h3);

    int table3x4[12] = {0, 2, 0,
                        3, 1, 6,
                        0, 5, 0,
                        0, 4, 0};

    for (int i=0; i<4; i++)
    {
        for (int j=0; j<3; j++)
        {
            int ind = table3x4[3*i+j];
            if (ind>0)
            {
                int ind = table3x4[3*i+j]-1;
                int x = s2*j + gap2*(j+1);
                int y = s2*i + gap2*(i+1);
                face[ind] = new QFrame(this);
                face[ind]->setFrameShape(QFrame::StyledPanel);
                face[ind]->setGeometry(x, y, s2, s2);
            }
        }
    }
}

Rubik_Croix::~Rubik_Croix()
{

}
