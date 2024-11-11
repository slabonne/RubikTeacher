#ifndef RUBIKPLATEDITOR_H
#define RUBIKPLATEDITOR_H

#include <QWidget>

namespace Ui {
    class RubikPlatEditor;
}

class RubikPlat;
class Palette;
class QToolButton;

class RubikPlatEditor : public QWidget
{
    Q_OBJECT

public:
    explicit RubikPlatEditor(QWidget *parent = nullptr);
    ~RubikPlatEditor();

    RubikPlat* getRubikPlat();
    Palette* getPalette();
    void resetColors();
    void translate();

private:
    Ui::RubikPlatEditor *ui;
    QToolButton* Initialiser_Cube;
};

#endif // RUBIKPLATEDITOR_H
