#ifndef COULEURPALETTE_H
#define COULEURPALETTE_H

#include <QIcon>
#include <QLabel>

#include "variables.h"

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
