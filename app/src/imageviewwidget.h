#pragma once

#include <QWidget>

#include <memory>

class QImageAdapter;

class ImageViewWidget : public QWidget
{
public:
	using QWidget::QWidget;

	void setImage(std::unique_ptr<QImageAdapter>&& adapter);

protected:
	void paintEvent(QPaintEvent* e) override;

private:
	std::unique_ptr<QImageAdapter> _img;
};

