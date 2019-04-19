#ifndef MAINFORM_H
#define MAINFORM_H

#include <QtWidgets>
#include <QFlag>
#include <QMdiArea>
#include <QMap>
#include <QStringList>
#include <QFile>
#include <QDialog>
#include "mymdiarea.h"
#include "diagnosticsetting.h"
#include "dbaccess.h"
#include "dbrepsettings.h"
#include "dbconnsettingsdialog.h"

namespace Ui
{
    class main_form;
}

class Mainform : public QMainWindow
{
	Q_OBJECT

public:
    Mainform(QMainWindow *parent = 0, Qt::WindowFlags flags = 0);
	virtual ~Mainform();

    QMdiArea    *m_mdiArea;
    QMdiSubWindow *interv;
    QString GlobfilePath;

    QList<QMdiSubWindow *> subwindowList;
    bool login_flag;
    QString db_driver,message,login_message;
    QString lastError();

private slots:

    void        show_interview_form();
    void        closeTab(int i);
    void        slotLocalRepConnect();
    void        slotShowLocalDBSettingsDialog();

private:
    QMenu       *menu;
    QAction     *action1;
    QAction     *action2;

    QMenu       *settings_menu;
    QAction     *sett_act1;
    QAction     *sett_act2;

    QMenu       *view_menu;
    QAction     *view_act1;
    QAction     *view_act2;

    QMenu       *service_menu;
    QAction     *service_act1;
    QAction     *service_act2;

    QMenu       *config_menu;
    QAction     *config_act1;
    QAction     *config_act2;

    QMenu       *faq_menu;
    QAction     *faq_act1;
    QAction     *faq_act2;

    QDialog     *DB_dialog;
    QComboBox   *ServDB_combobox;
    QLabel      *message_label;
    QLineEdit   *db_name_edit;
    QLineEdit   *host_edit;
    QLabel      *lab;

    void init_menu();


    bool createConnection();
    bool closeConnection();
    bool test_db_connection();
	void add_menu_exit(QMenu *menu);
    void add_menu_enter_(QMenu *menu);
    void add_menu_klassif(QMenu *menu);
    void add_menu_faq(QMenu *menu);
    bool connection_flag;
    DBAccess *db;
    DBConnSettingsDialog *settingsDlg;

	Ui::main_form *UI;
};

#endif // MAINFORM_H
