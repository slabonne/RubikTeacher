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


