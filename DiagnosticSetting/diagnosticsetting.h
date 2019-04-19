#ifndef DIAGNOSTICSETTING_H
#define DIAGNOSTICSETTING_H

#include <QtWidgets>
#include <QMenu>
#include <QSqlRelationalTableModel>
#include "config_diagnosticsetting.h"
#include "noeditabledelegate.h"
#include "../DiagnosticModel/diagnosticmodel.h"


class DBAccess;
class DBRepSettings;
class DiagnosticModel;

namespace Ui
{
    class DiagnosticSetting_form;
};

class __EXPORT_DIAGNOSTICSETTING DiagnosticSetting: public QWidget
{
    Q_OBJECT

public:
	
    DiagnosticSetting(QWidget *parent = 0);
    ~DiagnosticSetting();

     int        globalIdSys = 0;
     int        id_subSystemGlob = 0;
     int        id_checkDel = 0;
     int        id_resDel = 0;
     int        globalcheck = 0;

     bool       checkDelegate = false;

signals:
     void       commit_Data(QWidget *);

public slots:

     void       add_new_system(int, bool);
     void       customMenuTree(const QPoint &);
     void       customMenuTableCheck(const QPoint &);
     void       delete_system();
     void       editName_system();
     void       delete_checking();
     void       item_clicked ( const QModelIndex &);

     void       add_param_row();
     void       del_param_row();
     void       reshenie();

private:

     DiagnosticModel        *modelDB;
     DBRepSettings          *settings;
     DBAccess               *dbaccess;

     void       init_treeview();
     void       show_param(int, QString);
     void       show_tableModel(int,QString);
     void       show_cheking(int);

     QDialog         *add_system;
     QLabel          *path_lab;
     QLabel          *blok_name;
     QLineEdit       *blok_filepath_edit;
     QLineEdit       *blok_name_edit;
     QPushButton     *ok_button;
     QPushButton     *cancel_button;

     QStandardItemModel     *model_;
     QStandardItemModel     *param_model;
     QStandardItemModel     *subSystem_model;
     QStandardItemModel     *model_combo;
     QStandardItem          *parentItem;

     QSqlRelationalTableModel *modelMain;
     QSqlRelationalTableModel *modelTable;
     QSqlRelationalTableModel *modelRes;

     QStandardItem * set_child_item(QString item_text,QString user_data,QStandardItem *parent_item,int row,QString icon_path,QFont font);
     QStandardItem * set_child_item(QString item_text,QString user_data,QStandardItem *parent_item,int row);

     void       fill_combobox_Param(QComboBox *box, int id_system);
     void       fill_combobox_Subsystem(QComboBox *box, int id_system);
     void       child_system_objects(QStandardItem *parent_item,int id_parent_system);

     Ui::DiagnosticSetting_form *UI;

};

#endif
