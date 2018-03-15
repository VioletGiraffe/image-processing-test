#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "imageviewwidget.h"
#include "qimageadapter.hpp"

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);

	auto imageViewer = new ImageViewWidget(this);
	setCentralWidget(imageViewer);

	imageViewer->setImage(std::make_unique<QImageAdapter>(QImage(R"(C:\Users\Alex\Pictures\Wallpapers\Pictures\Art\underwater_city_by_nkabuto-d473jux.jpg)")));
}

MainWindow::~MainWindow()
{
	delete ui;
}
