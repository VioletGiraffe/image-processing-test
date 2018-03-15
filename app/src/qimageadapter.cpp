#include "qimageadapter.hpp"
#include "assert/advanced_assert.h"

QImageAdapter::QImageAdapter(const QImage &qImage) : _img(qImage)
{
}

std::unique_ptr<ImageAdapter> QImageAdapter::create(const uint32_t w, const uint32_t h, const uint8_t nChannels, const uint8_t bytesPerChannel) const
{
	assert_r(bytesPerChannel == 1);
	return std::make_unique<QImageAdapter>(QImage((int)w, (int)h, nChannels == 4 ? QImage::Format_RGB32 : QImage::Format_RGB888));
}

std::unique_ptr<ImageAdapter> QImageAdapter::clone() const
{
	return std::make_unique<QImageAdapter>(_img);
}

uint32_t QImageAdapter::width() const
{
	return (uint32_t)_img.width();
}

uint32_t QImageAdapter::height() const
{
	return (uint32_t)_img.height();
}

uint8_t QImageAdapter::numChannels() const
{
	return static_cast<uint8_t>(_img.depth() / 8);
}

uint8_t QImageAdapter::bytesPerChannel() const
{
	return 1;
}

const void *QImageAdapter::scanLine(const uint32_t row) const
{
	return _img.constScanLine((int)row);
}

void *QImageAdapter::scanLine(const uint32_t row)
{
	return _img.scanLine((int)row);
}

const QImage &QImageAdapter::qImg() const
{
	return _img;
}
