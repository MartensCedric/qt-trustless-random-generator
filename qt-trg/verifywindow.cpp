#include "verifywindow.h"
#include <QComboBox>
#include <QFormLayout>
#include <QLabel>
#include <QLineEdit>
#include <iostream>
#include <qpushbutton.h>
#include <QStatusBar>

QPushButton* btnVerify = nullptr;

VerifyWindow::VerifyWindow(QWidget *parent) :
    QMainWindow(parent)
{
    resize(WIDTH, HEIGHT);
    //this->layout()->setSizeConstraint(QLayout::SetFixedSize);
    setWindowTitle(tr("Verify results"));

    QLabel* lblBlockchain = new QLabel(this);
    lblBlockchain->setText(tr("Blockchain : "));
    lblBlockchain->move(20, 20);

    QComboBox* cboBlockchain = new QComboBox(this);
    cboBlockchain->addItems(QStringList() << "BTC" << "ETH" << "LTC");
    cboBlockchain->move(100, 20);
    connect(cboBlockchain, SIGNAL(currentIndexChanged(QString)), this, SLOT(updateBlockchain(QString)));
    blockchain = new QString("BTC");

    QLabel* lblHash = new QLabel(this);
    lblHash->setText(tr("Hash : "));
    lblHash->move(20, 60);

    QLineEdit* leHash = new QLineEdit(this);
    leHash->move(70, 60);
    leHash->resize(WIDTH - lblHash->size().width()/2 - 40, leHash->size().height());

    connect(leHash, SIGNAL(textChanged(QString)), this, SLOT(updateButton(QString)));

    btnVerify = new QPushButton(this);
    btnVerify->setText(tr("Verify results"));
    btnVerify->move(20, 100);
    btnVerify->resize(WIDTH - 40, btnVerify->size().height());
    btnVerify->setEnabled(false);

    connect(btnVerify, SIGNAL(clicked()), this, SIGNAL(verify()));
}
void VerifyWindow::updateButton(QString text)
{
    btnVerify->setEnabled(text.length() > 0);

    delete hash;
    hash = new QString(text);
}

void VerifyWindow::updateBlockchain(QString text)
{
    delete blockchain;
    blockchain = new QString(text);
}

VerifyWindow::~VerifyWindow()
{
    delete btnVerify;
    delete hash;
    delete blockchain;
}
