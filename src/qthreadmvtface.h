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
