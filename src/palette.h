#ifndef PALETTE_H
#define PALETTE_H

#include <QMap>
#include <QWidget>

#include "variables.h"

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
