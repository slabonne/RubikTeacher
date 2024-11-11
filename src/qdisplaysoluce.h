#ifndef QDISPLAYSOLUCE_H
#define QDISPLAYSOLUCE_H

#include <QTreeView>
#include "variables.h"
#include "mystandarditem.h"


class QStandardItemModel;
class MainWindow;
class MyStandardItem;
class QSemaphore;


class QDisplaySoluce : public QTreeView
{
    Q_OBJECT

public:
    explicit QDisplaySoluce(QWidget *parent = nullptr);

    AlgoType _autoPlayTo = END;

    void setCurrentLine(int row);
    int getCurrentRow() const;


    void play();
    void autoNext();
    void next();

    void moveFinished();

    int    addAlgo(Algorithm algo, bool isSoluce = false);
    void    addStep(Step step);
    void    addSolution(Solution soluce);
    void    addBreakLine();


    int     PrevMvt();
    int     NextMvt();
    bool    Begin(unsigned char cube[CUBE_SIZE]);
    bool    End(unsigned char cube[CUBE_SIZE]);
    bool    isEndStep();

    void    Play_Next_Algo();
    void    updatePlayer();

    static int getNumberMvts(const std::vector<unsigned char> &algo);
    static int getNumberMvts(const Step &step);
    static int getNumberMvts(const Solution &soluce);

    QList<int> getNextMvts();

    void displaySoluce(Solution* solution);

    void addLine(QString text, AlgoType type,  unsigned char cube[CUBE_SIZE]= {0}, unsigned char target[CUBE_SIZE] = {0});

public slots :
    void displayAlgo(const QModelIndex & modelindex);
    void nextLine();
    void ClearLog();

private:
    QStandardItemModel  *model = nullptr;
    MyStandardItem* getCurrentAlgo();

protected:
    void resizeEvent ( QResizeEvent * event );

signals:
    void nextLin();
};

#endif // QDISPLAYSOLUCE_H
