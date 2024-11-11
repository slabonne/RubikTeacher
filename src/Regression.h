#ifndef REGRESSION
#define REGRESSION

#include "qthread.h"
#include "variables.h"
#include "resolution.h"

#include <QDialog>


class Regression;
class QStandardItemModel;
class QTableView;
class QLabel;

class Thread_Regression : public QThread
{
 public:
    Thread_Regression(Regression * regression);
	
    Regression * _regression = nullptr;
    bool _continue;

    void run();
    void solveNewRandomCube();
};


class Regression : public QDialog
{
    Q_OBJECT
      
public:
    Regression(std::map<QString, Resolution * > map_methodes);
    virtual ~Regression();

    void cleanDisplay();
    void UpdateStats();
    void generateRandomCube(unsigned char ioCube[CUBE_SIZE]);
    std::vector<unsigned char> generateRandomSequence(unsigned int iMvts);
    QString getCube(const unsigned char iCube[CUBE_SIZE]);
    void writeSoluce(QString filename, Solution & soluce, const unsigned char cube[CUBE_SIZE], const int index);
    QString getStringSequence(const std::vector<unsigned char> &algo);

    int                 _nTest;
    QProgressBar        * _progressBar = nullptr;;
    QLabel              * _statistiques = nullptr;;
    QLabel              * _nbreMvts = nullptr;;
    QPushButton         * _startRegression = nullptr;;
    QTableView          * _displayResultats = nullptr;;
    QStandardItemModel  * _model = nullptr;;
    Thread_Regression   * _thread_regression = nullptr;;
    std::vector<unsigned char> _melange;

    std::map<QString, int >             _successMap;
    std::map<QString, Resolution * >    _map_methodes;
    std::map<QString, std::list<int> >  _map_mouvements;

signals:
    void startStop();

public slots :
    void startRegression();
    void startStopRegression();
};



#endif
