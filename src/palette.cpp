#include "palette.h"
#include "rubikplateditor.h"
#include "ui_palette.h"
#include <QDebug>
#include "variables.h"

#define CURSOR_SIZE 48


int Palette::_currentColor = -1;

Palette::Palette(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Palette)
{
    ui->setupUi(this);

    resetColors();

    connect(this, SIGNAL(changeColor(Color, QString)), this, SLOT(changeBrush(Color, QString)));

    _editor = static_cast<RubikPlatEditor*>(parent);

    setBrushCursor(":/palette/Images/palette/brush.png");
}

Palette::~Palette()
{
    delete ui;
}


int Palette::getCurrentColor()
{
    return _currentColor;
}

void Palette::retrieveColors()
{
    ui->red->Retrieve_Color();
    ui->orange->Retrieve_Color();
    ui->yellow->Retrieve_Color();
    ui->blue->Retrieve_Color();
    ui->green->Retrieve_Color();
    ui->white->Retrieve_Color();
}

void Palette::resetColors()
{
    ui->red->setColor(RED);
    ui->orange->setColor(ORANGE);
    ui->yellow->setColor(YELLOW);
    ui->blue->setColor(BLUE);
    ui->green->setColor(GREEN);
    ui->white->setColor(WHITE);

    _mapColorBrush[WHITE] = ":/palette/Images/palette/brush_white.png";
    _mapColorBrush[YELLOW] = ":/palette/Images/palette/brush_yellow.png";
    _mapColorBrush[ORANGE] = ":/palette/Images/palette/brush_orange.png";
    _mapColorBrush[RED] = ":/palette/Images/palette/brush_red.png";
    _mapColorBrush[BLUE] = ":/palette/Images/palette/brush_blue.png";
    _mapColorBrush[GREEN] = ":/palette/Images/palette/brush_green.png";

    ui->red->setBrushColor(_mapColorBrush[RED]);
    ui->orange->setBrushColor(_mapColorBrush[ORANGE]);
    ui->yellow->setBrushColor(_mapColorBrush[YELLOW]);
    ui->blue->setBrushColor(_mapColorBrush[BLUE]);
    ui->green->setBrushColor(_mapColorBrush[GREEN]);
    ui->white->setBrushColor(_mapColorBrush[WHITE]);
}

void Palette::translate()
{
    ui->retranslateUi(this);
}

void Palette::setBrushCursor(const QString &cursor)
{
    QPixmap brush = QPixmap(cursor);
    QPixmap brush2 = brush.scaled(CURSOR_SIZE,CURSOR_SIZE, Qt::KeepAspectRatio);
    _editor->setCursor(QCursor(brush2, 0, 0));
}

void Palette::changeBrush(Color c, QString brush)
{
    _currentColor = (int)c;
    setBrushCursor(brush);
}
