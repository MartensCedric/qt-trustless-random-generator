#ifndef VERIFYWINDOW_H
#define VERIFYWINDOW_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>

class VerifyWindow : public QMainWindow
{
    Q_OBJECT
    const int WIDTH = 400;
    const int HEIGHT = 300;    
public:
    explicit VerifyWindow(QWidget *parent = nullptr);        
    ~VerifyWindow();

public slots:
    void updateButton(QString text) const;

signals:    
    void verify();

public slots:
};

#endif // VERIFYWINDOW_H
