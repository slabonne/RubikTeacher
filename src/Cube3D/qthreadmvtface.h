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

#ifndef QTHREADMVTFACE_H
#define QTHREADMVTFACE_H

#include <QThread>

class MainWindow;
class QSemaphore;

class QThreadMvtFace : public QThread
{
 private:
    MainWindow * _mainFrame = nullptr;

 public:
    QThreadMvtFace(MainWindow * fenprincipale);

    QSemaphore * _semMvtFace = nullptr;
    QSemaphore * _semMvtDispo = nullptr;

    void run();
    void addMvt(unsigned char mvt);
    void addMvts(const std::vector<unsigned char>& mvts);
    void stopThread();

    std::vector<unsigned char> _mvts;
};

#endif // QTHREADMVTFACE_H
