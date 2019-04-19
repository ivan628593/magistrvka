#include "dbaccess.h"
#include <QFileInfo>
#include <QMap>
#include <QDateTime>

DBAccess::DBAccess(QObject *parent) : QObject(parent)
{

}


//==================== Создание соединения с БД (SQLite) ====================================
bool DBAccess::createConnection(QString dbDriver, QString dbFilePath)
{
    db = QSqlDatabase::addDatabase(dbDriver);
    db.setDatabaseName(dbFilePath);

    QFileInfo checkFile(dbFilePath);

    if(checkFile.isFile())
    {
        if (db.open())
        {
            errorMessage = tr("Database connection established");
            if(setPragmaFK())
            {
                return true;
            }
            else
            {
                errorMessage = db.lastError().text();
                return false;
            }
        }
        else
        {
            errorMessage = db.lastError().text();
            return false;
        }
    }
    else
    {
         errorMessage = tr("Database File does not exist");
         return false;
    }
}

//====
int DBAccess::generateUnique()
{
    return QDateTime::currentMSecsSinceEpoch();
}

bool DBAccess::getNameR()
{

   //    QString name;
//    QSqlQuery query;
//       QString str = QString("SELECT id_expert, expert_name FROM expert");
//     //  query.exec("SELECT id_expert, expert_name FROM expert");
//        if(!query.exec(str))
//        {
//            QSqlError error_sql = query.lastError();
//            QString qqq = error_sql.text();
//            return qqq;
//        }
//        QString f = "sfsdf";
//        return f;


//        while (query.next())
//        {
//        QString _id = query.value(0).toString();
//        name = query.value(1).toString();
//        }
//        return name;
}

//=============== Закрытие соединения с БД =====================================
bool DBAccess::closeConnection()
{
    db.close();
    if(!isConnected())
    {
        return true;
    }
    else
    {
        return false;
    }
}

//===  Проверка открытия соединения ==========
bool DBAccess::isConnected()
{
    if(db.isOpen())
    {
        return true;
    }
    else
    {
        return false;
    }
}

//==== Устанавливает режим работы с внешними ключами для SQLite ====
bool DBAccess::setPragmaFK()
{
    QSqlQuery query;
    QString str = QString(" PRAGMA FOREIGN_KEYS=ON; ");
    if(query.exec(str))
    {
        return true;
    }
    return false;
}

//==== Метод возвращает текст ошибки =====
QString DBAccess::getErrorMessage()
{
    return this->errorMessage;
}


