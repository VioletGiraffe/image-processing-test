#pragma once

#include "resize/imageadapter.hpp"

#include <QImage>

class QImageAdapter : public ImageAdapter
{
public:
	explicit QImageAdapter(const QImage& qImage);

	std::unique_ptr<ImageAdapter> create(const uint32_t w, const uint32_t h, const uint8_t nChannels, const uint8_t bytesPerChannel) const override;
	std::unique_ptr<ImageAdapter> clone() const override;

	uint32_t width() const override;
	uint32_t height() const override;
	uint8_t numChannels() const override;
	uint8_t bytesPerChannel() const override;
	const void* scanLine(const uint32_t row) const override;
	void* scanLine(const uint32_t row) override;

	const QImage& qImg() const;

private:
	QImage _img;
};
