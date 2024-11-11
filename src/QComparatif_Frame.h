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
