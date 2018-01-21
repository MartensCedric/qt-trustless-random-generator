#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    const int WIDTH = 750;
    const int HEIGHT = 600;
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void import();
    void generate();
    void browse() const;
    void copyHash() const;
    void verifyHash() const;
    void updateVerify() const;
private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
