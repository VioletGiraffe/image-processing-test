#include "imageviewwidget.h"
#include "qimageadapter.hpp"
#include "resize/cimageresizer.h"

#include <QPainter>

#include <utility>

void ImageViewWidget::setImage(std::unique_ptr<QImageAdapter> &&adapter)
{
	_img = std::move(adapter);
}

void ImageViewWidget::paintEvent(QPaintEvent* /*e*/)
{
	QPainter p(this);

	const auto resized = CImageResizer::bicubicInterpolation(*_img, (uint32_t)width(), (uint32_t)height());
	p.drawImage(0, 0, dynamic_cast<QImageAdapter*>(resized.get())->qImg());
}
