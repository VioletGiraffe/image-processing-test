#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "imageviewwidget.h"

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);

	auto imageViewer = new ImageViewWidget(this);
	setCentralWidget(imageViewer);

	imageViewer->setImage(QImage(R"(D:\Downloads\[gotowall.com]20120416_143658_2222.jpg)"));
}

MainWindow::~MainWindow()
{
	delete ui;
}
