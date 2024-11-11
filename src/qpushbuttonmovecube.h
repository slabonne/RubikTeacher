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
