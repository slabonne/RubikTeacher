#include "helpclass.h"
#include "constants.h"
#include "mainwindow.h"
#include "variables.h"

#include <QPushButton>

HelpClass::HelpClass()
{
    setMinimumSize(250,100);
    setWindowTitle("A propos...");

    QVBoxLayout * vert_layout1 = new QVBoxLayout;
    QLabel * aLabel = new QLabel("<strong style=""color:red"">"+___APP_NAME___+"</strong>");
    aLabel->setAlignment(Qt::AlignHCenter);
    QFont aFont;
    aFont.setBold(true);
    aFont.setPixelSize(18);
    aLabel->setFont(aFont);
    vert_layout1->addWidget(aLabel);

    QLabel * aLabel3 = new QLabel("v"+___VERSION___);
    aLabel3->setAlignment(Qt::AlignHCenter);
    vert_layout1->addWidget(aLabel3);

    QPushButton* checkNewVersion = new QPushButton(tr("Vérifier les mises à jour"), this);
    vert_layout1->addWidget(checkNewVersion);
    connect(checkNewVersion, SIGNAL(clicked()), MainWindow::getInstance(), SLOT(checkLatestVersion()));

    QLabel * aLabel2 = new QLabel(QString("<em>par %1</em>").arg(___AUTHOR___));
    aLabel2->setAlignment(Qt::AlignHCenter);
    vert_layout1->addWidget(aLabel2);

    QLabel * aLabel4 = new QLabel(QString("<a href=""%1"">%1</a>").arg(___WEBPAGE_URL___));
    aLabel4->setAlignment(Qt::AlignHCenter);
    aLabel4->setOpenExternalLinks(true);
    vert_layout1->addWidget(aLabel4);

     setLayout(vert_layout1);
     setModal(true);
}

