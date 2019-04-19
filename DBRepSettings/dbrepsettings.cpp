/***********************************************************************
 * Module:  RepositorySettings.cpp
 * Author:  Администратор
 * Modified: 17 мая 2016 г. 14:25:56
 * Purpose: Implementation of the class RepositorySettings
 ***********************************************************************/
#include "dbrepsettings.h"

//==============================================================
//=== Конструктор класса настроек репозитория ==================
//=== repType - тип репозитория (локальный), ========
//=== используется в качестве ключа для сохранения настроек ====
//==============================================================
DBRepSettings::DBRepSettings()
    :QSettings("Eurica")
{
    setHost("127.0.0.1");

}

void DBRepSettings::setIdDbDriver(int idDbDriver)
{
   this->setValue("idDbDriver", idDbDriver);
}


void DBRepSettings::setDbName(QString dbName)
{
   this->setValue("dbName", dbName);
}


void DBRepSettings::setUserName(QString userName)
{
   this->setValue("userName", userName);
}


void DBRepSettings::setPassword(QString password)
{
    this->setValue("password", password);
}


void DBRepSettings::setHost(QString host)
{
    this->setValue("host", host);
}

void DBRepSettings::setStoragePath(QString path)
{
    this->setValue("storagePath", path);
}


int DBRepSettings::getIdDbDriver(void)
{
   return this->value("idDbDriver").toInt();
}


QString DBRepSettings::getDbName(void)
{
   return this->value("dbName").toString();
}


QString DBRepSettings::getUserName(void)
{
   return this->value("userName").toString();
}


QString DBRepSettings::getPassword(void)
{
   return this->value("password").toString();
}


QString DBRepSettings::getHost(void)
{
   return this->value("host").toString();
}

int DBRepSettings::repType()
{
    return repType_;
}

QString DBRepSettings::getStoragePath()
{
    return this->value("storagePath").toString();
}
