#include "app.h"
#include "ui_app.h"
#include "forms/add_expense_form.h"
#include "service/dao.h"

App::App(std::shared_ptr<DAO> dao, QWidget *parent)
    : QMainWindow(parent),
    m_dao(dao),
    ui(new Ui::App)
{
    ui->setupUi(this);
    m_addExpenseForm = new AddExpenseForm(this);
    m_addExpenseForm->setWindowFlag(Qt::Window);
}

App::~App()
{
    delete ui;
    delete m_addExpenseForm;
}

void App::run() {
    m_dao->openDb();
}

// ## SLOTS ##

void App::on_addBtn_clicked() {
    m_addExpenseForm->show();
}

