#ifndef MYQMIDIAREA_H
#define MYQMIDIAREA_H
 
#include <QtWidgets>
#include <QMdiArea>
 
class myQMdiArea : public QMdiArea
{
  Q_OBJECT
  public:
    myQMdiArea(QImage image,QWidget *parent = 0);
	~myQMdiArea();

    QImage img;
  protected:
    void paintEvent(QPaintEvent *);


};
 
#endif // MYQMIDIAREA_H
