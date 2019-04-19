#include "mainform.h"
#include "ui_main_form.h"


Mainform::Mainform(QMainWindow *parent, Qt::WindowFlags flags)
    : QMainWindow(parent, flags),
	UI (new Ui::main_form)
{
	UI->setupUi(this);

    setWindowIcon(QIcon(":/icons/ВСРФ.png"));

    m_mdiArea = new QMdiArea(this);
    m_mdiArea->setTabShape(QTabWidget::Triangular);
    m_mdiArea->setViewMode(QMdiArea::TabbedView);
    setCentralWidget(m_mdiArea);
    statusBar()->showMessage("");
    db = new DBAccess();

    init_menu();
    //-------------------------------------------------------------
    Q_FOREACH (QTabBar * tab, m_mdiArea->findChildren<QTabBar *>())
    {
      tab->setTabsClosable(true);
//    tab->setMovable(true);
      tab->setExpanding(false);
 //   connect(tab, SIGNAL(tabCloseRequested(int)),this, SLOT(closeTab(int)));
    }
    //-------------------------------------------------------

}

Mainform::~Mainform()
{
    delete UI;
}
//====================== диалог коннект выбора БД ====================

void Mainform::slotShowLocalDBSettingsDialog()
{
    settingsDlg = new DBConnSettingsDialog(tr("Local Repository"));
    if(settingsDlg->exec() == QDialog::Accepted)
    {
        slotLocalRepConnect();
    }
}
//==== Открытие соединения с локальной бд =======
void Mainform::slotLocalRepConnect()
{
    DBRepSettings *settings = new DBRepSettings();
    QString dbType;
    int idDriver = settings->getIdDbDriver();
    if(idDriver == DBRepSettings::SQLITE)
    {
        dbType = "SQLite";
    }
    if (settings->getDbName() == ""){

        UI->statusbar->showMessage("Соединение не установлено");

    }else{
        UI->statusbar->showMessage( QString(" Имя БД: %1, Тип БД: %2").arg(settings->getDbName()).arg(dbType));
    }
}

//======================= для tab =====================================
void Mainform::closeTab(int i)
{

     QMdiSubWindow *sub = m_mdiArea->subWindowList()[i];
     QWidget *win = sub->widget();
     win->close();
//     m_mdiArea->setActiveSubWindow(sub);
//     m_mdiArea->closeActiveSubWindow();
     sub->close();
}
//======================================================================
//=============== Инициализация меню главной формы =====================
void Mainform::init_menu()
{
    UI->menuBar->clear();
    menu = new QMenu("Файл");
    add_menu_enter_(menu);
    add_menu_exit(menu);
    UI->menuBar->addMenu(menu);

    service_menu = new QMenu("Подключение к БД");
    add_menu_klassif(service_menu);
    UI->menuBar->addMenu(service_menu);

    faq_menu = new QMenu("Справка");
    add_menu_faq(faq_menu);
    UI->menuBar->addMenu(faq_menu);

    Mainform::setWindowTitle("КИСВКА");
}

void Mainform::add_menu_enter_(QMenu *menu){
    action1 = new QAction("Проверка",this);
    action1->setIcon(QIcon(":/icons/statistic_48x48.png"));
   // action2 = new QAction("Cохранить...",this);
   // action2->setIcon(QIcon(":icons/save_as.png"));
    menu->addAction(action1);
  //  menu->addAction(action2);
    UI->toolBar->setIconSize(QSize(48, 48));
    UI->toolBar->addAction(action1);
    UI->toolBar->addSeparator();
   // UI->toolBar->addAction(action2);
   // UI->toolBar->addSeparator();
    connect(action1, SIGNAL(triggered()),this, SLOT(show_interview_form()));
}

void Mainform::add_menu_exit(QMenu *menu){
	action2 = new QAction("Выход",this);
    action2->setIcon(QIcon(":icons/close.png"));
    menu->addSeparator();
	menu->addAction(action2);

   // connect(action2,SIGNAL(triggered()),this,SLOT(slotLocalRepConnect()));
    connect(action2, SIGNAL(triggered()),this, SLOT(close()));
}
void Mainform::add_menu_faq(QMenu *faq_menu){
    faq_act1 = new QAction("О программе",this);
    faq_act1->setIcon(QIcon(":icons/rubric_item.png"));
    faq_menu->addAction(faq_act1);
//  UI->toolBar->addSeparator();
//  connect(faq_act1, SIGNAL(triggered()),this, SLOT(close()));
}

void Mainform::add_menu_klassif(QMenu *service_menu){

    service_act1 = new QAction("Выбор БД",this);
    service_act2 = new QAction("Выход",this);
    service_act1->setIcon(QIcon(":/icons/database.png"));
    service_act2->setIcon(QIcon(":icons/close.png"));
    service_menu->addAction(service_act1);
    UI->toolBar->setIconSize(QSize(48, 48));
    UI->toolBar->addAction(service_act1);
    UI->toolBar->addSeparator();
    UI->toolBar->addSeparator();
    UI->toolBar->addAction(service_act2);

    connect(service_act1, SIGNAL(triggered()),this, SLOT(slotShowLocalDBSettingsDialog()));
    connect(service_act2, SIGNAL(triggered()),this, SLOT(close()));
}

void Mainform::show_interview_form(){

    QList<DiagnosticSetting *> lst = m_mdiArea->findChildren<DiagnosticSetting*>();
        if(!lst.isEmpty())
        {
            m_mdiArea->setActiveSubWindow(interv);
            return;
        }

    DiagnosticSetting *dialog = new DiagnosticSetting();

    dialog->setWindowTitle("Проверка параметров");
    interv =  m_mdiArea->addSubWindow(dialog,Qt::SubWindow);
    dialog->showMaximized();
    interv->setAttribute (Qt::WA_DeleteOnClose);

    interv->setWindowIcon(QIcon(":icons/.png"));
    m_mdiArea->setActiveSubWindow(interv);
    return;
}




