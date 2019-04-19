#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QPushButton>
#include <QSqlRelationalDelegate>
#include <QSqlRelationalTableModel>
#include "diagnosticsetting.h"
#include "noeditabledelegate.h"
#include "comboboxdelegate.h"
#include "dbaccess.h"
#include "dbrepsettings.h"
#include "ui_diagnosticsetting_form.h"


DiagnosticSetting::DiagnosticSetting(QWidget *parent)
    : QWidget(parent),
      UI (new Ui::DiagnosticSetting_form)
{
    UI->setupUi(this);

    bool con_flag;
    dbaccess = new DBAccess;
    settings = new DBRepSettings();
    modelDB = new DiagnosticModel();
    con_flag = dbaccess->createConnection("QSQLITE", settings->getDbName());
    UI->systemtreeView->setContextMenuPolicy(Qt::CustomContextMenu);
    UI->systemtreeView->setAnimated(true);
    QPushButton *button=new QPushButton("Принять решение");
    UI->gridLayout_21->addWidget(button);

    param_model = new QStandardItemModel();
      subSystem_model = new QStandardItemModel();
    model_combo = new QStandardItemModel();
    modelMain = new QSqlRelationalTableModel(this);

    UI->tableViewParam->setModel(param_model);
    QStringList header_param_list, header_state_list;
    header_param_list <<"Param_name"<<"Param_description";
    param_model->setHorizontalHeaderLabels(header_param_list);
    UI->tableViewParam->horizontalHeader()->setSectionResizeMode(1,QHeaderView::Stretch);

    //=============================== CONNECT ===================================================================
    connect(UI->systemtreeView,SIGNAL(customContextMenuRequested(const QPoint &)),this,SLOT(customMenuTree(const QPoint &)));
    connect(UI->systemtreeView,SIGNAL(doubleClicked(const QModelIndex &)),this,SLOT(item_clicked( const QModelIndex & )));
    //   connect(UI->tabWidget,SIGNAL(tabBarClicked(int)),this,SLOT(start_checking(int)));
    connect(UI->toolButtonAddParam,SIGNAL(clicked()),this,SLOT(add_param_row()));
    connect(UI->toolButtonDelParam,SIGNAL(clicked()),this,SLOT(del_param_row()));
    connect(button,SIGNAL(clicked()),this,SLOT(reshenie()));

    //===========================================================================================================

    QString mess;
    if(con_flag == false){
        mess = "Нет соединения с БД";
    }
    else if(con_flag == true){
        init_treeview();
    }
}

DiagnosticSetting::~DiagnosticSetting(){
    delete UI;
}

// ======================== инициализация дерева систем и подсистем ======================================

void DiagnosticSetting::init_treeview()
{
    checkDelegate = false;
    QFont font;
    font.setBold(true);
    QSqlQuery query;
    query.exec(QString("SELECT id_system, system_name FROM system where id_parent = 0"));
    model_ = new QStandardItemModel(this);
    parentItem = model_->invisibleRootItem();
    int id_system = 0;
    while (query.next()){
        QSqlQuery query_count; // ********
        query_count.exec(QString("select count(system_name) from system where id_parent = %1").arg(query.value(0).toInt()));

        while (query_count.next()){
            int g = query_count.value(0).toInt(); //********
            int id_system = query.value(0).toInt();
            QString system_name = query.value(1).toString();
            QStandardItem *item = new QStandardItem(query.value(1).toString());
            QString data_region="system_" + QString::number(id_system) + "_" + system_name;
            item->setData(data_region,Qt::UserRole);
            model_->appendRow(item);
            child_system_objects(item,id_system);
        }
    }
    query.clear();

    model_->setHeaderData(0, Qt::Horizontal,"Наименование системы");
    UI->systemtreeView->sortByColumn(0,Qt::AscendingOrder);
    QStandardItem *item = new QStandardItem(QIcon(":/icons/up.png"),"Добавить систему");
    item->setFont(font);
    item->setData(QString("psystem_%1").arg(id_system),Qt::UserRole);
    model_->appendRow(item);
    UI->systemtreeView->setModel(model_);
}

void DiagnosticSetting::child_system_objects(QStandardItem *parent_item,int id_parent_system)
{
    QSqlQuery query;
    int row = 0;
    query.exec(QString("SELECT id_system, system_name, id_parent FROM system WHERE id_parent = %1 ORDER BY id_system").arg(id_parent_system));

    if (query.size() == 0){

    }
    else{
        while (query.next()){
            QSqlQuery query_count;
            query_count.exec(QString("select count(system_name) from system where id_parent = %1 ").arg(query.value(0).toInt()));
            while (query_count.next()) {
                int g = query_count.value(0).toInt();
                int id_object = query.value(0).toInt();
                QString system_name = query.value(1).toString();
                if (id_object == id_parent_system)continue;
                child_system_objects(set_child_item(query.value(1).toString(),
                                                    "sys_" + QString::number(id_object) + "_" + QString::number(id_parent_system) + "_" + system_name,
                                                    parent_item, row),id_object);
                row++;
            }
        }
    }
    QFont font;
    font.setBold(true);
    set_child_item("Добавить компоненты системы",QString("psys_%1").arg(id_parent_system),parent_item,row,":/icons/up.png" ,font);  //preg
    query.clear();
}

