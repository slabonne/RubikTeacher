#include "constants.h"
#include "qdisplaysoluce.h"

#include "glrubik.h"
#include "mainwindow.h"
#include "qpushbuttonmovecube.h"
#include "resolution.h"
#include "ui_mainwindow.h"
#include "resolution.h"
#include "helpclass.h"
#include "QComparatif_Frame.h"
#include "qthreadmvtface.h"

#include <QDomDocument>
#include <QMessageBox>
#include <QNetworkAccessManager>
#include <QNetworkReply>

MainWindow* MainWindow::_mainWindow = nullptr;


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent), ui(new Ui::MainWindow)
{
    _mainWindow = this;

    ui->setupUi(this);

    QApplication::setStyle("fusion");

    srand(time(nullptr));

    Rubik1 = ui->rubik_editor->getRubikPlat();

   QGroupBox *groupBox2 = ui->groupMvts;
      QGridLayout *layout = new QGridLayout();

        layout->setContentsMargins(15,15,15,15);
        layout->setHorizontalSpacing(0);
        layout->setVerticalSpacing(0);
        layout->setSizeConstraint(QLayout::SetMinimumSize);

          Move_Rubik[0] = new QPushButtonMoveCube(Variables::Liste_Mouvements[U], this, U, QString(":/Moves/Images/Mvts/U.bmp"));
          Move_Rubik[1] = new QPushButtonMoveCube(Variables::Liste_Mouvements[L], this, L, QString(":/Moves/Images/Mvts/L.bmp"));
          Move_Rubik[2] = new QPushButtonMoveCube(Variables::Liste_Mouvements[F], this, F, QString(":/Moves/Images/Mvts/F.bmp"));
          Move_Rubik[3] = new QPushButtonMoveCube(Variables::Liste_Mouvements[D], this, D, QString(":/Moves/Images/Mvts/D.bmp"));
          Move_Rubik[4] = new QPushButtonMoveCube(Variables::Liste_Mouvements[R], this, R, QString(":/Moves/Images/Mvts/R.bmp"));
          Move_Rubik[5] = new QPushButtonMoveCube(Variables::Liste_Mouvements[B], this, B, QString(":/Moves/Images/Mvts/B.bmp"));

          Move_Rubik[6] = new QPushButtonMoveCube(Variables::Liste_Mouvements[U_], this, U_, QString(":/Moves/Images/Mvts/U_.bmp"));
          Move_Rubik[7] = new QPushButtonMoveCube(Variables::Liste_Mouvements[L_], this, L_, QString(":/Moves/Images/Mvts/L_.bmp"));
          Move_Rubik[8] = new QPushButtonMoveCube(Variables::Liste_Mouvements[F_], this, F_, QString(":/Moves/Images/Mvts/F_.bmp"));
          Move_Rubik[9] = new QPushButtonMoveCube(Variables::Liste_Mouvements[D_], this, D_, QString(":/Moves/Images/Mvts/D_.bmp"));
          Move_Rubik[10] = new QPushButtonMoveCube(Variables::Liste_Mouvements[R_], this, R_, QString(":/Moves/Images/Mvts/R_.bmp"));
          Move_Rubik[11] = new QPushButtonMoveCube(Variables::Liste_Mouvements[B_], this, B_, QString(":/Moves/Images/Mvts/B_.bmp"));

          Move_Rubik[12] = new QPushButtonMoveCube(Variables::Liste_Mouvements[u], this, u, QString(":/Moves/Images/Mvts/u2.bmp"));
          Move_Rubik[13] = new QPushButtonMoveCube(Variables::Liste_Mouvements[l], this, l, QString(":/Moves/Images/Mvts/l2.bmp"));
          Move_Rubik[14] = new QPushButtonMoveCube(Variables::Liste_Mouvements[f], this, f, QString(":/Moves/Images/Mvts/f2.bmp"));
          Move_Rubik[15] = new QPushButtonMoveCube(Variables::Liste_Mouvements[d], this, d, QString(":/Moves/Images/Mvts/d2.bmp"));
          Move_Rubik[16] = new QPushButtonMoveCube(Variables::Liste_Mouvements[r], this, r, QString(":/Moves/Images/Mvts/r2.bmp"));
          Move_Rubik[17] = new QPushButtonMoveCube(Variables::Liste_Mouvements[b], this, b, QString(":/Moves/Images/Mvts/b2.bmp"));

          Move_Rubik[18] = new QPushButtonMoveCube(Variables::Liste_Mouvements[u_], this, u_, QString(":/Moves/Images/Mvts/u2_.bmp"));
          Move_Rubik[19] = new QPushButtonMoveCube(Variables::Liste_Mouvements[l_], this, l_, QString(":/Moves/Images/Mvts/l2_.bmp"));
          Move_Rubik[20] = new QPushButtonMoveCube(Variables::Liste_Mouvements[f_], this, f_, QString(":/Moves/Images/Mvts/f2_.bmp"));
          Move_Rubik[21] = new QPushButtonMoveCube(Variables::Liste_Mouvements[d_], this, d_, QString(":/Moves/Images/Mvts/d2_.bmp"));
          Move_Rubik[22] = new QPushButtonMoveCube(Variables::Liste_Mouvements[r_], this, r_, QString(":/Moves/Images/Mvts/r2_.bmp"));
          Move_Rubik[23] = new QPushButtonMoveCube(Variables::Liste_Mouvements[b_], this, b_, QString(":/Moves/Images/Mvts/b2_.bmp"));

          Move_Rubik[24] = new QPushButtonMoveCube(Variables::Liste_Mouvements[MX], this, MX, QString(":/Moves/Images/Mvts/mx.bmp"));
          Move_Rubik[25] = new QPushButtonMoveCube(Variables::Liste_Mouvements[MY], this, MY, QString(":/Moves/Images/Mvts/my.bmp"));
          Move_Rubik[26] = new QPushButtonMoveCube(Variables::Liste_Mouvements[MZ], this, MZ, QString(":/Moves/Images/Mvts/mz.bmp"));

          Move_Rubik[27] = new QPushButtonMoveCube(Variables::Liste_Mouvements[RX], this, RX, QString(":/Moves/Images/Mvts/rx.bmp"));
          Move_Rubik[28] = new QPushButtonMoveCube(Variables::Liste_Mouvements[RY], this, RY, QString(":/Moves/Images/Mvts/ry.bmp"));
          Move_Rubik[29] = new QPushButtonMoveCube(Variables::Liste_Mouvements[RZ], this, RZ, QString(":/Moves/Images/Mvts/rz.bmp"));

          Move_Rubik[30] = new QPushButtonMoveCube(Variables::Liste_Mouvements[MX_], this, MX_, QString(":/Moves/Images/Mvts/mx_.bmp"));
          Move_Rubik[31] = new QPushButtonMoveCube(Variables::Liste_Mouvements[MY_], this, MY_, QString(":/Moves/Images/Mvts/my_.bmp"));
          Move_Rubik[32] = new QPushButtonMoveCube(Variables::Liste_Mouvements[MZ_], this, MZ_, QString(":/Moves/Images/Mvts/mz_.bmp"));

          Move_Rubik[33] = new QPushButtonMoveCube(Variables::Liste_Mouvements[RX_], this, RX_, QString(":/Moves/Images/Mvts/rx_.bmp"));
          Move_Rubik[34] = new QPushButtonMoveCube(Variables::Liste_Mouvements[RY_], this, RY_, QString(":/Moves/Images/Mvts/ry_.bmp"));
          Move_Rubik[35] = new QPushButtonMoveCube(Variables::Liste_Mouvements[RZ_], this, RZ_, QString(":/Moves/Images/Mvts/rz_.bmp"));

          for (int i=0; i<6; i++)
          {
              for (int j=0; j<6; j++)
              {
                   layout->addWidget(Move_Rubik[6*i+j], i, j);
              }
          }

          for (int i=0; i<2; i++)
          {
              for (int j=0; j<6; j++)
              {
                   Move_Rubik[6*i+j]->setStyleSheet("QPushButton {\nbackground-color : rgb(255,255,128);\n""}""\n");
              }
          }

          for (int i=2; i<4; i++)
          {
              for (int j=0; j<6; j++)
              {
                   Move_Rubik[6*i+j]->setStyleSheet("QPushButton {\nbackground-color : rgb(255,156,100);\n""}""\n");
              }
          }

          for (int i=4; i<6; i++)
          {
              for (int j=0; j<3; j++)
              {
                   Move_Rubik[6*i+j]->setStyleSheet("QPushButton {\nbackground-color : rgb(175,240,166);\n""}""\n");
              }
          }

          for (int i=4; i<6; i++)
          {
              for (int j=3; j<6; j++)
              {
                   Move_Rubik[6*i+j]->setStyleSheet("QPushButton {\nbackground-color : rgb(162,192,244);\n""}""\n");
              }
          }

    groupBox2->setLayout(layout);

    glRubik = ui->openGLWidget;

    log = ui->log;
    log->ClearLog();

    Rubik2 = ui->rubik_dest;

    _speed_slider = ui->speed;
    _speed_slider->setRange(1,100);
    _speed_slider->setValue(20);

    _LabelsMvt[0] = ui->mvt_prev;
    _LabelsMvt[1] = ui->mvt_current;
    _LabelsMvt[2] = ui->mvt_next;

    _next = ui->next;

    ///////////////////////////////////////////////////////////
    // METHODES DE RESOLUTION
    ///////////////////////////////////////////////////////////
    mapMethods();


    //////////////////////////////////////
    // INITIALISATION
    //////////////////////////////////////
    changeSpeed();

    Rubik1->initialiser();
    Resolution::Copie_Cube(Rubik1->getCube(), _init_cube);

      disablePlayer();

      loadIni();

      glRubik->init();

      setWindowTitle(___APP_NAME___);


    // check for a newer version
    try
    {
       if (!_ignoreNewVersion)
            checkLatestVersion();
    }
    catch (...)
    {
        qDebug() << "erreur";
    }
}

