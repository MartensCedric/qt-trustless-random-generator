#ifndef VERIFYWINDOW_H
#define VERIFYWINDOW_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>

class VerifyWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit VerifyWindow(QWidget *parent = nullptr);

signals:

public slots:
};

#endif // VERIFYWINDOW_H