#include "rubikplateditor.h"
#include "ui_rubikplateditor.h"
#include <QBitmap>
#include <QToolButton>
#include "rubik_croix_carres.h"


RubikPlatEditor::RubikPlatEditor(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RubikPlatEditor)
{
    ui->setupUi(this);

    Initialiser_Cube = new QToolButton(ui->rubikplat->Rubik);
    QPixmap * myPixmap13 = new QPixmap(QString(":/Cube2D/Images/Cube_Resolu.bmp"));
    myPixmap13->setMask(myPixmap13->createHeuristicMask());
    Initialiser_Cube->setIcon(QIcon(*myPixmap13));
    Initialiser_Cube->setIconSize(QSize(55,32));
    Initialiser_Cube->setToolTip("Réinitialiser le cube");
    Initialiser_Cube->setGeometry(10,180,60,40);
      Initialiser_Cube->setCursor(Qt::PointingHandCursor);

   QToolButton* Vider_Cube = new QToolButton(ui->rubikplat->Rubik);
    QPixmap * myPixmap14 = new QPixmap(QString(":/Cube2D/Images/Cube_Vide.bmp"));
    myPixmap14->setMask(myPixmap14->createHeuristicMask());
    Vider_Cube->setIcon(QIcon(*myPixmap14));
    Vider_Cube->setIconSize(QSize(55,32));
    Vider_Cube->setToolTip("Effacer le cube");
    Vider_Cube->setGeometry(10,220,60,40);
    Vider_Cube->setCursor(Qt::PointingHandCursor);

     QToolButton* Verifier_Cube = new QToolButton(ui->rubikplat->Rubik);
    QPixmap * myPixmap15 = new QPixmap(QString(":/Cube2D/Images/Cube_Check.bmp"));
    myPixmap15->setMask(myPixmap15->createHeuristicMask());
    Verifier_Cube->setIcon(QIcon(*myPixmap15));
    Verifier_Cube->setIconSize(QSize(55,32));
    Verifier_Cube->setToolTip("Vérifier si le cube peut être résolu");
    Verifier_Cube->setGeometry(10,260,60,40);
    Verifier_Cube->setCursor(Qt::PointingHandCursor);

    ui->rubikplat->setEditable();

    QObject::connect(Initialiser_Cube, SIGNAL(pressed()), ui->rubikplat, SLOT(initialiser()));
    QObject::connect(Vider_Cube, SIGNAL(pressed()), ui->rubikplat, SLOT(vider()));
    QObject::connect(Verifier_Cube, SIGNAL(pressed()), ui->rubikplat, SLOT(verifier()));
}

RubikPlatEditor::~RubikPlatEditor()
{
     delete ui;
}

RubikPlat *RubikPlatEditor::getRubikPlat()
{
    return ui->rubikplat;
}

Palette *RubikPlatEditor::getPalette()
{
    return ui->palette;
}

void RubikPlatEditor::resetColors()
{
    ui->palette->resetColors();
}

void RubikPlatEditor::translate()
{
    ui->retranslateUi(this);
    ui->palette->translate();
}

