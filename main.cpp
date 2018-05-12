#include "mainwindow.h"
#include <QApplication>
#include "logindlg.h"
#include "aboutdialog.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    //w.show();

    LoginDLG l;
    l.show();

    return a.exec();
}
