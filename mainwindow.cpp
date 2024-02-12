#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "gearwidget.h"
#include "ui_gearwidget.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
