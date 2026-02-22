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

#ifndef COULEURPALETTE_H
#define COULEURPALETTE_H

#include <QIcon>
#include <QLabel>

#include "../variables.h"

class CouleurPalette : public QLabel
{
    Q_OBJECT

public:
    CouleurPalette(QWidget*);

    void setColor(Color);
    void Retrieve_Color();
    void setBrushColor(const QString&);

protected:
    void enterEvent(QEnterEvent *ev) override;
    void leaveEvent(QEvent *ev) override;
    void mousePressEvent(QMouseEvent* event) override;

private:
    Color _color = GREY;
    QString _color_brush;
    QPixmap _icon;
    QPixmap _icon_hovered;
    QString _color_string;

signals:
    void changeColor(Color);
};

#endif // COULEURPALETTE_H
