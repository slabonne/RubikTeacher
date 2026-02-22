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

#ifndef PALETTE_H
#define PALETTE_H

#include <QMap>
#include <QWidget>

#include "../variables.h"

namespace Ui
{
    class Palette;
}

class RubikPlatEditor;

class Palette : public QWidget
{
    Q_OBJECT

public:
    explicit Palette(QWidget *parent = nullptr);
    ~Palette();

    static int getCurrentColor();
    void retrieveColors();
    void resetColors();
    void translate();

private:
    Ui::Palette *ui;
    static int _currentColor;
    RubikPlatEditor* _editor;
    QMap<Color, QString> _mapColorBrush;

    void setBrushCursor(const QString&);

signals:
    void changeColor(Color, QString);

private slots:
    void changeBrush(Color, QString);
};

#endif // PALETTE_H