QStandardItem * DiagnosticSetting::set_child_item(QString item_text,QString user_data,QStandardItem *parent_item,int row)	{
    QStandardItem *item = new QStandardItem(item_text.toStdString().c_str());
    item->setData(user_data,Qt::UserRole);
    parent_item->setChild(row,item);
    return item;
}

QStandardItem * DiagnosticSetting::set_child_item(QString item_text,QString user_data,QStandardItem *parent_item,int row,QString icon_path,QFont font)	{
    QStandardItem *item = new QStandardItem(QIcon(icon_path),item_text.toStdString().c_str());
    item->setFont(font);
    item->setData(user_data,Qt::UserRole);
    parent_item->setChild(row,item);
    return item;
}

//=================== клик по системе =======================================================
void DiagnosticSetting::item_clicked(const QModelIndex &index){

    QFont font;
    font.setBold(true);
    QVariant id=index.data(Qt::UserRole);
    if (id.type() == QVariant::String)
    {
        QString user_data=id.toString();
        QStringList list=user_data.split("_");
        if(list.value(0)=="psystem"){
            add_new_system(list.value(1).toInt(),true);
        }else if(list.value(0)=="psys"){
            add_new_system(list.value(1).toInt(),false);
        }else if(list.value(0)=="system"){
            param_model = modelDB->getParamList(list.value(1).toInt());
            show_param(list.value(1).toInt(),list.value(2));
        }else if(list.value(0)=="sys"){
            param_model = modelDB->getParamList(list.value(1).toInt());
            show_param(list.value(1).toInt(),list.value(3));
        }
    }
}
//================================ показать параметры выбранной системы =====================
void DiagnosticSetting::show_param(int id_system,QString name){

    globalIdSys = id_system;
    param_model->clear();
    param_model = modelDB->getParamList(globalIdSys);
    UI->label_nameSystem->setText(name);
    const QString tableName="parametres";
    modelMain->setTable(tableName);
    modelMain->setFilter(QString("id_system = %1").arg(id_system));
    modelMain->select();
    modelMain->setEditStrategy(QSqlTableModel::OnFieldChange);

    UI->tableViewParam->setModel(modelMain);
    UI->tableViewParam->hideColumn(0);
    UI->tableViewParam->hideColumn(1);
    UI->tableViewParam->horizontalHeader()->setSectionResizeMode(3,QHeaderView::Stretch);
    subSystem_model = modelDB->getSubSystemList(id_system);
    show_cheking(id_system);
}
//================================ показать проверки для системы =====================
void DiagnosticSetting::show_cheking(int id_system){


}

//================================ добавление параметров ====================================
void DiagnosticSetting::add_param_row(){

    if(globalIdSys == 0){
        QMessageBox::StandardButton ret;
        ret = QMessageBox::critical (this,"Ошибка",("Необходимо выбрать систему"),QMessageBox::Ok );
    }

    int row = modelMain->rowCount();
    QSqlQuery query;
    int id_par = 1;
    QString nameParam = "отсутствует";
    if (row ==0){
        query.prepare("INSERT INTO parametres (id_parametres,param_name) VALUES (?,?);");
        query.addBindValue(id_par);
        query.addBindValue(nameParam);
    }

    if(!query.exec()){}

    modelMain->insertRow(modelMain->rowCount());
    modelMain->setData(modelMain->index(row,1),globalIdSys);
    UI->tableViewParam->selectRow(row);
    modelMain->submitAll();
}

