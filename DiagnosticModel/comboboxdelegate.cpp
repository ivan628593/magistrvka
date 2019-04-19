#include "comboboxdelegate.h"

#include <QComboBox>
#include <QWidget>
#include <QModelIndex>
#include <QApplication>
#include <QString>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QDebug>
#include <iostream>

ComboBoxDelegate::ComboBoxDelegate(int id_check, QObject *parent)
:QItemDelegate(parent)
{
   globalCheck = id_check;
   resModel = new QStandardItemModel();

   QSqlQuery query;
   query.exec(QString("SELECT id_check_result,result_number FROM checking_result WHERE id_check = %1").arg(globalCheck));
   while (query.next()){

       QString state_name = query.value(1).toString();
       int id_state = query.value(0).toInt();

       QPair<int, QString> *pair = new QPair<int, QString>(id_state,state_name);
       resultNum.insert(pair);
   }

   QStandardItem *item_row = new QStandardItem();
        item_row->setData("-",Qt::DisplayRole);
        resModel->appendRow(item_row);

   QSet< QPair< int, QString >* >::iterator i;
   for (i = resultNum.begin(); i != resultNum.end(); ++i)
   {
       QStandardItem *item = new QStandardItem();
       item->setData((*i)->first,Qt::UserRole);
       item->setData((*i)->second,Qt::DisplayRole);
       resModel->appendRow(item);
   }
    resModel->sort(0);
}


QWidget *ComboBoxDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem & /*option*/ , const QModelIndex & /*index*/ ) const
{
    QComboBox* editor = new QComboBox(parent);
    editor->setModel(resModel);
    connect(editor,SIGNAL(currentIndexChanged(int)),this,SLOT(saveCurrentIndex(int)));
    return editor;
}

void ComboBoxDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
    QComboBox *comboBox = static_cast<QComboBox*>(editor);
    int value = index.model()->data(index, Qt::EditRole).toUInt();
    comboBox->setCurrentIndex(value);

}

void ComboBoxDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
    QComboBox *comboBox = static_cast<QComboBox*>(editor);
    model->setData(index, comboBox->currentIndex(), Qt::EditRole);
}

void ComboBoxDelegate::updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &/* index */) const
{
    editor->setGeometry(option.rect);
}

void ComboBoxDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    QStyleOptionViewItemV4 myOption = option;
    QApplication::style()->drawControl(QStyle::CE_ItemViewItem, &myOption, painter);
}

void ComboBoxDelegate::saveCurrentIndex(int index)
{
    currentIndex = index;
    //QAbstractItemModel *m = (qobject_cast<QComboBox *>(sender()))->model();
   // emit mySuperPuperSignal(m->data(m->index(index, 1)).toString());
    QComboBox *comboBox = qobject_cast<QComboBox *> (sender());
    emit commitUserData(comboBox);

}
