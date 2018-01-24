#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "verifywindow.h"

#include <QMainWindow>
#include <qcombobox.h>
#include <qlistwidget.h>
#include <qpushbutton.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    const int WIDTH = 750;
    const int HEIGHT = 600;
    QListWidget* dataList = nullptr;
    QPushButton* btnGenerate = nullptr;
    QComboBox* cboBlockchains = nullptr;
    QLineEdit* leBlockchain = nullptr;
    QLineEdit* leHash = nullptr;
    QLineEdit* leTimestamp = nullptr;
    QLineEdit* leResult = nullptr;
    QPushButton* btnBrowse = nullptr;
    QPushButton* btnCopy = nullptr;
    QAction* actionVerifyHash = nullptr;
    VerifyWindow* verifyWindow = nullptr;
public:
    explicit MainWindow(QWidget *parent = 0);
    void generateResult(std::string& hash, std::string& timestamp, QString* blockchainUsed);
    ~MainWindow();

public slots:
    void import();
    void generate();
    void browse() const;
    void copyHash() const;
    void verifyHash() const;
    void updateVerify();
private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