//================================ удаление параметров ====================================
void DiagnosticSetting::del_param_row(){

    int row = UI->tableViewParam->currentIndex().row();
    modelMain->removeRow(row);
    modelMain->submitAll();
    show_param(globalIdSys, UI->label_nameSystem->text());
}
//===============================принятие решения========================================к
void DiagnosticSetting::reshenie()
{
    QSqlQuery query;
    query.exec(QString("SELECT Значение FROM parametres WHERE id_system=20 ORDER BY id_parametres DESC LIMIT 1"));
    query.next();
    float sys = query.value(0).toFloat();
    if(sys>0.98){
        //продолжаем работать


        UI->label_3->setText("Продолжаем работать");
        UI->label_3->setStyleSheet("QLabel {background-color : green; color : black}");
    }
    else if(sys<=0.98&&sys>=0.96){
        QSqlQuery query1;
        query1.exec(QString("select count(*) FROM system WHERE id_parent=23"));
        query1.next();
        int count_zip = query1.value(0).toInt();
        if(!count_zip){

            //нет зип остановить работу

            QSqlQuery query2;
            query2.exec(QString("SELECT * FROM system INNER JOIN parametres ON parametres.id_system=system.id_system  WHERE id_parent=21 OR id_parent=22 ORDER BY Значение limit 1"));
            query2.next();
            QString system_name = query2.value(1).toString();
            QString parent = query2.value(2).toString();

            QString str = "Необходимо заменить элемент "+system_name;
            if(parent=="21"){
                str = str+" из 1 стойки";
            }else if(parent=="22" ){
                str = str+" из 2 стойки";
            }
            str = str + "\nНет ЗИП!";
            UI->label_3->setText(str);
            UI->label_3->setStyleSheet("QLabel {background-color : red; color : black}");

        }else{

            //заменить на зип

            QSqlQuery query2;
            query2.exec(QString("SELECT * FROM system INNER JOIN parametres ON parametres.id_system=system.id_system  WHERE id_parent=21 OR id_parent=22 ORDER BY Значение limit 1"));
            query2.next();
            QString system_name = query2.value(1).toString();
            QString parent = query2.value(2).toString();

            QString str = "Заменить элемент "+system_name;
            if(parent=="21"){
                str = str+" из 1 стойки";
            }else if(parent=="22" ){
                str = str+" из 2 стойки";
            }

            UI->label_3->setText(str);
            UI->label_3->setStyleSheet("QLabel {background-color : yellow; color : black}");

        }

    }else{

        //остановить работу ремонт


        UI->label_3->setText("Остановить работу\nНеобходим ремонт");
        UI->label_3->setStyleSheet("QLabel {background-color : red; color : black}");
    }
    }


//================================ правый клик ==============================================
void DiagnosticSetting::customMenuTree(const QPoint &){
    QModelIndex index = UI->systemtreeView->currentIndex();
    if(!index.data(Qt::UserRole).toBool()) return;
    QVariant id = index.data(Qt::UserRole);
    if (id.type() == QVariant::String){
        QString user_data = id.toString();
        QStringList list= user_data.split("_");
        if(list.value(0)=="system" || list.value(0)=="sys") {
            QPushButton *popupButton = new QPushButton;
            QMenu *menu = new QMenu(this);

            QAction *act_edit=new QAction("Редактировать",this);
            act_edit->setIcon(QIcon(":/icons/edit.png"));
            connect(act_edit,SIGNAL(triggered()),this,SLOT(editName_system()));

            QAction *act_del=new QAction("Удалить систему",this);
            act_del->setIcon(QIcon(":/icons/close.png"));
            connect(act_del,SIGNAL(triggered()),this,SLOT(delete_system()));

            menu->addAction(act_edit);
            menu->addSeparator();
            menu->addAction(act_del);
            popupButton->setMenu(menu);
            menu->exec(QCursor::pos());
        }
    }
}

void DiagnosticSetting::customMenuTableCheck(const QPoint &){


}

//================================= Добавление - Удаление системы =================
void DiagnosticSetting::add_new_system(int id_sys, bool is_parent){

    int id_system = id_sys;
    bool id_parent = is_parent;
    add_system = new QDialog();
    add_system->setMinimumSize(500,200);
    add_system->setWindowTitle("Добавить систему");
    add_system->setWindowIcon(QIcon(":/icons/add.png"));

    blok_name = new QLabel("Наименование cистемы:");
    blok_name->setMinimumWidth(100);

    blok_filepath_edit = new QLineEdit();
    blok_name_edit = new QLineEdit();


    ok_button = new QPushButton("Ок");
    connect(ok_button,SIGNAL(clicked()),add_system,SLOT(accept()));
    cancel_button = new QPushButton("Отмена");
    connect(cancel_button,SIGNAL(clicked()),add_system,SLOT(close()));

    QHBoxLayout *buttons_layout = new QHBoxLayout();
    buttons_layout->addWidget(ok_button);
    buttons_layout->addWidget(cancel_button);

    QHBoxLayout *path_layout = new QHBoxLayout();
    path_layout->addWidget(blok_name_edit);

    QHBoxLayout *name_layout = new QHBoxLayout();
    name_layout->addWidget(blok_name);

    QGridLayout *mainLayout = new QGridLayout;
    mainLayout->setSizeConstraint(QLayout::SetFixedSize);
    mainLayout->addLayout(name_layout, 0, 0);
    mainLayout->addLayout(path_layout, 0, 1);
    mainLayout->addLayout(buttons_layout, 1, 1);

    add_system->setLayout(mainLayout);

    if(add_system->exec() == QDialog::Accepted)
    {
        QModelIndex index = UI->systemtreeView->currentIndex();
        QString id = index.data(Qt::UserRole).toString();
        QStringList list = id.split("_");
        int id_par = 0;
        QString f = blok_name_edit->text();

        if (id_parent == true){
            modelDB->addNewSystem(id_par,f);
        }
        else {
            modelDB->addNewSystem(id_system,f);
        }
        init_treeview();
    }
}

