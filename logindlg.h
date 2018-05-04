#ifndef LOGINDLG_H
#define LOGINDLG_H

#include <QDialog>
#include "mainwindow.h"

namespace Ui {
class LoginDLG;

}

class LoginDLG : public QDialog
{
    Q_OBJECT

public:
    explicit LoginDLG(QWidget *parent = 0);
    ~LoginDLG();

private slots:
    void on_pushButton_Login_clicked();

private:
    Ui::LoginDLG *ui;
    MainWindow *mainWindow;
};

#endif // LOGINDLG_H
