#include "verifywindow.h"

#include <QFormLayout>
#include <QLabel>
#include <QLineEdit>
#include <iostream>
#include <qpushbutton.h>

QPushButton* btnVerify = nullptr;
VerifyWindow::VerifyWindow(QWidget *parent) : QMainWindow(parent)
{
    resize(WIDTH, HEIGHT);
    setWindowTitle(tr("Verify results"));

    QLabel* lblHash = new QLabel(this);
    lblHash->setText(tr("Hash : "));
    lblHash->move(20, 20);

    QLineEdit* leHash = new QLineEdit(this);
    leHash->move(50, 20);
    leHash->resize(WIDTH - lblHash->size().width(), leHash->size().height());

    connect(leHash, SIGNAL(textChanged(QString)), this, SLOT(updateButton(QString)));

    btnVerify = new QPushButton(this);
    btnVerify->setText(tr("Verify results"));
    btnVerify->move(20, 40);
    btnVerify->resize(WIDTH - 40, btnVerify->size().height());
    btnVerify->setEnabled(false);
    connect(btnVerify, SIGNAL(clicked()), this, SIGNAL(verify()));
}
void VerifyWindow::updateButton(QString text) const
{
    btnVerify->setEnabled(text.length() > 0);
}

VerifyWindow::~VerifyWindow()
{

}
