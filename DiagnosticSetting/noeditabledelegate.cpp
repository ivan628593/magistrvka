#include "noeditabledelegate.h"

#include <QWidget>
#include <QModelIndex>
#include <QApplication>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QDebug>
#include <iostream>

NoEditableDelegate::NoEditableDelegate(QObject *parent)
:QStyledItemDelegate(parent)
{

}


QWidget *NoEditableDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &, const QModelIndex &) const
{
    return 0;
}

