#ifndef VERIFYWINDOW_H
#define VERIFYWINDOW_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <qcombobox.h>
#include <qlineedit.h>
#include <qpushbutton.h>

namespace Ui {
class VerifyWindow;
}

class VerifyWindow : public QMainWindow
{
    Q_OBJECT
    const int WIDTH = 600;
    const int HEIGHT = 160;
    QPushButton* btnVerify = nullptr;
    QLineEdit* leHash = nullptr;
    QComboBox* cboBlockchain = nullptr;
public:
    explicit VerifyWindow(QWidget *parent = 0);
    QString* hash = nullptr;
    QString* blockchain = nullptr;
    void showClear();
    ~VerifyWindow();

public slots:
    void updateButton(QString text);
    void updateBlockchain(QString text);

signals:    
    void verify();
};

#endif // VERIFYWINDOW_H