MainWindow::~MainWindow()
{
    saveIni();
    delete ui;
}

void MainWindow::init()
{
    resizeEvent(nullptr);
}







//////////////////////////////////////////////
/// CHECK LATEST VERSION
/////////////////////////////////////////////
void MainWindow::checkLatestVersion()
{
    _ignoreNewVersion = false;
    QNetworkAccessManager * manager = new QNetworkAccessManager(this);
    manager->clearAccessCache();
    connect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(manifestDownloaded(QNetworkReply*)) );
    manager->get(QNetworkRequest(QUrl(___MANIFEST_FILE___)));
}


void MainWindow::manifestDownloaded(QNetworkReply *reply)
{
    char* data = new char[1000];
    reply->read(data, 1000);

    reply->deleteLater();

     QDomDocument dom("mon_xml");
     QString s = data;
     if (!dom.setContent(s))
     {
         qDebug() << "erreur";
     }

   QDomElement dom_element = dom.documentElement();
   QDomNode noeud = dom_element.firstChild();
   QString version, url;
   while(!noeud.isNull())
   {
       if (noeud.toElement().tagName() == "version")
           version = noeud.firstChild().nodeValue();
       else if (noeud.toElement().tagName() == "url")
           url = noeud.firstChild().nodeValue();
       noeud = noeud.nextSibling();
   }

   if (!version.isEmpty() && version != ___VERSION___)
   {
       QMessageBox::StandardButton reply = QMessageBox::question(this, ___APP_NAME___ + " v." + ___VERSION___,
            QString(tr("Une nouvelle version est disponible : %1\nVoulez-vous la télécharger?")).arg(version), QMessageBox::Yes|QMessageBox::No|QMessageBox::Ignore);
       if (reply == QMessageBox::Yes)
           QDesktopServices::openUrl(url);
       else if (reply == QMessageBox::Ignore)
           _ignoreNewVersion = true;
   }
}