void DiagnosticSetting::delete_checking(){

    QMessageBox msgBox;
    msgBox.setWindowTitle("Предупреждуние");
    msgBox.setText("Вы действительно хотите удалить проверку?");
    msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    msgBox.setButtonText(QMessageBox::Yes, "Да");
    msgBox.setButtonText(QMessageBox::No, "Нет");
    switch (msgBox.exec()) {
    case QMessageBox::Yes:
        // yes was clicked
        break;
    case QMessageBox::No:
        return;
        break;
    default:
        return;
        break;
    }

    modelDB->deleteTableName("checking","id_check",id_checkDel);
    show_cheking(globalIdSys);
}

void DiagnosticSetting::delete_system(){

    QModelIndex index = UI->systemtreeView->currentIndex();
    if(!index.data(Qt::UserRole).toBool()) return;
    QString id_system = index.data(Qt::UserRole).toString();
    QStringList list = id_system.split("_");

    QMessageBox msgBox;
    msgBox.setWindowTitle("Предупреждуние");
    msgBox.setText("Вы действительно хотите удалить систему?");
    msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    msgBox.setButtonText(QMessageBox::Yes, "Да");
    msgBox.setButtonText(QMessageBox::No, "Нет");
    switch (msgBox.exec()) {
    case QMessageBox::Yes:
        // yes was clicked
        break;
    case QMessageBox::No:
        return;
        break;
    default:
        return;
        break;
    }

    modelDB->deleteTableName("system","id_system",list.value(1).toInt());
    //modelRes->clear();
    init_treeview();
    modelMain->clear();
    param_model->clear();
    subSystem_model->clear();
    UI->label_nameSystem->clear();

}

void DiagnosticSetting::editName_system(){

    QModelIndex index = UI->systemtreeView->currentIndex();
    if(!index.data(Qt::UserRole).toBool()) return;
    QString name_all = index.data(Qt::UserRole).toString();
    QStringList list = name_all.split("_");
    int id_sys = 0;
    QString system_name;

    if(list.value(0) == "system"){
        id_sys = list.value(1).toInt();
        system_name = list.value(2);
    }else if(list.value(0) == "sys"){
        id_sys = list.value(1).toInt();
        system_name = list.value(3);
    }

    add_system = new QDialog();
    add_system->setMinimumSize(500,200);
    add_system->setWindowTitle("Редактировать систему");
    add_system->setWindowIcon(QIcon(":/icons/edit.png"));

    blok_name = new QLabel("Наименование cистемы:");
    blok_name->setMinimumWidth(100);

    blok_name_edit = new QLineEdit(system_name);

    ok_button = new QPushButton("Ок");
    connect(ok_button,SIGNAL(clicked()),add_system,SLOT(accept()));
    cancel_button = new QPushButton("Отмена");
    connect(cancel_button,SIGNAL(clicked()),add_system,SLOT(close()));

    QHBoxLayout *buttons_layout = new QHBoxLayout();
    buttons_layout->addWidget(ok_button);
    buttons_layout->addWidget(cancel_button);

    QHBoxLayout *path_layout = new QHBoxLayout();
    path_layout->addWidget(blok_name_edit);

    QHBoxLayout *name_layout = new QHBoxLayout();
    name_layout->addWidget(blok_name);

    QGridLayout *mainLayout = new QGridLayout;
    mainLayout->setSizeConstraint(QLayout::SetFixedSize);
    mainLayout->addLayout(name_layout, 0, 0);
    mainLayout->addLayout(path_layout, 0, 1);
    mainLayout->addLayout(buttons_layout, 1, 1);

    add_system->setLayout(mainLayout);

    if(add_system->exec() == QDialog::Accepted)
    {
        QSqlQuery query;
        query.prepare("UPDATE system SET system_name = ? WHERE id_system = ?");
        query.addBindValue(blok_name_edit->text());
        query.addBindValue(id_sys);

        if(!query.exec())
        {
            QMessageBox::about(this,"Ошибка",query.lastError().text());
        }
        init_treeview();
        UI->label_nameSystem->clear();

    }
}
