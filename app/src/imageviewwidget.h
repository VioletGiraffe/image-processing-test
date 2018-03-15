#pragma once

#include <QImage>
#include <QWidget>

class ImageViewWidget : public QWidget
{
public:
	using QWidget::QWidget;

	void setImage(const QImage& img);

protected:
	void paintEvent(QPaintEvent* e) override;

private:
	QImage _img;
};