//////////////////////////////////////////////
/// SETTINGS
/////////////////////////////////////////////
void MainWindow::loadIni()
{
    QSettings settings(QSettings::IniFormat, QSettings::UserScope, "RubikTeacher", "settings");

    restoreGeometry(settings.value("Rubik Teacher/geometry").toByteArray());

    _ignoreNewVersion = settings.value("Rubik Teacher/ignoreVersion", false).toBool();

    QString lang = settings.value("Rubik Teacher/language","fr").toString();
    if (lang == "fr")
    ui->lang_fr->setChecked(true);
    else
    ui->lang_en->setChecked(true);

    ui->methods->setCurrentIndex(settings.value("Rubik Teacher/method",0).toInt());
    ui->numberMvts->setValue(settings.value("Rubik Teacher/randomMoves",15).toInt());
    ui->speed->setValue(settings.value("Rubik Teacher/speed",20).toInt());
}

void MainWindow::saveIni()
{
    QSettings settings(QSettings::IniFormat, QSettings::UserScope, "RubikTeacher", "settings");

    settings.beginGroup("Rubik Teacher");
    settings.setValue("geometry", saveGeometry());
    settings.setValue("ignoreVersion", _ignoreNewVersion);
    QString lang = (ui->lang_en->isChecked() ? "en" : "fr");
    settings.setValue("language", lang);
    settings.setValue("method", ui->methods->currentIndex());
    settings.setValue("randomMoves", ui->numberMvts->value());
    settings.setValue("speed", ui->speed->value());
    settings.endGroup();
}

