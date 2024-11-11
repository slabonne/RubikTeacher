#include "couleurpalette.h"
#include "mainwindow.h"
#include "palette.h"
#include "variables.h"


CouleurPalette::CouleurPalette(QWidget *palette)
    : QLabel(palette)
{

}

void CouleurPalette::setColor(Color c)
{
    _color = c;
    _color_string = Variables::COLORS[c];

    switch (_color)
    {
        case BLUE:
            _icon = QPixmap(":/palette/Images/palette/color_blue.png");
            _icon_hovered = QPixmap(":/palette/Images/palette/color_blue_hover.png");
            break;
      case WHITE:
            _icon = QPixmap(":/palette/Images/palette/color_white.png");
            _icon_hovered = QPixmap(":/palette/Images/palette/color_white_hover.png");
            break;
        case YELLOW:
            _icon = QPixmap(":/palette/Images/palette/color_yellow.png");
            _icon_hovered = QPixmap(":/palette/Images/palette/color_yellow_hover.png");
            break;
        case RED:
            _icon = QPixmap(":/palette/Images/palette/color_red.png");
            _icon_hovered = QPixmap(":/palette/Images/palette/color_red_hover.png");
            break;
        case GREEN:
            _icon = QPixmap(":/palette/Images/palette/color_green.png");
            _icon_hovered = QPixmap(":/palette/Images/palette/color_green_hover.png");
            break;
        case ORANGE:
            _icon = QPixmap(":/palette/Images/palette/color_orange.png");
            _icon_hovered = QPixmap(":/palette/Images/palette/color_orange_hover.png");
            break;
        default:
            break;
    }

}

void CouleurPalette::Retrieve_Color()
{
    int ind = 0;
    while (Variables::COLORS[ind] != _color_string)
        ind++;
    _color = Color(ind);
}

void CouleurPalette::setBrushColor(const QString &color)
{
    _color_brush = color;
}

void CouleurPalette::enterEvent(QEnterEvent *)
{
    setPixmap(_icon_hovered);
}

void CouleurPalette::leaveEvent(QEvent *)
{
    setPixmap(_icon);
}

void CouleurPalette::mousePressEvent(QMouseEvent *)
{
    emit MainWindow::getInstance()->getPalette()->changeColor(_color, _color_brush);
}
