#ifndef DBCONNSETTINGSDIALOG_H
#define DBCONNSETTINGSDIALOG_H

#include <QDialog>
#include <QtSql/QSqlDatabase>
#include <QLabel>
#include <QComboBox>
#include <QLineEdit>
#include <QBoxLayout>
#include <QPushButton>
#include <QToolButton>
#include "dbaccess.h"
#include "dbrepsettings.h"

#include "config_dialog.h"

class __EXPORT_DBCONNSETTINGSDIALOG DBConnSettingsDialog : public QDialog
{
    Q_OBJECT

public:
    DBConnSettingsDialog(QString repName = "", QDialog *parent=0);

    QComboBox *DB_type_combobox;
    QLineEdit *db_name_edit;


private slots:
    void slotTestConnection();
    void slotGetSQLiteFilePath();
    void slotSaveSettings();
//  void closeConnection();
private:
    void init_form();
    void saveSettings();
private:

    QLabel *db_name_label;
    QLabel *host_label;
    QLabel *user_label;
    QLabel *password_label;
    QLabel *storagePath_label;
    QPushButton *test_button;
    QPushButton *ok_button;
    QPushButton *cancel_button;
    QToolButton *sqliteFilePathButton;
    QString message;
    int repType;

    DBAccess *dbaccess;
    DBRepSettings *sett;

    bool closeConnection();
};

#endif // DBCONNSETTINGSDIALOG_H
