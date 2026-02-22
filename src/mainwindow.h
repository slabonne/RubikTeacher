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

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <qtranslator.h>
#include "variables.h"

namespace Ui {
    class MainWindow;
}

class QPushButtonMoveCube;
class RubikPlat;
class GLRubik;
class QLabel;
class Resolution;
class QProgressBar;
class QThreadMvtFace;
class QComboBox;
class QLCDNumber;
class QSlider;
class Palette;
class QDisplaySoluce;
class QPushButton;
class QNetworkReply;


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void init();

    void loadIni();
    void saveIni();

    static MainWindow* getInstance();

    RubikPlat      *Rubik1 = nullptr;
    RubikPlat      *Rubik2 = nullptr;
    GLRubik         *glRubik = nullptr;
    QLabel          *_LabelsMvt[3] = {nullptr};


    QPushButton* _next;

     double      _speed = 0.0;

     void queueMovement(unsigned char mvt, bool updatePlayer = false);

     Palette* getPalette();
    void disablePlayer();
    void enableNext(bool);
    void enablePrev(bool);
    QDisplaySoluce      *log = nullptr;
    void clearPlayer();

    QList<Resolution * > _listMethodes;

private:
    void mapMethods();

public slots:
    void checkLatestVersion();

private slots:
    void manifestDownloaded(QNetworkReply *reply);

private:
    Ui::MainWindow *ui;
    bool _ignoreNewVersion = false;
    static MainWindow* _mainWindow;
    QPushButtonMoveCube *Move_Rubik[36] = {nullptr};
    QSlider				* _speed_slider;
    unsigned char         _init_cube[CUBE_SIZE] = {0};
    QTranslator _translator;

    Resolution* computeSolution();

public slots:
    void on_stop_clicked();
    void on_next_clicked();

private slots:
     void on_shuffle_clicked();
     void update_Liste_Methodes(int n);
     void update_Liste_Steps(int n);
     void Update_Algo(int n);
     void on_about_clicked();
     void on_first_clicked();
     void on_prev_clicked();
     void on_play_clicked();
     void on_last_clicked();
     void on_solve_clicked();
     double changeSpeed(int n=1);
     void on_speed_valueChanged(int value);
     void on_compare_clicked();
     void on_clean_clicked();
     void on_lang_en_toggled(bool checked);
     void on_lang_fr_toggled(bool checked);
     void methods_currentIndexChanged(int index);
     void steps_currentIndexChanged(int index);
     void algos_currentIndexChanged(int index);

private:
    void translate (QString lang);

protected:
    void resizeEvent(QResizeEvent* event) override;
};

#endif // MAINWINDOW_H