MainWindow *MainWindow::getInstance()
{
    return _mainWindow;
}

void MainWindow::queueMovement(unsigned char mvt, bool updatePlayer)
{
    glRubik->queueMovement(mvt, updatePlayer);
}






//////////////////////////////////////////////
/// COLUMN 1
/////////////////////////////////////////////
Palette *MainWindow::getPalette()
{
    return ui->rubik_editor->getPalette();
}







// Shuffle cube
void MainWindow::on_shuffle_clicked()
{
    int nbre_mvts_melange = ui->numberMvts->value();

    unsigned char mvt_prec = 255;
    unsigned char mvt = 0;

    unsigned char mvts[] = {U, L, F, D, R, B, MX, MY, MZ, u, l ,f, d, r, b, U_, L_, F_, D_, R_, B_, MX_, MY_, MZ_, u_, l_ ,f_, d_, r_, b_};
    int n_mvt = sizeof(mvts) / sizeof(unsigned char);

    for (int i=0; i<nbre_mvts_melange; i++)
    {
        do
        {
            mvt = mvts[rand()%n_mvt];
        } while (mvt_prec==((mvt+18)%36));
        mvt_prec = mvt;

        queueMovement(mvt);
    }
}





/*** ABOUT ***/
void MainWindow::on_about_clicked()
{
    HelpClass().exec();
}




/*** TRANSLATE ***/
void MainWindow::on_lang_en_toggled(bool checked)
{
    if (checked)
        translate("en");
}

void MainWindow::on_lang_fr_toggled(bool checked)
{
    if (checked)
       translate("fr");
}

void MainWindow::translate(QString lang)
{
    bool ok = _translator.load("lang/rubik_" + lang,":/");
    if (!ok)
        return;
    qApp->installTranslator(&_translator);
    ui->retranslateUi(this);
    ui->rubik_editor->translate();

    mapMethods();
    log->ClearLog();
}


void MainWindow::resizeEvent(QResizeEvent *)
{
    int width = ui->log->width();
    int height = width*13/16;

    glRubik->setMinimumHeight(height);
    glRubik->setMaximumHeight(height);
}





