#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QSqlRecord>
#include <QMessageBox>
#include <QSqlError>
#include "diagnosticmodel.h"


DiagnosticModel::DiagnosticModel(QObject *parent)
    : QObject(parent)
{


}

QStandardItemModel* DiagnosticModel::getParamList(int id_system)
{
    QStandardItemModel *model = new QStandardItemModel;
    int idParam;
    QString paramName;

    QSqlQuery query;
    if(query.exec(QString("SELECT id_parametres, param_name FROM parametres WHERE id_system = %1").arg(id_system))){
        QSqlRecord rec = query.record();
        while (query.next())
        {
            idParam = query.value(rec.indexOf("id_parametres")).toInt();
            paramName = query.value(rec.indexOf("param_name")).toString();
            QStandardItem *item = new QStandardItem;
            item->setData("-",Qt::DisplayRole);
            item->setData(idParam,Qt::UserRole);
            item->setData(paramName,Qt::DisplayRole);
            model->appendRow(item);
        }
    }
    return model;
}

QStandardItemModel* DiagnosticModel::getStateList(int id_system)
{
    QStandardItemModel *model = new QStandardItemModel;
    int idState;
    QString stateName;

    QSqlQuery query;
    if(query.exec(QString("SELECT id_state, state_name FROM state WHERE id_system = %1").arg(id_system))){
        QSqlRecord rec = query.record();
        while (query.next())
        {
            idState = query.value(rec.indexOf("id_state")).toInt();
            stateName = query.value(rec.indexOf("state_name")).toString();
            QStandardItem *item = new QStandardItem;
            item->setData(idState,Qt::UserRole);
            item->setData(stateName,Qt::DisplayRole);
            model->appendRow(item);
        }
    }
    return model;
}


QStandardItemModel* DiagnosticModel:: getSubSystemList(int id_system)
{
    QStandardItemModel *model = new QStandardItemModel;
    int idSystem;
    QString systemName;

    QSqlQuery query;
    if(query.exec(QString("SELECT id_system, system_name FROM system WHERE id_parent=%1").arg(id_system))){
        QSqlRecord rec = query.record();
        while (query.next())
        {
            idSystem = query.value(rec.indexOf("id_system")).toInt();
            systemName = query.value(rec.indexOf("system_name")).toString();
            QStandardItem *item = new QStandardItem;
            item->setData(idSystem,Qt::UserRole);
            item->setData(systemName,Qt::DisplayRole);
            model->appendRow(item);
        }
    }
    return model;
}

void DiagnosticModel::addModelMatrix(int id_sys){

    QSqlQuery query;
    QSqlQuery query_;
    query_.exec(QString("SELECT ch.id_check,st.id_state FROM checking ch, state st WHERE ch.id_system = %1 AND ch.id_system = st.id_system").arg(id_sys));
    while(query_.next()){

        int id = query_.value(0).toInt();
        int id_st = query_.value(1).toInt();
        query.prepare("INSERT INTO model (id_system,id_state,id_check,id_check_result) VALUES (?,?,?,?);");
        query.addBindValue(id_sys);
        query.addBindValue(id_st);
        query.addBindValue(id);
        query.addBindValue(1);

            if(!query.exec()){
            }
    }
}

void DiagnosticModel::delModelMatrix(int id_sys){

    QSqlQuery queryDel;
    queryDel.prepare("DELETE FROM model WHERE id_system = ?");
    queryDel.addBindValue(id_sys);

    if(!queryDel.exec()){
        QString err = queryDel.lastError().text();
        return;
    }
}

void DiagnosticModel::delModelStateRow(int id_state){

    QSqlQuery queryDel;
    queryDel.prepare("DELETE FROM model WHERE id_state = ?");
    queryDel.addBindValue(id_state);

    if(!queryDel.exec()){
        QString err = queryDel.lastError().text();
        return;
    }
}

