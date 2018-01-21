#ifndef VERIFYWINDOW_H
#define VERIFYWINDOW_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>

namespace Ui {
class VerifyWindow;
}

class VerifyWindow : public QMainWindow
{
    Q_OBJECT
    const int WIDTH = 600;
    const int HEIGHT = 160;
public:
    explicit VerifyWindow(QWidget *parent = 0);
    QString* hash = nullptr;
    QString* blockchain = nullptr;
    ~VerifyWindow();

public slots:
    void updateButton(QString text);
    void updateBlockchain(QString text);

signals:    
    void verify();
};

#endif // VERIFYWINDOW_H
