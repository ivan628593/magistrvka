#ifndef COMBOBOXDELEGATE_H
#define COMBOBOXDELEGATE_H

#include <string>
#include <vector>
#include <QList>
#include <QStandardItemModel>
#include <QItemDelegate>

class QModelIndex;
class QWidget;
class QVariant;

class ComboBoxDelegate : public QItemDelegate
{
Q_OBJECT

public:
  ComboBoxDelegate(int id_check, QObject *parent = 0);
  int globalCheck = 0;

  QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const;
  void setEditorData(QWidget *editor, const QModelIndex &index) const;
  void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const;
  void updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const;
  void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const;

  QSet < QPair<int,QString>*> resultNum;
  QStandardItemModel      *resModel;

public slots:
  void saveCurrentIndex(int index);

signals:
    void commitUserData(QWidget *);

private:
  int currentIndex;
  std::vector<std::string> Items;

};
#endif
