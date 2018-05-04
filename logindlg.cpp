#include "logindlg.h"
#include "ui_logindlg.h"
#include <QMessageBox>
#include <QtSql/QSqlDatabase>
#include <QDebug>
#include <QtSql/QSqlQuery>

QString getArg(int args){
    QString arg;
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setDatabaseName("account");
    db.setUserName("root");
    db.setPassword("User1234");
    if(db.open()){
        qDebug()<<"Success!";
        qDebug()<<db.driverName();
        QSqlQuery query("Select * from account");
        while(query.next()){
            arg = query.value(args).toString();
            qDebug()<<arg;

        }
    }
    return arg;
}

LoginDLG::LoginDLG(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginDLG)
{
    ui->setupUi(this);

}

LoginDLG::~LoginDLG()
{
    delete ui;
}


void LoginDLG::on_pushButton_Login_clicked()
{
    QString account = getArg(0);
    QString pwd = getArg(1);
    QString username = ui->lineEdit_username->text();
    QString password = ui->lineEdit_Password->text();

    if(username == account && password == pwd) {
        this->close();
        mainWindow = new MainWindow(this);
        mainWindow->show();

    }
    else {
        QMessageBox::warning(this,"Login","Username and password is wrong");
    }
}