//////////////////////////////////////////////
/// COLUMN 2
/////////////////////////////////////////////

void MainWindow::on_clean_clicked()
{
    ui->log->ClearLog();
}















//////////////////////////////////////////////
/// COLUMN 3
/////////////////////////////////////////////

void MainWindow::mapMethods()
{
    disconnect(ui->methods, SIGNAL(currentIndexChanged(int)), this, SLOT(methods_currentIndexChanged(int)));
    disconnect(ui->steps, SIGNAL(currentIndexChanged(int)), this, SLOT(steps_currentIndexChanged(int)));
    disconnect(ui->algos, SIGNAL(currentIndexChanged(int)), this, SLOT(algos_currentIndexChanged(int)));

    int algo = ui->algos->currentIndex();
    int step = ui->steps->currentIndex();
    int method = ui->methods->currentIndex();

    ui->steps->clear();
    ui->algos->clear();
    ui->methods->clear();

    _listMethodes.clear();

    // + Layout By Layout
    Resolution_Layer * resolution_layer = new Resolution_Layer(this);
    _listMethodes.push_back(resolution_layer);
    ui->methods->addItem(resolution_layer->getTitle());

    // + Fridrich
    Resolution_Friedriech * resolution_fridrich = new Resolution_Friedriech(this);
    _listMethodes.push_back(resolution_fridrich);
    ui->methods->addItem(resolution_fridrich->getTitle());


    if(method >=0)
    {
        ui->methods->setCurrentIndex(method);
        methods_currentIndexChanged(method);
    }
    if (step >= 0)
    {
        ui->steps->setCurrentIndex(step);
        steps_currentIndexChanged(step);
    }
    if (algo >= 0)
    {
        ui->algos->setCurrentIndex(algo);
    }

    connect(ui->methods, SIGNAL(currentIndexChanged(int)), this, SLOT(methods_currentIndexChanged(int)));
    connect(ui->steps, SIGNAL(currentIndexChanged(int)), this, SLOT(steps_currentIndexChanged(int)));
    connect(ui->algos, SIGNAL(currentIndexChanged(int)), this, SLOT(algos_currentIndexChanged(int)));
}


void MainWindow::methods_currentIndexChanged(int index)
{
    update_Liste_Methodes(index);
}


void MainWindow::update_Liste_Methodes(int n)
{
    ui->steps->clear();
     for (std::map<QString, std::map<QString, Algorithm * > >::const_iterator it = _listMethodes[n]->map_steps.begin(); it != _listMethodes[n]->map_steps.end(); it++)
     {
         ui->steps->addItem(it->first);
     }

     update_Liste_Steps(0);
}

void MainWindow::steps_currentIndexChanged(int index)
{
    if (index >=0 && index < ui->steps->count())
        update_Liste_Steps(index);
}

void MainWindow::update_Liste_Steps(int)
{
    int meth = ui->methods->currentIndex();
     ui->algos->clear();
     for (std::map<QString, Algorithm * >::const_iterator it = _listMethodes[meth]->map_steps[ui->steps->currentText()].begin();
          it != _listMethodes[meth]->map_steps[ui->steps->currentText()].end(); it++)
     {
        ui->algos->setIconSize(QSize(64,64));

        // add algo
        ui->algos->addItem(it->second->_icon, it->first);
     }
}

void MainWindow::Update_Algo(int)
{
    int meth = ui->methods->currentIndex();
    QString s = ui->algos->currentText();
    if (!s.isEmpty() )
    {
        Algorithm Algo(_listMethodes[meth]->map_steps[ui->steps->currentText()][s]->_title, _listMethodes[meth]->map_steps[ui->steps->currentText()][s]->_init_cube,
                _listMethodes[meth]->map_steps[ui->steps->currentText()][s]->_target_cube, _listMethodes[meth]->map_steps[ui->steps->currentText()][s]->_target_cube,
                _listMethodes[meth]->map_steps[ui->steps->currentText()][s]->_mvts);
        log->addAlgo(Algo);
        log->setCurrentLine(-1);
    }
}

