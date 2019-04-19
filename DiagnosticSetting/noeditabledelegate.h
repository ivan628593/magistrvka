#ifndef NOEDITABLEDELEGATE_H
#define NOEDITABLEDELEGATE_H


#include <QStandardItemModel>
#include <QStyledItemDelegate>

class NoEditableDelegate : public QStyledItemDelegate
{
Q_OBJECT

public:
  NoEditableDelegate(QObject *parent = 0);

  QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const;


private:

};
#endif