void DiagnosticModel::addCheckingDB(int id_system, int id_param, QString check_type, int id_subsystem, double alpha, double beta, double durat, double resource){

    QSqlQuery query;
    query.prepare("INSERT INTO checking(id_system,id_parametres,check_type,id_subsytem,alpha,beta,duration,resource) VALUES (?,?,?,?,?,?,?,?)");
    query.addBindValue(id_system);
    query.addBindValue(id_param);
    query.addBindValue(check_type);
    query.addBindValue(id_subsystem);
    query.addBindValue(alpha);
    query.addBindValue(beta);
    query.addBindValue(durat);
    query.addBindValue(resource);

    if(!query.exec()){
     //   QMessageBox::about(this,"Ошибка",query.lastError().text());
    }
}

void DiagnosticModel::addResultCheckingDB(int id_check, int id_state, QString check_type, double min, double max, double av, int result){

    QSqlQuery query;
    query.prepare("INSERT INTO checking_result(id_check,id_state,check_type,check_min,check_max,check_accuracy,result_number) VALUES (?,?,?,?,?,?,?)");
    query.addBindValue(id_check);
    query.addBindValue(id_state);
    query.addBindValue(check_type);
    query.addBindValue(min);
    query.addBindValue(max);
    query.addBindValue(av);
    query.addBindValue(result);

    if(!query.exec()){
        //QMessageBox::about(this,"Ошибка",query.lastError().text());
    }
}

void DiagnosticModel::addNewSystem(int id, QString f){

    QSqlQuery query;
    query.prepare("INSERT INTO system (id_parent,system_name) VALUES (?,?);");
    query.addBindValue(id);
    query.addBindValue(f);

    if(!query.exec()){
    //    QMessageBox::about(this,"Ошибка",query.lastError().text());
    }
}

void DiagnosticModel::deleteTableName(QString table, QString param, int id){

    QSqlQuery query;
    QString str;
    str = QString("DELETE FROM " + table + " WHERE " + param + "=%1").arg(id);

    if((!query.exec(str))){
        return;
    }

}
void DiagnosticModel::fillComboboxSubsystem(QComboBox *box, int id_system){

    if(id_system == 0){
        box->clear();
        box->addItem("-");
    }else{
        box->clear();
        QSqlQuery query;
        //box->addItem("-");
        query.exec(QString("SELECT id_state, state_name FROM state WHERE id_system=%1").arg(id_system));
        while (query.next()){
            QString state_name = query.value(1).toString();
            int id_state = query.value(0).toInt();
            box->addItem(state_name,id_state);
        }
        query.clear();
    }
}

int DiagnosticModel::getIdParametres(int id_check){

    int idParam;
    QSqlQuery query;
    if(query.exec(QString("SELECT id_parametres FROM checking WHERE id_check=%1").arg(id_check))) {
        QSqlRecord rec = query.record();
        while (query.next()){
            idParam = query.value(rec.indexOf("id_parametres")).toInt();
        }
    }
    return idParam;
}

int DiagnosticModel::getIdSub(int id_check){

    int idSub;
    QSqlQuery query;
    if(query.exec(QString("SELECT id_subsytem FROM checking WHERE id_check=%1").arg(id_check))){
        QSqlRecord rec = query.record();
        while (query.next()){
            idSub = query.value(rec.indexOf("id_subsytem")).toInt();
        }
    }
    return idSub;
}

bool DiagnosticModel::getCheckresult(int id_sys){

    QStringList colors;
    QStringList id_checkRes;

    QSqlQuery query;
    query.exec(QString("SELECT id_check_result FROM model WHERE id_system = %1").arg(id_sys));
    while (query.next()){
        colors.append("1");
        id_checkRes.append(query.value(0).toString());
    }

    QSet<QString> set = colors.toSet();
    int count = colors.size();
    if(count !=id_checkRes.size()) return false;


    for(int i=0; i<count; ++i)
        if(!set.contains(id_checkRes[i])) return false;
    return true;
}
