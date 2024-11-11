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
