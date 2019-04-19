#include "dbconnsettingsdialog.h"
#include <QFileDialog>
#include <QMessageBox>
#include "dbrepsettings.h"
#include "diagnosticsetting.h"
#include "dbaccess.h"

DBConnSettingsDialog::DBConnSettingsDialog(QString repName, QDialog *parent):
    QDialog(parent)
{

    dbaccess = new DBAccess;

    sett = new DBRepSettings();

    QString title = tr("DB connection settings ");

    if(!repName.isEmpty())
    {
        title.append("(");
        title.append(repName);
        title.append(")");
    }
    this->setWindowTitle(title);
    this->setFixedSize(400,250);

    init_form();

}



//========== Создание и открытие диалогового окна настроек соединения с БД ===============
void DBConnSettingsDialog::init_form()
{
 //============== Создание элементов формы ====================
 QLabel *DB_label = new QLabel(tr("DB type: "));
 DB_type_combobox = new QComboBox();
 //DB_type_combobox->addItem(QIcon(":/icons/PostgreSQL.png"),"PostgreSQL",RepositorySettings::POSTGRESQL);
 DB_type_combobox->addItem(QIcon(":icons/sqlite.png"),"SQLite",DBRepSettings::SQLITE);

 DBRepSettings *settings = new DBRepSettings(); //rep->settings();

 DB_type_combobox->setCurrentIndex(settings->getIdDbDriver());

 db_name_label = new QLabel(tr("DB name: "));
 db_name_edit = new QLineEdit();
 db_name_edit->setText(settings->getDbName());


 sqliteFilePathButton = new QToolButton;
 sqliteFilePathButton->setText("...");
 sqliteFilePathButton->setToolTip(tr("Choose database filepath"));


 //slotHideShowSQLiteButton(DB_type_combobox->currentIndex());

 test_button = new QPushButton(tr("Connection test"));
 ok_button = new QPushButton(tr("Ok"));
 cancel_button = new QPushButton(tr("Cancel"));

 //=============== Размещение объектов на форме ===================
 QGridLayout *grid_layout = new QGridLayout;
 grid_layout->addWidget(DB_label,0,0);
 grid_layout->addWidget(DB_type_combobox,0,1);
 grid_layout->addWidget(db_name_label,1,0);
 grid_layout->addWidget(db_name_edit,1,1);
 grid_layout->addWidget(sqliteFilePathButton,1,2);

 QBoxLayout *buttons_layout = new QBoxLayout(QBoxLayout::LeftToRight);
 buttons_layout->addWidget(test_button);
 buttons_layout->addStretch();
 buttons_layout->addWidget(ok_button);
 buttons_layout->addWidget(cancel_button);

 QBoxLayout *main_layout = new QBoxLayout(QBoxLayout::TopToBottom);
 main_layout->addLayout(grid_layout);
 main_layout->addStretch();
 main_layout->addLayout(buttons_layout);

 this->setLayout(main_layout);

 //=================================================================
 connect(test_button,SIGNAL(clicked()),this,SLOT(slotTestConnection()));
 connect(ok_button,SIGNAL(clicked()),this,SLOT(slotSaveSettings()));
 connect(cancel_button,SIGNAL(clicked()),this,SLOT(reject()));
// connect(DB_type_combobox,SIGNAL(currentIndexChanged(int)),this,SLOT(slotHideShowSQLiteButton(int)));
 connect(sqliteFilePathButton,SIGNAL(clicked()),this,SLOT(slotGetSQLiteFilePath()));
 //=================================================================
}


//=== Слот выбора пути к файлу SQLite БД  ====
void DBConnSettingsDialog::slotGetSQLiteFilePath()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open Database File"),
                                                    "/",
                                                    tr("SQLite database files (*.db *.sqlite);;All Files (*.*)"));
    db_name_edit->setText(fileName);
}

bool DBConnSettingsDialog::closeConnection()
{
    return dbaccess->closeConnection();
}
//====== Слот проверки соединения =====
void DBConnSettingsDialog::slotTestConnection()
{
      saveSettings();

      bool connFlag = dbaccess->createConnection("QSQLITE",sett->getDbName());
      if(connFlag)
      {
          closeConnection();
      }

      QMessageBox::information(this,tr("Connection testing"),dbaccess->getErrorMessage());
      return;

}

//==== Сохранение настроек соединения ============
void DBConnSettingsDialog::saveSettings()
{
    DBRepSettings *settings = new DBRepSettings();
    int index = DB_type_combobox->currentIndex();
    QVariant id = DB_type_combobox->itemData(index);
    settings->setIdDbDriver(id.toInt());
    settings->setDbName(db_name_edit->text());
}


//==== Слот сохранения настроек при закрытии диалога по кнопке OK ===========
void DBConnSettingsDialog::slotSaveSettings()
{
    saveSettings();
    accept();
}
