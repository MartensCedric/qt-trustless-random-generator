#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFileDialog>
#include <QListWidget>
#include <QPushButton>
#include <qcombobox.h>
#include <qdesktopwidget.h>
#include <qgridlayout.h>
#include <qlabel.h>
#include <string>
#include <fstream>
#include <streambuf>

QListWidget* dataList = nullptr;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    resize(WIDTH, HEIGHT);
    this->setWindowTitle("Trustless Random Generator");
    QDesktopWidget* desktop = QApplication::desktop();
    this->move(desktop->width()/2 - WIDTH/2, desktop->height()/2 - HEIGHT/2);

    QMenu* menuFile = menuBar()->addMenu("&File");
    QAction* actionQuit = new QAction("&Quit");
    QAction* actionImportFile = new QAction("&Import .csv");

    menuFile->addAction(actionImportFile);
    menuFile->addAction(actionQuit);

    connect(actionImportFile, SIGNAL(triggered()), this, SLOT(import()));
    connect(actionQuit, SIGNAL(triggered()), this, SLOT(close()));

    QGridLayout* gridLayout = new QGridLayout(centralWidget());
    const QRect layoutGeometry(0, 0, WIDTH, HEIGHT);
    gridLayout->setGeometry(layoutGeometry);

    QLabel* lblBlockchains = new QLabel(this);
    lblBlockchains->setText("Blockchains : ");

    QComboBox* cboBlockchains = new QComboBox(this);
    QStringList qBlockchainsList = (QStringList() << "BTC" << "ETH" << "LTC");
    cboBlockchains->addItems(qBlockchainsList);

    gridLayout->addWidget(lblBlockchains, 0, 0, 1, 1);
    gridLayout->addWidget(cboBlockchains, 0, 1, 1, 1);

    dataList = new QListWidget(this);
    gridLayout->addWidget(dataList, 1, 0, 4, 4);

    QPushButton* btnGenerate = new QPushButton(this);
    btnGenerate->setText("Generate");
    gridLayout->addWidget(btnGenerate, 5, 0, 1, 1);
}

void MainWindow::import()
{
    dataList->clear();
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"),".",tr("CSV Files (*.csv)"));
    std::ifstream f(fileName.toStdString());
    std::string data((std::istreambuf_iterator<char>(f)),
                     std::istreambuf_iterator<char>());
    QString qData(data.c_str());
    QRegExp rx("(\\,)");
    dataList->addItems(qData.split(rx));
}

MainWindow::~MainWindow()
{
    delete ui;
}
