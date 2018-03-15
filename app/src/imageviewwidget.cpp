#include "imageviewwidget.h"

#include <QPainter>

void ImageViewWidget::setImage(const QImage& img)
{
	_img = img;
}

void ImageViewWidget::paintEvent(QPaintEvent* /*e*/)
{
	QPainter p(this);
	p.drawImage(0, 0, _img);
}