void MainWindow::algos_currentIndexChanged(int index)
{
    Update_Algo(index);
}









void MainWindow::on_compare_clicked()
{
    Rubik1->Update_Colors();

    try
    {
        if (_listMethodes[1]->solve(Rubik1->getCube()))
        {
           QComparatif_Frame(_listMethodes, Rubik1->getCube()).exec();
        }
        else
        {
            QMessageBox::critical(this, tr("Vérification Résolution"), tr("Erreur : Résolution impossible\nVérifiez le cube !"));
        }
    } catch (CubeAlreadySolved)
    {
        QMessageBox::information(this, tr("Cube résolu..."), tr("Le cube est déjà résolu... non?!"));
    }
}


Resolution *MainWindow::computeSolution()
{
    if (Rubik1->check_Cube())
    {
        on_clean_clicked();
        Resolution *resolution = _listMethodes[ui->methods->currentIndex()];

        Rubik1->Update_Colors();
        resolution->solve(Rubik1->getCube());

        return resolution;
    }
    else
    {
         QMessageBox::critical(this, tr("Vérification Résolution"), tr("Erreur : Résolution impossible\nVérifiez le cube !"));
    }

   return nullptr;
}


void MainWindow::on_solve_clicked()
{
    try
    {
        Resolution* resolution = computeSolution();
        if (!resolution)
            return;

        log->displaySoluce(&(resolution->solution));
    }
    catch (CubeAlreadySolved)
    {
        QMessageBox::information(this, tr("Cube résolu..."), tr("Le cube est déjà résolu... non?!"));
    }
}









/*************
 * PLAYER
 * ************/
void MainWindow::clearPlayer()
{
    disablePlayer();
    ui->mvt_next->clear();
    ui->mvt_prev->clear();
    ui->mvt_current->clear();
}

void MainWindow::disablePlayer()
{
    ui->first->setEnabled(false);
    ui->prev->setEnabled(false);
    ui->play->setEnabled(false);
  //  ui->stop->setEnabled(false);
    ui->next->setEnabled(false);
    ui->last->setEnabled(false);
}

void MainWindow::enableNext(bool enabled)
{
    ui->next->setEnabled(enabled);
    ui->last->setEnabled(enabled);
    ui->play->setEnabled(enabled);
}

void MainWindow::enablePrev(bool enabled)
{
    ui->first->setEnabled(enabled);
    ui->prev->setEnabled(enabled);
}



void MainWindow::on_first_clicked()
{
    unsigned char cube[CUBE_SIZE];
    if (!log->Begin(cube))
        return;
    Rubik1->fill_Cube(cube);
    glRubik->rubik_cube->mapping_Textures(cube);

    ui->first->setEnabled(false);
}

void MainWindow::on_prev_clicked()
{
  unsigned char mvt = log->PrevMvt();
    if (mvt != _VOID_)
        queueMovement(mvt);
}

void MainWindow::on_play_clicked()
{
    log->play();
}

void MainWindow::on_stop_clicked()
{
    glRubik->_qThreadMvtFace->stopThread();
    log->updatePlayer();
}

void MainWindow::on_next_clicked()
{
    log->_autoPlayTo = SINGLE_MOVE;
    log->next();
}

void MainWindow::on_last_clicked()
{
    unsigned char cube[CUBE_SIZE];
    if (!log->End(cube))
        return;
    Rubik1->fill_Cube(cube);
    glRubik->rubik_cube->mapping_Textures(cube);

    ui->last->setEnabled(false);
}










/***************
 * SPEED
 * **************/
double MainWindow::changeSpeed(int )
{
    _speed = (double)(_speed_slider->value())/100.;
    return _speed;
}

void MainWindow::on_speed_valueChanged(int value)
{
    changeSpeed(value);
}
