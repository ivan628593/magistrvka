#include "mymdiarea.h"
 
myQMdiArea::myQMdiArea(QImage image,QWidget *parent) 
  : QMdiArea(parent)
{
  img = image;
}

myQMdiArea::~myQMdiArea()
{

}
 
void myQMdiArea::paintEvent(QPaintEvent *paintEvent)
{
	QPainter painter(viewport());
	QLinearGradient grad(0, 0, geometry().width(),geometry().height());
	grad.setColorAt(0, QColor::fromRgb(0,0,0));
	grad.setColorAt(1, QColor::fromRgb(0,0,0));
	grad.setColorAt(0, QColor::fromRgb(0,0,0));
	grad.setColorAt(1, QColor::fromRgb(0,0,0));
	QBrush brush(grad);
	painter.fillRect(paintEvent->rect(), brush);

	QImage new_img = img.scaled(geometry().width(),geometry().height(),Qt::KeepAspectRatio);
	

	int x = (geometry().width() - new_img.width() ) /2;
	int y = (geometry().height() - new_img.height() ) /2;

	painter.drawImage(x,y,new_img);  // draw the image in center, or whatever location you want
}