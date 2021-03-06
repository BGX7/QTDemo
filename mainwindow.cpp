#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
QMainWindow(parent),
ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    camera=new QCamera(this);
    viewfinder=new QCameraViewfinder(this);
    imageCapture=new QCameraImageCapture(camera);

    ui->ImageView->addWidget(viewfinder);
    ui->ImageCapture->setScaledContents(true);


    camera->setViewfinder(viewfinder);
    camera->start();

    connect(imageCapture, SIGNAL(imageCapture(int,QImage)), this, SLOT(displayImage(int,QImage)));

    connect(ui->buttonCapture, SIGNAL(clicked()), this, SLOT(captureImage()));
    connect(ui->buttonSave, SIGNAL(clicked()), this, SLOT(saveImage()));
    connect(ui->buttonExit, SIGNAL(clicked()), qApp, SLOT(quit()));

    connect(ui->actionContact_US,SIGNAL(triggered()),this,SLOT(triggerContact()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::captureImage()
{
    ui->statusBar->showMessage(tr("capturing..."), 1000);
    imageCapture->capture();
}

void MainWindow::displayImage(int , QImage image)
{
    ui->ImageCapture->setPixmap(QPixmap::fromImage(image));

    ui->statusBar->showMessage(tr("capture OK!"), 5000);
}

void MainWindow::saveImage()
{
    QString fileName=QFileDialog::getSaveFileName(this, tr("save file"), QDir::homePath(), tr("jpegfile(*.jpg)"));
    if(fileName.isEmpty()) {
    ui->statusBar->showMessage(tr("save cancel"), 5000);
    return;
}

const QPixmap* pixmap=ui->ImageCapture->pixmap();
    if(pixmap) {
        pixmap->save(fileName);
        ui->statusBar->showMessage(tr("save OK"), 5000);
    }
}
void MainWindow::triggerContact(){
}
